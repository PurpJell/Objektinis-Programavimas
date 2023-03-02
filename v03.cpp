#include "myLib.h"
#include "op.h"

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
