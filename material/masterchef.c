#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<math.h>

#define R    0.77
#define LATO 0.5
#define NMIN 330
#define NMAX 550
#define NEXP 1000

/* 3 pt: interfaccia funzione: corretta scelta di tipo e argomenti */
void contaPepe(double, double, int* , int*, int* );

/* 2 pt interfaccia funzione */
void genCirc(double, double*, double*);

/* 1 pt: interfaccia funzione */
double media(int*, int);


int main() {

  /* 1 pt: array di lunghezza giusta */
 int N;
 int A[NEXP], B[NEXP], C[NEXP], Out[NEXP];
 double fout[NEXP];
 int i,Na,Nb,Nc,iexp;
 double x,y;

 // 1 pt: inizializzare il generatore
 srand48( time(0) );

  // 2 pt : apertura file
  FILE* fp;
  char fname[100] = "grani.txt";
  fp = fopen(fname, "w");
  if(!fp) {
      printf("errore in apertura di %s ... exit\n", fname);
      exit(-1);
  }


 printf("benvenuti a Masterchef!\n");


 /* 2 pt: corretta acquisizione di N */
 do{
   printf("numero grani di sale %d <= N <= %d: ", NMIN, NMAX);
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

  if(!((iexp+1)%50))
   printf("esperimento: %5d NA: %3d  NB: %3d  NC: %3d frazione fuori: %.3f\n", 
          iexp+1, Na, Nb, Nc,(N-Na-Nb-Nc)/(double)N); 

   /* 2 pt: salvare i dati nella casella giusta dell'array */
   A[iexp] = Na;
   B[iexp] = Nb;
   C[iexp] = Nc;
   // nunmero di grani e frazione di grani fuori dalle mattonelle sono due quantita` diverse
   // basta conoscere uno dei due numeri
   Out[iexp] = N-Na-Nb-Nc; // numero di grani fuori dalle mattonelle
   fout[iexp] = (double)Out[iexp]/N; // frazione di grani fuori dalle mattonelle

   // 1 pt: scrittura del file
   fprintf(fp, "%d \t %d \t %d\n", Na, Nb, Nc);
 }  
 printf("fine degli esperimenti con %5d grani\n", N);

 // 1 pt: chiusura del file
 fclose(fp);
 printf("dati scritti con successo in %s\n",fname);

 /* 2 pt: calcolo delle medie e la stampa del risultato */
 printf("------------------------------------------\n");
 printf("numero medio grani mattonella A: %-.1f\n", media(A,NEXP) );
 printf("numero medio grani mattonella B: %-.1f\n", media(B,NEXP) );
 printf("numero medio grani mattonella C: %-.1f\n", media(C,NEXP) );
 double avg_fout = media(Out,NEXP)/N;
 printf("frazione grani fuori da A,B,C: %-.3f (%.1f%s)\n", avg_fout, 100.*avg_fout,"%"  );

}

void contaPepe(double x, double y, int* Na, int*Nb, int* Nc) {

  /* 6 pt: corretto conteggio di granelli di pepe; 2 pt per ciascuna mattonella */

  // prima i casi sicuramete fuori
  if(x<0. || y<0.|| x > 2*LATO || y > 2*LATO) return;

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



