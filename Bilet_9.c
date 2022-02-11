#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct Punct    
{
    int x, y;
} Punct;

void citire_punct (Punct* coord)
{
    printf("Introduceti coordonatele x si y:\n");
    scanf("%d%d", &coord->x, &coord->y);
}

void afisare_punct (Punct* coord)
{
    printf("Coordonatele punctului sunt: x=%d si y=%d\n", coord->x, coord->y);
}

double distanta (Punct* a, Punct* b)
{
    int x = b->x - a->x;
    int y = b->y - a->y;

    return sqrt(x*x+y*y);
}

int egalitate (Punct* a, Punct* b)
{   
    return(a->x==b->x && a->y==b->y);
}


typedef struct Poligon
{
    int nr;
    Punct* varfuri;
} Poligon;

void initializare (Poligon* valori, int nr_vf)
{
    valori->nr = nr_vf;
    valori->varfuri = malloc(sizeof(Punct)*nr_vf);
}

void citire_poligon (Poligon* valori)
{
    int nr_vf;

    printf("Introduceti nr de varfuri:\n");
    scanf("%d", &nr_vf);

    initializare(valori, nr_vf);

    for (int i = 0; i < nr_vf; i++)
    {
        //valori->varfuri[i];
        citire_punct(&valori->varfuri[i]);
    }
    
}

void afisare_poligon (Poligon* valori)
{
   
    printf("Nr de vf este: %d\n", valori->nr);

    for (int i = 0; i < valori->nr; i++)
    {
        afisare_punct(&valori->varfuri[i]);
    }
    
}

double calcul_perimetru (Poligon* valori)
{   
    double perimetru = 0.0;

    for (int i = 0; i < valori->nr; i++)
    {
        int intoarcere=i;
        if(i+1==valori->nr)
        {
            intoarcere=0;
        }
        perimetru += distanta(&valori->varfuri[i], &valori->varfuri[intoarcere]);  
    }
    
    return  perimetru;
}

void dealocare (Poligon* valori)
{
    free(valori->varfuri);
    valori->nr = 0;
}

int main()
{
    Poligon patrat;
    citire_poligon(&patrat)
}
