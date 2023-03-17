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

void generuoti(vector<studentas> &mas, int &stCount, int &pazNr)
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
	ofstream wkieti("kieti.txt");
	ofstream wprasti("prasti.txt");
	write<<left<<setw(20)<<"Pavarde"<<setw(15)<<"Vardas "<<tempSt<<endl;
	write<<"___________________________________________________________________________________________"<<endl;
	wkieti<<left<<setw(20)<<"Pavarde"<<setw(15)<<"Vardas "<<tempSt<<endl;
	wkieti<<"___________________________________________________________________________________________"<<endl;
	wprasti<<left<<setw(20)<<"Pavarde"<<setw(15)<<"Vardas "<<tempSt<<endl;
	wprasti<<"___________________________________________________________________________________________"<<endl;
	
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
		if (paz == 10) tempSt += to_string(paz) + "   ";
		else tempSt += " "+ to_string(paz) + "   ";
		
		
		temp.vid = 0.4 * vid(temp) + 0.6 * temp.egz;
		temp.med = 0.4 * med(temp) + 0.6 * temp.egz;
		
		write<<left<<setw(20)<<temp.pavarde<<setw(15)<<temp.vardas<<setw(3)<<tempSt<<endl;
		
		
		string eilNr;
		eilNr = temp.vardas;
    	eilNr.erase(0,6);
    	temp.nr = stoi(eilNr);
		
		mas.push_back(temp);
		temp.paz.clear();
		temp.vardas = "";
		temp.pavarde = "";
		stCount++;
		
	}
	
}

void dalinti(studentas temp, vector<studentas> &kieti, vector<studentas> &prasti, int &kietiCnt, int &prastiCnt)
{
	if (temp.vid >= 5)
		{
			kieti.push_back(temp);
			kietiCnt++;
		}
		else
		{
			prasti.push_back(temp);
			prastiCnt++;
		}
}

//void kietiOut(studentas &kietas, int pazNr)
//{
//	string tempSt = "";
//	int paz;
//	
//	ofstream wkieti("kieti.txt", ios_base::app);
//	
//	for (int j = 0; j < pazNr; j++)
//		{
//			paz = kietas.paz.at(j);
//			if (paz == 10) tempSt += to_string(paz) + "   ";
//			else tempSt += " "+ to_string(paz) + "   ";
//		}
//		paz = kietas.egz;
//		if (paz == 10) tempSt += to_string(paz) + "   ";
//		else tempSt += " "+ to_string(paz) + "   ";
//	
//	wkieti<<left<<setw(20)<<kietas.pavarde<<setw(15)<<kietas.vardas<<setw(3)<<tempSt<<endl;
//}
//
//void prastiOut(studentas &prastas, int pazNr)
//{
//	string tempSt = "";
//	int paz;
//	
//	ofstream wprasti("prasti.txt", ios_base::app);
//	
//	for (int j = 0; j < pazNr; j++)
//		{
//			paz = prastas.paz.at(j);
//			if (paz == 10) tempSt += to_string(paz) + "   ";
//			else tempSt += " "+ to_string(paz) + "   ";
//		}
//		paz = prastas.egz;
//		if (paz == 10) tempSt += to_string(paz) + "   ";
//		else tempSt += " "+ to_string(paz) + "   ";
//	
//	wprasti<<left<<setw(20)<<prastas.pavarde<<setw(15)<<prastas.vardas<<setw(3)<<tempSt<<endl;
//}

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

//void spausdinti(studentas &temp, char mode)
//{
//	
//	ofstream write("res.txt", ios_base::app);
//	
//	if (mode == 'v' || mode == 'V') 
//	{
//		write<<left<<setw(20)<<temp.pavarde<<setw(15)<<temp.vardas<<setw(3)<<fixed<<setprecision(2)<<temp.vid<<endl;
//	}
//	else if (mode == 'm' || mode == 'M')
//	{
//		write<<left<<setw(20)<<temp.pavarde<<setw(15)<<temp.vardas<<setw(3)<<fixed<<setprecision(2)<<temp.med<<endl;
//	}
//}

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
			if (swapNames(mas[i].vardas, mas[j].vardas)) 
			{
				swap(mas[i], mas[j]);
				cout<<i<<endl;
				i = 0;
				break;
			}
		}
	}
}

//void rusiuotiGen(vector<studentas> &mas)
//{
//	int j, key;
//	
//	studentas temp;
//	
//	for (int i = 1; i < mas.size(); i++)
//	{
//		key = mas.at(i).nr;
//		temp = mas.at(i);
//		j = i - 1;
//		
//		while (j >= 0 && mas.at(j).nr > key)
//		{
//			mas.at(j+1) = mas.at(j);
//			j--;
//		}
//		mas.at(j+1) = temp;
//		
//	}
//}

int partition(vector<studentas>& mas, int start, int end)
{
	int pivot = mas.at(start).nr;

	int count = 0;
	for (int i = start + 1; i <= end; i++)
	{
		if (mas.at(i).nr <= pivot) count++;
	}

	int pivotIndex = start + count;
	swap(mas.at(pivotIndex), mas.at(start));

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex)
	{
		while (mas.at(i).nr <= pivot)
		{
			i++;
		}

		while (mas.at(j).nr > pivot)
		{
			j--;
		}

		if (i < pivotIndex && j > pivotIndex)
		{
			swap(mas.at(i++), mas.at(j--));
		}
	}

	return pivotIndex;
}

void quicksort(vector<studentas>& mas, int start, int end)
{
	if (start >= end) return;

	int p = partition(mas, start, end);

	quicksort(mas, start, p - 1);

	quicksort(mas, p + 1, end);
}

void print(vector<studentas> &mas, char mode)
{
	stringstream stream;
	string output;
	ofstream write("res.txt", ios_base::app);
	
	studentas temp;

	if (mode == 'v' || mode == 'V') 
	{
		for (int i = 0; i < mas.size(); i++)
		{
			temp = mas.at(i);
			stream<<left<<setw(20)<<temp.pavarde<<setw(15)<<temp.vardas<<setw(3)<<fixed<<setprecision(2)<<temp.vid<<endl;
			if ((i + 1) % 1000 == 0 || (i == mas.size()-2))
			{
				output = stream.str();
				write<<output;
				stream.str("");
			}
		}
	}
	else if (mode == 'm' || mode == 'M')
	{
		for (int i = 0; i < mas.size(); i++)
		{
			temp = mas.at(i);
			stream<<left<<setw(20)<<temp.pavarde<<setw(15)<<temp.vardas<<setw(3)<<fixed<<setprecision(2)<<temp.med<<endl;
			if ((i + 1) % 1000 == 0 || (i == mas.size()-2))
			{
				output = stream.str();
				write<<output;
				stream.str("");
			}
		}
	}
}

void kout(vector<studentas> &kieti, int pazNr)
{
	
	stringstream stream;
	string output;
	
	studentas kietas;
	
	ofstream wkieti("kieti.txt", ios_base::app);
	
	for (int i = 0; i < kieti.size(); i++)
	{
		kietas = kieti.at(i);
		stream<<left<<setw(20)<<kietas.pavarde<<setw(15)<<kietas.vardas;
		for (int j = 0; j < pazNr; j++)
		{
			stream<<right<<setw(4)<<kietas.paz.at(j)<<" ";
		}
		stream<<right<<setw(4)<<kietas.egz<<endl;
		
		if ((i + 1) % 1000 == 0 || (i == kieti.size()-1))
		{
			output = stream.str();
			wkieti<<output;
			stream.str("");
		}
	}
}

void pout(vector<studentas> &prasti, int pazNr)
{
	
	stringstream stream;
	string output;
	
	studentas prastas;
	
	ofstream wprasti("prasti.txt", ios_base::app);
	
	for (int i = 0; i < prasti.size(); i++)
	{
		prastas = prasti.at(i);
		stream<<left<<setw(20)<<prastas.pavarde<<setw(15)<<prastas.vardas;
		for (int j = 0; j < pazNr; j++)
		{
			stream<<right<<setw(4)<<prastas.paz.at(j)<<" ";
		}
		stream<<right<<setw(4)<<prastas.egz<<endl;
		
		if ((i + 1) % 1000 == 0 || (i == prasti.size()-1))
		{
			output = stream.str();
			wprasti<<output;
			stream.str("");
		}
	}
}
