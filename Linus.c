/**	\file Linus.c	\brief Fonctions tiré une carte et donner la valeur de la carte
*	\author	Linus König
*	\date	24/10/2014
*	\version	1.0.1
*/

#include <stdlib.h>
#include <stdio.h>

#define	LIBRE	0
#define	BANQUE	1
#define	JOUEUR	2
#define	BANQUE_CACHEE	3

short	cartes[52];
short	nb_as_joueur;
short	nb_as_banque;


/**	\brief Fonction permettant de choisir au hasard une carte du tas de 52 cartes
*/

short tirer_carte(short joueur){	
	return cartes[rand() % 52];
}



/**	\brief	Fonction donnant la valeur d'une carte tirée et incrémentant le compteur d'a du joueur possédant la carte en question
*/
short donner_valeur_carte(short joueur, short carte){
	if(carte==0%13){
		return 1;
	}
	if(carte==1%13){
		return 2;
	}
	if(carte==2%13){
		return 3;
	}
	if(carte==3%13){
		return 4;
	}
	if(carte==4%13){
		return 5;
	}
	if(carte==5%13){
		return 6;
	}
	if(carte==6%13){
		return 7;
	}
	if(carte==7%13){
		return 8;
	}
	if(carte==8%13){
		return 9;
	}
	if((carte==9%13)||(carte==10%13)||(carte==11%13)||(carte==12%13)){
		return 10;
	}
	if(cartes==13%13){
		return 11;
		if(joueur==JOUEUR){
			nb_as_joueur++;
		}else{
			nb_as_banque++;
		}
	}
	return 0;
}
