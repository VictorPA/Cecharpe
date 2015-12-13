// AweleConsole.cpp
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "ConsoleTTT.h"

void afficher(ConsoleTTT* pc) { // affichage du Tic Tac Toe
	TTT* pt = pc->pt;
	messageCondition(pc); // affiche le nombre de cases gagnantes
	borderTop(getLargeurTTT(pt) * 5 + 2);
	printf("\n");
	hashTag(getLargeurTTT(pt) * 5 + 2);
	for (int x = 1; x <= getHauteurTTT(pt); ++x) {
		printf("\n");
		hashTag(getLargeurTTT(pt) * 5 + 2);
		printf("\n");
		printf("|");
		for (int y = 1; y <= getLargeurTTT(pt); ++y) {
			hashTagW(2);
			if (xy2i(pt, x, y) > 9 && xy2i(pt, x, y) <= 99 && !(getCase(pt, xy2i(pt, x, y)) == 'X' || (getCase(pt, xy2i(pt, x, y)) == 'O'))) {
				printf("%u%c ", (xy2i(pt, x, y)) / 10, getCase(pt, xy2i(pt, x, y)));
			}
			else if (xy2i(pt, x, y) > 99 && !(getCase(pt, xy2i(pt, x, y)) == 'X' || (getCase(pt, xy2i(pt, x, y)) == 'O'))) {
				printf("%u%c", (xy2i(pt, x, y)) / 10, getCase(pt, xy2i(pt, x, y)));
			}
			else {
				printf(" %c ", getCase(pt, xy2i(pt, x, y)));
			}
		}
		hashTagW(2);
		printf("|");
		printf("\n");
		hashTag(getLargeurTTT(pt) * 5 + 2);
	}
	printf("\n");
	hashTag(getLargeurTTT(pt) * 5 + 2);
	printf("\n");
	borderBot(getLargeurTTT(pt) * 5 + 2);
	printf("\n\n\n");
}

void choisirTailleConsole(ConsoleTTT* pc){
	TTT* pt = pc->pt;
	int cote = 0, nbCaseVic = 0;
	printf("Veuillez choisir les dimensions du jeu (cote) ainsi que le nombre de cas gagnants\n");
	scanf_s("%d%d", &cote, &nbCaseVic);
	setNbCasesVictoireTTT(pt, nbCaseVic);
	setCote(pt, cote);
	clean_stdin();
}

void initialiserConsole(ConsoleTTT* pc) {
	srand(time(0));
	TTT* pt = (TTT*)malloc((sizeof(TTT)));
	pc->pt = pt;
	choisirTailleConsole(pc);
	initialiserScores(pt);
}

void sessionTTT(ConsoleTTT* pc) {
	TTT* pt = pc->pt;
	int relancerPartieConsole = 0;
	do {
		jouer(pc);
		finirPartie(pc, relancerPartieConsole);
		detruireTableau(pt);
	} while (getRelancerPartie(pt) == 1);
	free(pc->pt);
	pc->pt = 0;
	//exit(EXIT_SUCCESS);
}

void jouer(ConsoleTTT*pc){
	TTT* pt = pc->pt;
	initialiserTTT(pt, ""); //on touche pas
	system("cls");
	afficher(pc);
	randomiserJoueur(pt);
	while (!partieTerminee(pc) && getChoixJoueur(pt) != 0) {
		changerJoueur(pt);
		actionJoueur(pc);
		if (getChoixJoueur == 0) {
			return;
		}

	}
}

bool partieTerminee(ConsoleTTT* pc) {
	TTT* pt = pc->pt;
	return (comptaVictoire(pt) != 0 || checkFull(pt));
}

void actionJoueur(ConsoleTTT* pc) {
	TTT* pt = pc->pt;
	int choixJoueurConsole = 0;
	printf(" %c joue : ", getSymbole(pt, getIdJouant(pt)));
	printf("\n");
	scanf_s("%i", &choixJoueurConsole);
	clean_stdin(); //commentaire pour jouer d'un coup
	setChoixJoueur(pt, choixJoueurConsole);
	if (choixJoueurConsole == 0) {
		return;
	}
	while (getChoixJoueur(pt) > getTailleTTT(pt) - 1 || getChoixJoueur(pt) < 1
		|| getCase(pt, getChoixJoueur(pt)) == getSymbole(pt, getIdRondTTT()) || getCase(pt, getChoixJoueur(pt)) == getSymbole(pt, getIdCroixTTT())) {
		system("cls");
		afficher(pc);
		printf("Erreur de saisie, %c joue :", getSymbole(pt, getIdJouant(pt)));
		printf("\n");
		clean_stdin();
		scanf_s("%d", &(choixJoueurConsole));
		setChoixJoueur(pt, choixJoueurConsole);
	}
	setCase(pt, getChoixJoueur(pt), getSymbole(pt, getIdJouant(pt)));
	system("cls");
	afficher(pc);
}

void finirPartie(ConsoleTTT*pc, int relancerPartieConsole){
	TTT* pt = pc->pt;
	if (getChoixJoueur(pt) == 0) {
		printf("Partie interompue  \n");
		setRelancerPartie(pt, 0);
		return;
	}
	else if (checkFull(pt) && comptaVictoire(pt) == 0)
		printf("Match nul ! \n");
	else {
		augmenterScore(pt, getIdJouant(pt));
		printf("%c gagne ! \n", getSymbole(pt, getIdJouant(pt)));
	}
	system("pause");
	printf("Rond : %d, Croix : %d \n", getScore(pt, getIdRondTTT()), getScore(pt, getIdCroixTTT()));
	printf("\nUne autre ? 1 (oui) / 0 (non) \n");
	scanf_s("%d", &relancerPartieConsole);
	setRelancerPartie(pt, relancerPartieConsole);
	while ((getRelancerPartie(pt) != 0) && (getRelancerPartie(pt) != 1)) {
		printf("Hello world ? 1 (oui)/ 0 (non)?\n");
		clean_stdin();
		scanf_s("%d", &(relancerPartieConsole));
		setRelancerPartie(pt, relancerPartieConsole);
	}
}

void messageCondition(ConsoleTTT*pc){
	TTT* pt = pc->pt;
	printf("\n\nAlignez %d cases pour gagner ! \n", getNbCasesVictoireTTT(pt));
}

void hashTag(int t) {
	printf("|");
	for (int i = 1; i <= t; ++i) {
		printf("%c", 176);
	}
	printf("|");
}
void hashTagW(int t) {
	for (int i = 1; i <= t; ++i) {
		printf("%c", 176);
	}
}
void borderTop(int t) {
	printf("/");
	for (int i = 1; i <= t; ++i) {
		printf("-");
	}
	printf("\\");
}
void borderBot(int t) {
	printf("\\");
	for (int i = 1; i <= t; ++i) {
		printf("-");
	}
	printf("/");
}
void afficherIndices(ConsoleTTT* pc) {
	TTT* pt = pc->pt;
	for (int x = 1; x <= getHauteurTTT(pt); ++x) {
		for (int y = 1; y <= getLargeurTTT(pt); ++y)
			printf(" x=%d y=%d i=%d	", x, y, xy2i(pt, x, y));
		printf("\n");
	}
}


int clean_stdin()
{
	while (getchar() != '\n');
	return 1;
}
