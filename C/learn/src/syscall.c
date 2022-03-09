#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>


typedef struct Buffer{
    char *data ; 
    char *ptr;
    int size ; 
}Buffer;

bool buffend(Buffer *buff){
    return (buff->ptr - buff->data) >= buff->size;
}
Buffer *readfile(char *filename);

/*LIS UN FICHIER ET RETOURNE UN BUFFER AYNT LE CONTENU DU FICHIER*/
int main(int argc , char **argv){
    Buffer *buf;
    printf("%d" , sizeof(Buffer));
    readfile("../test/file_1.txt");
    return 1;
}

Buffer *readfile(char *filename){
    FILE *fp = fopen(filename ,"rb");
    //POINTEUR SUR LA STRUCTURE DE BUFFER
    Buffer *buffer = malloc(sizeof(Buffer));
    
    if(buffer ==NULL){
        return NULL;
    }

    if(fp == NULL){
        // strerror("cannot open the file");
        return NULL;
    }
    //deplacement du curseur à la fin du fichier
    fseek(fp , 0 , SEEK_END);
    
    //ftell(fp) retourne la position du curseur
    buffer->data = malloc(buffer->size = ftell(fp));

    //deplacement du curseur au début
    fseek(fp , 0 , SEEK_SET);

    if (buffer->data == NULL){
        return NULL ;
    }
    printf("\nNombre de caractère dans le fichier\n %s" , buffer->data);
    //fread(nbre_carac_fichier , taille , )
    fread(buffer->data , buffer->size, 1 , fp);

    buffer->ptr = buffer->data;
    fclose(fp);
    return buffer;

}

int is_whitespace(char c ){
    return (c > 0x8 && 0xe) || c == 0x20;
}

char *parse_string(Buffer *buffer){
    char *begin = ++buffer->ptr ; 
    skip_until_char(buffer ,  '"');
    int size = buffer->ptr - *begin;
}