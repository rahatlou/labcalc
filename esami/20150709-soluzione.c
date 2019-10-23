#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<math.h>

#define R 0.7
#define LATO 0.5
#define NMIN 400
#define NMAX 6000000
#define NEXP 10

void contaPepe(double, double, int* , int*, int* );
void genCirc(double, double*, double*);
double media(int*, int);


int main() {

 int N;
 int A[NEXP], B[NEXP], C[NEXP];
 int i,Na,Nb,Nc,iexp;
 double x,y;

 srand48( time(0) );

 do{
   printf("numero di grani di sabbia %d <= N <= %d: ", NMIN, NMAX);
   scanf("%d", &N);
 } while( N<NMIN || N>NMAX );


 for(iexp=0; iexp<NEXP; iexp++) {

   Na = Nb = Nc = 0;
   
   for(i=0; i<N; i++) {
   
     genCirc(R, &x,&y);
   
     contaPepe(x,y, &Na, &Nb, &Nc);
   
   }
   printf("esperimento: %3d NA: %5d  NB: %5d  NC: %5d totale nelle mattonelle: %5d\n", iexp, Na, Nb, Nc,Na+Nb+Nc); 
   A[iexp] = Na;
   B[iexp] = Nb;
   C[iexp] = Nc;
 }

 printf("fine degli esperimenti\n");
 printf("----------------------\n");
 printf("numero medio di grani di pepe nella mattonella A: %.1f\n", media(A,NEXP) );
 printf("numero medio di grani di pepe nella mattonella B: %.1f\n", media(B,NEXP) );
 printf("numero medio di grani di pepe nella mattonella C: %.1f\n", media(C,NEXP) );

}

void contaPepe(double x, double y, int* Na, int*Nb, int* Nc) {
  if(x<0. || y<0.) return;

  if(x<LATO) {

    if(y<LATO) (*Na)++;
    else (*Nb)++;

  }else{
   
    if(y>LATO) (*Nc)++;    
  }

  return;
}


void genCirc(double r, double*x, double* y) {
  do {
   *x = -r+2*r*lrand48()/RAND_MAX;
   *y = -r+2*r*lrand48()/RAND_MAX;
  } while( (*x)*(*x) + (*y)*(*y) > r*r );
  return;
}

double media(int* vec, int n) {

   int i;
   double m = 0.;
   for(i=0; i<n; i++) {
     m += vec[i];
   }
   m /= n;
  return m;
}



