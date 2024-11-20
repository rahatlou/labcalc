#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define LEN 10

int main() {

  FILE* fp;
  char fname[] = "esempio.txt";

  double dati[LEN]={0};
  double* pd;
  
  srand48( time(0) );
  
  fp = fopen( fname, "w+" );

  if(fp == NULL ) {
    printf("problema nella creazione di %s... exit\n", fname);
    exit(-1);
  }

  for(pd=dati; pd<dati+LEN; pd++) {
    *pd = -1. + 2.*lrand48()/RAND_MAX;
  }

  int n =1;
  for(pd=dati; pd<dati+LEN; pd++) {
    fprintf(fp, "%d\t%lf\n", n++, *pd);
  }

  fclose(fp);
}
