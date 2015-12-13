// TTT.h
#ifndef CONSOLETTT_H
#define CONSOLETTT_H

#include <math.h>
#include <ctime>

#include "TTT.h"
#include "unittest.h"

struct ConsoleTTT {
	TTT *pt;
};
void borderBot(int t);
void borderTop(int t);
void hashTagW(int t);
void hashTag(int);

void choisirTailleConsole(ConsoleTTT* pc);

void messageCondition(ConsoleTTT*);

void initialiserConsole(ConsoleTTT*);
void sessionTTT(ConsoleTTT*);
void afficherRegle(ConsoleTTT*);

void afficher(ConsoleTTT*);
bool partieTerminee(ConsoleTTT*);
void afficherIndices(ConsoleTTT*);
void actionJoueur(ConsoleTTT*);

void jouer(ConsoleTTT*);
void finirPartie(ConsoleTTT*, int i);
int clean_stdin();




#endif