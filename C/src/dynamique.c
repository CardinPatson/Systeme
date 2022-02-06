#include <stdio.h>
#include <stdlib.h>

int main(int argc , char **argv){

/*
 * ALLOCATION DYNAMIQUE DE MEMOIRE EN C (MALLOC CALLOC REALLOC)
 *
 * MALLOC(sizeof(int)*taille) : Alloue dynamiquement <taille> case d'entier
 * FREE libere la zone alloué
 */
	int cpt = 0;
	int taille = 0;
	int *tableau = NULL;

	printf("Entrez la taille de votre tableau : \t");
	scanf("%d", &taille);

	tableau = malloc(sizeof(int)*taille);

	if(tableau == NULL){
		exit(1);
	}

	for(cpt = 0; cpt<taille; cpt++ ){
		tableau[cpt] = cpt*2;
		printf("\ntableau de %d --> %d", cpt, tableau[cpt]);
	}
	free(tableau);

/*
 *
 * CALLOC(<taille du tableau> , <taille en octect>) : alloue et initialise toutes les cases à 0
 * CALLOC --> Clear Allocation
 *
 */
	int cpt_2 = 0;
	int taille_2 = 0;
	int *tableau_2 = NULL;
	
	printf("\nEntrez la taille de votre second tableau: \t");
	scanf("%d", &taille_2);

	tableau_2 = calloc(taille , sizeof(int));
	
	for(cpt_2 = 0; cpt_2<taille_2 ; cpt_2++){
		printf("\nvaleur de la case %d --> %d" , cpt_2, tableau_2[cpt_2]);
	}

/*
 *REALLOC(<tableau> , <nouvelle taille>) : realloue de l'espace mémoire pour notre tableau
 *
 */

	printf("\nEntrez une taille supérieur à la précédente pour visualise le realloc:\t");
	scanf("%d",&taille_2);

	tableau_2 = realloc(tableau_2 , taille_2*sizeof(int));
	for(cpt_2 =0 ; cpt_2<taille_2; cpt_2++){
		printf("\nValeur de la case %d --> %d", cpt_2, tableau_2[cpt_2]);
	}
	
	free(tableau_2);
	return 0;
}
