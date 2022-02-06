#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *
 * MANIPULATION DES FICHIERS EN LANGAGE C
 *
 */

int main(int argc , char **argv){

	char *file_1 = "../test/file_1.txt";
	int lettre = 0; 
	/*
	 *FOPEN(pathname , MO) MO : (r-> lecture seule) ; (w ecriture seule) ; a (ajout en fin)
	 *			   (r+ lect/ecr , doit exister) ; (w+ lect/ecr, suppr contenu)
	 *			   (a+ ajout lect/ecr , suppr contenu)
	 *fclose(fichier) : fermer le fichier sinon fuite de mem
	 */

	FILE *fichier_1 = fopen(file_1 , "r");
	
	if(fichier_1 == NULL){
		exit(1);
	}

	/*
	 *fgetc(fichier) : lire un caratère du fichier
	 *
	 *feof(fichier) : teste la fin du fichier	 
 	 */

	printf("Première facon de lire un fichier fgetc \n\n");
	lettre = fgetc(fichier_1); //EOF si on arrive à la fin(End Of File)
	printf("%c" , lettre); 
	
	//premiere facon de lire fgetc
	while(1){	 
		lettre = fgetc(fichier_1);
		if (feof(fichier_1)){
			break;
		}
		printf("%c" , lettre);
	}
	fclose(fichier_1);

	//seconde facon de lire avec fgetc

	//int cpt = 1;
	printf("\n\nSeconde facon de lire un fichier  fgetc: \n\n");
        char *file_2 = "../test/file_2.txt";
	//char *store = calloc(cpt , sizeof(char));
	FILE *fichier_2 =  fopen(file_2, "r");
	

	if(fichier_2 == NULL){
		exit(1);
	}
	while((lettre = fgetc(fichier_2)) != EOF){
		//cpt++;
		printf("%c" , lettre);
		//strcat(store , lettre);
		//store = realloc(store , cpt*sizeof(char));
	}
	//printf("Contenu du store\n %s\n", store);


	/*
	 * fgets(store , taille_store, file) lit une ligne renvoit NULL si on est à la fin
	 *
	 */	
	fclose(fichier_2);
		
	printf("\nTroisième facon de lire fgets\n");
	signed char texte[255];
	FILE *fichier_3 = fopen(file_1 , "r");
 
	while(fgets(texte, 254, fichier_3 ) != NULL ){
		printf("%s\n" , texte);
	};
	
	fclose(fichier_3);
	
	/*
	 * fscanf(<fichier> , <format> , store) : lit du texte formaté retourne 0 si à la fin 
	 *
	 */

	printf("\nQuatrième facon avec fscanf\n");
	int cpt = 1;
	FILE *fichier_4 = fopen(file_2 , "r");
	char *store = calloc(cpt , sizeof(char));

	while(fscanf(fichier_4, "%c", store) != EOF){
		cpt++;
		store = realloc(store, cpt*sizeof(char));
	};
	printf("Contenu de file_2 %s\n" , store);
	
	fclose(fichier_4);

	/*
	 * fputc(<caractère>, <fichier>) : ecrit un caractère
	 * fputs(<chaine> , <fichier>) : ecrit une ligne d
	 * fprintf(<fichier> , <format>, ...) ecrit du texte formaté
	 *
	 */

	FILE *fichier_5 = fopen("../test/file_5" , "w");
	char contenu[] = "Bonjour je suis une ligne pour le file 4";
	if(fichier_5 == NULL){
		exit(1);
	}
	fputs(contenu , fichier_5);
	fclose(fichier_5);

	FILE *fichier_6 = fopen("../test/file_6" , "w");

	if(fichier_6 == NULL){
		exit(1);
	}
	fprintf(fichier_6 , "%d", 253);

	fclose(fichier_6);

	/*
 	 * ftell(<fichier>) : retourne la position du curseur
	 * fseek(<fichier> , <déplacement>, <origine>) : déplace le curseur
	 *					-> <origine> : SEEK_SET (début du fichier)
	 *						       SEEK_CUR (position courante)
	 *						       SEEK_END (fin fichier)
	 *
	 * rewind(<fichier>) : reinitialise la position du curseur
	 */

	FILE *fichier_7 = fopen(file_1, "r" );

	printf("Position du curseur dans file_1 %d\n", ftell(fichier_7));
	fseek(fichier_7 , 5 , SEEK_SET );
	printf("Nouvelle position du curseur %d\n", ftell(fichier_7));
	rewind(fichier_7);
	printf("Position après le rewind %d\n", ftell(fichier_7));
	
	fclose(fichier_7); 

	/*
	 * rename(<old name> <new name>) 
	 * remove(<fichier>)
	 *
 	 */
	return 0;
}
