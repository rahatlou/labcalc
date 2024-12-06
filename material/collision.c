#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//probabilita di interazione
#define XSEC 0.70 
// raggio massimo di interazione
#define RMAX 0.1 
// valore massimo per A e B
#define LMAX 10
// numero massimo di atomi 
#define NMAX 10000


/* bonus 1 pt: per ciascuna funzione aggiuntiva e sensata */


double uniforme(double,double);
double getDouble(char*,double,double);
int getInt(char*,int, int);

// genera un punto nell'ellisse
void ellisse(double,double,double*, double*);

// genera posizione atomi
void atomi(int, double[NMAX][2], double, double);

// verifica interazione di un proiettile con gli atomi
int interazione(double*, double, double[NMAX][2], int);

// calcola distanza tra due punti
double distanza(double*, double*);


int main() {

  FILE* fp;

  double bersaglio[NMAX][2]; /* posizione dei bersgli. solo array statici in C */
  double xp[2]; // posizione di un punto generico

  int N, MA;
  double R, A, B;

  int nchar;
  char c, fname[100];

  int i, nhit, nhitTot, nhitMax;


  /* 1 pt: inizializza */
  srand48(time(0));


  /* 2 pt: condizioni corrette per i dati dall'utente */

  MA = getInt("numero di atomi M", 1, NMAX);
  N = getInt("numero particelle incidenti N", 1, MA);

  A = getDouble("semiasse maggiore A: ", 0, LMAX);
  B = getDouble("semiasse minore B: ", 0, A);
  R = getDouble("raggio interazione: ", 0, RMAX);

  /* genera atomi di bersaglio */
  atomi(MA, bersaglio, A, B);

  /* 2 pt: nome del file come variabile */
  printf("inserire nome di file (max 100 caratteri) per scrivere posizione atomi: ");
  scanf("%s", fname);

  /* 1 pt: apertura file */
  fp = fopen(fname,"w+");
  if(!fp) {
    printf("file %s non valido. abort.\n", fname);
    exit(-1);
  }

  /* 2 pt: scrittura su file */
  for(i=0; i<MA; i++) {
    /* 1 pt: scrittura su file */
    fprintf(fp, "%.3f \t %.3f\n", bersaglio[i][0], bersaglio[i][1]);
  }
  /* 1 pt: chiusura file */
  fclose(fp);


  /* 1 pt: ciclo su bersagli */
  nhitTot = 0;
  nhitMax = 0;
  for(i=0; i<N; i++) {

    /* 2 pt: genera proittile e controlla interazione */
    ellisse(A,B, xp, xp+1);
    nhit = interazione(xp, R, bersaglio, MA);

    nhitTot += nhit;
    if(nhit>nhitMax) nhitMax = nhit;

  }

  /* 3 pt: calcolo numero medio e max di interazioni per proiettile con giusta inizializzione */
  printf("Numero medio di interazioni per proiettile: %.1f\n", (double)nhitTot/N);
  printf("Numero max di interazione per un proiettile: %d\n", nhitMax);

  /* fine del programma */
  return 0;

}

/* 1 pt: prendi double */
double getDouble(char* msg, double min, double max) {
  double x;
  do{
    printf("inserisci %s compreso tra (%.2f,%.2f): ", msg, min, max);
    scanf("%lf", &x);
  } while(x<=min || x>=max);
  return x;
}


/* 1 pt: prendi intero */
int getInt(char* msg, int min, int max) {
  int x;
  do{
    printf("inserisci %s compreso tra [%d,%d]: ", msg, min, max);
    scanf("%d", &x);
  } while(x<min || x>max);
  return x;
}

/* 2 pt: generazione numeri casuali */
double uniforme(double a, double b) {
  return a + (b-a)*lrand48()/RAND_MAX;
}

double distanza(double p1[2], double p2[2]) {
  return sqrt( (p1[0]-p2[0])*(p1[0]-p2[0]) +  (p1[1]-p2[1])*(p1[1]-p2[1])  );
}


/* 1 pt: interfaccia corretta */
// A, B: semiassi dell'ellisse
// x,y le coordinate da generare
void ellisse(double A,double B, double* x, double* y) {
  /* 2 pt: generazione punto nell'ellisse */
  double dist;
  do{
    *x = uniforme(-A, A);
    *y = uniforme(-B, B);
    dist = (*x/A)*(*x/A) + (*y/B)*(*y/B);
  } while( dist > 1 ); 

}


/* 2 pt: interfaccia funzione */
// M: numero di atomi
// bers: array 2D per immagazzinare le posizioni di atomi
// A,B: semiassi dell'ellisse dove generare gi atomi
void atomi(int M, double bers[NMAX][2], double A, double B) {
  int i;

  /* 2 pt: generazione atomi e salvare nell'array */
  for(i=0; i<M; i++) {

    ellisse(A, B, *(bers+i), *(bers+i)+1);

    /* modo alternativo per passare elementi dell'array */
    /* ellisse(A, B, &bers[i][0], &bers[i][1]); */
  }
}

// xp: posizione del proiettile come array di lunghezza 2
// R: raggio di interazione
// bers: array 2D con le posizioni di atomi
// M: mumero di atomi
// la funzione restituisce il numero di interazioni per questa particella
int interazione(double xp[2], double R, double bers[NMAX][2], int M) {

  int i,n=0;
  double p;

  /* 3 pt: condizione di interazione */
  for(i=0; i<M; i++) {
    if( distanza(xp, *(bers+i)) < R && uniforme(0,1) < XSEC) n++;
  }
  /* printf("  numero interazioni: %d\n", n); */

  return n;
}
