#include <stdlib.h>
#include<stdio.h>
#include<time.h>

#define NMAX 10
#define CMAX 20
#define XMIN -1.
#define XMAX 1.

int main() {

 int neq, i,j,k;
 double A[NMAX][NMAX], b[NMAX], x[NMAX], C, S;

 srand48( time(0) );

 do{
   printf("Inserisci numero di equazioni(<%d): ",NMAX);
   scanf("%d", &neq);
 } while(neq<0 || neq>NMAX);


 /* genera casualmente elementi delle matrici */
 for(i=0; i<neq; i++) {
   b[i] = XMIN+(XMAX-XMIN)*lrand48()/RAND_MAX;
   for(j=0; j<neq; j++) {
     A[i][j] = XMIN+(XMAX-XMIN)*lrand48()/RAND_MAX;
   }
 }


 /* stampa sullo schermo le matrici */
 printf("Sistema di %d equazioni lineari A x = b con\n",neq);
 printf("\nA:\n");
 for(i=0;i<CMAX; i++) {
    printf("=");
 }
 printf("\n");

 for(i=0; i<neq; i++) {
   for(j=0; j<neq; j++) {
     printf("A[%d][%d]: %-3.3lf\t", i, j, A[i][j]);
   }
   printf("\n");
 }

 printf("\nb:\n");
 for(i=0;i<CMAX; i++) {
    printf("=");
 }
 printf("\n");

 for(i=0; i<neq; i++) {
   printf("b[%d]: %-3.3lf\t",i,b[i]);
 }
 printf("\n");

 printf("\nmatrice triangolare:\n=======================\n");

 /* triangolarizza la matrice A e scala il vettore b */
 for(i=0; i<neq; i++) {

   /* normalizza la riga i dividendo per A[i][i] */
   C = A[i][i];

   /* ciclo su colonne per dividere */
   for(j=i; j<neq; j++) {
     A[i][j] /= C;
   }

   /* scala b */
   b[i] /= C;

   /* sottrarre i-esima riga normalizzata da quelle successive */
   for(k=i+1; k<neq; k++) {
     C = A[k][i];

     for(j=i; j<neq; j++) {
       A[k][j] -= C * A[i][j];
     }

     b[k] -= C * b[i];
   }

   /* stampa la matrice sullo schermo */
   for(j=0; j<neq ;j++) {
     printf("A[%d][%d]: %3.3lf\t", i, j, A[i][j]);
   }
   printf("\n");

  } /* for i */


  /* stampa il vettore b scalato */
  printf("\nvettore b scalato:\n=======================\n");
  for(i=0; i<neq; i++) {
    printf("b[%d]: %3.3lf\t", i, b[i]);
  }
  printf("\n");

  /* soluzione delle equzioni */
  printf("\nSoluzioni:\n");
  printf("=================================\n");
  for(i=neq-1; i>=0; i--) {

    /* calcolare il termine dovute alla soluzione della riga successiva */
    S=0.;
    for(j=i+1; j<neq; j++) {
      S += A[i][j]*x[j];
    } 

    x[i] = b[i] - S;

    printf("x[%d] = %3.3lf\t", i, x[i]);
  } /* for i */
    
  printf("\n");
} /* end */
