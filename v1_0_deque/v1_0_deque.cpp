#include "myLibDeque.h"
#include "op_deque.h"

int main()
{
	
	auto progStart = system_clock::now();
	
	deque<studentas> mas; // studentu masyvas
	deque<studentas> kieti;
	deque<studentas> prasti;
	int kietiCnt = 0, prastiCnt = 0, pazNr = -1;

	studentas tempas;
	int stCount = 0;

	char uzkl = 'n';
	
	char inputMode; // budas ivesti duomenis
	cout<<"Ivesti duomenis Ranka (h), Automatiskai (a), Nuskaityti (r) ar Generuoti (g)?"<<endl;
	cin>>inputMode;
	
	if ((inputMode == 'g' || inputMode == 'G')) // jei generuojamas failas
	{
		
		auto genStart = system_clock::now();
		
		generuoti(mas, stCount, pazNr);
		
		auto genEnd = system_clock::now();
		
		auto genElapsed =
    	duration_cast<seconds>(genEnd - genStart);
		cout<<endl<<"~Failo generavimo laikas: "<<genElapsed.count()<<"s."<<endl<<endl;
		
		return 0;
	}
	else if ((inputMode != 'r' && inputMode != 'R')) // jei neskaitoma is failo
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
		nuskaityti(mas, stCount, pazNr);
	}

	char mode;
	
	cout<<"Kaip isvesti duomenis Vidurki (v) ar Mediana (m)?"<<endl;
	cin>>mode;
	
	ofstream write("res.txt");
	
	if (mode == 'v' || mode == 'V') write<<left<<setw(20)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(3)<<"Galutinis (Vid.)"<<endl<<"__________________________________________________________________________________"<<endl;
	else if (mode == 'm' || mode == 'M') write<<left<<setw(20)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(3)<<"Galutinis (Med.)"<<endl<<"__________________________________________________________________________________"<<endl;
	
	
	auto sortStart = system_clock::now();

	quicksort(mas, 0, mas.size() - 1);
	
	auto sortEnd = system_clock::now();

	auto sortElapsed =
	duration_cast<seconds>(sortEnd - sortStart);
	cout << endl << "~Rusiavimo laikas: " << sortElapsed.count() << "s." << endl << endl;


	print(mas, mode);

	char dalMode; // budas dalinti studentus i skirtingus konteinerius
	cout << "Kaip dalinti studentus, Sukuriant du naujus konteinerius (a) ar Sukuriant viena nauja konteineri (b)?" << endl;
	cin >> dalMode;

	auto splitStart = system_clock::now();

	if (dalMode == 'a' || dalMode == 'A') for (auto& i : mas) dalinti(i, kieti, prasti, kietiCnt, prastiCnt);
	else if (dalMode == 'b' || dalMode == 'B')
	{
		dalinti2(mas, kieti, kietiCnt, prastiCnt);
		prasti = mas;
	}

	auto splitEnd = system_clock::now();

	auto splitElapsed =
	duration_cast<seconds>(splitEnd - splitStart);
	cout << endl << "~Studentu skirstymo laikas: " << splitElapsed.count() << "s." << endl << endl;

	kout(kieti, pazNr);
	pout(prasti, pazNr);

	auto progEnd = system_clock::now();
	auto progElapsed = duration_cast<seconds>(progEnd - progStart);
	cout<<endl<<"~Visas programos vykdymo laikas: "<<progElapsed.count()<<"s."<<endl<<endl;
}
