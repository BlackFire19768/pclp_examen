#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

typedef struct vector{
    int dim;
    int *vect;
} vector;

vector initializare(int dimensiune){
    vector vec;
    vec.dim=dimensiune;
    vec.vect=malloc(sizeof(int*)*dimensiune);

    return vec;
}

void dealocare(vector *pointer){
    free(pointer);
    pointer=NULL;
}

