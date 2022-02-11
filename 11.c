#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#include <math.h>

struct rational{
    int p,q;
};

int simplificare(struct rational a);
void citire(struct rational *);
double afisare(struct rational);
int suma(struct rational a, struct rational b);
float conversie_R(struct rational a);
int conversie_I(struct rational a);
int egal(struct rational a, struct rational b);

int main(){

    int n;
    int i,j;

    FILE* f;

    struct rational * tab;

    printf("n=");
    scanf("%d", &n);
    tab = (struct rational*)malloc( n * sizeof(struct rational));

    printf("\nIntroduceti valori pentru %d perechi de numere", n);

    for(i=0;i<n;i++)
    {
        printf("\ntab[%d]: ", i);
        citire(&tab[i]);
    }

    printf("\nse afiseaza valorile pentru %d perechi de numere", n);
    for(i=0;i<n;i++){
        printf("\ntab[%d]: ", i);
        afisare(tab[i]);
    }
 
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n;j++)
        suma(tab[i], tab[j]);
         
    }

    for(i=0;i<n;i++){

        simplificare(tab[i]);

    }

    for(i=0;i<n;i++){

        conversie_R(tab[i]);

    }

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n;j++)
        egal(tab[i], tab[j]);
         
    }

    //partea intreaga

    for(i=0;i<n;i++){

        conversie_I(tab[i]);
    }

    f=fopen("fis.txt", "w");

    if(f != NULL)
    {
        for(i=0; i<n;i++)
            fprintf(f,"salut");
        fclose(f);
    }

}

void citire(struct rational *c){

    printf("\nvaloarea lui p este: ");
    scanf("%d", &c->p);
    printf("\n valoarea lui q este: ");
    scanf("%d", &c->q);
}

double afisare(struct rational c){
    printf("\n p-ul este egal cu: %d", c.p);
    printf("\n q-ul este egal cu: %d", c.q);
    
}

int suma(struct rational a, struct rational b){
    int x;
    x= a.p+a.q+b.p+b.q;
    printf("\nsuma elementelor este %d\n", x);
}

int simplificare(struct rational a){


    int mod,numerat,denomi,lessnumert,lessdenomi;

    numerat=a.p;
    denomi=a.q;

    switch(a.q){
        case 0: printf("nu se poate 0\n");
        break;
    }

    while(mod!=0){
        mod= a.p % a.q;
        a.p= a.q;
        a.q= mod;
    }

    lessnumert = numerat/a.p;
    lessdenomi= denomi/a.p;
    printf("fractia simplificata este: %d/%d\n",lessnumert, lessdenomi);
    return 0;

}

float conversie_R(struct rational a){

    int mod,numerat,denomi,lessnumert,lessdenomi;

    numerat=a.p;
    denomi=a.q;

    switch(a.q){
        case 0: printf("nu se poate 0\n");
        break;
    }

    while(mod!=0){
        mod= a.p % a.q;
        a.p= a.q;
        a.q= mod;
    }

    lessnumert = numerat/a.p;
    lessdenomi= denomi/a.p;
    
    float numar;
    float numar1=0.F;
    float numar2=0.F;
    numar1= lessnumert;
    numar2= lessdenomi;

    numar= numar1/numar2;

    printf("fractia %d/%d este egala cu %f\n", lessnumert, lessdenomi, numar);
}


int egal(struct rational a, struct rational b){

    int mod,numerat,denomi,lessnumert,lessdenomi;
    int mod2,numerat2,denomi2,lessnumert2,lessdenomi2;

    numerat=a.p;
    denomi=a.q;

    switch(a.q){
        case 0: printf("nu se poate 0\n");
        break;
    }

    while(mod!=0){
        mod= a.p % a.q;
        a.p= a.q;
        a.q= mod;
    }

    lessnumert = numerat/a.p;
    lessdenomi= denomi/a.p;

    numerat2=b.p;
    denomi2=b.q;

    switch(b.q){
        case 0: printf("nu se poate 0\n");
        break;
    }

    while(mod2!=0){
        mod2= b.p % b.q;
        b.p= b.q;
        b.q= mod2;
    }

    lessnumert2 = numerat2/b.p;
    lessdenomi2= denomi2/b.p;


    if((lessnumert==lessnumert2)&&(lessdenomi=lessdenomi2)){
        printf("\nfraactiile %d/%d si %d/%d sunt egale", lessnumert, lessdenomi, lessnumert2, lessdenomi2);

    }

    return 0;

}


int conversie_I(struct rational a){


    int mod,numerat,denomi,lessnumert,lessdenomi;

    numerat=a.p;
    denomi=a.q;

    switch(a.q){
        case 0: printf("nu se poate 0\n");
        break;
    }

    while(mod!=0){
        mod= a.p % a.q;
        a.p= a.q;
        a.q= mod;
    }

    lessnumert = numerat/a.p;
    lessdenomi= denomi/a.p;


    int x;

    x= lessnumert/lessdenomi;

    printf("\npartea intreaga a fractiei %d/%d este %d", lessnumert, lessdenomi, x);

    

}
