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
#define FIN_TREFLES 51
#define	LIBRE	0
#define	BANQUE	1
#define	JOUEUR	2
#define	BANQUE_CACHEE	3
#define N 20


short nb_as_joueur;
short nb_as_banque;
short cartes[52]={0};

/**	\brief Cette fonction permet d'afficher une carte en utilisant juste la place de cette carte dans le tableau
*/
void afficher_carte(short num) {
	char couleur[N];
	char COEUR[N] = "de coeur\0";
	char CARREAU[N] = "de carreau\0";
	char PIQUE[N] = "de pique\0";
	char TREFLE[N] = "de trefle\0";
	short valeur = num % 13;	/*! Conversion rapide case carte/carte */

	valeur ++;		/*! On étalonne la valeur obtenue avec celle de la carte voulue */
	if(valeur==1) valeur --;		/*! Gestion des As */
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
	}					/*! Ici la couleur de la carte à forcément été déterminée*/

	if (valeur == 0) {			/*! Gestion des cartes particulière*/
		printf("AS %s \n", couleur);
	} else if (valeur == 11) {
		printf("VALET %s \n", couleur);
	} else if (valeur == 12) {
		printf("DAME %s \n", couleur);
	} else if (valeur == 13) {
		printf("ROI %s \n", couleur);
	} else {
		printf("%d %s \n", valeur, couleur);
	}
}

/**	\brief	Cette fonction permet d'afficher les cartes de la Banque, carte cachée comprise
*/
void afficher_mains_cachee() {

	short banque[10];			/*! La banque n'aura jamais plus de 11 cartes(calcul savant)*/
	int i;
	int k;
	int j=0;
	for(i=0; i< 52; i++) {
		if ((cartes[i] == 1) || (cartes[i] == 3)) {
			banque[j] = i;
			j++;
		}
	}
	for(k = 0; k <= j; k++) {		/*!affichage de toutes les cartes en rapport avec la banque */
		afficher_carte(banque[k]);
	}
}


/**	\brief	Cette fonction permet d'afficher la main du joueur en recherchant dans le tableau la valeur du joueur
*/
void afficher_mains(short joueur){
        short i;
	if(joueur==BANQUE)
		printf("\nMain de la banque \n\n\n");

	if(joueur==JOUEUR)
		printf("\nMain du joueur \n\n\n");  

        for(i=0; i<52; i++){			/*! affichage de toutes les cartes en rapport avec joueur */
                if(cartes[i] ==joueur){                 
			afficher_carte(i);
                }
        }
}



/**	\brief	Fonction retournant la valeur d'une carte tirée 
*	\return la valeur de la carte (entre 1 et 11)
*/
short donner_valeur_carte(short carte){

	if(carte%13==0){
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

/**	\brief	Cette fonction retourne le nouveau score du joueur en fonction de la carte reçue
*	\return Le score du joueur, actualisé.
*/
short evaluer_score (short joueur, short carte_recue, short score){
	int val_cart= donner_valeur_carte(carte_recue);			/*!On recupere la valeur de la carte */
	
	if((val_cart==1) && (score+11)<21)					/*!Si c'est un as on gère en fonction de */
		score+=11;
	else 
		score+=val_cart;
	if(joueur==2)								/*!Pour gérer à qui on met ou on enleve des as */
		while((score>21) && (nb_as_joueur>0)){
			score-=10;
			nb_as_joueur--;
		}
	else
		while((score>21) && (nb_as_banque>0)){
                        score-=10;
                        nb_as_banque--;
                }

        return score;
}

/**	\brief Fonction permettant de choisir au hasard une carte du tas de 52 cartes
*	\return la case de la carte aléatoire tirée
*/

short tirer_carte(short joueur){
	short nontiree=-1;
	do{
		nontiree=(rand() % (51-0));	/*! on cherche une Carte aléatoire mais différente de toute celles déjà tirées */
	}while(cartes[nontiree]!=LIBRE);
	cartes[nontiree]=joueur;		/*! on l'assigne au joueur concerné*/
	return nontiree;
}
