//mainTTT.cpp
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <assert.h>
#include "TTT.h"

void setCote(TTT*pt, int c){
	pt->cote = c;
}

void setNbCasesVictoireTTT(TTT* pt, int n){
	pt->nbCasesVictoire = n;
}

int getNbCasesVictoireTTT(TTT* pt) {
	return pt->nbCasesVictoire;
}
int getLargeurTTT(TTT* pt){
	return pt->cote;
}
int getHauteurTTT(TTT* pt) {
	return pt->cote;
}
int getTailleTTT(TTT* pt) {
	return (pt->cote)*(pt->cote) + 1;
}
int getNbJoueurTTT() {
	return TTT::NBJOUEUR;
}

int getIdCroixTTT() {
	return TTT::CROIX;
}
int getIdRondTTT() {
	return TTT::ROND;
}

void detruireTableau(TTT*pt){
	free(pt->tableau);
	pt->tableau = 0;
}


int getIdJouant(TTT* pt){
	return pt->idJouant;
}
int getScore(TTT* pt, int id){
	return pt->score[id];
}
char getSymbole(TTT* pt, int id){
	return pt->symbole[id];
}
char getCase(TTT* pt, int i){
	return pt->tableau[i];
}
void setCase(TTT* pt, int i, int b){
	pt->tableau[i] = b;
}

int getRelancerPartie(TTT* pt){
	return pt->relancerPartie;
}
void setRelancerPartie(TTT* pt, int b){
	pt->relancerPartie = b;
}

int getChoixJoueur(TTT*pt){
	return pt->choixJoueur;
}
void setChoixJoueur(TTT*pt, int b){
	pt->choixJoueur = b;
}


bool checkFull(TTT*pt) {
	int i = 1;
	for (; pt->tableau[i] == TTT::X || pt->tableau[i] == TTT::O; ++i) {
	}
	return i == pt->taille;
}



void initialiserTTT(TTT* pt, char*s) {

	//Zpt->idJouant = 0;
	pt->taille = (pt->cote)*(pt->cote) + 1;
	char * tab = (char*)malloc(sizeof(char)*(pt->taille));
	pt->tableau = tab;
	pt->tableau[0] = 0;
	pt->choixJoueur = 999;
	pt->symbole[TTT::CROIX] = TTT::X;
	pt->symbole[TTT::ROND] = TTT::O;
	if (s == "") {
		for (int i = 1; i < pt->taille; ++i) {
			pt->tableau[i] = ('0' + i % 10);
		}
	}
	if (s != "") {
		assert(strlen(s) == pt->taille - 1);
		for (int x = pt->cote; x >= 1; --x) {
			for (int y = 1; y <= pt->cote; ++y) {
				pt->tableau[xy2i(pt, x, y)] = s[xy2i(pt, x, y) - 1];
			}
		}
	}
}

void choisirTaille(TTT* pt, int cote, int nbCaseVic){
	pt->cote = cote;
	pt->nbCasesVictoire = nbCaseVic;
	//setCote(pt, cote);
	//setNbCasesVictoiresTTT(pt, nbCaseVic);
}

int xy2i(TTT* pt, int x, int y) {
	return (pt->cote - x) * (pt->cote) + y;
}

bool victoireColonne(TTT* pt, int x, int y) {
	unsigned int compteur = 0;
	for (unsigned int i = 1; i < pt->nbCasesVictoire; ++i) {
		if (pt->tableau[xy2i(pt, x, y)] == pt->tableau[xy2i(pt, x - i, y)]
			&& (pt->tableau[xy2i(pt, x, y)] == TTT::X || pt->tableau[xy2i(pt, x, y)] == TTT::O)) {
			compteur++;
		}
	}

	return compteur + 1 == pt->nbCasesVictoire;
}

bool victoireLigne(TTT* pt, int x, int y) {
	unsigned int compteur = 0;
	for (unsigned int i = 1; i < pt->nbCasesVictoire; ++i) {
		if (pt->tableau[xy2i(pt, x, y)] == pt->tableau[xy2i(pt, x, y + i)]
			&& (pt->tableau[xy2i(pt, x, y)] == TTT::X || pt->tableau[xy2i(pt, x, y)] == TTT::O)) {
			compteur++;
		}
	}
	return compteur + 1 == pt->nbCasesVictoire;
}

bool victoireHautDroite(TTT* pt, int x, int y) {
	unsigned int compteur = 0;
	for (unsigned int i = 1; i < pt->nbCasesVictoire; ++i) {
		if (pt->tableau[xy2i(pt, x, y)] == pt->tableau[xy2i(pt, x - i, y + i)]
			&& (pt->tableau[xy2i(pt, x, y)] == TTT::X || pt->tableau[xy2i(pt, x, y)] == TTT::O)) {
			compteur++;
		}
	}
	return compteur + 1 == pt->nbCasesVictoire;
}

bool victoireHautGauche(TTT* pt, int x, int y) {
	unsigned int compteur = 0;
	for (unsigned int i = 1; i < pt->nbCasesVictoire; ++i) {
		if (pt->tableau[xy2i(pt, x, y)] == pt->tableau[xy2i(pt, x - i, y - i)]
			&& (pt->tableau[xy2i(pt, x, y)] == TTT::X || pt->tableau[xy2i(pt, x, y)] == TTT::O)) {
			compteur++;
		}
	}
	return compteur + 1 == pt->nbCasesVictoire;
}

int comptaVictoire(TTT* pt){
	int compteur = 0;
	for (int y = 1; y <= pt->cote; ++y) {
		for (int x = pt->cote; x >= pt->nbCasesVictoire; --x) {
			compteur += victoireColonne(pt, x, y);//dernière boucle
		}
	}
	for (int y = 1; y <= pt->cote - pt->nbCasesVictoire + 1; ++y) {
		for (int x = pt->cote; x >= 1; --x) {
			compteur += victoireLigne(pt, x, y);
		}
	}
	for (int y = 1; y <= pt->cote - pt->nbCasesVictoire + 1; ++y) {
		for (int x = pt->cote; x >= pt->nbCasesVictoire; --x) {
			compteur += victoireHautDroite(pt, x, y);
		}
	}
	for (int y = pt->cote; y >= pt->nbCasesVictoire; --y) {
		for (int x = pt->cote; x >= pt->nbCasesVictoire; --x) {
			compteur += victoireHautGauche(pt, x, y);
		}
	}
	return compteur;
}


void initialiserScores(TTT* pt) {
	for (unsigned int i = 0; i < getNbJoueurTTT(); ++i) {
		pt->score[i] = 0;
	}

}


void changerJoueur(TTT* pt){
	pt->idJouant = (pt->idJouant + 1) % 2;
}
void augmenterScore(TTT*pt, int id){
	pt->score[id] += 1;
}

void randomiserJoueur(TTT* pt){
	pt->idJouant = rand() % 2;
}

int maxi(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}

}



//SOUVENIRS///////

//while (!condVict(pt->tableau) && q != taille - 1) {
//while(superF(pt->tableau, alignementEffectif) == 0 && q != taille - 1) {


/*bool condVict(TTT* pt) {
return (pt->tableau[7] == pt->tableau[8] && pt->tableau[8] == pt->tableau[9] && pt->tableau[7] != '.')
|| (pt->tableau[4] == pt->tableau[5] && pt->tableau[5] == pt->tableau[6] && pt->tableau[4] != '.')
|| (pt->tableau[1] == pt->tableau[2] && pt->tableau[2] == pt->tableau[3] && pt->tableau[1] != '.')
|| (pt->tableau[7] == pt->tableau[4] && pt->tableau[4] == pt->tableau[1] && pt->tableau[7] != '.')	En souvenirs...
|| (pt->tableau[8] == pt->tableau[5] && pt->tableau[5] == pt->tableau[2] && pt->tableau[8] != '.')
|| (pt->tableau[9] == pt->tableau[6] && pt->tableau[6] == pt->tableau[3] && pt->tableau[9] != '.')
|| (pt->tableau[7] == pt->tableau[5] && pt->tableau[5] == pt->tableau[3] && pt->tableau[7] != '.')
|| (pt->tableau[1] == pt->tableau[5] && pt->tableau[5] == pt->tableau[9] && pt->tableau[1] != '.');
}*/

/*bool isEmpty(TTT* pt) {
int q = 0;
for (int i = 1; i < TTT::TAILLE; ++i) {
if (pt->tableau[i] == TTT::X || pt->tableau[i] == TTT::O)
q += 1;
}
return q != TTT::TAILLE;
}
*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////
bool colonne(TTT*pt){
int i = 1; int v = 0;
while ((pt->tableau[pt->derniereCaseJouee]) == (pt->tableau[xy2i(pt,pt->xCaseJouee+i,pt->yCaseJouee)])
&& v != pt->nbCasesVictoire - 1
&& pt->xCaseJouee+i < pt->cote){
++i; ++v;
}
i = 1;
while ((pt->tableau[pt->derniereCaseJouee]) == (pt->tableau[xy2i(pt,pt->xCaseJouee - i, pt->yCaseJouee)])
&& v != pt->nbCasesVictoire - 1
&& pt->xCaseJouee - i >0){
++i; ++v;
}
return v >= pt->nbCasesVictoire - 1;

}

bool ligne(TTT*pt){
int i = 1; int v = 0;
while ((pt->tableau[pt->derniereCaseJouee]) == (pt->tableau[xy2i(pt,pt->xCaseJouee, pt->yCaseJouee + i)])
&& v != pt->nbCasesVictoire - 1
&& pt->yCaseJouee + i < pt->cote){
++i; ++v;
}
i = 1;
while ((pt->tableau[pt->derniereCaseJouee]) == (pt->tableau[xy2i(pt,pt->xCaseJouee, pt->yCaseJouee - i)])
&& v != pt->nbCasesVictoire - 1
&& pt->yCaseJouee - i >0){
++i; ++v;
}
return v >= pt->nbCasesVictoire - 1;

}



bool obliqueDroite(TTT* pt){
int i = 1; int v = 0;
while ((pt->tableau[pt->derniereCaseJouee]) == (pt->tableau[xy2i(pt,pt->xCaseJouee - i, pt->yCaseJouee + i)])
&& v != pt->nbCasesVictoire - 1
&& pt->yCaseJouee + i < pt->cote && pt->xCaseJouee - i > 0){
++i; ++v;
}
i = 1;
while ((pt->tableau[pt->derniereCaseJouee]) == (pt->tableau[xy2i(pt,pt->xCaseJouee + i, pt->yCaseJouee - i)])
&& v != pt->nbCasesVictoire - 1
&& pt->yCaseJouee - i >0 && pt->xCaseJouee + i < pt->cote){
++i; ++v;
}
return v >= pt->nbCasesVictoire - 1;

}

bool obliqueGauche(TTT* pt){
int i = 1; int v = 0;
while ((pt->tableau[pt->derniereCaseJouee]) == (pt->tableau[xy2i(pt,pt->xCaseJouee - i, pt->yCaseJouee - i)])
&& v != pt->nbCasesVictoire - 1
&& pt->yCaseJouee - i > 0 && pt->xCaseJouee - i > 0){
++i; ++v;
}
i = 1;
while ((pt->tableau[pt->derniereCaseJouee]) == (pt->tableau[xy2i(pt,pt->xCaseJouee + i, pt->yCaseJouee + i)])
&& v != pt->nbCasesVictoire - 1
&& pt->yCaseJouee + i <pt->cote && pt->xCaseJouee + i < pt->cote){
++i; ++v;
}
return v >= pt->nbCasesVictoire - 1;

}

bool victoire2(TTT*pt){
return colonne(pt) || ligne(pt) || obliqueDroite(pt) || obliqueGauche(pt);
}

int i2x(int i){
return pt->cote - ((i - 1) / pt->cote + 1);
}


int i2y(int i){
return (i - 1) % pt->cote + 1;
}


*/
/*int i2x(int i){
if (i / 10 == (i + pt->cote - 1) / 10)
return i % 10;
else
return (i + pt->cote - 1) % 10;
}


int i2y(int i){
if (i / 10 == (i + pt->cote - 1) / 10)
return i % 10;
else
return (i + pt->cote - 1) % 10;
}*/