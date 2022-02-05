#include <stdio.h>
#include <stdlib.h>


int modifInt(int* i );
int modifTabInt(int *i);
int modifTabChar(char **pat);
int main(int argc , char **argv){

	//type entier
	int i = 0;
	for(i==0; i<=5; i++ ){
		printf("ancienne valeur de i --> %d\n", i);
		modifInt(&i); //On passe l'adresse de i a la fonction
		printf("Nouvelle valeur de i -->%d\n\n", i);
	} 
	//type tableau d'entier
	
	int tabInt[] ={1,2,3,4,5};
	
	printf("Première valeur de i --> %d\n", tabInt[0]);
	modifTabInt(tabInt);
	printf("Nouvelle Première valeur de i --> %d\n", tabInt[0]); 
	
	//Pas la peine de passer des chaines sa ne marche pas en C

	//type tableau de chaine de caractère
	char *pat[] = {"abracadabra" , "je suis" , "un", "titan"};
	printf("Ancienne valeur de pat -->%s %s %s %s\n", pat[0], pat[1], pat[2], pat[3]);
	modifTabChar(pat);
	printf("Nouvelle valeur de pat -->%s %s %s %s\n\n", pat[0], pat[1], pat[2], pat[3]);

}
//MODIFICATION DUNE VARIABLE DE TYPE ENTIER DANS UNE FONCTION
int modifInt(int* i){

	*i = *i + 1;
	return 0;
}

//MODIFICATION DUNE VARIABLE DE TYPE TABLEAU DE INT DANS UNE FONCTION
int modifTabInt(int *i){
	*i = 5;
	return 0;

}

//MODIFICATION DUNE VARIABLE DE TYPE CHAINE DANS UNE FONCTION 
//REM : On ne peut que modifier des tableaux de chaine pas des chaines dans une fonction externe
//SI TU PASSES UNE CHAINE CELA VA ETRE UNE COPIE QUE TU NE POURRAS PAS MODIFIER
int modifTabChar(char **pat){
	printf("Première valeur de pat dans la fonction --> %s\n", *pat);
	*pat = "Patson";//n'essaie pas de faire sa en passant un char* a cette fonction sa ne marche pas
	return 0;
}

//Rem Lorsqu'on passe un pointeur vers une structure, on utilise la notation -> pour accéder au valeur de la structure
