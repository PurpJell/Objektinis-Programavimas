#include "myLib.h"

struct studentas
{
	string vardas = "", pavarde = "";
	vector<int> paz;
	int egz;
	double vid = 0;
	double med = 0;
};

double vid(studentas &temp)
{
	double vid = 0;
	
	for (int i = 0; i < temp.paz.size(); i++)
	{
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
	
	temp.vid = 0.4 * vid(temp) + 0.6 * temp.egz;
	temp.med = 0.4 * med(temp) + 0.6 * temp.egz;
	
}

void nuskaityti(vector<studentas> &mas, int &stCount)
{
	
	studentas temp;
	
	string fileToRead;
	char endLine = 'a'; // is the next character == '\n'?
	
	cout<<"Iveskite failo pavadinima: ";
	cin>>fileToRead;
	
	ifstream read(fileToRead);
	
	string input;
	
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
			else
			{
				temp.pavarde = input;
			}
		}
		else // jei input yra skaicius
		{	
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

int main()
{
	vector<studentas> mas; // studentu masyvas
	studentas tempas;
	int stCount = 0;

	char uzkl = 'n';
	
	char inputMode; // budas ivesti duomenis
	cout<<"Ivesti duomenis Ranka (h), Automatiskai (a) ar Nuskaityti (r)?"<<endl;
	cin>>inputMode;
	
	if ((inputMode != 'r' && inputMode != 'R')) // jei neskaitoma is failo
	{
		do
		{
			pildyti(tempas, inputMode);
			mas.push_back(tempas);
			tempas.paz.clear();
			tempas.vardas = "";
			tempas.pavarde = "";
			
			cout<<"\'n\' - baigti, bet koks klavisas - ivesti nauja studenta: ";
			cin>>uzkl;
		} while(uzkl != 'n' && uzkl != 'N');
	}
	else // jei skaitoma is failo
	{
		nuskaityti(mas, stCount);
	}

	char mode;
	
	cout<<"Kaip isvesti duomenis Vidurki (v) ar Mediana (m)?"<<endl;
	cin>>mode;
	
	ofstream write("res.txt");
	
	if (mode == 'v' || mode == 'V') write<<endl<<left<<setw(15)<<"Pavarde"<<setw(10)<<"Vardas"<<setw(3)<<"Galutinis (Vid.)"<<endl<<"__________________________________________________________________________________"<<endl;
	else if (mode == 'm' || mode == 'M') write<<endl<<left<<setw(15)<<"Pavarde"<<setw(10)<<"Vardas"<<setw(3)<<"Galutinis (Med.)"<<endl<<"__________________________________________________________________________________"<<endl;
	
	rusiuoti(mas);
	for (auto &i : mas) spausdinti(i, mode);
}
