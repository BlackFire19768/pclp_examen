#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#include <math.h>


struct student{
    char nume[30];
    char prenume[30];
    char cnp[14];
};

struct camera{
    int nr_camera;
    int nr_locuri;
    struct strudent * stud;
    int locuri_ocupate;
};
void citires(struct student *c);
void afisares(struct student c);
void egals(struct student a,struct student c);
void initc();
void cazare_stud();
void decazare_stud();
void afisarec();
void cautare_student();

int main(){

    int n;
    printf("\nintroduce ti numarul de studenti: ");
    scanf("%d", &n);

    struct student * tab;

    tab = (struct student*)malloc( n * sizeof(struct student));

    int i;

    for(i=0;i<n;i++)
    {
        printf("\nstudent [%d]: ", i);
        citires(&tab[i]);
    }

    for(i=0;i<n;i++){
        printf("\nstudent [%d]: ", i);
        afisares(tab[i]);
    }

    int j;

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n;j++)
            egals(tab[i], tab[j]);
         
    }

   
    int nrcamera;

    struct camera * tab2;

    tab2 = (struct camera*)malloc( n * sizeof(struct camera));

    for(i=0;i<n;i++){
        
        initc(&tab2[i])
    }


}


void citires(struct student *c){

    printf("\nintroduce ti numele studentului: \n");
    scanf("%s", &c->nume);
    printf("\nintroduce ti prenumele studentului: \n");
    printf("%s", &c->prenume);
    printf("\n introduce ti cnp ul studentului:\n");
    scanf("%s", &c->cnp);

}

void afisares(struct student c){

    printf("\nnumele studentului este: %s", c.nume);
    printf("\nprenumele studentului este: %s", c.prenume);
    printf("\ncnp ul studentului este: %s", c.cnp);
}

void egals(struct student a,struct student c){

    cnp1= a.cnp;
    cnp2= c.cnp;

    if(cnp1==cnp2){
        printf("\n cele doua cenepe uri sunt egale\n");
    }

}

initc(struct camera *a){

    
    printf("\n numarul camerei este:");
    scanf("%d", &a->nr_camera);
    printf("\n introduce ti locurile din camera %d:", a->nr_camera);
    scanf("%d", &a->nr_locuri);s

}
