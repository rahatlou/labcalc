#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NMAX 100000

double uniforme(double,double);
double gensin(double,double,int*);
double genexp(double, double, int*);

// da fare come esercizio: implementare una funzione a piacere e la relativa generazione 
double myf(double);
double genmyf(double, double, int*);


int main() {

  srand48( time(0) );
  double a=0, b=M_PI;

  // max di sin(x) e e^(-x) per x in [0,PI]
  double ymax = 1.;


  // numero effettivo di numeri generatori per ottenere
  // NMAX numeri con la distribuzione giusta
  int npiatto=0, nsinx=0, nexpx=0, nmyfx=0;

  FILE* fp;
  char fname[] = "numeri.txt";
  fp = fopen(fname,"w+");
  if(!fp) {
    printf("errore a creare %s... exit\n", fname);
    exit(-1);
  }
      
  int nprint = NMAX/10;
  for(int i=0; i<NMAX; i++) {

    if(! ((i+1)%nprint) ) printf("generazione: %3d\n", i+1);

    double x1, x2, x3;

    // distribuzione uniforme
    x1 = uniforme(a,b);
    npiatto++;
    
    x2 = gensin(a,b, &nsinx); 

    x3 = genexp(a, b, &nexpx);
    
    // scrivi output
    fprintf(fp, "%.10f\t %.10f\t %.10f\n", x1, x2, x3);
    
  } // ciclo generazione

  printf("numero generazioni per piatto: %6d \t sin(x): %6d \t exp(-x): %6d\n",
	 npiatto, nsinx, nexpx);


  fclose(fp);
  
} // main

double uniforme(double a, double b) {
  return a+(b-a)*lrand48()/RAND_MAX;
}

double gensin(double a, double b, int* counter) {
  double x,y, ymax=1.;
  do{
    (*counter)++;
    x = uniforme(a,b); 
    y = uniforme(0,ymax);
  } while ( y > sin(x) );
  return y;
}

double genexp(double a, double b, int* counter) {
  double x,y, ymax=1.;
  do{
    (*counter)++;
    x = uniforme(a,b); 
    y = uniforme(0,ymax);
  } while ( y > exp(-x) );
  return y;
}


// da implementare: una propria funzione
double myf(double x) {
    
    return -1.;
}

// da implementare: generatore di myf() tra a e b
double genmyf(double a, double b, int* counter) {
  return -1;
}

  
