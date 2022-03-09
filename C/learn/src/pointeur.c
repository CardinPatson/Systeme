#include <stdio.h>
#include <stdlib.h>
// #include "../include/pointeur.h"

typedef struct Personne{
		char *name;
		int age;
	}Personne;

int modifInt(int* i );
int modifTabInt(int *i);
int modifTabChar(char **pat);
int modifStruct(Personne *patson);
int modifTabStruct(Personne *famille);

int paraFunction(int value);
int modifFunc(int (*)(func), int value);


int main(int argc , char **argv){


	modifFunc(&paraFunction  , 5 );
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

//FUNCTION EN PARAMETREze

int paraFunction(int value){
	return value;
};

int modifFunc(int *(func) , int value){
	return *func(value);
}


///