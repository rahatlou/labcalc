#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define LEN 7

int main() {

  
  int data[LEN] = {1, 4, 7, 12, 14, 19, 23 };

   int i, j, temp;

   int end= LEN-1, start=0, middle;

   int target, found=0;

   target = 7;
   printf("valore da cercare? ");
   scanf("%d", &target);

   printf("stai cercando il numero %d\n", target);

   
   do{ 
     // elemento a meta`
     middle = (start+end)/2;

     printf("start: %d \t middle:%d \t end: %d\n", start, middle, end);

     if(data[middle] == target) {
       found =1;
     } else if(data[middle] < target) {
       start = middle +1;
     } else {
       end = middle -1;
     }

   } while( !found && start <= end);

   if(found) {
     printf("trovato %d in posizione %d !\n", target, middle);
   } else {
     printf("array non contiene il valore %d\n", target);
   }

  
} // fine main
