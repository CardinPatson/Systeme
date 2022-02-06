#include <stdio.h>
#include <stdlib.h>

typedef struct Personne{
		char *name;
		int age;
	}Personne;

int modifInt(int* i );
int modifTabInt(int *i);
int modifTabChar(char **pat);
int modifStruct(Personne *patson);
int modifTabStruct(Personne *famille);

int main(int argc , char **argv){

	//type entier
	int i = 0;
	for(i=0; i<=5; i++ ){
		printf("ancienne valeur de i --> %d\n", i);
		modifInt(&i); //On passe l'adresse de i a la fonction
		printf("Nouvelle valeur de i -->%d\n\n", i);
	} 
	//type tableau d'entier
	
	int tabInt[] ={1,2,3,4,5};
	
	printf("Première valeur de i --> %d\n", tabInt[0]);
	modifTabInt(tabInt);
	printf("Nouvelle Première valeur de i --> %d\n\n", tabInt[0]); 
	
	//Pas la peine de passer des chaines sa ne marche pas en C

	//type tableau de chaine de caractère
	char *pat[] = {"abracadabra" , "je suis" , "un", "titan"};
	printf("Ancienne valeur de pat -->%s %s %s %s\n", pat[0], pat[1], pat[2], pat[3]);
	modifTabChar(pat);
	printf("Nouvelle valeur de pat -->%s %s %s %s\n\n", pat[0], pat[1], pat[2], pat[3]);
	
	//type structure

	
	Personne patson;
	patson.name = "patson";
	
	modifStruct(&patson);
	printf("Age de patson --> %d\n\n", patson.age);

	//type tableau de structure

	Personne famille[2];
	famille[0].name = "cardin";

	modifTabStruct(famille);
	printf("Age du premier membre --> %d",famille[0].age);
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
int modifStruct(Personne *patson){
	printf("Nom de la personne --> %s\n", patson->name);
	
	patson->age = 21; // Modification de la structure dans la fonction
	return 0;
}


//MODIFICATION DUN TABLEAU DE STRUCTURE DANS UNE FONCTION
//[{} , {} , {} , {}] 
int modifTabStruct(Personne *famille){
	printf("Nom du premier membre -->%s\n", famille[0].name);

	famille[0].age = 35;
}
