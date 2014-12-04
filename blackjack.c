/** \file blackjack.c \brief le main du blackjack
*   \author Linus König Elliot Candale
*   \date 22 octobre 2014
*   \version 5.0.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define	LIBRE	0
#define	BANQUE	1
#define	JOUEUR	2
#define	BANQUE_CACHEE	3
#include "fonctions.h"

short	nb_as_joueur;
short	nb_as_banque;

/**	\brief	Le main gère les tours des joueurs ainsi que les conditions de victoire en utilisant fonctions.h
*/
int main(){
	srand(time(NULL));
	short cartebc;		/*! carte banque cachée*/
	short carteb;		/*! carte banque*/
	short carteJ;		/*! carte joueur*/
	short scoreb=0;		/*! les scores*/
	short scorebc=0;
	short scoreJ=0;
	int choix = 0;		/*! choix de tirer ou non du joueur*/
	int arret=0;		/*! arret de tirer pour le joueur*/
	int stop=0;		/*! arret de tirer pour la banque*/

	cartebc=tirer_carte(BANQUE_CACHEE);		/*! on gère la banque cachée*/	
	scorebc=evaluer_score(BANQUE_CACHEE,cartebc, scorebc);
	carteJ=tirer_carte(JOUEUR);			/*!Puis les deux premières cartes du oeur */
	scoreJ=evaluer_score(JOUEUR,carteJ, scoreJ);
	carteJ=tirer_carte(JOUEUR);
	scoreJ=evaluer_score(JOUEUR,carteJ, scoreJ);
	afficher_mains(JOUEUR);
	printf("\nVotre score est de: %i\n", scoreJ);
	while((scoreJ< 21) && (scorebc< 21)){		/*! Si l'un des deux joueurs dépasse 21 on arrete tout*/
		if((arret==0)||(stop==0)){		/*! si les deux joueurs (banque et joueur) ne tirent plus, on arretera*/
			if((scorebc<=17)&&(stop==0)){		/*! condition pour que la banque continue ou non de piocher*/
				printf("La banque tire\n");
				carteb=tirer_carte(BANQUE);		/*! toujours le meme schéma, on tire on évalue puis on affiche*/
		 		scoreb=evaluer_score(BANQUE,carteb, scoreb);
				afficher_mains(BANQUE);
				scorebc=evaluer_score(BANQUE_CACHEE,carteb, scorebc);		/*! gestion banque cachée*/
			}
			else{
				stop=1;				/*! l'arret de la pioche de la banque*/
				printf("\nLa banque cesse de tirer\n");
			}
				while((choix!=1)&&(choix!=2)&&(arret!=1)){		/*! choix du joeur pour continuer à piocher*/
					printf("\nVoulez vous choisir de tirer une carte ?\n 1:oui       2:non\n");
					scanf("%i", &choix);
					if(choix==2)		/*! Pour ne plus rentrer dans la boucle à l'avenir */
						arret=1;
				}
				choix=0; /*! Pour que le joueur ai de nouveau le choix de piocher ensuite*/
				if(arret==0){
					carteJ=tirer_carte(JOUEUR);
					scoreJ=evaluer_score(JOUEUR,carteJ, scoreJ);
					afficher_mains(JOUEUR);
				}
				
		        	printf("\nLe score minimal de la banque est de : %i\n", scoreb);
		        	printf("Votre score est de: %i\n", scoreJ);
				if((scoreJ>21)&&(nb_as_joueur>0)){		/*! gestion des as du joueur*/
					scoreJ-=10;
					nb_as_joueur--;
				}
				if((scorebc>21)&&(nb_as_banque>0)){
					if(donner_valeur_carte(cartebc)==1){	/*!gestion si un as est dans banque cachée */
						scorebc-=10;
						nb_as_banque--;
						cartebc=2;		/*! cette valeur est la case de carte cachée, si elle est perdu celà permet de ne plus considérer que l'on puisse perdre l'as de la banque cachée, sans affecter le tableau de cartes */
					}
					else{
						scoreb-=10;
                                        	scorebc-=10;
                                        	nb_as_banque--;
					}
                                }
				if((scoreJ>=21)||(scorebc>=21)){		/*! dans e cas où les deux joueurs dépassent 21 avant la fin de la boucle*/
					arret=1;
					stop=1;
				}
		}
		else
			break;
	}
	afficher_mains_cachee();			/*! fin du suspense pour le joueur*/
	printf("\nScore banque final: %i \n\nScore joueur final %i\n\n", scorebc, scoreJ);
	if ((scorebc==21)||(scoreJ>21)||(scorebc==scoreJ)){		/*! les conditions de victoires*/
		printf("La banque a gagne !!! \n");
	}
	else if((scorebc > scoreJ)&&(scorebc<21))
		printf("La banque a gagne !!! \n");
	else
	 	printf("Vous avez gagne!!! \n");
	return 0;
}
