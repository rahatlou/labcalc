#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LATO 0.5
#define RAGGIO 0.77
#define N_MAX 550
#define N_MIN 330
#define LEN 100

void genCirc(double* x, double* y, double r);
void contaPepe(double x, double y, int* NA, int* NB, int* NC);
double media(int N, int* array);

int main () {
  int N, i, NA=0, NB=0, NC=0, j;
  double x, y;
  int A[LEN] = {0};
  int B[LEN] = {0};
  int C[LEN] = {0};
  srand48(time(0));
  printf("Il programma simula la posizione dei grani e ne calcola il numero caduto sulle tre mattonelle.\n");
 do{
   printf(" Inserire il numero di grani caduti nell'intervallo 330<=N<=550, N: ");
   scanf("%d",&N);
   if(N<N_MIN || N>N_MAX) {
     printf(" Il valore non e' compreso nell'intervallo"); 
   }
 } while (N<N_MIN || N>N_MAX);
 for(i=0; i<LEN; i++) {
   for(j=0; j<N; j++) {
     genCirc(&x, &y, RAGGIO);
     contaPepe(x, y, &NA, &NB, &NC);
   }
   printf(" Esperimento %3d -- NA: %5d,-- NB: %5d,--  NC: %5d,-- mattonelle: %5d.\n", i, NA, NB, NC, (NA+NB+NC));
   A[i] =  NA;
   B[i] =  NB;
   C[i] =  NC;
 }
 printf(" Il valore medio dei grani su A e': %lf \n", media(LEN, A));
 printf(" Il valore medio dei grani su B e': %lf \n", media(LEN, B));
 printf(" Il valore medio dei grani su C e': %lf \n", media(LEN, C));
 exit(0);
}

void genCirc(double* x, double* y, double r) {
  do{
    *x=-r+2*r*lrand48()/RAND_MAX;
    *y=-r+2*r*lrand48()/RAND_MAX;
  } while ((*x)*(*x)+(*y)*(*y)> r*r);
}


void contaPepe(double x, double y, int* NA, int* NB, int* NC){
  if(x<0. || y<0.) ;
  if(x<0.5){
    if(y<0.5) (*NA)++; 
    else (*NB)++;
  } else {
    if(y>0.5) (*NC)++;
  }	
 
}

double media(int N, int* array){
  double z=0;
  int k;
  for(k=0; k<N; k++) {
    z += array[k];
  }
  z /= N;
  return z;
}
