/** \file affichage.c \brief Fonctions du BlackJack
*   \author Fabien Ciron, Linus Konig, Elliot Candale
*   \date 01 decembre 2014
*   \version 2.0.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEB_COEURS 0
#define FIN_COEURS 12
#define DEB_CARREAUX 13
#define FIN_CARREAUX 25
#define DEB_PIQUES 26
#define FIN_PIQUES 38
#define DEB_TREFLES 39
#define FIN_TREFLES 51	/** \brief Définitions des intervalles des différentes couleurs
*/

#define	LIBRE	0
#define	BANQUE	1
#define	JOUEUR	2
#define	BANQUE_CACHEE	3	/** \brief Définition des numéros des participants
*/


#define N 20


short nb_as_joueur;
short nb_as_banque;
short cartes[52]; /** \brief Le tableau représentant le paquet de carte
*/

/** \brief Fonction permettant d'afficher une carte en utilisant juste la place de cette carte dans le tableau
*/
void afficher_carte(short num) {
	char couleur[N];
	char COEUR[N] = "de coeur\0";
	char CARREAU[N] = "de carreau\0";
	char PIQUE[N] = "de pique\0";
	char TREFLE[N] = "de trefle\0";
	short valeur = num % 13;

	if ((num >= DEB_COEURS) && (num <= FIN_COEURS)) {
		strcpy(couleur, COEUR);
	} else if ((num >= DEB_CARREAUX) && (num <= FIN_CARREAUX)) {
		strcpy(couleur, CARREAU);
	} else if ((num >= DEB_PIQUES) && (num <= FIN_PIQUES)) {
		strcpy(couleur, PIQUE);
	} else if ((num >= DEB_TREFLES) && (num <= FIN_TREFLES)) {
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

/** \brief Fonction permettant  d'afficher les cartes de la Banque, carte cachée comprise
*/
void afficher_mains_cachee() {

	short banque[9];
	int i;
	int k;
	int j=0;
	for(i=0; i< 52; i++) {
		if ((cartes[i] == 1) || (cartes[i] == 3)) {
			banque[j] = i;
			j++;
		}
	}
	for(k = 0; k <= j; k++) {
		afficher_carte(banque[k]);
	}
}



/** \brief Fonction permettant d'afficher la main d'un joueur
*/
void afficher_mains(short player){
        short i;
		if (player == BANQUE) {
			printf ("main de la banque \n");
		} else if (player == JOUEUR) {
			printf ("main du joueur \n");
		}

		for(i=0; i<52; i++){
                if(cartes[i] ==player){
                	afficher_carte(i);
               }
        }
}



/** \brief Fonction permettant d'évaluer le score du joueur
*/
short evaluer_score (short joueur, short carte_recue, short *score){
        cartes[carte_recue]=joueur;
        if(carte_recue<=FIN_COEURS) {
                carte_recue ++;
                *score+=(carte_recue);
        }else if(carte_recue<=FIN_CARREAUX) {
                carte_recue -= 12;
                *score+=(carte_recue);
        }else if(carte_recue<=FIN_PIQUES) {
                carte_recue -= 25;
                *score+=(carte_recue);
        }else{
                carte_recue -= 38;
                *score+=(carte_recue);
        }
        return 0;
}


/**	\brief Fonction permettant de choisir au hasard une carte du tas de 52 cartes
*/

short tirer_carte(short joueur){
	int nontiree=-1;
	while(cartes[nontiree]!=LIBRE)
		nontiree=(rand() % (52-0))+0;
	return nontiree;
}



/**	\brief	Fonction donnant la valeur d'une carte tirée et incrémentant le compteur d'a du joueur possédant la carte en question
*/
short donner_valeur_carte(short joueur, short carte){
	short score;

	evaluer_score(joueur, carte, &score);
	if(carte%13==0){
		if((score+11)>21){
			if(joueur==JOUEUR){
				nb_as_joueur++;
			}else{
				nb_as_banque++;
			}
			return 11;
		}
	}
	else{
	
			if(joueur==JOUEUR){
				nb_as_joueur++;
			}else{
				nb_as_banque++;
			}
			return 1;
	}
	if((carte%13)==1){
		return 2;
	}
	if((carte%13)==2){
		return 3;
	}
	if((carte%13)==3){
		return 4;
	}
	if((carte%13)==4){
		return 5;
	}
	if((carte%13)==5){
		return 6;
	}
	if((carte%13)==6){
		return 7;
	}
	if((carte%13)==7){
		return 8;
	}
	if((carte%13)==8){
		return 9;
	}
	if((carte%13==9)||(carte%13==10)||(carte%13==11)||(carte%13==12)){
		return 10;
	}
	return 0;
}
