#pragma once


struct Travail {
	enum { TOTALPROGRAMMES = 8 };
	bool enCours;
	//	int Programme;



};



long long P(int, int);

bool getSession(Travail*);
void setSession(Travail*pt, int a);

//void setProgramme(Travail*,int); passé en console

int syracuseT(int n);
int hotpo(int n);
int getTotalProgram();
char* valeurs(unsigned int i);
int* getFormat(int a);
int* getNombreTab(int*tab);

void space(int n);
int backspace(int n);