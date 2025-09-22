#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NSAMPLE 10000
#define N 10

// generatore numeri razionali in [0,1]
double generatore_casuale ();
// campionamento di p(n)
void init_prob(double p[N]);
// generatore di interi in [0,n-1]
int generatore_interi(int n);
// generatore di numeri secondo p(n)
void metropolis (int samples[NSAMPLE], double p[N]);
// conteggio frequenza di numero generati
void frequency (int samples[NSAMPLE], double freq[N]); 

int main () {
  srand48(time(NULL));
  // inizializza array di dati
  double p[N]={0};
  double freq[N]={0};
  int samples[NSAMPLE]={0};
  
  // aprtura file per salvare i dati
  FILE *fp;
  char fname[100]= "frequency.dat";
  fp=fopen (fname, "w");
  if (!fp) {
    printf ("errore in apertura di %s \n", fname);
    exit(-1);
  } 
  
  // campionamento della distribuzione p(n)
  init_prob(p);

  // genera NSAMPLE valori secondo la distribuzione p(n)
  metropolis(samples, p);

  // conta frequenza dei valori generati
  frequency(samples, freq);
  
  printf ("%s \t %s \t\t %s \n ", "  n", "p(n)", "freq(n)");
  for (int t=0; t<N; t++) {
    // scrittura sullo schermo per controllo valori
    printf ("%2d \t %.4f \t %.4f \n ", t, p[t], freq[t]);
    // scrittura su file
    fprintf (fp, "%d \t %.4f \t %.4f \n ", t, p[t], freq[t]);
  } //for t per salvare nel file testo
  
  fclose(fp);
  printf ("dati scritti in %s \n", fname);
  
  return 0; 
} //main

// generatore casuale in [0,1]
double generatore_casuale () {
  double random;
  random=(double) lrand48 () /RAND_MAX;
  return random; 
  
} //func 1 che genera numeri casuali double fra 0 e 1

// campionamento di p(n)
void init_prob(double p[N]) {
  double norm=0;
  
  for (int i=0; i<N; i++) {
    p[i]=generatore_casuale();
    norm+=p[i];
    
  } //for i
  
  for (int j=0; j<N; j++) {
    p[j]/=norm;
   
  } //for j per normalizzare
  
} //func 2 che riempie e nornmalizza array p

// generatore di interi in [0,n-1]
int generatore_interi(int n) {
  return lrand48 () % n; 
  
} //func 3 per generare casualmente numeri interi fra 0 e n-1

// generazione di NSAMPLE secondo p(n)
void metropolis (int samples[NSAMPLE], double p[N]) {
  int n0, nk, ntmp;
  double Rk, A, y;
  
  n0=generatore_interi(N);
  samples[0]=n0; 
  
  for (int k=0; k<NSAMPLE; k++) {
    nk=samples[k];
    ntmp=generatore_interi(N);
    Rk=p[ntmp]/p[nk];

    // calcolo di A
    if (Rk<1) {
      A=Rk;
    } else {
      A=1;
    }

    // assegnare n_k+1 in base a un nuovo numero casuale
    y=generatore_casuale();
    
    if (y<=A) {
      samples[k+1]=ntmp;
    } else {
      samples[k+1]=nk;
    } 
    /*printf ("samples  %d , nk %d, k %d, ntmp %d, Rk %lf, A %lf, y %lf, samples[k+1] %d \n", samples[k], nk, k, ntmp, Rk, A, y, samples[k+1]); */
    
  } //for k
  
} //func  4


// conteggio valori generati
void frequency (int samples[NSAMPLE], double freq[N]) {
  int count[N]={0};
  
  for (int l=0; l<NSAMPLE; l++) {
    int i=samples[l];
    count[i]++;
  }
  for (int c=0; c<N; c++) {
    freq[c]=(double) count[c] / NSAMPLE;
    
  } 
  
} //func 5 per riempire l'array frequenza
