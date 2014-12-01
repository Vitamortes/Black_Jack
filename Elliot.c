afficher_mains(short joueur){
	int i;
	for(i=0; i<52; i++){
		if(cartes[i]==joueur){
			if(cartes[i]<13){//coeur
				if(cartes[i]>1 && cartes[i]<10){
					printf("%i de coeur", i+1);
				}
				else{
					switch(i){
						case 1:	 printf("As de coeur");break;
						case 10: printf("Valet de coeur");break;
						case 11: printf("Dame de coeur");break;
						case 12: printf("Roi de coeur");break;					
					}
				}
			}
			if(cartes[i]<26 && cartes[i]>12){//careaux
				if(cartes[i]<23){
					printf("%i de coeur", i-12);
				}
				else{
					switch(i){
						case 13: printf("As de carreau");break;
						case 23: printf("Valet de carreau");break;
						case 24: printf("Dame de carreau");break;
						case 25: printf("Roi de carreau");break;					
					}
				}
			}
			if(cartes[i]<39 && cartes[i]>25){//piques
				if(cartes[i]<36){
					printf("%i de coeur", i-24);
				}
				else{
					switch(i){
						case 26: printf("As de pique");break;
						case 36: printf("Valet de pique");break;
						case 37: printf("Dame de pique");break;
						case 38: printf("Roi de pique");break;					
					}
				}	
			}
			if(cartes[i]<51 && cartes[i]>38){//trefles
				if(cartes[i]<49){
					printf("%i de coeur", i-36);
				}
				else{
					switch(i){
						case 39: printf("As de trefles");break;
						case 49: printf("Valet de trefles");break;
						case 50: printf("Dame de trefles");break;
						case 51: printf("Roi de trefles");break;					
					}
				}	
			}	
		}
	}
}



short evaluer_score (short joueur, short carte_recue, short *score){
	cartes[carte_recue]=joueur;
	if(carte-recue<=FIN_COEURS)
		*score+=(carte_recue++);
	else if(carte-recue<=FIN_CARREAUX)
		*score+=(carte_recue-12);
	else if(carte-recue<=FIN_PIQUES)
		*score+=(carte_recue-24);
	else 
		*score+=(carte_recue-36);
	return 0;
}