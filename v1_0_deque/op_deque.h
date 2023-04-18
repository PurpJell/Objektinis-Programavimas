#ifndef OP_DEQUE_H
#define OP_DEQUE_H

#include "myLibDeque.h"

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
void nuskaityti(deque<studentas> &mas, int &stCount, int &pazNr);
void generuoti(deque<studentas> &mas, int &stCount, int &pazNr);
void dalinti(studentas temp, deque<studentas> &kieti, deque<studentas> &prasti, int &kietiCnt, int &prastiCnt);
void dalinti2(deque<studentas>& mas, deque<studentas>& kieti, int& kietiCnt, int& prastiCnt);
int partition(deque<studentas>& mas, int start, int end);
void quicksort(deque<studentas>& mas, int start, int end);
void print(deque<studentas> &mas, char mode);
void kout(deque<studentas> &kieti, int pazNr);
void pout(deque<studentas> &prasti, int pazNr);
bool daugiau(string s1, string s2);

#endif


