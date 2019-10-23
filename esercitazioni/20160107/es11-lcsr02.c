#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define inf 330
#define sup 550
#define R 0.77
#define Nexp 100

double randUniforme(double, double);
void genCirc(double*, double*);
void contaPepe(double, double, int*, int*, int*);
void media(int*, int*);

int main() {
  int NA, NB, NC;
  int A[Nexp], B[Nexp], C[Nexp];
  int i,j,N,gA,gB,gC;
  double x,y;
  srand48(time(NULL));
  printf("\nIl programma simula la caduta di N grani di pepe e calcola quanti di questi cadono su ciascuna di tre mattonelle A, B, C.\n");
  
  do {
    printf("\nInserire N tra %d e %d: ", inf, sup);
    scanf("%d", &N);
    if(N<inf || N>sup) printf("Errato. Riprovare.");
  } while(N<inf || N>sup);

  for(j=0; j<Nexp; j++) {
    gA=0;
    gB=0;
    gC=0;
    for(i=0; i<N; i++) {
      genCirc(&x, &y);
      contaPepe(x, y, &gA, &gB, &gC);
    }
    A[j]=gA;
    B[j]=gB;
    C[j]=gC;
  }
  
  media(A, &NA);
  media(B, &NB);
  media(C, &NC);

  printf("\nNumero medio di grani in A, B, C rispettivamente:   %d   %d   %d \n\n", NA, NB, NC);

  return 0;
}

double randUniforme(double a, double b) {
  return ((double) lrand48()/RAND_MAX)*(b-a) + a;
}

void genCirc(double* x, double* y) {
  double X, Y;
  do {
    *(x)=randUniforme(-R, R);
    *(y)=randUniforme(-R, R);
      X=*(x);
      Y=*(y);
  } while(X*X + Y*Y > R*R);
}

void contaPepe(double x, double y, int* gA, int* gB, int* gC) {
  if((0<x && x<0.5) && (0<y && y<0.5)) {
    *(gA) +=1;
  } else if((0<x && x<0.5) && (0.5<y && y<1.0)) {
    *(gB) +=1; 
  } else if(x>0.5 && (0.5<y && y<1.0)) {
    *(gC) +=1;
  }
}

void media(int* valori, int* avg) {
  int S=0,i;
  for(i=0; i<Nexp; i++) {
    S+=valori[i];
  }
  S/=Nexp;
  *(avg)=S;
}
