#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NMAX 100000

double uniforme(double,double);

int main() {

  srand48( time(0) );
  double a=0, b=M_PI;

  // max di sin(x) e e^(-x) per x in [0,PI]
  double ymax = 1.;

  // array per salvare i numeri generati  da utilizzare 
  double piatto[NMAX];
  double sinx[NMAX];
  double expx[NMAX];
  double myfx[NMAX];

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
    
  int i;
  double x,y;
  
  for(i=0; i<NMAX; i++) {

    if(! ((i+1)%1000) ) printf("generazione: %3d\n", i+1);
    // distribuzione uniforme
    x = uniforme(a,b);
    *(piatto+i) = x;
    npiatto++;
    
    do{
      nsinx++;
      x = uniforme(a,b); 
      y = uniforme(0,ymax);
    } while ( y > sin(x) );
    *(sinx+i) = x;

    do{
      nexpx++;
      x = uniforme(a,b); 
      y = uniforme(0,ymax);
    } while ( y > exp(-x ) );
    *(expx+i) = x;

    
    // scrivi output
    fprintf(fp, "%.10f\t %.10f\t %.10f\n", piatto[i], sinx[i], expx[i]);
    
  } // ciclo generazione
  printf("numero generazioni per piatto: %6d \t sin(x): %6d \t exp(-x): %6d\n",
	 npiatto, nsinx, nexpx);


  fclose(fp);
  
} // main

double uniforme(double a, double b) {
  return a+(b-a)*lrand48()/RAND_MAX;
  
}

//double myf(double x) {
//  return fabs(x)*sin(x)
//}
  
