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
    short scoreJ=0;
    int choix = 0;

    cartebc=tirer_carte(BANQUE_CACHEE);
	carteb=tirer_carte(BANQUE);
    afficher_mains(BANQUE);
    evaluer_score(BANQUE,carteb,&scoreb);
    evaluer_score(BANQUE_CACHEE,cartebc,&scoreb);
  
  	printf("banque: %i\n", scoreb);
	printf("joueur: %i\n", scoreJ);
 
  	carteJ=tirer_carte(JOUEUR);
    evaluer_score(JOUEUR,carteJ,&scoreJ);
    carteJ=tirer_carte(JOUEUR);
    afficher_mains(JOUEUR);
    evaluer_score(JOUEUR,carteJ,&scoreJ);
   

	printf("Voullez vous choisir de tirer une carte ou pas?\n 1:oui       2:non\n");
	scanf("%i",&choix);
	
	while (choix != 2) {
		switch(choix){
			case 1:
					while(choix!=2){
						printf("Veuillez choisir si vous desirez une autre carte?\n 1:Oui 2:Non\n");
						scanf("%i",&choix);
						while ((choix!=1)&&(choix!=2)){
							printf("Saisie incorrecte: 1 pour oui 2 pour non");
							scanf("%i",&choix);
						}
						if (choix==1){
							carteJ=tirer_carte(JOUEUR);
							afficher_mains(JOUEUR);
						}
					}
					if(scoreb<=17){
						carteb=tirer_carte(BANQUE);
						evaluer_score(BANQUE_CACHEE,cartebc,&scoreb);
					}
					break;
			case 2:	while((scoreb<=21)&&(scoreJ<=21)){
						tirer_carte(BANQUE);
						tirer_carte(JOUEUR);
					}
					break;
			default: 	printf("DEFAULT: Veuillez choisir si vous desirés une autre carte 1:Oui 2:Non\n");
						scanf("%i",&choix);
						break;	
		} 
	}
	printf("banque: %i\n", scoreb);
	printf("joueur: %i\n", scoreJ);

    if ((scoreb==21)||(scoreJ>21||scoreb > scoreJ)){
        printf("La banque a gagne");
        afficher_mains_cachee();
    }else if ((scoreJ==21)||(scoreb>21||scoreJ > scoreb)){
        printf("Le joueur a gagne");
        afficher_mains_cachee();
    }
    return 0;
}