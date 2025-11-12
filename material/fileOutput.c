#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define LEN 10

int main() {

  FILE* fp;
  char fname[] = "esempio.txt";
  
  srand48( time(0) );

  // apertura del file in scrittura
  fp = fopen( fname, "w+" );

  // controllo che il file sia aperto correttamente
  if(fp == NULL ) {
    printf("problema nella creazione di %s... exit\n", fname);
    exit(-1);
  }

  // scrittura sul file in formato ASCII
  for(int i=0; i<LEN; i++) {

    // simile a printf ma richiede nome della variabile FILE
    // scrive 2 valori casuali per riga (intero e razionale)
    fprintf( fp, "%d \t %.5f \n", lrand48()%6 +1 , drand48() ); 
  }

  // chiusura del file
  fclose(fp);
   
} // fine main
