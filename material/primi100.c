#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

int main() {

  int i,j,jMax;
  printf("Numeri primi tra 1 e %d:\n", N);

  // ciclo sui numeri da 1 a N
  for(i=1; i<=N; i++) {

    // valori tra cui cercare divisori
    j = 2;
    jMax = (int)sqrt(i)+1;

    // aumenta j fino jMax  solo se i non divisibile per j
    while( (j<jMax) && (i%j) ) {
      j++;
    }
    
    if(j == jMax) printf("%d\n", i);

  } // ciclo for

}  // main


