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
    int cartebc;
    int carteb;
    int carteJ;
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
    
    /*
     *  while((scoreb<=21)&&(scoreJ<=21)){
     *      tirer_carte(BANQUE);
     *      tirer_carte(JOUEUR);
     *  }
     */
    
    if ((scoreb==21)||(scoreJ>21)){
        printf("La banque a gagné");
        afficher_mains_cachee();
    }
    if ((scoreJ==21)||(scoreb>21)){
        printf("Le joueur a gané");
        afficher_mains_cachee();
    }
        
  
    /*
     while(choix!=2){
        printf("Veuillez choisir si vous desirés une autre carte 1:Oui 2:Non\n");
        scanf("%",choix);
        while ((choix==1)&&(choix==2)){
            scanf("%",choix);
        }
        if (choix==1){
            tirer_carte(JOUEUR);
        }
     }
     if(scoreb<=17){
        tirer_carte(BANQUE);
     }
     */
}
