#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define C 10000.
#define NMAX 100
#define T 26

/* 2 pt : interfaccia funzione */
double profitloss(double);

/* 2 pt : interfaccia */
void result(int,double,double*, double*);

int main() {
  // inserimento dati
  int N = 0;
  double P = 0.;
  int i = 0;
  double capitale[NMAX] = {C, 0.};
  double profitti[NMAX] = {0.};   /* 2 pt : array giusti */
  double profTot = 0.;

  srand48(time(0) );
  
  do {
    printf("Inserisci il numero N di sessioni di borsa da simulare con 5 < N < 100: ");
    scanf("%d", &N);
  } while ((N < 5) || (N >= 100));  /* 2 pt */
  
  do {
    printf("Inserisci il massimo profitto P che si puo' ottenere in una singola sessione con 0 < P <= 5: ");
    scanf("%lf", &P);
  } while ( (P <= 0) || (P > 5) ); /* 2 pt */


  
  printf("inizio  capitale: %.2f profitto: %.2f\n", i, capitale[i], profitti[i]);

  /* 3 pt: con indice corretto */
  for (i = 1; i <= N; i++) {


    result(i, P, capitale, profitti) ;
    
    profTot += profitti[i];  /* 2 pt : calcolo profitto totale */
  }

  /* 2 pt : stampa messaggi finali */
  if (profTot > 0.) {
    printf("Profitto lordo: %.2f\n", profTot);
    printf("Profitto netto: %.2f\n", profTot * (1. - T/100.));   /* 2 pt : calcolo profitto netto */
  }

  printf("Capitale residuo: %.2f\n", capitale[N]);  /* 2 pt : stampa capitale residuo */
}

double profitloss(double P) {
  // restituisce un numero compreso tra -P/100 e P/100
  return (-P + 2.*P*lrand48()/RAND_MAX)*0.01;    /* 3 pt : generazione casuale */
}

void result(int i, double p, double* capitale, double* profitti) {
  
  capitale[i] = capitale[i - 1] * (1. + profitloss(p)); /* 2 pt : calcolo capitale */
  profitti[i] = capitale[i] - capitale[i - 1];  /* 2 pt : calcolo profitto */

  /* 1 pt : stampa */
  printf("passo i: %d capitale: %.2f profitto: %.2f\n", i, capitale[i], profitti[i]);

  if (profitti[i] < 0)     profitti[i] = 0.; /* 2 pt : profitto negativo non permesso */
  
}
