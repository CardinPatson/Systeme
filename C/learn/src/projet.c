#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Mettre en application toutes les lecons (dynamique, pointeur, fichier)
 */

 /*
  * Le programme devra 
  * 1. Lire et écrire dans un fichier
  * 2. Utiliser des preprocesseurs et des fonctions
  * 3. Changer la valeur des variables dans ces fonctions
  * 4. Utiliser l'allocation dynamique de mémoire pour les tableaux
  */

  /*
   * Faire un programme qui demande à un utilisateur dentré son identite
   * L'ouvrir après cela un editeur de texte avec son nom et ses informations qu'il a entré
   * Et à la fin enregistré ce qu'il a entré dans un fichier son forme de lettre
   */



typedef struct Identite{
    char nom[20];
    char prenom[20];
    char mail[50];
    int age;
}Identite;

int traitementIdentite(Identite *personne);

int main(int   argc , char **argv){
    char texte[256];

    printf("Entrez du texte:\n");
    scanf("%s",texte);

    printf("COntenu de votre lettre %s", texte);
    printf("taille de votre lettre %d" , sizeof(texte));


    return 0;
    Identite personne;
    printf("===================================\n");
    printf("Bienvenue sur ton editeur de lettre\n");
    printf("===================================\n\n");
    getchar();
    printf("Pour commencer nous allons te demander des infos d'identification\n\n");
    getchar();
    printf("Entre donc ton jolie nom!\t");
    // scanf("%s" , &personne.nom);
    fgets(personne.nom ,20 , stdin);
    printf("Entre donc ton jolie prenom!\t");
    scanf("%s" , &personne.prenom);
    fgets(personne.prenom , 20 , stdin);
    printf("Entre maintenant ton adresse mail\t");
    scanf("%s", &personne.mail);
    printf("Sort nous ton age enfin!\t");
    scanf("%d", &personne.age);

    printf("\nL'entête de ta lettre à été parfaitement concu\n");
    printf("-------------------------------------------------\n");
    traitementIdentite(&personne);

    printf("Maintenant place au corps de la lettre\n\n");
    getchar();

    char *lettre = calloc(1 , sizeof(char));
    // return 0;

}

int traitementIdentite(Identite *personne){
    char nom_lettre[40] = "../test/Lettre_";
    char mail[60] = "E-mail : ";
    
    strcat(nom_lettre , personne->prenom);
    strcat(nom_lettre, ".txt");

    strcat(mail , personne->mail);
    strcat(mail , "\n");

    FILE *lettre = fopen(nom_lettre , "w");

    fprintf(lettre,"%s %s %s %s" , "Nom & Prenom:", personne->nom, personne->prenom,"\n");
    fputs(mail, lettre);
    fprintf(lettre, "%s %d %s", "Age: ", personne->age,"\n" ); 

    fclose(lettre);
    return 0;
}

int traitementLettre(){

}