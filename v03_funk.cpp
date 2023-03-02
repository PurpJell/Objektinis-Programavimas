#include "myLib.h"
#include "op.h"

using namespace std;

double vid(studentas &temp)
{
	
	if (temp.paz.size() == 0)
	{
		throw "Pazymiu skaicius lygus nuliui!";
	}
	else if (temp.egz > 10 || temp.egz < 0)
	{
		throw "Neteisingai ivestas egzamino pazimys!";
	}
	
	double vid = 0;
	
	for (int i = 0; i < temp.paz.size(); i++)
	{
		if(temp.paz.at(i) > 10 || temp.paz.at(i) < 0)
		{
			throw "Neteisingai ivesti pazymiai";
		}
		vid += temp.paz.at(i);
	}
	
	vid /= temp.paz.size();
	
	return vid;
}

double med(studentas &temp)
{
	double med = 0;
	
	sort(temp.paz.begin(), temp.paz.begin()+temp.paz.size());
	if (temp.paz.size() % 2 == 0)
	{
		med = (1.0 * temp.paz.at(temp.paz.size()/2 - 1) + 1.0 * temp.paz.at(temp.paz.size()/2)) / 2;
	}
	else med = 1.0 * temp.paz.at(temp.paz.size()/2);
	
	return med;
}

void pildyti(studentas &temp, char md)
{
	int n;

	if (md == 'a' || md == 'A')
	{
		temp.vardas += (char)(rand()%10+97);;
		temp.pavarde += (char)(rand()%10+97);;
		temp.vardas += (char)(rand()%10+97);;
		temp.pavarde += (char)(rand()%10+97);;
		temp.vardas += (char)(rand()%10+97);;
		temp.pavarde += (char)(rand()%10+97);
		
		cout<<"Pazymiu generavimas,\'n\' - sustoti, bet koks simbolis - testi"<<endl;
		
		char x = 'a';
		int num;
		
		while (true)
		{
			cin>>x;
			if (x == 'n' || x == 'N') break;
			num = rand()%11;
			temp.paz.push_back(num);
			cout<<num<<endl;
		}
		
		temp.egz = (rand()%11);
	}

	if (md == 'h' || md == 'H')
	{
		cout<<"Iveskite varda ir pavarde: "<<endl;
		cin>>temp.vardas>>temp.pavarde;
		
		cout<<"Iveskite studento pazymius (sustabdyti iveskite bet koki simboli): "<<endl;
		
		int x;
		
		while (cin>>x)
		{
			temp.paz.push_back(x);
		}
		
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		cout<<"Iveskite egzamino pazymi: "<<endl;
		cin>>temp.egz;
		
	}
	
	try
	{
		temp.vid = 0.4 * vid(temp) + 0.6 * temp.egz;
		temp.med = 0.4 * med(temp) + 0.6 * temp.egz;
	}
	catch (const char* err)
	{
		cerr<<err<<endl;
		cout<<"Bandykite is naujo"<<endl<<endl;
		temp.paz.clear();
		temp.vardas = "";
		temp.pavarde = "";
		pildyti(temp, md);
	}
	
}

void nuskaityti(vector<studentas> &mas, int &stCount)
{
	
	studentas temp;
	
	string fileToRead;
	char endLine = 'a'; // is the next character == '\n'?
	
	cout<<"Iveskite failo pavadinima: ";
	cin>>fileToRead;
	
	ifstream read(fileToRead);
	
	if (!read)
	{
		throw "Failas nerastas";
	}
	
	string input;
	
	bool badFile = false; // ar failas paruostas neteisingai?
	
	getline(read, input); // praleidzia pirma eilute
	
	while (!read.eof())
	{
		read>>input;
		if(!(input[0] > 47 && input[0] < 58)) // jei ne skaicius
		{
			if (temp.vardas == "") // jei input yra vardas
			{
				temp.vardas = input;
			}
			else if (temp.pavarde == "") // jei input yra pavarde
			{
				temp.pavarde = input;
			}
			else // neteisingai sudarytas failas
			{
				getline(read, input);
				temp.paz.clear();
				temp.vardas = "";
				temp.pavarde = "";
				badFile = true;
			}
		}
		else // jei input yra skaicius
		{
			if (!(stoi(input) >= 0 && stoi(input) <= 10)) // pazimys iseina is ribu [0;10]
			{
				getline(read, input);
				temp.paz.clear();
				temp.vardas = "";
				temp.pavarde = "";
				badFile = true;
				continue;
			}
			
			temp.paz.push_back(stoi(input));
		
			endLine = read.get();
			if(endLine == '\n') // jei baigiasi eilute (baigiamas studento pazymiu ivedimas)
			{
				temp.egz = temp.paz[temp.paz.size() - 1]; // paskutinis pazimys tampa egzamino pazimiu
				temp.paz.pop_back(); // pasalinamas paskutinis pazimys
				
				temp.vid = 0.4 * vid(temp) + 0.6 * temp.egz;
				temp.med = 0.4 * med(temp) + 0.6 * temp.egz;
			
				mas.push_back(temp);
				temp.paz.clear();
				temp.vardas = "";
				temp.pavarde = "";

				stCount++;
			}
		}
	}
	
	if (badFile) throw "Neteisingai paruostas failas, kai kurie irasai gali buti praleisti";
		
}

void spausdinti(studentas &temp, char mode)
{
	
	ofstream write("res.txt", ios_base::app);
	
	if (mode == 'v' || mode == 'V') 
	{
		write<<left<<setw(15)<<temp.pavarde<<setw(12)<<temp.vardas<<setw(3)<<fixed<<setprecision(2)<<temp.vid<<endl;
	}
	else if (mode == 'm' || mode == 'M')
	{
		write<<left<<setw(15)<<temp.pavarde<<setw(12)<<temp.vardas<<setw(3)<<fixed<<setprecision(2)<<temp.med<<endl;
	}
}

bool swapNames(string v1, string v2)
{
	bool res = false;
	
	if (v1.length() > v2.length()) // jei v2 trumpesnis
	{
		for (int i = 0; i < v2.length() - 1; i++)
		{
			if(v1[i] > v2[i])
			{
				return true;
			}
			else if (v1[i] < v2[i])
			{
				return false;
			}
		}
		
		return true; // jei visos raides sutampa, bet v1 turi daugiau raidziu
		
	}
	else // jei v1 trumpesnis
	{
		for (int i = 0; i < v1.length() - 1; i++)
		{
			if(v1[i] > v2[i])
			{
				return true;
			}
			else if (v1[i] < v2[i])
			{
				return false;
			}
		}
	}
	return false;
}

void rusiuoti(vector<studentas> &mas)
{
	
	for (int i = 0; i < mas.size() - 1; i++)
	{
		for (int j = i + 1; j < mas.size(); j++)
		{
			if (swapNames(mas[i].vardas, mas[j].vardas)) swap(mas[i], mas[j]);
		}
	}
}
