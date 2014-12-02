#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define	LIBRE	0
#define	BANQUE	1
#define	JOUEUR	2
#define	BANQUE_CACHEE	3
#include "fonctions.h"

/** \file blackjack.c \brief le main du blackjack
*   \author Linus König
*   \date 22 octobre 2014
*   \version 1.0.0
*/


short	nb_as_joueur;
short	nb_as_banque;



int main(){
	srand(time(NULL));
	short cartebc;
	short carteb;
	short carteJ;
	short scoreb=0;
	short scorebc=0;
	short scoreJ=0;
	int choix = 0;
	int arret=0;

	cartebc=tirer_carte(BANQUE_CACHEE);
	evaluer_score(BANQUE_CACHEE,cartebc, scorebc);
	carteJ=tirer_carte(JOUEUR);
	carteJ=tirer_carte(JOUEUR);
	evaluer_score(JOUEUR,carteJ, scoreJ);
  	while(scoreJ<21 && scorebc< 21){
		if(scorebc<=17){
			carteb=tirer_carte(BANQUE);
	 		evaluer_score(BANQUE,carteb, scoreb);
			afficher_mains(BANQUE);
			evaluer_score(BANQUE_CACHEE,carteb, scorebc);
		}
			while((choix!=1)||(choix!=2)){
				printf("Voulez vous choisir de tirer une carte ou pas?\n 1:oui       2:non\n");
				scanf("%i", &choix);
				if(choix==2)
					arret=1;
			}
			if(arret==0){
				carteJ=tirer_carte(JOUEUR);
				evaluer_score(JOUEUR,carteJ, scoreJ);
				afficher_mains(JOUEUR);
			}
			
		 
	}

	printf("le score minimal de la banque est de : %i\n", scoreb);
	printf("votre score est de: %i\n", scoreJ);
	if ((scorebc==21)||(scoreJ>21||scoreb > scoreJ)){
        	printf("La banque a gagne !!! \n");
	}
	else
        printf("Vous avez  gagne!!! \n");
    
	return 0;
}
