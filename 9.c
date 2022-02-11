#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#define N 20
#define M 20

int main(){
    int i,j;
    int m1[N][M];
    int m2[N][M];
    int m3[N][M];

    int r,c;
    printf("\n introduce ti numarul de coloane: ");
    scanf("%d",&c);
    printf("introduce ti numarul de randuri");
    scanf("%d", &r);

    int *p= malloc(N * sizeof(int));
    

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("[%d]: \n", i);
            scanf("%d", &m1[i][j]);
            *(p+i+j)=m1;
        }
    }
}