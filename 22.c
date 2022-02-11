#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>

typedef struct nrtelefon {
    
    char prefix[16];
    char numar[7];
}nrtelefon;

typedef struct persoana{

    char nume[20];
    char prenume[20];
    nrtelefon telefon;
}persoana;

void citiretel(nrtelefon *);
void afisaretel(nrtelefon);
void citireper(persoana *);
void afisareper(persoana);
int compartel(nrtelefon, nrtelefon);
void ordonare(persoana);
void prefi(persoana c, char prefics);



int main(){

    FILE* f;

    printf("introduce ti numarul de persoane: ");
    int numar;
    scanf("%d", &numar);
    struct persoana *lista;

    lista = (struct persoana*)malloc(sizeof(struct persoana)*numar);

    int i;
    printf("\n acum se vor introduce valori in lista");
    for(i=0;i<numar;i++){
        printf("\npesoana %d: ",i );
        citireper(&lista[i]);
    }
    printf("\n acum se vor afisa datele persoanelor: ");
    for(i=0;i<numar;i++){
        printf("\npersoana %d: ", i);
        afisareper(lista[i]);
    }
    
    printf("\nintroduce ti prefixul pe care doriti s al cautati: ");
    char prf[6];
    scanf("%s", prf);

    char aux[25];
    int j;
    //ordonare in ordine alfabetica
    /*
    for(i=0;i<=numar;i++){
        for(j=i+1;j<=numar;j++){
          if(strcmp(lista[i],lista[j])>0){
              strcpy(aux,lista[i]);
              strcpy(lista[i],lista[j]);
              strcpy(str[j],aux);
            }
        }
    }
    

    char prefics[6];
    printf("\nintroduce ti prefixul pe care vre ti sa l cautati: ");
    scanf("%s", prefics);

    printf("\nacum se vor afisa numerele care au %s ca prefix: ", prefics);
    for(i=0;i<numar;i++){
        prefi(lista[i], prefics);
    }
    */

    f=fopen("fis.txt","w");
    if(f!=NULL){
        for(i=0;i<numar;i++){
            fprintf(f,"numele este: %s prenumele este: %s numarul de telefon este: %s",lista[i].nume,lista[i].prenume,strcat(lista[i].telefon.prefix,lista[i].telefon.numar));
        }
    }

}

void citiretel(nrtelefon * a){
    printf("\nintroduce ti prefixul: ");
    scanf("%s", &a->prefix);
    printf("\nintroduce ti numarul de telefon: ");
    scanf("%s", &a->numar);
}

void afisaretel(nrtelefon a){
    printf("\nprefixul este: %s", a.prefix);
    printf("\nnumarul este: %s", a.numar);
    printf("\nacum se va afisa numarul intreg: ");
    puts(strcat(a.prefix,a.numar));


}

void citireper(persoana *c){
    printf("\nintroduce ti numele: ");
    scanf("%s", &c->nume);
    printf("\nintroduce ti prenumele: ");
    scanf("%s",&c->prenume);
    printf("\nintroduce ti numarul de telefon: ");
    citiretel(&c->telefon);
}

void afisareper(persoana c){
    printf("\nnumele persoanei este: %s", c.nume);
    printf("\nprenumele persoanei este: %s", c.prenume);
    printf("\nnumarul de telefon al persoanei este: ");
    afisaretel(c.telefon);
}



int compartel(nrtelefon a, nrtelefon b){
    if((a.numar==b.numar)&&(a.prefix==b.prefix)){
        return 1;
    }else{
        return 0;
    }
}

