#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 7

int main() {
  
  int data[LEN] = {-5, -2, 7, 12, 14, 19, 23 };

   int i, j, temp;

   int end= LEN-1, start=0, middle;

   int target;

   target = 7;
   printf("valore da cercare? ");
   scanf("%d", &target);

   printf("stai cercando il numero %d\n", target);

   // variabile di appoggio
   int found = 0;
   do{ 
     // indice elemento in mezzo
     middle = (start+end)/2;

     printf("start: %d \t middle:%d \t end: %d\n", start, middle, end);

     if(*(data+middle) == target) {
       found =1;
       
     } else if(*(data+middle) < target) {
       start = middle +1;
       
     } else {
       end = middle -1;
     }

   } while( !found && start <= end);

   if(found) {
     printf("trovato %d in posizione %d !\n", target, middle);
   } else {
     printf("data non contiene il valore %d\n", target);
   }
  
} // fine main
