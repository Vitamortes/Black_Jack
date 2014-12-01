#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \file affichage.c \brief l'affichage du BlackJack
*   \author Fabien Ciron
*   \date 08 novembre 2014
*   \version 1.0.0
*/

#define DEB_COEURS 0
#define FIN_COEURS 12
#define DEB_CARREAUX 13
#define FIN_CARREAUX 25
#define DEB_PIQUES 26
#define FIN_PIQUES 38
#define DEB_TREFLES 39
#define FIN_TREFLES 51
#define N 20


void afficher_carte(short num) {
	char couleur[N];
	char COEUR[] = "de coeur";
	char CARREAU[] = "de carreau";
	char PIQUE[] = "de pique";
	char TREFLE[] = "de trefle";
	short valeur = num % 13;
	if (num >= DEB_COEURS && num <= FIN_COEURS) {
		strcpy(couleur, COEUR);
	} else if ( num >= DEB_CARREAUX && num <= FIN_CARREAUX) {
		strcpy(couleur, CARREAU);
	} else if (num >= DEB_PIQUES && num <= FIN_PIQUES) {
		strcpy(couleur, PIQUE);
	} else if ( num >= DEB_TREFLES && num <= FIN_TREFLES) {
		strcpy(couleur, TREFLE);
	} else {
		printf("ERREUR");
	}

	if (valeur == 0) {
		printf("AS %s \n", couleur);
	} else if (valeur == 10) {
		printf("VALET %s \n", couleur);
	} else if (valeur == 11) {
		printf("DAME %s \n", couleur);
	} else if (valeur == 12) {
		printf("ROI %s \n", couleur);
	} else {
		printf("%d %s \n", valeur-1, couleur);
	}
}

void afficher_carte(short num) {
	short banque[4];
	int i, j, k = 0;
	for(i=0; i< 52; i++) {
		if (cartes[i] == 1 || cartes[i] == 3) {
			banque[j] = i;
			j++;
		}
	}
	for (k = 0; k <= j; k++) {
		afficher_carte(banque[k]);
	}
}
