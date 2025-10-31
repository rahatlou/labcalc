#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 3

int main() {
  // array statico di lunghezza NMAX
  double v1[NMAX] = {1 , 2.5, -1.5};
  double v2[NMAX] = { -1, 2, 3.5};

  // matrice NMAX x NMAX
  double mat[NMAX][NMAX] = { 1, 0, -1, 0, 1, 0, 2, 0, 1 };
  
  int i,j;

  // ora stampa i valori nel vettore
  printf("=== ecco i valori salvati:\n");
  for(i = 0; i < NMAX; i++) {
    printf("v1[%d] = %.3f \t v2[%d] = %.3f\n", i, v1[i], i, v2[i]);
  } // ciclo output
  printf("\n\n");

  for(i = 0; i < NMAX; i++) {
    for(j = 0; j < NMAX; j++) {
      // \t equivale al tasto TAB
      printf("mat[%d][%d] = %.3f \t", i, j, mat[i][j]);
    } // ciclo j
    // finita la stampa della riga si va a capo
    printf("\n");
  } // ciclo i
  
  //prodotto scalare
  double scalProd = 0.;
  for(i = 0; i < NMAX; i++) {
      scalProd += v1[i]*v2[i];
  } // ciclo output
  printf("\nv1 * v2 = %.3f\n", scalProd);


  // v3 = mat x v1
  double v3[NMAX]={0};
 
  //prodotto  mat x v1
  printf("\nv3[] = mat[][] x v1[] \n");
  for(i = 0; i < NMAX; i++) {
    double p = 0.;
    for(j = 0; j < NMAX; j++) {
      p += mat[i][j] * v1[j];
    } // ciclo j colonne mat
    
    v3[i] = p;
    printf("v3[%d] = %.3f\n", i, v3[i]);
    
  } // ciclo i righe mat
  

} // main
