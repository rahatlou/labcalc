#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define XSEC 0.70
#define RMAX 0.1
#define LMAX 10
#define NMAX 10000


/* bonus 1 pt: per ciascuna funzione aggiuntiva e sensata */


float uniforme(float,float);
float getFloat(char*,float,float);
float getInt(char*,int, int);

void ellisse(float,float,float*, float*);
void atomi(int, float[NMAX][2], float, float);
int interazione(float*, float, float[NMAX][2], int);
float distanza(float*, float*);


int main() {

  FILE* fp;

  float bersaglio[NMAX][2]; /* posizione dei bersgli */
  float xp[2];

  int N, M;
  float R, A, B;

  int nchar;
  char c, fname[100];

  int i, nhit, nhitTot, nhitMax;


  /* 1 pt: inizializza */
  srand48(time(0));


  /* 2 pt: condizioni corrette per i dati dall'utente */

  M = getInt("numero di atomi M", 0, NMAX+1);
  N = getInt("numero particelle incidenti N", 0, M);

  A = getFloat("semiasse maggiore A:", 0, LMAX);
  B = getFloat("semiasse minore B:", 0, A);
  R = getFloat("raggio interazione", 0, RMAX);

  /* genera atomi di bersaglio */
  atomi(M, bersaglio, A, B);

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
  for(i=0; i<M; i++) {
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
    nhit = interazione(xp, R, bersaglio, M);

    nhitTot += nhit;
    if(nhit>nhitMax) nhitMax = nhit;

  }

  /* 3 pt: calcolo numero medio e max di interazioni per proiettile con giusta inizializzione */
  printf("Numero medio di interazioni per proiettile: %.1f\n", (float)nhitTot/N);
  printf("Numero max di interazione per un proiettile: %d\n", nhitMax);

  /* fine del programma */
  return 0;

}

/* 1 pt: prendi float */
float getFloat(char* msg, float min, float max) {
  float x;
  do{
    printf("inserisci %s compreso tra (%.2f,%.2f): ", msg, min, max);
    scanf("%f", &x);
  } while(x<=min || x>=max);
  return x;
}


/* 1 pt: prendi intero */
float getInt(char* msg, int min, int max) {
  int x;
  do{
    printf("inserisci %s compreso tra (%d,%d): ", msg, min, max);
    scanf("%d", &x);
  } while(x<=min || x>=max);
  return x;
}

/* 2 pt: generazione numeri casuali */
float uniforme(float a, float b) {
  return a + (b-a)*lrand48()/RAND_MAX;
}

float distanza(float p1[2], float p2[2]) {
  return sqrt( (p1[0]-p2[0])*(p1[0]-p2[0]) +  (p1[1]-p2[1])*(p1[1]-p2[1])  );
}


/* 1 pt: interfaccia corretta */
void ellisse(float A,float B, float* x, float* y) {
  /* 2 pt: generazione punto nell'ellisse */
  float dist;
  do{
    *x = uniforme(-A, A);
    *y = uniforme(-B, B);
    dist = (*x/A)*(*x/A) + (*y/B)*(*y/B);
  } while( dist > 1 ); 

}


/* 2 pt: interfaccia funzione */
void atomi(int M, float bers[NMAX][2], float A, float B) {
  int i;

  /* 2 pt: generazione atomi e salvare nell'array */
  for(i=0; i<M; i++) {

    ellisse(A, B, *(bers+i), *(bers+i)+1);

    /* modo alternativo per passare elementi dell'array */
    /* ellisse(A, B, &bers[i][0], &bers[i][1]); */
  }
}

int interazione(float* xp, float R, float bers[NMAX][2], int M) {

  int i,n=0;
  float p;

  /* 3 pt: condizione di interazione */
  for(i=0; i<M; i++) {
    if( distanza(xp, *(bers+i)) < R && uniforme(0,1) < XSEC) n++;
  }
  /* printf("  numero interazioni: %d\n", n); */

  return n;
}
