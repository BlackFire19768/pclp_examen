#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

struct matrix{
    int linii,coloane;
    double ** m;
};

int ** initializare(int linii, int coloane);
void citire(int linii, int coloane, int **p);
void afisare(int linii, int coloane, int **p);
int suma_linie(int linii, int coloane, int **p);
void inversare_linii();
int eliminare_linie(int linii, int coloane, int **p);
void dealocare(int ** p, int linii);
#define NO_UNIQUE -1

int main(){

    
    
    int i,j,l,c;
    printf("\n introduce ti nr de linii si de coloane:");
    scanf("%d",&l);
    scanf("%d",&c);
    
    int **p=initializare(l,c);

    //pentru alocare in main

    /*
    p=malloc(l*sizeof(int*));
    for(i=0;i<l;i++){
        p=malloc(c*sizeof(int));
    }
    */

    citire(l,c,p);
    afisare(l,c,p);
    suma_linie(l,c,p);
    dealocare(p,l);
    printf("Max sum is %d\n", suma_linie(l,c,p));
    

    //pentru dealocare in main
    /*
    for(i=0;i<l;i++){
        free(p[i]);
    }
    free(p);
    */
    
}

int ** initializare(int linii, int coloane){

    int i,j;
    int ** p= (int**)malloc(linii*sizeof(int*));
    for(i=0;i<linii;i++){
        p[i]=(int*)malloc(sizeof(int)*coloane);
        
    }

    return p;
}

void citire(int linii, int coloane, int **p){
    int i;
    int j;
    for (i=0;i<linii;i++){
        for(j=0;j<coloane;j++){
            printf("[%d][%d]: ", i,j);
            scanf("%d", &p[i][j]);
        }
        printf("\n");
    }
}

void afisare(int linii, int coloane, int **p){

    int i;
    int j;
    for (i=0;i<linii;i++){
        for(j=0;j<coloane;j++){
            printf("%5d",p[i][j]);
        }
        puts("");
    }

}

int suma_linie(int linii, int coloane, int **p){
    int i,j;
    for(int i=0;i<linii;i++)   
    {
        int rsum=0;
        for(int j=0;j<coloane;j++)
        {
            rsum=rsum+p[i][j];
        }
        printf("\nsuma elementelor linielor %d este %d\n",i,rsum);
    }
}

void dealocare(int **p, int linii){
    int i;
    for(i=0;i<linii;i++){
        free(p[i]);
    }
    free(p);
}

int eliminare_linie(int linii, int coloane, int **p){

    int i,j;
    int row_max=-1;
    bool unique= false;
    int row_sum;

    for (i = 0; i < linii; ++i) {
        row_sum = 0;
        for (j = 0; j < coloane; ++j)
            row_sum += p[i][j];

        if (row_max < row_sum) {
            row_max = row_sum;
            unique = true;
        } else if (row_max == row_sum)
            unique = false;
    }

    if (unique)
        return row_max;
    else {
        printf("No unique max.\n");
        return NO_UNIQUE;
    }

}

