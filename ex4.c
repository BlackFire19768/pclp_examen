#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <math.h>
typedef struct {
int x1,y1,x2,y2;
}segment;

void initSegment(int n){
    segment s;
    int *a = (segment*)malloc( n * sizeof(segment));
    for(int i=0;i<n;i++)
        a[i]=0;
}

void citire(int n){

    segment s;


    for(int i=0;i<n;i++){
    printf("a[%d]=",i);
    scanf("%d",&s.x1);
    scanf("%d",&s.y1);
    scanf("%d",&s.x2);
    scanf("%d",&s.y2);
    }
}
void afisare(int n)
{
    segment s;
    for(int i=0;i<n;i++)
    printf("segment %d = %d %d %d %d ",i, s.x1, s.y1, s.x2, s.y2 );
    printf("\n");

}
void lungime(int n){
}

void main(){
    int n;
    printf("Dati numarul de coeficienti dim= ");
    scanf("%d",&n);

    initSegment(n);

    citire(n);
    afisare(n);
}
