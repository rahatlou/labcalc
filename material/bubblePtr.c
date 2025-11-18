#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 4

int main() {

   int data[LEN] = {9, 3, 4 , 1 };

   int i, j, temp;

   //stampa array
   printf("pre-ordinamento data = { ");
   for(i=0; i<LEN; i++) printf("%d ", *(data+i));
   printf("}\n\n");

   
   // ciclo i sugli elementi dall'inizio
   for(i=0; i<LEN; i++) { 

     // ciclo j sugli elemento da ultimo fino a i+1
     for(j=LEN-1; j>i; j--) {

       printf("i: %d \t j: %d \t data[%d]: %d \t data[%d]: %d\n",
	      i, j, j-1, *(data+j-1), j, *(data+j));

       if(*(data+j-1) > *(data+j)) {
	 printf("==> scambia data[%d] con data[%d]\n\n", j, j-1);
	 temp = *(data+j);
	 *(data+j) = *(data+j-1);
	 *(data+j-1) = temp;
       } // fine scambio 
       
     }  // ciclo j sugli elementi successivi a i
     
   } // ciclo i su tutti gli elementi

   //stampa array
   printf("dopo ordinamento data = { ");
   for(i=0; i<LEN; i++) printf("%d ", *(data+i));
   printf("}\n\n");


   
} // fine main

