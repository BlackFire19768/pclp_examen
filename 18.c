#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

struct vectr{
    int dim;
    int *vect;
}v;

int * initializare(struct vectr c);
void citire();
void afisare();

int main(){

    struct vectr  c;
    
    printf("\nintroduce-ti dimensiunea vectorului: ");

    scanf("%d", &c.dim );

    int *vec= initializare(struct vectr c);

}

int * initializare(struct vectr c){

    int *array=(int*)malloc(c.dim*sizeof(int));

    return array;
}