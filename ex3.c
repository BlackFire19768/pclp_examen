
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>
typedef struct {
int grad;
double *coef;
}Polinom;

Polinom initPol(int n){
    Polinom p;
    p.grad=n;
    p.coef = (Polinom*)malloc( n * sizeof(Polinom));
    for (int i = 0; i < n; i++) {
        p.coef[i] = 0;
    }
    return p;
}

void elibPol(Polinom p){
    free (p.coef);
}

Polinom citestePol(){
    int n;
    printf("Dati numarul de coeficienti dim= ");
    scanf("%d",&n);
    Polinom p=initPol(n);
    for(int i=0;i<p.grad;i++){
    printf("a[%d]=",i);
    scanf("%d",&p.coef[i]);
    }
    return p;
}

void scriePol(Polinom p, char mesaj[]){
    printf("%s",mesaj);
    for(int i=0;i<p.grad;i++)
    printf("a[%d]=%d",i, p.coef[i]);
    printf("\n");
}

Polinom plus(Polinom p, Polinom q){
    Polinom r;
    int pdim=p.grad, qdim=q.grad;
    if(pdim<=qdim){
        r=initPol(qdim);
        for(int i=0;i<pdim;i++)
            r.coef[i]=p.coef[i]+q.coef[i];
        for(int i=pdim;i<qdim;i++)
        r.coef[i]=q.coef[i];
    }
    else{
        r=initPol(pdim);
        for(int i=0;i<qdim;i++)
        r.coef[i]=p.coef[i]+q.coef[i];
        for(int i=qdim;i<pdim;i++)
        r.coef[i]=p.coef[i];
        }
    return r;
}

int main(){
Polinom p=citestePol();
scriePol(p,"polinomul p:");
Polinom q=citestePol();
scriePol(q,"polinomul q:");
Polinom r=plus(p,q);
scriePol(r, "suma p+q:");
elibPol(p);
elibPol(q);
elibPol(r);
return 0;
}
