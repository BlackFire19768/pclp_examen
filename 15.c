#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>

struct persoana{
    char nume[20];
    char prenume[20];
    char cnp[14];

};

struct data{
    int zi;
    int luna;
    int an;
};

void citire(struct persoana *);
void afisare(struct persoana);
void conversie(struct persoana c);
void compar_nume(struct persoana a,struct persoana c);
void compar_data();

int main(){

    int n;
    printf("\nintroduce ti numarul de persoae: ");
    scanf("%d", &n);

    struct persoana * tab;

    tab = (struct persoana*)malloc( n * sizeof(struct persoana));

    int i;
    for(i=0;i<n;i++)
    {
        printf("\npersoana [%d]: ", i);
        citire(&tab[i]);
    }

    for(i=0;i<n;i++)
    {
        printf("\npersoana [%d]: ", i);
        afisare( tab[i]);
    }

    for(i=0;i<n;i++)
    {
        printf("\npersoana [%d]: ", i);
        conversie( tab[i]);
    }
    int j;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n;j++)
            compar_nume(tab[i], tab[j]);
         
    }


}

void citire(struct persoana * c){

    printf("\nintrodu numele persoanei: ");
    scanf("%s", &c->nume);
    printf("\nintroduce ti prenumele persoaneai:");
    scanf("%s", &c->prenume);
    printf("\nintroduce ti cnp ul persoaneai:");
    scanf("%s", &c->cnp);

}


void afisare(struct persoana c){

    printf("\nnumele: %s", c.nume);
    printf("\nprenumele: %s", c.prenume);
    printf("\ncnp: %s", c.cnp);
}

void conversie(struct persoana c){
    printf("\ncnp ul este: %s", c.cnp);
    //nu mere :()

}

void compar_nume(struct persoana a,struct persoana c){

    int x;

    x=strcmp(a.nume,c.nume);
    int z;

    z=strcmp(a.prenume,c.prenume);

    if(x==z){
        printf("\ncele doua persoane au acelasi nume si prenume");
    }
    else if(x!=z){
        printf("\ncele doua persoeane nu au acelasi nume si prenume");
    }




}



