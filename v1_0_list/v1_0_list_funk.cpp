#include "myLibList.h"
#include "op_list.h"

using namespace std;

double vid(studentas &temp)
{
	
	if (temp.paz.size() == 0)
	{
		throw "Pazymiu skaicius lygus nuliui!";
	}
	else if (temp.egz > 10 || temp.egz < 0)
	{
		throw "Neteisingai ivestas egzamino pazymys!";
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

void generuoti(list<studentas> &mas, int &stCount, int &pazNr)
{
	cout<<"Irasykite, kiek irasu generuoti 1k (1), 10k (2), 100k (3), 1M (4), 10M (5)"<<endl;
	int records = 1;

	cin>>records;
	
	switch(records){
		case 1:
			records = 1000;
			break;
		case 2:
			records = 10000;
			break;
		case 3:
			records = 100000;
			break;
		case 4:
			records = 1000000;
			break;
		case 5:
			records = 10000000;
			break;
		default:
			cout<<"Neteisinga ivestis"<<endl;
			return;
	}
	
	vector<int> skaic;
	
	for (int i = 1; i <= records; i++)
	{
		skaic.push_back(i);
	}
	
	random_shuffle(skaic.begin(), skaic.end());
	
	cout<<"Irasykite, kiek pazymiu generuoti kiekvienam studentui"<<endl;
	cin>>pazNr;
	
	string tempSt = "";
	
	for (int i = 0; i < pazNr; i++)
	{
		tempSt += "paz"+ to_string(i+1) + " "; 
	}
	tempSt += " egz";

	string failas = "klase"+to_string(records)+".txt";
	ofstream write(failas);

	write<<left<<setw(20)<<"Pavarde"<<setw(15)<<"Vardas "<<tempSt<<endl;

	
	studentas temp;
	int paz;
	int sk;
	
	for (int i = 0; i < records; i++)
	{
		sk = skaic.at(skaic.size()-1);
		skaic.pop_back();

		temp.vardas = "vardas" + to_string(sk);
		temp.pavarde = "pavarde" + to_string(sk);
		tempSt = "";
		
		for (int j = 0; j < pazNr; j++)
		{
			paz = rand()%11;
			if (paz == 10) tempSt += to_string(paz) + "   ";
			else tempSt += " "+ to_string(paz) + "   ";
			temp.paz.push_back(paz);
		}
		paz = rand()%11;
		temp.egz = paz;
		if (paz == 10) tempSt += to_string(paz) + "\n";
		else tempSt += " "+ to_string(paz) + "\n";
		
		write<<left<<setw(20)<<temp.pavarde<<setw(15)<<temp.vardas<<setw(3)<<tempSt;
		
	}
	
}

void dalinti(studentas temp, list<studentas> &kieti, list<studentas> &prasti)
{
	if (temp.vid >= 5)
		{
			kieti.push_back(temp);
		}
		else
		{
			prasti.push_back(temp);
		}
}

void dalinti2(list<studentas>& mas, list<studentas>& kieti)
{
	for (auto it = mas.begin(); it != mas.end();) {
		if (it->vid >= 5) {
			kieti.push_back(*it);
			it = mas.erase(it);
		}
		else {
			++it;
		}
	}
}

void nuskaityti(list<studentas> &mas, int &stCount, int &pazNr)
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

	auto readStart = system_clock::now();
	
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
			if (!(stoi(input) >= 0 && stoi(input) <= 10)) // pazymys iseina is ribu [0;10]
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

				if (stCount == 0)
				{
					pazNr = temp.paz.size();
				}

				temp.paz.clear();
				temp.vardas = "";
				temp.pavarde = "";

				stCount++;
			}
		}
	}
	
	if (badFile) throw "Neteisingai paruostas failas, kai kurie irasai gali buti praleisti";

	auto readEnd = system_clock::now();

	auto readElapsed =
	duration_cast<seconds>(readEnd - readStart);
	cout << endl << "~Nuskaitymo laikas: " << readElapsed.count() << "s." << endl << endl;
		
}

bool daugiau(string s1, string s2)
{
	return s1 > s2;
}

bool compareByName(const studentas& a, const studentas& b)
{
	return a.vardas < b.vardas;
}

void print(list<studentas> &mas, char mode)
{

	stringstream stream;
	string output;
	ofstream write("res.txt", ios_base::app);
	
	studentas temp;

	int i = 0;

	if (mode == 'v' || mode == 'V') 
	{
		for (studentas temp : mas)
		{
			i++;
			stream<<left<<setw(20)<<temp.pavarde<<setw(15)<<temp.vardas<<setw(3)<<fixed<<setprecision(2)<<temp.vid<<endl;
			if ((i + 1) % 1000 == 0 || (i == mas.size()))
			{
				output = stream.str();
				write<<output;
				stream.str("");
			}
		}
	}
	else if (mode == 'm' || mode == 'M')
	{
		for (studentas temp : mas)
		{
			i++;
			stream<<left<<setw(20)<<temp.pavarde<<setw(15)<<temp.vardas<<setw(3)<<fixed<<setprecision(2)<<temp.med<<endl;
			if ((i + 1) % 1000 == 0 || (i == mas.size()))
			{
				output = stream.str();
				write<<output;
				stream.str("");
			}
		}
	}
}

void kout(list<studentas> &kieti, int pazNr)
{

	int i = 0;
	string tempSt = "";

	for (int i = 0; i < pazNr; i++)
	{
		tempSt += "paz" + to_string(i + 1) + " ";
	}
	tempSt += " egz";

	ofstream wkieti("kieti.txt");
	wkieti<<left<<setw(20)<<"Pavarde"<<setw(15)<<"Vardas "<<tempSt<<endl;
	wkieti<<"___________________________________________________________________________________________"<<endl;

	stringstream stream;
	string output;

	for (studentas kietas : kieti)
	{
		i++;
		stream<<left<<setw(20)<<kietas.pavarde<<setw(15)<<kietas.vardas;
		for (int j = 0; j < pazNr; j++)
		{
			stream<<right<<setw(4)<<kietas.paz.at(j)<<" ";
		}
		stream<<right<<setw(4)<<kietas.egz<<endl;
		
		if ((i + 1) % 1000 == 0 || (i == kieti.size()))
		{
			output = stream.str();
			wkieti<<output;
			stream.str("");
		}
	}
}

void pout(list<studentas> &prasti, int pazNr)
{
	int i = 0;

	string tempSt = "";

	for (int i = 0; i < pazNr; i++)
	{
		tempSt += "paz" + to_string(i + 1) + " ";
	}
	tempSt += " egz";

	ofstream wprasti("prasti.txt");
	wprasti << left << setw(20) << "Pavarde" << setw(15) << "Vardas " << tempSt << endl;
	wprasti << "___________________________________________________________________________________________" << endl;
	
	stringstream stream;
	string output;
	
	for (studentas prastas : prasti)
	{
		i++;
		stream<<left<<setw(20)<<prastas.pavarde<<setw(15)<<prastas.vardas;
		for (int j = 0; j < pazNr; j++)
		{
			stream<<right<<setw(4)<<prastas.paz.at(j)<<" ";
		}
		stream<<right<<setw(4)<<prastas.egz<<endl;
		
		if ((i + 1) % 1000 == 0 || (i == prasti.size()))
		{
			output = stream.str();
			wprasti<<output;
			stream.str("");
		}
	}
}
