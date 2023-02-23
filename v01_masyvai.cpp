#include "myLib.h"

struct studentas
{
	string vard = "", pav = "";
	int* paz;
	int egz, pazCount = 0;
	float vid = 0, med = 0;
};

void mediana(studentas* stud, int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (stud->paz[j] < stud->paz[i]) swap(stud->paz[j],stud->paz[i]);
		}
	}
	
	float mediana = size % 2 == 0 ? (stud->paz[size/2-1] + stud->paz[size/2]) / 2.0 : stud->paz[size/2];
	stud->med = 0.4 * mediana + 0.6 * stud->egz;
//	stud->med = mediana; // paprasta mediana
}

void resizePaz(int*& paz, int size)
{
	int* temp = new int[size];
	
	for (int i = 0; i < size-1; i++)
	{
		temp[i] = paz[i];
	}
	
	delete [] paz;
	
	paz = temp;
}

void enterPaz(studentas* stud, char im)
{
	char input;
	float sk, suma = 0;
	stud->paz = NULL;
	
	if (im == 'h' || im == 'H')
	{
		cout<<"Iveskite studento varda ir pavarde: "<<endl;
		cin>>stud->vard>>stud->pav;
		
		cout<<"Iveskite studento pazymius (nustoti iveskite ne skaiciu):"<<endl;
		
		while (cin>>sk)
		{
			if (stud->pazCount == 0)
			{
				stud->paz = new int[1]; // sukuria nauja pazymiu masyva
				stud->paz[0] = sk;
				suma += sk;
				stud->pazCount++;
			}
			else
			{
				suma += sk;
				stud->pazCount++;
				resizePaz(stud->paz, stud->pazCount);
				stud->paz[stud->pazCount - 1] = sk;
			}
		}
		
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		
		cout<<"Iveskite egzamino pazymi: ";
		cin>>stud->egz;
	}
	
	else if (im == 'a' || im == 'A')
	{
		stud->vard += (char)(rand()%10+97);
		stud->pav += (char)(rand()%10+97);
		stud->vard += (char)(rand()%10+97);
		stud->pav += (char)(rand()%10+97);
		stud->vard += (char)(rand()%10+97);
		stud->pav += (char)(rand()%10+97);
		
		cout<<"Kiek pazymiu sugeneruoti?"<<endl;
		cin>>stud->pazCount;
		
		stud->paz = new int[stud->pazCount];
		
		for (int i = 0; i < stud->pazCount; i++)
		{
			sk = rand()%11;
			suma += sk;
			stud->paz[i] = sk;
		}
		
		stud->egz = rand()%11;
	}
	
	if (stud->pazCount > 0) stud->vid = 0.4 * (suma/stud->pazCount) + 0.6 * stud->egz;
	else stud->vid = stud->egz * 0.6;

//	stud->vid = suma/stud->pazCount; // paprastas vidurkis
	mediana(stud, stud->pazCount);
}

void resize(studentas*& studentai, int size)
{
	studentas* temp = new studentas[size];
	
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = studentai[i];
	}
	
	delete [] studentai;
	
	studentai = temp;
}

void print(studentas temp, char mode)
{
	if (mode == 'v' || mode == 'V') 
	{
		cout<<setw(15)<<temp.pav<<setw(10)<<temp.vard<<setw(3)<<fixed<<setprecision(2)<<temp.vid<<endl;
	}
	
	else if (mode == 'm' || mode == 'M')
	{
		cout<<setw(15)<<temp.pav<<setw(10)<<temp.vard<<setw(3)<<fixed<<setprecision(2)<<temp.med<<endl;
	}
	
//	for (int i = 0; i < temp.pazCount; i++) // isvesti visus pazymius
//	{
//		cout<<temp.paz[i]<<" ";
//	}
//	cout<<endl;
}

int main()
{
	studentas* studentai;
	
	int studCount = 0;
	char input;
	
	char inputMode;
	cout<<"Ivesti duomenis Ranka (h) ar Automatiskai (a)?"<<endl;
	cin>>inputMode;
	
	while (input != 'n' && input != 'N')
	{
		if (studCount == 0)
		{
			studentai = new studentas[1];
			studCount++;
			enterPaz(&studentai[0], inputMode);
		}
		else
		{
			studCount++;
			resize(studentai, studCount);
			enterPaz(&studentai[studCount-1], inputMode);
		}
		
		cout<<"Baigti ivedineti studentus - n, testi - bet koks klavisas"<<endl;
		cin>>input;	
	}
	
	char mode;
	
	cout<<"Kaip isvesti duomenis Vidurki (v) ar Mediana (m)?"<<endl;
	cin>>mode;
	
	if (mode == 'v' || mode == 'V') cout<<endl<<left<<setw(15)<<"Pavarde"<<setw(10)<<"Vardas"<<setw(3)<<"Galutinis (Vid.)"<<endl<<"__________________________________________________________________________________"<<endl;
	else if (mode == 'm' || mode == 'M') cout<<endl<<left<<setw(15)<<"Pavarde"<<setw(10)<<"Vardas"<<setw(3)<<"Galutinis (Med.)"<<endl<<"__________________________________________________________________________________"<<endl;
	
	for (int i = 0; i < studCount; i++) print(studentai[i], mode);
}
