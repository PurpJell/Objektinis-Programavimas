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
	
	temp.vid = vid(temp);
	temp.med = med(temp);
	
}

void spausdinti(studentas &temp, char mode)
{
	if (mode == 'v' || mode == 'V') 
	{
		cout<<setw(15)<<temp.pavarde<<setw(10)<<temp.vardas<<setw(3)<<fixed<<setprecision(2)<<temp.vid<<endl;
	}
	else if (mode == 'm' || mode == 'M')
	{
		cout<<setw(15)<<temp.pavarde<<setw(10)<<temp.vardas<<setw(3)<<fixed<<setprecision(2)<<temp.med<<endl;
	}
}

int main()
{
	vector<studentas> mas;
	studentas tempas;

	char uzkl = 'n';
	
	char inputMode;
	cout<<"Ivesti duomenis Ranka (h) ar Automatiskai (a)?"<<endl;
	cin>>inputMode;
	
	do
	{
		pildyti(tempas, inputMode);
		mas.push_back(tempas);
		tempas.paz.clear();
		
		cout<<"\'n\' - baigti, bet koks klavisas - ivesti nauja studenta: ";
		cin>>uzkl;
	} while(uzkl != 'n' && uzkl != 'N');
	
	char mode;
	
	cout<<"Kaip isvesti duomenis Vidurki (v) ar Mediana (m)?"<<endl;
	cin>>mode;
	
	if (mode == 'v' || mode == 'V') cout<<endl<<left<<setw(15)<<"Pavarde"<<setw(10)<<"Vardas"<<setw(3)<<"Galutinis (Vid.)"<<endl<<"__________________________________________________________________________________"<<endl;
	else if (mode == 'm' || mode == 'M') cout<<endl<<left<<setw(15)<<"Pavarde"<<setw(10)<<"Vardas"<<setw(3)<<"Galutinis (Med.)"<<endl<<"__________________________________________________________________________________"<<endl;
	
	
	for (auto &i : mas) spausdinti(i, mode);
}
