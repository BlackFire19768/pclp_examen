#include <stdio.h> 
#include <stdlib.h>
#include <conio.h> 
#include <malloc.h>
#include <string.h>
#define N 20

int main()
{
   char str[N];
   char str2[N];
   
   gets(str);
   
   gets(str2);
  

   char *p1= str;
   char *p2= str2;
   

   printf("\n\n%s", strcat(p1,p2));



   return 0;
}