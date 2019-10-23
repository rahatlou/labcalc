#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define Nmin 330
#define Nmax 550
#define R 0.77
#define Nexp 100

void genCirc (float *, float *);
void contaPepe (float , float, int *, int *, int *);
float media (int []);

int main() {
  int N, i, j, nA, nB, nC;
  int A[Nexp], B[Nexp], C[Nexp];
  srand48(time(NULL));

  float x, y;
  printf("Questo programma calcola la media dei grani "
	 "di pepe caduti per ogni mattonella\n");
  
  do {
    printf("Inserire il numero di granelli caduti "
	   "compreso fra %d e %d:\t", Nmin, Nmax);
    scanf("%d", &N);
    if (N<Nmin || N>Nmax)
      printf("Valore non consentito\n");
  } while (N<Nmin || N>Nmax);
  for (i=0;i<Nexp;i++) {
    A[i] = B[i] = C[i] = 0;
    nA = nB = nC = 0;
    for (j=0;j<N;j++) {
      genCirc(&x, &y);
      contaPepe(x,y,&nA,&nB, &nC);
    }
    A[i] = nA;
    B[i] = nB;
    C[i] = nC;
  }
  printf("Media di A:\t%.2f\nMedia di B:\t%.2f\nMedia di C:\t%.2f\n", media(A), media(B), media(C));
  exit(0);
}

void genCirc (float * x, float * y) {
  float a, b, I;
  a = ((float)lrand48()/RAND_MAX)*2*R-R;
  I = R*R - a*a;
  I = sqrt(I);
  b = ((float)lrand48()/RAND_MAX)*2*I-I;
 
  *x = a;
  *y = b;
}

float media (int array[Nexp]) {
  int i, n=0;
  float m;
  for (i=0;i<Nexp;i++)
    n += array[i];
  m = (float)n/Nexp;
  return m;
}

void contaPepe (float x, float y, int * a, int * b, int * c) {
  if ((x>=0 && x<=0.5)&&(y>=0 && y<=0.5))
    *a += 1;
  else if ((x>=0 && x<=0.5)&&(y>0.5 && y<=1))
    *b += 1;
  else if ((x>0.5 && x<=1)&&(y>0.5 && y<=1))
    *c += 1;
}
