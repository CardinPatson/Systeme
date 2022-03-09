#include <stdio.h>
#include <stdlib.h>
#include <string.h>
include "pointeur.c"


int main(int argc  , char **argv){


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


	//PASSAGE DE FUNCTION EN PARAMETRE
	int val = 2;
	printf("valeur de la fonction : %d" , modifFunc(val ));
	// print("si je retourne une valeur quie est ")


}