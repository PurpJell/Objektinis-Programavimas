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
void nuskaityti(vector<studentas> &mas, int &stCount, int &pazNr);
void generuoti(vector<studentas> &mas, int &stCount, int &pazNr);
void dalinti(studentas temp, vector<studentas> &kieti, vector<studentas> &prasti, int &kietiCnt, int &prastiCnt);
int partition(vector<studentas>& mas, int start, int end);
void quicksort(vector<studentas>& mas, int start, int end);
void print(vector<studentas> &mas, char mode);
void kout(vector<studentas> &kieti, int pazNr);
void pout(vector<studentas> &prasti, int pazNr);
bool daugiau(string s1, string s2);

#endif


