#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

struct vector{
    int dim;
    int *vect;
}v;

int * initializare(int dimensiune);
void citire(int dimensiune , int *pointer);
void afisare(int dimensiune , int *pointer);
int apartenenta(int dimensiune, int *pointer);
void dealocare(int *pointer);
void egalitate(int dimensiune,int dimensiune2, int *pointer, int*pointer2);
void intersectie(int dimensiune,int dimensiune2, int *pointer, int*pointer2);

int main(){
    int c;
    
    printf("\nintroduce-ti dimensiunea vectorului: ");

    scanf("%d", &c);

    int *vec= initializare(c);

    citire(c,vec);

    afisare(c,vec);

    int verificare= apartenenta(c,vec);
    printf("%d", verificare);

    printf("\nintrdouce-ti dimensiunea pentru al doilea vector: ");

    int dim2;

    scanf("%d", &dim2);

    int *vec2= initializare(dim2);

    citire(dim2,vec2);

    afisare(dim2,vec2);

    egalitate(c,dim2,vec,vec2);

    intersectie(c,dim2,vec,vec2);

    dealocare(vec);

    dealocare(vec2);


}

int * initializare(int dimensiune){

    int *array=(int*)malloc(dimensiune*sizeof(int));

    return array;
}

void citire(int dimensiune , int *pointer){

    printf("\nacum se vor citii elementele vectorilor: \n");

    int i;
    for(i=0;i<dimensiune;i++){
        printf("\n[%d]: ",i);
        scanf("%d", &pointer[i]);
    }
    printf("\n");
}

void afisare(int dimensiune , int *pointer){

    int i;
    for(i=0;i<dimensiune;i++){
        printf("\n%d ",pointer[i]);
        
    }
    printf("\n");

}

int  apartenenta(int dimensiune, int *pointer){

    printf("\n introduce ti o valoare pentru ai verifica apartenenta la vector: ");
    int valoare;
    scanf("%d", &valoare);
    int x=-1;
    int verificare=0;

    int i;
    for(i=0;i<dimensiune;i++){
        if(pointer[i]==valoare){

            verificare = 1;
            
        }
        if(verificare){
            return i;

        }else{

            return x;
        }
        
    }

    puts("");
}

void egalitate(int dimensiune,int dimensiune2, int *pointer, int*pointer2){
    

    if(dimensiune2!=dimensiune){
        printf("\nvectorii nu sunt egali");
    }

    int i,j;
    int egal=0;

    if(dimensiune2==dimensiune){
        for(i=0;i<dimensiune;i++){
            for(j=0;j<dimensiune;j++){
                if(pointer[i]==pointer2[j]){
                    egal=1;
                }
            }
        }
        if(egal){
            printf("\nvectorii sunt egali\n");
        }
    }
    
    
}

void intersectie(int dimensiune,int dimensiune2, int *pointer, int*pointer2){
    int j,i;
    int inter[dimensiune2];
    int k=0;

    for(i=0;i<dimensiune;i++){
        for(j=0;j<dimensiune2;j++){
            if(pointer2[j]==pointer[i]){
                inter[k]=pointer2[j];
                k++;
            }
        }
    }

    for(k=0;k<dimensiune;k++){
        printf("\n[%d]: %d",k,inter);
    }
}

void dealocare(int *pointer){

    free(pointer);
    pointer = NULL;
}

