
#ifndef TTT_H
#define TTT_H

struct TTT {
	enum {
		NBJOUEUR = 2, ROND = 0, CROIX = 1, X = 88, O = 79
	};
	char* tableau;
	int taille;
	int cote;
	int nbCasesVictoire;
	int relancerPartie;
	int alignementEffectif;// variable qui renvoie le nombre d'alignements
	int idJouant; //Indice du joueur dont le tour est actif
	int choixJoueur; // indice de la case choisi par le joueur en scanf

	int score[TTT::NBJOUEUR];
	char symbole[TTT::NBJOUEUR];
};

void choisirTaille(TTT* pt, int cote, int nbCaseVic);

void setCote(TTT*, int);
void setNbCasesVictoireTTT(TTT*, int);

int getCoteTTT();

void detruireTableau(TTT*pt);

int xy2i(TTT*, int x, int y);

int maxi(int a, int b);
void initialiserTTT(TTT*, char*);

int getNbCasesVictoireTTT(TTT*);
int getLargeurTTT(TTT*);
int getHauteurTTT(TTT*);
int getTailleTTT(TTT*);
int getNbJoueurTTT();
int getIdCroixTTT();
int getIdRondTTT();
int getIdJouant(TTT*);
int getScore(TTT*, int);
int getTotalCasesOccup(TTT*pt);
int getChoixJoueur(TTT*);
void setChoixJoueur(TTT*pt, int b);

char getSymbole(TTT*, int);
char getCase(TTT*, int); //
void setCase(TTT*, int, int);





int getRelancerPartie(TTT*);
void setRelancerPartie(TTT*, int);

int choisirCase(TTT*);

bool victoireColonne(TTT*, int, int);
bool victoireLigne(TTT*, int, int);
bool victoireHautDroite(TTT*, int, int);
bool victoireHautGauche(TTT*, int, int);

void initialiserScores(TTT*);

void changerJoueur(TTT*);
bool checkFull(TTT*);
void incrementTotalCasesOccup(TTT*);
void augmenterScore(TTT*, int);
void randomiserJoueur(TTT*);

int comptaVictoire(TTT*);
int super(int y, int i);


//nombre de combinaisons de victoire : 8 * ( L + H - 5)
//bool condVict(char*);
//bool isEmpty(char*);
bool colonne(TTT*);
bool ligne(TTT*);
bool obliqueDroite(TTT*);
bool obliqueGauche(TTT*);
bool victoire2(TTT*pt);

int i2x(int i);
int i2y(int i);

int setFull(TTT*pt);
int normalGame(TTT*pt);
#endif