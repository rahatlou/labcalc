#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<math.h>

#define R    0.77
#define LATO 0.5
#define NMIN 330
#define NMAX 550
#define NEXP 100

/* 3 pt: interfaccia */
void contaPepe(double, double, int* , int*, int* );

/* 2 pt: interfaccia */
void genCirc(double, double*, double*);

/* 1 pt: interfaccia */
double media(int*, int);


int main() {

  /* 1 pt: array di lunghezza giusta */
 int N;
 int A[NEXP], B[NEXP], C[NEXP];
 int i,Na,Nb,Nc,iexp;
 double x,y;

 srand48( time(0) );


 /* 1 pt: stampa messaggio */
 printf("benvenuti alla simulazione della caduta del pepe!\n");


 /* 2 pt: corretta acquisizione di N */
 do{
   printf("numero di grani di sabbia %d <= N <= %d: ", NMIN, NMAX);
   scanf("%d", &N);
 } while( N<NMIN || N>NMAX );


 /* 2 pt: ciclo corretto e di lunghezza giusta */
 for(iexp=0; iexp<NEXP; iexp++) {

   /* 2 pt: azzerare i valori per ciascun esperimento */
   Na = Nb = Nc = 0;

   
   /* 1 ciclo corretto per generare e contare */
   for(i=0; i<N; i++) {
   
     genCirc(R, &x,&y);
     contaPepe(x,y, &Na, &Nb, &Nc);
   }

   printf("esperimento: %3d NA: %5d  NB: %5d  NC: %5d totale nelle mattonelle: %5d\n", iexp, Na, Nb, Nc,Na+Nb+Nc); 

   /* 2 pt: salvare i dati nella casella giusta dell'array */
   A[iexp] = Na;
   B[iexp] = Nb;
   C[iexp] = Nc;
 }

 /* 2 pt: calcolo delle medie e la stampa del risultato */
 printf("fine degli esperimenti\n");
 printf("----------------------\n");
 printf("numero medio di grani di pepe nella mattonella A: %.1f\n", media(A,NEXP) );
 printf("numero medio di grani di pepe nella mattonella B: %.1f\n", media(B,NEXP) );
 printf("numero medio di grani di pepe nella mattonella C: %.1f\n", media(C,NEXP) );

}

void contaPepe(double x, double y, int* Na, int*Nb, int* Nc) {

  /* 6 pt: corretto conteggio di granelli di pepe; 2 pt per ciascuna mattonella */

  if(x<0. || y<0.) return;

  if(x<LATO) {

    if(y<LATO) (*Na)++;
    else (*Nb)++;

  }else{
   
    if(y>=LATO) (*Nc)++;    
  }

  return;
}


void genCirc(double r, double*x, double* y) {

  /* 3 pt: corretta generazione nel cerchio */
  do {
   *x = -r+2*r*lrand48()/RAND_MAX;
   *y = -r+2*r*lrand48()/RAND_MAX;
  } while( (*x)*(*x) + (*y)*(*y) > r*r );
  return;
}

double media(int* vec, int n) {

  /*3 pt: corretto calcolo della media */
  int i;
  double m = 0.;
  for(i=0; i<n; i++) {
    m += vec[i];
  }
  m /= n;
  return m;
}



