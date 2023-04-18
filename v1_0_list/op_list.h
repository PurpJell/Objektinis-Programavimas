#ifndef OP_LIST_H
#define OP_LIST_H

#include "myLibList.h"

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
void dalinti(studentas temp, list<studentas> &kieti, list<studentas> &prasti);
void dalinti2(list<studentas>& mas, list<studentas>& kieti);
bool compareByName(const studentas& a, const studentas& b);
void print(list<studentas> &mas, char mode);
void kout(list<studentas> &kieti, int pazNr);
void pout(list<studentas> &prasti, int pazNr);
bool daugiau(string s1, string s2);

#endif


