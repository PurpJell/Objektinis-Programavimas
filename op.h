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
void nuskaityti(vector<studentas> &mas, int &stCount);
void spausdinti(studentas &temp, char mode);
bool swapNames(string v1, string v2);
void rusiuoti(vector<studentas> &mas);
void generuoti(vector<studentas> &mas, int &stCount, int &pazNr);
void kietiOut(studentas &kietas, int pazNr);
void prastiOut(studentas &prastas, int pazNr);
void rusiuotiGen(vector<studentas> &mas);
void dalinti(studentas temp, vector<studentas> &kieti, vector<studentas> &prasti, int &kietiCnt, int &prastiCnt);
int partition(vector<studentas>& mas, int start, int end);
void quicksort(vector<studentas>& mas, int start, int end);
void print(vector<studentas> &mas, char mode);
void kout(vector<studentas> &kieti, int pazNr);
void pout(vector<studentas> &prasti, int pazNr);

#endif


