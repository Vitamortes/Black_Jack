#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Linus.h"
#include "Fabien.h"
#include "Elliot.h"

/** \file blackjack.c \brief le main du blackjack
*   \author Linus König
*   \date 22 octobre 2014
*   \version 1.0.0
*/

int main(){
    int choix=0;
    short cartebc;
    short carteb;
    short carteJ;
    short scoreb=0;
    short scoreJ=0;
    
    cartebc=tirer_carte(BANQUE_cachee);
    carteb=tirer_carte(BANQUE);
    afficher_mains(BANQUE);
    evaluer_score(BANQUE,carteb,scoreb);
    evaluer_score(BANQUE_cachee,cartebc,scoreb);
    
    carteJ=tirer_carte(JOUEUR);
    evaluer_score(JOUEUR,carteJ,scoreJ);
    carteJ=tirer_carte(JOUEUR);
    afficher_mains(JOUEUR);
    evaluer_score(JOUEUR,carteJ,scoreJ);
    
	
	printf("Voullez vous choisir de tirer une carte ou pas?\n 1:oui       2:non\n");
	scanf("%i",&choix);
	switch(choix){
		case 1:	choix=0;
				while(choix!=2){
					printf("Veuillez choisir si vous desirez une autre carte?\n 1:Oui 2:Non\n");
					scanf("%i",&choix);
					while ((choix==1)&&(choix==2)){
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
					evaluer_score(BANQUE_cachee,cartebc,scoreb);
				}
				break;
		case 2:	while((scoreb<=21)&&(scoreJ<=21)){
					tirer_carte(BANQUE);
					tirer_carte(JOUEUR);
				}
				break;
		default: 	printf("Veuillez choisir si vous desirés une autre carte 1:Oui 2:Non\n");
					scanf("%i",&choix);
					break;
	
	}
   
    if ((scoreb==21)||(scoreJ>21)){
        printf("La banque a gagné");
        afficher_mains_cachee();
    }
    if ((scoreJ==21)||(scoreb>21)){
        printf("Le joueur a gané");
        afficher_mains_cachee();
    }
}
