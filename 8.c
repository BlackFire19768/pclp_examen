#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#define N 20
#define M 20

int main(){
    int n,m;
    int matrice[N][M];
    printf("\n introduce ti numarul de linii:");
    scanf("\n %d", &n);
    
    int i;
    int j;
    for(i=0;i< n;i++)
    {
        for(j=0;j< n;j++)
        {
            printf("[%d,%d] : ",i+1,j+1);
            scanf("%d",&matrice[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t", matrice[i][j]);

        }
        printf("\n");
    }

    for(i=0;i< n;i++)
    {
        for(j=0;j< n;j++)
        {
            if(i==j){
                printf("%d", matrice[i][j]);
            }
        }
    }

    
}