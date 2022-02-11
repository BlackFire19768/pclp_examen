#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>
struct punct
{
 int x, y;
};
struct cerc
{
 punct centru;
 float raza;
} ;
void citireP(punct *);
void afisareP(punct );
double distanta(punct, punct);
void citireC(cerc*);
void afisareC(cerc);
double aria(cerc);
int compar(cerc, cerc);
int verificare(cerc, punct);
int main()
{
 int n, i, j, k, imax=0;
 double amax=0;
 cerc * tab;
 punct p;
 FILE* f;
 printf("n=");
 scanf("%d", &n);
 tab = (cerc*)malloc( n * sizeof(cerc));
 printf("\nIntroduceti valori pentru %d cercuri", n);
 for(i=0;i<n;i++)
 {
 printf("\ntab[%d]: ", i);
 citireC(&tab[i]);
 }
 printf("\nSe afiseaza valorile pentru %d cercuri", n);
 for(i=0;i<n;i++)
 {
 printf("\ntab[%d]: ", i);
 afisareC(tab[i]);
 }
 cerc aux;
 for(i=0;i<n-1;i++)
 for(j=i+1; j<n;j++)
 if(compar(tab[i], tab[j])==1)
 {
 aux=tab[i];
 tab[i]=tab[j];
 tab[j]=aux;
 }
 printf("\nSe afiseaza valorile pentru cercuri dupa ordonare");
 for(i=0;i<n;i++)
 {
 printf("\ntab[%d]: ", i);
 afisareC(tab[i]);
 }
 printf("\n\nIntroduceti coordonatele unui punct:");
 citireP(&p);
 for(i=0; i<n;i++)
 if(verificare(tab[i], p) == 1 )
 printf("\nPunctul apartine elementului de index %d ", i);
 k=0;
 for(i=0; i<n-1; i++)
 {
 for(j=i+1; j<n;j++)
 if(distanta(tab[i].centru, tab[j].centru) ==0)
 {
 printf("\nCercurile %d si %d sunt concentrice", i, j);
 k++;
 }
 }
 if(k==0)
 printf("\nNu exista cercuri concentrice");
 f=fopen("fis.txt", "w");
 if(f != NULL)
 {
 for(i=0; i<n;i++)
 fprintf(f, "raza=%8.2f, x= %3d, y=%3d\n", tab[i].raza, tab[i].centru.x, tab[i].centru.y );
 fclose(f);
 }
 free(tab);
getch();
 return 0;
}
void citireP(punct *p)
{
 printf("\nx=");
 scanf("%d",&p->x);
 printf("y=");
 scanf("%d",&p->y);
}
void afisareP(punct p)
{
 printf("x=%d, y=%d", p.x, p.y);
}
double distanta(punct a, punct b)
{
 return sqrt((a.x-b.x)*(a.x-b.x) +(a.y-b.y)*(a.y-b.y));
}
void citireC(cerc*c)
{
 printf("\nraza = ");
 scanf("%f", &c->raza);
 printf("Coordonatele centrului:");
 citireP(&c->centru);
}
void afisareC(cerc c)
{
 printf("\nRaza = %.2f", c.raza);
 printf("\nCentru: ");
 afisareP(c.centru);
}
double aria(cerc c)
{
 return 3.14 * c.raza*c.raza;
}
int compar(cerc c1, cerc c2)
{
 if(aria(c1)>aria(c2))
 return 1;
 else
 if(aria(c1)== aria(c2))
 return 0;
 return -1;
}
int verificare(cerc c, punct p)
{
 if (distanta(c.centru, p)<c.raza)
 return 1;
 return 0;
}
