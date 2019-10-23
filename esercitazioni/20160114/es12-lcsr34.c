#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUSTMAX 7
#define FIGMAX 220
#define FIGMIN 180

void check(int*, int*, int);
void packet(int, int fp[], int*);
void update(int*, int*, int*);
void exchange(int*, int*, int); 

int main() {

  int Nfig, choice, spesapi = 0, spesapa = 0, checkpi = 0, checkpa = 0, i;
  int paolo[FIGMAX] = {0}, pietro[FIGMAX] = {0}, doppionipa = 0, doppionipi = 0;
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
  
  do {
    packet(Nfig, fpi, &npi);
    if(checkpi==0){
      spesapi++;
    }
    packet(Nfig, fpa, &npa);
    if(checkpa==0){
      spesapa++;
    }
    if (checkpi == 0) {
      update(&npi, pietro, fpi);
    }
    if (checkpa == 0) {
      update(&npa, paolo, fpa);
    }
    

    if ((choice == 0) && ((checkpi == 0) && (checkpa == 0))) {
    exchange(pietro, paolo, Nfig);
  }


    check(&checkpa, paolo, Nfig);
    check(&checkpi, pietro, Nfig);
    
  
    } while (checkpi == 0 || checkpa == 0);
  for (i=0; i<Nfig; i++) {
    if (paolo[i] > 1) {
      doppionipa++;
    } else if (pietro[i] > 1) {
      doppionipi++;
    }
  }
printf("Paolo ha comprato %d pacchetti, ha speso %d euro e ha %d doppioni.\n Pietro ha comprato %d pacchetti, ha speso %d euro e ha %d doppioni.\n", spesapa, spesapa, doppionipa, spesapi, spesapi, doppionipi);
}



void packet(int Nfig, int fp[], int *n) {

  int i;
  (*n) = lrand48()%4 + 4;
  fp[0] = lrand48()%Nfig;
  for (i=1; i<(*n); i++) {
    do {
      fp[i] = lrand48()%Nfig;
    } while (fp[i] == fp[i-1]);
    
  }

}



void update(int* np, int array[FIGMAX], int fp[BUSTMAX]) {

  int i;
  for (i=0; i<(*np); i++) {
    array[fp[i]]++;
   
  }

}



void check(int* controllo, int array[], int Nfig) {

  int i, complete = 0;
  for (i=0; i<Nfig; i++) {
    if (array[i] > 0) {
      complete++;
    }
  }
  if (complete == Nfig) {
    (*controllo) = 1;
  } else {
    (*controllo) = 0;
  }
}



void exchange(int A[], int B[], int Nfig) {

  int i, scambioA, scambioB, cedoA, cedoB;
  for (i=0; i<Nfig; i++) {
    scambioA=scambioB=cedoA=cedoB=0;
    if (A[i] == 0) {
      scambioA++;
    } else if (B[i] > 1) {
      cedoA++;
    }
    if (B[i] == 0) {
      scambioB++;
    } else if (A[i] > 1) {
      cedoB++;
    }
    if (scambioA == cedoB) {
      A[i]++;
      B[i]--;
    } else if (scambioB == cedoA) {
      B[i]++;
      A[i]--;
    }
  }

}
