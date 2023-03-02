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
};

double vid(studentas &temp);
double med(studentas &temp);
void pildyti(studentas &temp, char md);
void nuskaityti(vector<studentas> &mas, int &stCount);
void spausdinti(studentas &temp, char mode);
bool swapNames(string v1, string v2);
void rusiuoti(vector<studentas> &mas);

#endif


