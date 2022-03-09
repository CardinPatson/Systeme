#ifndef __POINTEUR__
#define __POINTEUR__

int modifInt(int* i );
int modifTabInt(int *i);
int modifTabChar(char **pat);
int modifStruct(Personne *patson);
int modifTabStruct(Personne *famille);

int paraFunction(int value);
int modifFunc(int *func(int), int value);