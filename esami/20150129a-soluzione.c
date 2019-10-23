#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KAPPA 100
#define ALPHA 10

#define NBMIN 10
#define NBMAX 20

#define LMIN 1.5
#define LMAX 15.6 


#define DMIN 210.
#define DMAX 1050.

#define TMIN 610.5
#define TMAX 1225.3

#define NEXP 50

float uniform(float,float);
void barca(float,float,float*,float*);
void calcolo(float*,int);


int main() {

  int Nb, i, iexp;
  float Mn=0, tn=0, 
   length, dist;
  float tTot[NEXP]={0}, pesceTot[NEXP]={0};

  srand48( time(0) );

  printf("simulazione del porto di Mazara del Vallo\n");


  do{
    printf("inserire il numero di barche (tra 10 e 20 inclusi):");
    scanf("%d", &Nb);
  } while( Nb < NBMIN || Nb > NBMAX );


  for(iexp=0; iexp<NEXP; iexp++) {

     for(i=0; i< Nb; i++) {
       length = uniform(LMIN, LMAX);
       dist   = uniform(DMIN,DMAX);
       barca( length, dist, &tn, &Mn ); 
       tTot[iexp]     += tn;
       pesceTot[iexp] += Mn;
     } /* barche */

  } /* esperimenti */

  printf("Tempo totale per le operazioni (secondi):\n");
  calcolo(tTot, NEXP);


  printf("Pesce scaricato al porto (kg):\n");
  calcolo(pesceTot, NEXP);


  printf("fine del programma.\n");
  return 0;
}

float uniform(float a, float b) {
  return a + (b-a)*lrand48()/RAND_MAX;
}


void barca(float l, float d, float* t, float* m) {

  float p;

  p = 1.-0.25*(lrand48()%4);
  *m = p * KAPPA * l;
  *t = sqrt(2*d*(*m)/ALPHA) + uniform(TMIN,TMAX);

}

void calcolo(float* data, int n) {

  float mu=0, sig=0;
  int i;

  for(i=0;i<n;i++) {
    mu += data[i];
  }
  mu /= n;
  printf("media: %.2f\n", mu);


  for(i=0;i<n;i++) {
    sig += (data[i]-mu)*(data[i]-mu);
  }
  sig = sqrt(sig/(n-1));
  printf("deviazione standard: %.2f\n", sig);

}
