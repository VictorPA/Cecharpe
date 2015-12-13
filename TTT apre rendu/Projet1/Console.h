#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Travail.h"
#include "ConsoleTTT.h"


struct Console {
	Travail* pt;
	ConsoleTTT*pcttt;
};


void sommePoids(Console*pc);
void sommePoidsV2(Console*pc);
void quitter(Console*pc);
void bip(Console*pc);
void syracuse(Console*pc);


void initialiser(Console* pc);
void session(Console*);
void choisirProgramme(Console* pc);
int clean();
void lancerProgramme(Console* pc, int);

void relancerSession(Console*);
char* printspace_(int n);

void testChar(Console*pc);
void bten2b(Console*pc);
bool bonFormat(char*, int, int b);



void sessionTTT(Console*);

void courseXXX(Console*pc); // 6
void space(int n);
void antiSpace(int n);