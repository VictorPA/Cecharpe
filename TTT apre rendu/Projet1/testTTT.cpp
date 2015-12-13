#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "consoleTTT.h"
#include "TTT.h"
#include "Unittest.h"

void testTTT(){
	/*

				y=1 y=2 y=3
			////////////////
	x=1		////7///8///9///
			////////////////
	x=2		////4///5///6///  =>  123456789
			////////////////
	x=3		////1///2///3///
			////////////////
	*/
	//Taille = cote * cote + 1;


	TTT t;
	printf("\nOn initialise un tableau 3x3 :\n\n");
	choisirTaille(&t, 3, 3);
	assertEquals(getTailleTTT(&t), 10, "test choix taille");
	initialiserTTT(&t, "");
	initialiserScores(&t);
	assertEquals(getScore(&t, getIdCroixTTT()), 0, "test de score croix nul");
	assertFalse(checkFull(&t), "test de jeu non rempli");
	assertTrue(comptaVictoire(&t) == 0, "test non rempli et non gagnant");
	assertEquals(getCase(&t, 0), (char)(0), "verifier que case non jouee est nulle ");
	setCase(&t, 1, getSymbole(&t, getIdCroixTTT()));
	assertEquals(getCase(&t, 1), 'X', "test de remplissage de case 1");
	assertEquals((char)(xy2i(&t, 3, 1) + '0'), '1', "test d'indice de case 1");
	assertEquals((char)(xy2i(&t, 1, 3) + '0'), '9', "test d'indice de case 9");
	assertEquals((char)(xy2i(&t, 2, 2) + '0'), '5', "test d'indice de case 5");
	detruireTableau(&t);

	initialiserTTT(&t, "XXXXXXXXX");
	printf("\nOn remplit le tableau full X :\n\n");
	assertTrue(checkFull(&t), "test de jeu rempli");
	assertEquals(comptaVictoire(&t), 8, "test 8 lignes");
	augmenterScore(&t, getIdCroixTTT());
	assertEquals(getScore(&t, getIdCroixTTT()), 1, "test de score croix gagnant");
	detruireTableau(&t);

	initialiserTTT(&t, "XOXOXOOXO");
	assertTrue(checkFull(&t), "test de jeu rempli");
	assertTrue(comptaVictoire(&t) == 0, "test de match nul");
	assertEquals((getCase(&t, 5)), 'X', "test de case X en position 5");
	assertEquals((getCase(&t, 9)), 'O', "test de case O en position 9");
	setCase(&t, 9, getSymbole(&t, getIdCroixTTT()));
	assertEquals((getCase(&t, 9)), 'X', "test de changement en X en position 9");

	choisirTaille(&t, 5, 5);
	initialiserTTT(&t, "OOXXOXOXOOXXOXOXOXOOOOOOO");
	assertTrue(checkFull(&t), "test de jeu rempli");
	assertFalse(comptaVictoire(&t) == 0, "test de match non nul");
	assertEquals(getTailleTTT(&t), 25 + 1, "test de taille 25");
	assertTrue(victoireColonne(&t, 5, 5), "test victoire 5e colonne");
	assertTrue(victoireLigne(&t, 1, 1), "test victoire 1e ligne");
	assertTrue(victoireHautGauche(&t, 5, 5), "test victoire diagonale gauche haute");
	assertTrue(victoireHautDroite(&t, 5, 1), "test victoire diagonale droite haute");
	assertEquals(comptaVictoire(&t), 4, "test des quatres directions");
	/*

			  y=1 y=2 y=3 y=4 y=5
			/////////////////////////		
	x=1		////O///O///O///O///O////		21	22	23	24	25
			/////////////////////////		
	x=2		////X///O///X///O///O////		16	17	18	19	20
			/////////////////////////
	x=3		////X///X///O///X///O////		11	12	13	14	15
			/////////////////////////		
	x=4		////X///O///X///O///O////		6	7	8	9	10
			/////////////////////////		
	x=5		////O///O///X///X///O////		1	2	3	4	5
			/////////////////////////
			*/
	detruireTableau(&t);



	printf("\n***** FIN DES TESTS *****\n\n");
	system("pause");
	system("cls");
}

