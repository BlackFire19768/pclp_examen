
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <chrono>  
using namespace std;  

struct vectr{
    int dim;
    int *vect;
}v;

int * initializare(struct vectr c);
void citire(int dimensiune , int *pointer);
void afisare();

int main(){

    struct vectr  c;
    
    cout<<endl<<"introduce ti dimensiunea vectorului: ";

    cin>>c.dim;

    int *vec= initializare(struct vectr c);

    citire(c,vec);


}

int * initializare(struct vectr c){

    int *array=(int*)malloc(c.dim*sizeof(int));

    return array;
}

void citire(int dimensiune , int *pointer){

    cout<<endl<<"acum se vor citii elementele vectorilor"<<endl;

    int i;
    for(i=0;i<dimensiune;i++){
        cout<<endl<<"["<<i<<"]"<<endl;
        cin >> &pointer[i];
    }
    cout<<endl;
}