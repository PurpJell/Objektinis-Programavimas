#ifndef OP_H
#define OP_H

#include "myLib.h"

struct studentas
{
	string vardas = "", pavarde = "";
	vector<int> paz;
	int egz;
	double vid = 0;
	double med = 0;
	int nr = 0;
};

double vid(studentas &temp);
double med(studentas &temp);
void pildyti(studentas &temp, char md);
void nuskaityti(list<studentas> &mas, int &stCount, int &pazNr);
void generuoti(list<studentas> &mas, int &stCount, int &pazNr);
void dalinti(studentas temp, list<studentas> &kieti, list<studentas> &prasti, int &kietiCnt, int &prastiCnt);
int partition(list<studentas>& mas, int start, int end);
void quicksort(list<studentas>& mas, int start, int end);
void print(list<studentas> &mas, char mode);
void kout(list<studentas> &kieti, int pazNr);
void pout(list<studentas> &prasti, int pazNr);
bool daugiau(string s1, string s2);

#endif


