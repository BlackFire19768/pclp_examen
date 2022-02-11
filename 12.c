#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#include <math.h>

struct segment{
    int x1,y1,x2,y2;
};

void init();
void citire(struct segment *);
void afisare(struct segment );
float lungime(struct segment c);
void incrementare(struct segment c);
float compara(struct segment c, struct segment q);

int main(){
    int n;
    
    printf(" introduce ti numarul de segmente\n");
    scanf("%d", &n);

    int i;
    struct segment * tab;

    tab = (struct segment*)malloc( n * sizeof(struct segment));

    for(i=0;i<n;i++)
    {
        printf("\ntab[%d]: ", i);
        citire(&tab[i]);
    }

    for(i=0;i<n;i++){
        printf("\ntab[%d]: ", i);
        afisare(tab[i]);
    }

    for(i=0;i<n;i++){
        printf("\ntab[%d]: ", i);
        incrementare(tab[i]);
    }

    for(i=0;i<n;i++){

        lungime(tab[i]);

    }

    float lungime1, lungime2;

    int j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            lungime1= lungime(tab[i]);
            lungime2= lungime(tab[j]);

            if(lungime1==lungime2){

                printf("\n cele doua segmente au aceasi lungime\n");
            }
        }
    } 

}

void citire(struct segment *c){

    printf("x1:\n ");
    scanf("%d", &c->x1);
    printf("y1:\n ");
    scanf("%d", &c->y1);
    printf("x2:\n ");
    scanf("%d", &c->x2);
    printf("y2:\n ");
    scanf("%d", &c->y2);
}

void afisare(struct segment c){
    printf("\n x1 este egal cu: %d",c.x1); 
    printf("\n y1 este egal cu: %d",c.y1); 
    printf("\n x2 este egal cu: %d",c.x2); 
    printf("\n y2 este egal cu: %d",c.y2); 
    
}

void incrementare(struct segment c){

    int x3,y3,x4,y4;
    x3=c.x1++;
    y3=c.y1++;
    x4=c.x2++;
    y4=c.y2++;

    printf("\nx1 incrementat este: %d", x3);
    printf("\ny1 incrementat este: %d", y3);
    printf("\nx2 incrementat este: %d", x4);
    printf("\ny2 incrementat este: %d", y4);

}

float lungime(struct segment c){

    float l1;
    int a,b;

    if((c.x1>c.x2)&&(c.y1>c.y2)){

        a=c.x1-c.x2;
        b=c.y1-c.y2;
        l1= sqrt(a*a+b*b);
        printf("lungimea segmentului este: %f\n",l1 );

    }
    else if((c.x1<c.x2)&&(c.y1>c.y2)){

        a=c.x2-c.x1;
        b=c.y1-c.y2;
        l1= sqrt(a*a+b*b);
        printf("\nlungimea segmentului este: %f\n",l1 );
    }

    else if((c.x1<c.x2)&&(c.y1<c.y2)){

        a=c.x2-c.x1;
        b=c.y2-c.y1;
        l1= sqrt(a*a+b*b);
        printf("\nlungimea segmentului este: %f\n",l1 );
    }

    else if((c.x1>c.x2)&&(c.y1<c.y2)){

        a=c.x1-c.x2;
        b=c.y2-c.y1;
        l1= sqrt(a*a+b*b);
        printf("\nlungimea segmentului este: %f\n",l1 );
    }

    else if((c.x1==c.x2)&&(c.y1==c.y2)){

        a=c.x1-c.x2;
        b=c.y2-c.y1;
        l1= sqrt(a*a+b*b);
        printf("\nlungimea segmentului este: %f\n",l1 );
    }

    else if((c.x1>c.x2)&&(c.y1==c.y2)){

        a=c.x1-c.x2;
        b=c.y2-c.y1;
        l1= sqrt(a*a+b*b);
        printf("\nlungimea segmentului este: %f\n",l1 );
    }

    else if((c.x1<c.x2)&&(c.y1==c.y2)){

        a=c.x2-c.x1;
        b=c.y2-c.y1;
        l1= sqrt(a*a+b*b);
        printf("\nlungimea segmentului este: %f\n",l1 );
    }

    else if((c.x1==c.x2)&&(c.y1<c.y2)){

        a=c.x1-c.x2;
        b=c.y2-c.y1;
        l1= sqrt(a*a+b*b);
        printf("\nlungimea segmentului este: %f\n",l1 );
    }

    else if((c.x1==c.x2)&&(c.y1>c.y2)){

        a=c.x1-c.x2;
        b=c.y1-c.y2;
        l1= sqrt(a*a+b*b);
        printf("\nlungimea segmentului este: %f\n",l1 );
    }
}

float compara(struct segment c, struct segment q){

    float lungime1, lungime2;

    struct segment f;

    struct segment g;
    

    lungime1= lungime(f);
    lungime2= lungime(g);

    if(lungime1==lungime2){
        printf("\n au aceleasi lungime\n");
    }

}
