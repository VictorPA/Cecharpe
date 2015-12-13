#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "Travail.h"


long long P(int a, int b) {
	long long p = 1;
	if (b > 0) {
		for (int i = 1; i <= b; ++i) {
			p *= a;
		}
	}

	return p;
}


bool getSession(Travail*pt) {
	return pt->enCours;
}

/*void setProgramme(Travail* pt, int a) { ////////////////// j'ai tout passé en console
pt->Programme = a;
}

*/
void setSession(Travail*pt, int a) {
	pt->enCours = a;
}


int syracuseT(int n) {
	int compteur = 0;
	while (n != 1) {
		printf("hotpo(%d) =", n);
		n = hotpo(n);
		printf(" %d\n", n);
		++compteur;
	}
	return compteur;
}
int hotpo(int n) {
	if (n % 2 == 0 && n != 0)
		return n / 2;
	else
		return 3 * n + 1;
}

int getTotalProgram() {
	return Travail::TOTALPROGRAMMES;
}

char* valeurs(unsigned int i) {
	static char* valeurs[] = { "dame", "roi", "as", "mabite" };
	return valeurs[i];
}

int* getFormat(int a) {
	int n = 0;
	int b = a;
	while (b > 0) {
		b /= 10;
		++n;
	}
	int taille = (sizeof(int)) * (n + 1);
	int* tab = (int*)malloc(taille);
	tab[0] = n; // gaffe la case 0 contient la taille
	for (int i = n; i > 0; --i) {
		//tab[i] = a / (P(10, i- 1)); //i - 1 car i[0] est une sentinelle contenant la taille;
		//	a = a - (tab[i]*(P(10,i - 1)));
		tab[i] = a / (P(10, i - 1));
		tab[i] = tab[i] % 10;
	}
	return tab;

}

void space(int n){
	for (int i = 0; i < n; ++i)
		printf(" ");
}

int backspace(int n){
	for (int i = 0; i < n; ++i)
		return 'b';
}

