#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 10

int main() {
  // array statico di lunghezza NMAX
  double vettore[NMAX] = {0};
  int i,j, n;

  // numero effettivo di valori da trattare n < NMAX
  do {
    printf("numero massimo di dati da inserire (< %d): ", NMAX);
    scanf("%d", &n);
  } while(n<=0 || n > NMAX);

  
  printf("ora inserisci %d elementi del vettore\n", n);
  for(i = 0; i < n; i++) {
    vettore[i] = i + 1;
    printf("vettore[%d]: ",i);
    scanf("%lf", &vettore[i] );  
  } // ciclo input

  // ora stampa i valori nel vettore
  printf("ecco i valori salvati:\n");
  for(i = 0; i < n; i++) {
    printf("vettore[%d] = %.3f\n",i, vettore[i]);
  } // ciclo output

} // main

