#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Console.h"
#include "testTTT.h"




void initialiser(Console* pc) {
	Travail* pt = (Travail*)malloc(sizeof(Travail));
	pc->pt = pt;
}

void session(Console* pc) {
	Travail*pt = pc->pt;
	do {
		choisirProgramme(pc);
		relancerSession(pc);
	} while (getSession(pt));
	free(pc->pt);
	pc->pt = 0;
}


void choisirProgramme(Console* pc) {
	Travail*pt = pc->pt;
	int choix;

	do {
		printf("[0] : Base b  -> base 10	Afficher les poids et en faire leur somme\n");
		printf("[1] : Base 10 -> base b'\n");
		printf("[2] : Syracuse		\n");
		printf("[3] : Test char\n");
		printf("[4] : Bip				Fait un bip de qualit%c\n", 3);
		printf("[5] : TTT\n");
		printf("[6] : Course XXX (by Aiman)\n");
		printf("[%d] : Retour					...\n", getTotalProgram() - 1);

		scanf_s("%i", &choix);
		clean();
		printf("\n");
	} while (choix < 0 || choix > Travail::TOTALPROGRAMMES - 1);
	lancerProgramme(pc, choix);

}

int clean() {
	while (getchar() != '\n');
	return 0;
}

void relancerSession(Console*pc) {
	Travail*pt = pc->pt;
	int choix;
	do {
		printf("\nRelancer un programme? 1 (oui) 0 (non)\n");
		scanf_s("%i", &choix);
		clean();
	} while (choix != 0 && choix != 1);
	setSession(pt, choix);
}


char* printspace_(int n) {
	char* d = (char*)malloc(sizeof(char)*n);
	for (int i = 0; i < n - 1; ++i) {
		d[i] = ' ';
	}
	d[n - 1] = '\0';
	return d;

}

void print_(int n) {
	printf("\n");
	for (int i = 0; i < n - 10 && n >= 10; ++i) {
		printf("_ ");
	}
	for (int i = n - 10; i < n && n >= 10; ++i) {
		printf("_ ");
	}
	for (int i = 0; i < n && n < 10; ++i) {
		printf("_ ");
	}

	printf("\n");
	for (int i = n - 1; i >= 10 && n >= 10; --i) {
		printf("%d", i);
	}
	for (int i = 9; i >= 0 && n >= 10; --i) {
		printf("%d ", i);
	}
	for (int i = n - 1; i >= 0 && n < 10; --i) {
		printf("%d ", i);
	}

}


void lancerProgramme(Console*pc, int a) {
	Travail*pt = pc->pt;
	typedef void(*listeFonctions)(Console*pc);
	listeFonctions lancer[Travail::TOTALPROGRAMMES] =
	{
		sommePoidsV2, //indice 0
		bten2b,
		syracuse,
		testChar,
		bip,
		sessionTTT,
		courseXXX,
		quitter
	};

	lancer[a](pc);
}
void quitter(Console*pc) {
	//int tab[5] = { 0, 6, 7, 8, 9 };
	//	printf("%d",tab[3]);
}

void bip(Console*pc) {
	printf("\a");
}

void syracuse(Console*pc) {
	int n = 0;
	printf("Entrer un entier n : \n");
	scanf_s("%d", &n);
	printf("\nIl faut appliquer hotpo %d fois", syracuseT(n));
}

void testChar(Console*pc) {
	char tab[100];
	printf("Rentrez une opération\n");
	fgets(tab, 100, stdin);
	if (tab[0] == '²') {
		return;
	}
	int i = 0; double a = 0; double b = 0;
	while (tab[i] == ' ') {
		++i;
	}
	while (tab[i] != '+' && tab[i] != '-' && tab[i] != '/' && tab[i] != '*' && tab[i] != ' ') {
		a = 10*a + double(tab[i])-double('0');
		++i;
	}
	while (tab[i] != '+' && tab[i] != '-' && tab[i] != '/' && tab[i] != '*') {
		++i;
	}
	++i;
	while (tab[i] == ' ') {
		++i;
	}
	while (tab[i] != ' ' && tab[i] != '\n') {
		b = 10*b + double(tab[i]) - double('0');
		++i;
	}
	//double a = static_cast<double>(static_cast<double>(tab[0]) - static_cast<double>('0'));
	//double b = static_cast<double>(static_cast<double>(tab[2]) - static_cast<double>('0'));
	i = 0;
	while (tab[i] != '\n'){
		if (tab[i] == '+')
			printf("%3.2f", a + b);
		if (tab[i] == '-')
			printf("%3.2lf", a - b);
		if (tab[i] == '*')
			printf("%3.2lf", a * b);
		if (tab[i] == '/')
			printf("%3.2lf", a / b);
		++i;
	}

}
void bten2b(Console*pc) {
	int n, b;
	printf("Entrer un nombre entier n, la base d'arrivée b': \n");
	scanf_s("%d%d", &n, &b);
	int i = 0; int r = n; int format = 0;
	format = ((log((double)n)) / (log((double)b)) + 1);
	int*tab = (int*)malloc(sizeof(int)*format);
	while (n >= 1)
	{
		r = n;
		while (r >= b) {
			r = r - b;
		}
		tab[format - 1 - i] = r;
		++i;
		//printf("%d ", r);
		n = n / b;
	}
	printf("\n");
	for (int i = 0; i < format; ++i) {
		if (tab[i] > 9){
			printf("%c ", tab[i] - 10 + 'A');
		}
		else{
			printf("%d ", tab[i]);
		}


	}
	print_(format);

	free(tab);
	tab = 0;

}

void sommePoidsV2(Console*pc) {
	int b = 0; char tab[256]; int n = 0;

	printf("\nEntrer un nombre à convertir : ");
	//scanf_s("%d", &a);

	fgets(tab, sizeof(tab), stdin);
	printf("Entrer la base de départ b : ");
	scanf_s("%d", &b);
	clean();

	char temp = 0;
	for (n = 0; tab[n] != '\n'; ++n){
	}
	for (int i = n; i >= 1; --i){
		tab[i] = tab[i - 1];
	}

	for (int i = 1; i <= (n + 1) / 2; ++i){
		temp = tab[i];
		tab[i] = tab[n - i + 1];
		tab[n - i + 1] = temp;
	}
	while (!bonFormat(tab, n, b) || b < 1){
		printf("Erreur format\n");
		printf("Entrer la base B : ");
		scanf_s("%d", &b);
		clean();
		fgets(tab, sizeof(tab), stdin);
		printf("\nEntrer un nombre à convertir : ");
		for (n = 0; tab[n] != '\n'; ++n){
		}
		for (int i = n; i >= 1; --i){
			tab[i] = tab[i - 1];
		}
		for (int i = 1; i <= (n + 1) / 2; ++i){
			temp = tab[i];
			tab[i] = tab[n - i + 1];
			tab[n - i + 1] = temp;
		}
	}
	for (int i = 0; i <= n; ++i){
		if (tab[i] >= '0' && tab[i] <= '9'){
			tab[i] = tab[i] - '0';
		}
		if (tab[i] >= 'a' && tab[i] <= 'z'){
			tab[i] = tab[i] - 'a' + 10;
		}
		if (tab[i] >= 'A' && tab[i] <= 'Z'){
			tab[i] = tab[i] - 'A' + 10;
		}

	}
	/*
	printf("\nn = %d\n", n);
	for (int i = n; i > 0; --i) {
	printf("a = %d ", tab[i]);
	}
	*/
	printf("\n	N nombres possibles au format %d = %d^%d = %lld :", n, b, n, P(b, n));
	print_(n);
	printf("\nLa somme des poids :\n\n");
	long long p = 0;
	for (int i = n; i >= 2; --i) {
		//char*d = printspace_(n - i); Ah oui on peut utiliser %15d :)
		printf("Poid (n%2d) = %d x %d^%2d = %18lld +\n", i - 1, tab[i], b, i - 1, P(b, i - 1) * (tab[i]));
		p += (tab[i]) * P(b, i - 1);
		//free(d);
	}
	p += (P(b, 0)) * ((tab[1]));
	//char*espaces = printspace_(n);
	printf("Poid (n%2d) = %d x %d^%2d = %18lld \n", 0, tab[1], b, 0, (P(b, 0)) * ((tab[1])));
	printf(" =%41lld en base 10\n", p);
	//free(espaces);
	//espaces = nullptr;
	printf("et Amax(10) = %d^%d - 1 =	%lld\n", b, n, P(b, n) - 1);

}

bool bonFormat(char*tab, int n, int b) {
	for (int i = 1; i <= n; ++i) {
		if (tab[i] - '0' >= b && tab[i] >= '0' && tab[i] <= '9') {
			return false;
		}
		if (tab[i] - 'a' + 10 >= b && tab[i] >= 'a' && tab[i] <= 'z') {
			return false;
		}
		if (tab[i] - 'A' + 10 >= b && tab[i] >= 'A' && tab[i] <= 'Z') {
			return false;
		}
	}
	return true;
}
void sessionTTT(Console*pc){
	ConsoleTTT* pcttt = (ConsoleTTT*)malloc(sizeof(ConsoleTTT));
	pc->pcttt = pcttt;
	testTTT();
	initialiserConsole(pcttt);
	sessionTTT(pcttt);
	free(pc->pcttt);
	pc->pcttt = 0;

}

void courseXXX(Console*pc){
	void space(int);
	int backspace(int n);
	int n = 100;
	int i;
	for (i = 0; (_kbhit() == 0); ++i){
		printf("catch!!!\n");
		printf("                                                    %c  %c\n", 178, 178);
		space(i);
		printf("%c", 16);

		//Sleep(5);
		system("cls");
	}

	if (45 < i && i < 55){
		printf("\t\t\t\t YOU WIN!!!!!\n\n");
		space(i - 3);
		backspace(i);
		printf("%c %c %c", 178, 16, 178);
		Beep(330, 100); Sleep(100);
		Beep(330, 100); Sleep(300);
		Beep(330, 100); Sleep(300);
		Beep(262, 100); Sleep(100);
		Beep(330, 100); Sleep(300);
		Beep(392, 100); Sleep(700);
		Beep(196, 100); Sleep(700);
		Beep(196, 100); Sleep(125);
		Beep(262, 100); Sleep(125);
		Beep(330, 100); Sleep(125);
		Beep(392, 100); Sleep(125);
		Beep(523, 100); Sleep(125);
		Beep(660, 100); Sleep(125);
		Beep(784, 100); Sleep(575);
		Beep(660, 100); Sleep(575);
		Beep(207, 100); Sleep(125);
		Beep(262, 100); Sleep(125);
		Beep(311, 100); Sleep(125);
		Beep(415, 100); Sleep(125);
		Beep(523, 100); Sleep(125);
		Beep(622, 100); Sleep(125);
		Beep(830, 100); Sleep(575);
		Beep(622, 100); Sleep(575);
		Beep(233, 100); Sleep(125);
		Beep(294, 100); Sleep(125);
		Beep(349, 100); Sleep(125);
		Beep(466, 100); Sleep(125);
		Beep(587, 100); Sleep(125);
		Beep(698, 100); Sleep(125);
		Beep(932, 100); Sleep(575);
		Beep(932, 100); Sleep(125);
		Beep(932, 100); Sleep(125);
		Beep(932, 100); Sleep(125);
		Beep(1046, 675);
	}
	else{
		printf("you lose\n\n");
		space(i - 1);
		printf("%c", 16);
		space(50 - i);
		printf("%c %c", 178, 178);
	}
	getchar();
}




