#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<math.h>

#define NMIN 1000
#define NMAX 100000


/* 3 pt interfaccia */
double fdist(double x, double lamnbda);

/* 3 pt: interfaccia */
double hitAndMiss(double);


double uniforme(double, double);

int main() {

  /* 1 pt */
  srand48( time(0) );
  
  double lambda, x;
  int nexp, i;

  /* 2 pt */
  do{
    printf("inserire valore di lambda ]0.0,1.0]: ");
    scanf("%lf", &lambda);
  }while(lambda<=0 || lambda>1.);

  /* 2 pt */
  do{
    printf("inserire numero di punti da generare [%d,%d]: ", NMIN, NMAX);
    scanf("%d", &nexp);
  }while(nexp<NMIN || nexp>NMAX);


  /* 2 pt : ciclo */
  for(i=0; i<nexp; i++) {

    /* 2 pt : corretta chiamata */
    x = hitAndMiss(lambda);
    
  }

 return 0;
}


double uniforme(double a, double b) {
  /* 3 pt : corretta generazione num casuali unif */
  return a+(b-a)*lrand48()/RAND_MAX;
}

double fdist(double x, double lambda) {
  /* 3 pt : corretta funzione fdist */
  return x*exp(-x/lambda)/lambda/lambda;
}

double hitAndMiss(double lambda) {

  double x, y;

  /* 2 pt : corretta scelta di do/while */
  do{
    x = uniforme(0.,1.);
    /* 2 pt : corretti estremi per y */
    y = uniforme(0, fdist(lambda,lambda) );

    /* 3 pt : corretta condizone */
  } while( y > fdist(x,lambda) );

  /* 2 pt : corretta stampa dei valori richiest  */
  printf("x: %.3f \t f(x): %.3f \t y: %.3lf \n", x,  fdist(x,lambda), y );
  
  return x;
}

  

  

  
