#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUSTMAX 7
#define FIGMAX 220
#define FIGMIN 180

int packet(int, int*, int*);
void update(int*, int*, int*);

int main() {

  int Nfig, choice, spesapi = 0, spesapa = 0, checkpi, checkpa;
  int paolo[FIGMAX] = {0}, pietro[FIGMAX] = {0};
  int npi, npa, fpi[BUSTMAX] = {0}, fpa[BUSTMAX] = {0};

  srand48(time(0));

  printf("Questo programma simula due bambini che completano due album di figurine scambiandosi o meno i doppioni.\n");

  do {
    printf("Inserire il numero massimo di figurine nell'album:");
    scanf("%d", &Nfig);
  } while (Nfig<FIGMIN || Nfig>FIGMAX);

  do {
    printf("Digitare 0 se si vuole scambiare i doppioni, altrimenti digitare 1.\n");
    scanf("%d", &choice);
  } while (choice<0 || choice>1);
  
  /*  do {*/
    packet(Nfig, fpi, &npi);
    packet(Nfig, fpa, &npa);
    
    
    /* } while (checkpi == 0 || checkpa == 0);*/

}



void packet(int Nfig, int* fp[], int* n) {

  int i;
  (*n) = lrand48()%4 + 4;
  fp[0] = lrand48()%Nfig;
  for (i=1; i<(*n); i++) {
    do {
      fp[i] = lrand48%Nfig;
    } while (fp[i] == fp[i-1]);
    printf("%d  %d\n", fpi[0], fpi[i]);
  }

}



void update(int* np, int array[FIGMAX], int fp[BUSTMAX]) {

  int i;
  for (i=0; i<(*np); i++) {
    array[fp[i]]++;
  }

}
