#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* usare il precompilatore per valori costanti */

/* num max di esperimenti */
#define NEXPMAX    100000

/* valore di a piu` grande */
#define AMAX       100

/* numero max di = sullo schermo */
#define NSTARMAX   50

/* funzione utile per generare num casuali interi */
int genInt(int a, int b);

int main() {

  int Nexp, Ndati, a, Nstar;
  int iexp, j, istar; /* contatori dei cicli for */
  int imax; /* la media con maggiore frequenza */
  float media; /* valore medio per ciascun esperimento */
  int  freq[AMAX+1]; /* freq viene calclota per 0,...., a con a <= AMAX */

  /* inizializzare UNA SOLA volta il generatore random nella main() */
  srand48( time(0) );


  printf("questo programma calcola e grafica la frequenza del valore \n");
  printf("medio di Ndati valori casuali generati nell'intervallo [0,a].\n");

  /* acquisire il valore di Nexp < NEXPMAX */
  do {
   printf("Inserire il numero di esperimenti [1,%d]: ", NEXPMAX);
   scanf("%d", &Nexp);
  } while(Nexp<= 0 || Nexp>NEXPMAX);

  /* acquisire il valore di a < AMAX */
  do {
   printf("Inserire il valore di a nell\'intervallo [0,%d]: ", AMAX);
   scanf("%d", &a);
  } while(a<= 0 || a>AMAX);

  /* inizializzare freq */
  for(j=0; j< AMAX+1; j++) {
     freq[j] = 0;
  }

  /* acquisire il valore di Ndati */
  do {
   printf("Inserire il numero di valori casuali da generare per esperimento: ");
   scanf("%d", &Ndati);
  } while(Ndati<= 0);


  for(iexp=0; iexp < Nexp; iexp++) { /* ciclo di esperimenti */

    /* reset di media per ciascun esperimento */ 
    media = 0.0;

    /* ciclo per genrare Ndati per ciascun esperimenti */
    for(j=0; j< Ndati; j++) {

       /* genera num casuale e aumenta la media */
       media += genInt(0,a);

    } /* fine ciclo Ndati */

    /* dividi la somma dei num casuali per Ndati e calcola la media */
    media /= Ndati;  

    /* printf("iexp: %d \t media = %d\n", iexp, media); */

    /* NB: media essendo razionale sara` sempre del tipo 3.2, 3.7, 3.9
       possiamo usare la parte intera di media come l'indice dell'array freq
    */

    /* aggiornare la frequenza di media appena calcolato */
    freq[(int)media]++;

  } /* fine ciclo esperimenti */


  /* al termine degli esperimenti anche tutte le freuenze sono state 
     correttamente calcolate
  */

  /* stampare ora il valore delle frequenze */
  for(j=0; j < a+1; j++) {
   printf("freq[%3d] = %d\n", j, freq[j] );

  } /*fine ciclo stampa freq */
  
  printf("---------- istogramma delle frequenze ----------\n");


  /* trovare il valore medio con la maggior frequenza */
  imax = 0;
  for(j=1; j < a+1; j++) {

    /* aggiornare imax se condizione verificata */
    if( freq[j] > freq[imax] ) imax = j;

  }

  /* graficare l'istogramma */
  for(j=0; j < a+1; j++) {

    /* ora stampare un numero di = proporzionale al valore di freq[j] 
       NB: freq[j]/freq[imax] e` divisione tra interi e verrebbe sempre 0
      se non si fa il casting a float
    */
    Nstar = NSTARMAX * ( (float) freq[j]/freq[imax] );

    /* prima scrivere il valore di media */
    printf("%3d: ", j);

    /* poi stampare = */
    for(istar=0; istar<Nstar; istar++) {
      printf("=");
    }

    /* andare a capo per il prossimo valore di media */
    printf("\n");

  } /* fine ciclo per graficare l'istogramma */

  return 0;

} /*fine main() */


/* definizione di genInt(int a, int b) */
int genInt(int a, int b) {

   return lrand48()%(b-a+1);

}
