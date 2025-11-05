#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 7

int main() {

   int data[LEN] = {3, 6, 2 , 5, 9, 0, 1 };

   int i, j, temp;

   for(i=0; i<LEN; i++) {
     for(j=LEN-1; j>i; j--) {

       printf("i: %d \t data[%d]: %d \t data[%d]: %d\n",
	       i, j-1, data[j-1], j, data[j]);

       if(data[j-1] > data[j]) {
	 printf("      scambia data[%d] con data[%d]\n", j, j-1);
	 temp = data[j];
	 data[j] = data[j-1];
	 data[j-1] = temp;
       } // scambio se necessario
       
     }  // ciclo j sugli elementi successivi a i
     
   } // ciclo i su tutti gli elementi
  
} // fine main

