#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include<string.h>


int numar_prim(int a, int b){
    int i,nr=0;
    for(i=a;i<=b;i++){
        for(int d=2;d<i/2;d++){
            if(i%d!=0)
                nr++;
            if(nr==0){
                printf("%d", i);
                
            }


        }
        
    }
}

int main(){
    int a,b;
    printf("introduce ti minimul intervalului ");
    scanf("%d", &a);
    printf("\n introduce ti capatul maxim al intervalului ");
    scanf("%d", &b);
    numar_prim(a,b);
}