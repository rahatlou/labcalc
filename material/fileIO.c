#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define LEN 10

int main() {

  FILE* fp;
  char fname[] = "esempio.txt";

  double dati[LEN]={0};
  double* pd;
  
  srand48( time(0) );


  //============================
  //  scrittura formattata su file
  //============================

  // apertura del file in scrittura
  fp = fopen( fname, "w+" );

  // controllo che il file sia aperto correttamente
  if(fp == NULL ) {
    printf("problema nella creazione di %s... exit\n", fname);
    exit(-1);
  }

  // riempimento di array con numeri casuali
  for(pd=dati; pd<dati+LEN; pd++) {
    *pd = -1. + 2.*lrand48()/RAND_MAX;
  }

  // scrittura sul file in formato ASCII
  int n =1;
  for(pd=dati; pd<dati+LEN; pd++) {
    fprintf(fp, "%d\t%lf\n", n++, *pd);
  }

  // chiusura del file
  fclose(fp);

  //============================
  //  lettura dal file
  //  NB: bisogna sapere a priori il numero massimo di dati da leggere
  //============================

  // apertura del file in lettura
  fp = fopen( fname, "r+" );

  // controllo corretta apertura. ad esempio errore se nome errato o file inesistente
  if(fp == NULL ) {
    printf("problema in apertura di |%s|... controlla se esiste. exit\n", fname);
    exit(-1);
  }

  int casella[LEN];
  double valore[LEN]; 
  // riempimento di array con numeri casuali
  for(int i=0; i< 10; i++) {
    // lettura di dati dal file e salvati in array con fscanf()
    // formato simile a scanf: solo tipo senza specifcare numero di decimali
    // come scanf() richiede puntatori
    fscanf(fp, "%d  %lf", casella+i, valore+i);
    printf("i: %d\t casella: %d\t valore: %f\n", i, *(casella+i), *(valore+i));
  
  }

  fclose(fp);
  
}
