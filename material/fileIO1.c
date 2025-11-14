#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define LEN 10

int main() {

  FILE* fp;

  srand48( time(0) );

  // == nome del file ===
  char fname[100];
  printf("nome file (max 100 caratt): ");
  scanf("%s", fname);

  printf("hai inserito: %s\n\n", fname);

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
  for(int i=0; i<LEN; i++) {
    double x = -1. + 2.*lrand48()/RAND_MAX;

    // scrittura sul file in formato ASCII
    fprintf(fp, "%d \t %lf\n", i+1, x);
    
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

  int index;
  double dati[LEN]={0};

  // lettura di dati dal file e salvati in array con fscanf()
  // formato simile a scanf: solo tipo senza specifcare numero di decimali

  // riempimento di array con numeri casuali
  for(int i=0; i< LEN; i++) {

    
    fscanf(fp, "%d  %lf", &index, &dati[i]);

    printf("i: %d\t index: %d\t valore: %f\n", i, index, dati[i]);
  
  }

  fclose(fp);
  
}
