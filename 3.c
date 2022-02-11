#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include<string.h>
#define N 4
#define M 10

void copiaza(int sir[]);
void compara(char vector[], char vector2[]);
void concateneaza(char vector1[], char vector2[]);
void copiaza_litere(char vector[]);

int main(){
    char vector[M];
    int sir[N];

    
    char array[M];
    char array2[M];
    scanf("%s", array);
    
    scanf("%s", array2);
    
    
    //compara(array, array2);
    
    //copiaza_litere(array);



    /*
    printf("introdu ce ti un sir: ");
    int i;
    for (i=0;i<N;i++){
        scanf("\n %d", &sir[i]);
    }
    
    printf("\n acum se copiaza sirul in alt sir : ");
    copiaza(sir);
    */
    

}
void concateneaza(char vector1[], char vector2[]){

    char vector3[M];
    

}
void compara(char vector1[], char vector2[]){
    int size_t;
    size_t = sizeof (vector1) / sizeof(vector1[0]);
    int size;
    size= sizeof (vector2) / sizeof(vector2[0]);
    if(size_t<size){
        printf("%s este mai mare de cat %s", vector2, vector1);
    }
    else(size_t>size);
    {
        printf("%s este mai mare de cat %s", vector1, vector2);
    }
    
}
void copiaza_litere(char vector[]){
    char vector2[M];
    vector2[M]=vector[M];
    printf(" \n %s", vector2);
}
void copiaza(int sir[]){
    int sir2[N];
    int i,j;
    for(i=0;i<N;i++){
        sir2[i]=sir[i];
    }
    
    printf("\n sirul copiat este: ");
    for(i=0;i<N;i++){
        printf("\n[%d]: %d", i,sir2[i]);
    }
}