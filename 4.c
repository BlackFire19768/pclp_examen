#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include<malloc.h>
#define N 4


int citire();
void afisare(int j[]);
void maxim(int vector[]);

int main(){
    int k[N];
    int vector[N],*ptr;
    printf("acum se va citii vectorul: ");
    
    k[N]=citire();
    printf("\nacum se vor afisa valorile citite: \n");
    afisare(k);
}

int citire(){
    int aux;
    int *ptr;
    ptr = (int*) malloc( N * sizeof(int));
    int i;
    int j;
    printf("\n introduce ti elemente: \n");
    for(i=0;i<N;i++){
        scanf("%d", &aux);
        *(ptr+i)=aux;
        j=*(ptr+i);
    }

    return j;
}

void afisare(int j[]){

    int i;
    for (i=0;i<N;i++){
        printf("%d", j[i]);
    }
}

