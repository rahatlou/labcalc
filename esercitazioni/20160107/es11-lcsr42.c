#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define NMIN 330
#define NMAX 550
#define R 0.77
#define RIP 100
#define L 0.5


void genCirc (double*, double*);
int contaPepe (double, double);
double media (int*);

int main() {
  int n, i, j, mat;
  int A[RIP]={0}, B[RIP]={0}, C[RIP]={0};
  double x, y, NA, NB, NC;

  srand48(time(0));
  printf ("Questo programma simula la distribuzione di N granelli di pepe su delle mattonelle\n");

  printf ("Inserire il numero di granelli di pepe caduti (compreso tra %d e %d): ", NMIN, NMAX);
  do{
    scanf ("%d", &n);
    if (n<NMIN || n>NMAX) printf ("Input errato, ripeti\n");
  } while (n<NMIN || n>NMAX);

  /*for (i=0; i<RIP; i++) {
    A[i]=0;
    B[i]=0;
    C[i]=0;
    }*/

  for (i=0; i<RIP; i++) {
    for (j=0; j<n; j++) {
      genCirc(&x, &y);
      mat=contaPepe(x,y);
      if (mat==1) A[i]++;
      if (mat==2) B[i]++;
      if (mat==3) C[i]++;
    }
  }
  
  NA=media(A);
  NB=media(B);
  NC=media(C);

  printf ("La media dei granelli di sabbia caduti nella prima mattonella e': %.2lf\n", NA);
  printf ("La media dei granelli di sabbia caduti nella seconda mattonella e': %.2lf\n", NB);
  printf ("La media dei granelli di sabbia caduti nella terza mattonella e': %.2lf\n", NC);
  
  
  exit (0);
}

void genCirc (double* x, double* y) {

  do {
    *x=((double)lrand48()/RAND_MAX)*2*R-R;
    *y=((double)lrand48()/RAND_MAX)*2*R-R;
  } while (sqrt((*x)*(*x)+(*y)*(*y))>R);
}


int contaPepe (double x, double y) {
  if (x<=L && y<=L && x>=0 && y>=0) return 1;     //in A
  if (x<=L && y>L && x>=0) return 2;              //in B
  if (x>L && y>L) return 3;                       //in C
  return 0;                           // nulla
}

double media (int X[]) {
  int i, somma=0;
  
  for (i=0; i<RIP; i++) {
    //somma+=X[i];
    somma+=*(X+i);
  }
  return (((double)somma)/RIP);
}
