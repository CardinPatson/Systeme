#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct identite{
    int x ; 
    int y;
}identite;

//Un tableau de n entier en memoire occupe un taille de 4*n octect 
void viderBuffer();
int main(int argc, char **argv){
    printf("Taille d'un entier en memoire %d\n" , sizeof(int));
    printf("Taille d'un char en memoire %d\n", sizeof(char));
    printf("Taille de notre structure %d\n" , sizeof(identite) );

    //Au lieu d'utiliser scanf on peut demander à lire l'entré standard
    // char *fgets(char *str, int num,FILE *stream)
    // str: contient la chaine lu 
    // num: taille du tableau str pas en octect

    //fgets retourne le pointeur sur str si pas erreur NULL si erreur 
    /*
        Lorsque l'utilisateur entre des caractères au clavier, 
        Elle est stocké d'abord dans un buffer stdin(récupère temporairement l'entrée du clavier) 
        puis recupéré a partir du buffer pour être stocké dans la mémoire
        Si le user entre plus de caractère que ce qui est autorisé fgets prend ce qu'il peut du buffer
        Il est de la responsabilité du programmeur de vider le buffer pour eviter des fuites

    */

    /*FONCTION POUR VIDER UN BUFFER*/
  

    char fichier[15];
    char *indexBackslashN = NULL ;
    printf("Entrez un texte \n");

    //remplacer le caractère de fin \n dans le fgets
    if(fgets(fichier , 15 , stdin) != NULL){

        indexBackslashN = strchr(fichier , '\n'); // recupere la position de /n dans la chaine

        if(indexBackslashN != NULL){
            *indexBackslashN = '\0';
        }
    };
    viderBuffer();
    printf("Est ce que vous venez d'ecrire : %s!\n", fichier);

    /* strol pour convertir des nombres en des chaines
     * long(const char *start, char **end, int base)
     * start : chaine envoyé
     * end: Position du premier caractère qui n'est pas un nombre (NULL)
     * base : decimal
     */
    return 0;
}
void viderBuffer(){
    int c = 0;
    while(c!= '\n' && c != EOF){
        c = getchar();  
    }
}

