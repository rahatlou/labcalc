#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

int main() {

  int n,j,jMax;
  printf("inserisci un numero intero: ");
  scanf("%d", &n);
  
  // valori tra cui cercare divisori
  j = 2;
  jMax = (int)sqrt(n)+1;

  printf("verifica fino jMax: %d\n", jMax);
  
  // aumenta j solo se i non divisibile per j
  for(j = 2; j < jMax; j++) {
    printf("provo con %d\n", j);
    if( n%j == 0) {
      printf("%d multiplo di %d ... non primo :(\n", n, j);
      break; // interrompe il ciclo. non molto elegante
    }
  }
  printf("j dopo ciclo: %d\n", j);
  if(j == jMax) printf("Numero primo %d\n", n);
  
}

