#include <stdio.h>
#include <stdlib.h>
#include "Fabien.h"

#define DEB_COEURS 0
#define FIN_COEURS 12
#define DEB_CARREAUX 13
#define FIN_CARREAUX 25
#define DEB_PIQUES 26
#define FIN_PIQUES 38
#define DEB_TREFLES 39
#define FIN_TREFLES 51

short carte[52];

void afficher_mains(short joueur){
	short i;
	for(i=0; i<52; i++){
		if(carte[i] ==joueur){
			afficher_carte(i);
		}
	}
}



short evaluer_score (short joueur, short carte_recue, short *score){
	cartes[carte_recue]=joueur;
	if(carte_recue<=FIN_COEURS)
		*score+=(carte_recue++);
	else if(carte_recue<=FIN_CARREAUX)
		*score+=(carte_recue-12);
	else if(carte_recue<=FIN_PIQUES)
		*score+=(carte_recue-24);
	else
		*score+=(carte_recue-36);
	return 0;
}
