#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#define N 4

void citire(int i[]);
void afisare(int i[]);
int maxim(int i[]);

int main(){
    int i[N];
    printf("acum se va citii vectorul");
    citire(i);
    printf("\n acum se va afisa vectorul");
    afisare(i);
    printf("\n acum se va afisa maximul: ");
    maxim(i);
}

void citire(int i[]){
    for(int j=0;j<N;j++){
        printf("\n%d: ",j);
        scanf("%d", &i[j]);
    }
}

void afisare(int i[]){
    int j;
    for (j=0;j<N;j++)
        printf("\nelementul [%d]= %d", j+1, i[j]);
}

int maxim(int i[]){
    int max=i[0];
    for(int j=0;j<N;j++){
        if(max<i[j]){
            max= i[j];
        }
        
    }

    printf("%d", max);
}