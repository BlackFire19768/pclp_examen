#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include<malloc.h>
#define N 4

int main(){
    int i,j;
    int *p, *k;
    int vector1[N];
    int vector2[N];

    p=(int*) malloc(N * sizeof(int));
    k=(int*) malloc(N * sizeof(int));

    printf("\n acum se vor citii valori pentru primul vector: \n");

    for(i=0;i<N;i++){
        scanf("\n %d", &vector1[i]);
        *(p+i)= vector1[i];
    }

    printf("\n acum se vor citii valori de la tastatura pentru al doilea vector: \n");

    for(j=0;j<N;j++){
        scanf("\n %d", &vector2[i]);
        *(k+j)= vector2[i];
    }

    int y;
    int vector3[N];
    int *g;
    g=(int*) malloc(N*sizeof(int));
    
    for(y=0;y<N;y++){
       vector3[y]= *(p+y) + (*(k+y));
       printf("\n [%d]: %d", y, vector3[y]);
    }


    /*
    printf("\nacum testam sa vedem daca merge: \n");

    for(i=0;i<N;i++){
        printf("\n [%d]: %d \n", i, *(p+i));
    }

    for(j=0;j<N;j++){
        printf("\n [%d]: %d \n", j, *(k+j));
    }
    */
}