#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include<malloc.h>

int main(){
    printf("introduce ti numarul de elemente din tablou: ");
    int n;
    scanf("%d", &n);
    int i;
    int *p,aux;
    int vector[n];
    p=(int*) malloc(n*sizeof(int));
    printf("\n acum se vor citi elementele  de la tastatura: \n");
    for(i=0;i<n;i++){
        scanf("\n %d", &vector[i]);
        *(p+i)=vector[i];
    }
    for(i=0;i<n;i++){
        if(*(p+i)<0){
            *(p+i)=0;
        }
    }
    printf("\n acum se vor afisa valorile confor cerintei: \n");
    for(i=0;i<n;i++){
        printf("[%d]: %d", i, *(p+i));

    }

}