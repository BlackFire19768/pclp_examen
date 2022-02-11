#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#include <math.h>


struct vector{
    int dim;
    int *vect;
};

void initializare(struct vector *);
void citire();
void afisare();

int main(){

    int n;

    printf("n=\n");
    scanf("%n\n", &n);

    struct vector * tab;

    tab = (struct vector *)malloc(n*sizeof(struct vector));


}

