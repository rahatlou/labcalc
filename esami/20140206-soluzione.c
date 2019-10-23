#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define NMIN   290
#define NMAX   400
#define NESAMI  25
#define LMAX    8.


int poisson(double);
double casuale(double, double);
void frazioni(double*, int*, int, double*, double*, double*);

int main() {

  int i, j, Nstudenti, voto, min_voto, max_voto;
  double lambda;
  double media[NMAX]={0.};
  int ripetuto[NMAX]={0};

  double falto,fbasso,frip = 0.;


  srand48(time(0));

  /* 2 pt: acquisizione Nstudenti */
  do {
    printf("Inserisci numero di studenti tra [%d,%d]:", NMIN, NMAX);
    scanf("%i", &Nstudenti);
  } while( Nstudenti < NMIN || Nstudenti > NMAX );


  for(i=0; i<Nstudenti; i++) {

    /* 2 pt: azzerare */
    media[i] = 0;
    ripetuto[i] = 0;

    /* 1 pt: generazione lambda*/ 
    lambda = casuale(0.,LMAX);

    /* 3 pt: calcolo min e max ed opportuno azzeramento */
    min_voto=30;
    max_voto = 18;


    for(j=0; j<NESAMI; j++) {

       /* 3 pt: generazione voto con condizione */
       do{
        voto = 30 - poisson(lambda);
        if(voto<18) ripetuto[i]++;
       } while( voto < 18 );

       if(voto > max_voto) { max_voto = voto; }
       if(voto < min_voto) { min_voto = voto; }

       media[i] += voto;
    }

    /* escludere il voto min e max */
    media[i] -= (min_voto+max_voto);

    /* 2 pt: calcolo della media con NESAMI-2 */
    media[i] /= (NESAMI-2);

    //printf("media[%2d]: %.1lf \t lambda: %.1lf esami ripetuti:%2d\n", i, media[i], lambda, ripetuto[i]);

  }

  frazioni(media, ripetuto, Nstudenti, &falto, &fbasso, &frip);

  /* 2 pt: stampa valori */
  printf("Frazione studenti con media >= 29: %.3lf\n", falto);
  printf("Frazione studenti con media <= 26: %.3lf\n", fbasso);
  printf("Frazione studenti con almeno un esame ripetuto: %.3lf\n", frip);


}/* main */

/* 2 pt: interfaccia funzione e corretto funzionamento */
double casuale(double min, double max) {
  return min + (max-min)*lrand48()/RAND_MAX;
}

/* 2 pt: interfaccia funzione */
int poisson(double l) {


  /* 2 pt: corretto azzeramento */
  double cum = exp(-l);
  double p = 1.;

  int k = 0 ;

  /* 2 pt: corretta condizione e calcolo k */
  do {
   k++;
   p *= casuale(0.,1.);
  } while( p > cum );

  return k-1;

}

/* 3 pt: interfaccia funzione con puntatori */
void frazioni(double* m, int* r, int N, double* fa, double* fb, double* fr) {

  int i;

  /* 1 pt: azzerare prima di contare */
  *fa = *fb = *fr = 0.;

  for(i=0; i<N; i++) {

    if(m[i]>= 29.) (*fa)++;
    if(m[i]<= 26.) (*fb)++;
    if(r[i]>0)     (*fr)++;
  }

  /* 3 pt: calcolo delle frazioni */
  *fa /= N;
  *fb /= N;
  *fr /= N;

}

