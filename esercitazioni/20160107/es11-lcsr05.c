#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define R 0.77
#define EXP 100
void genCirc(double*, double*);
double casuale(double, double);
void contaPepe(double, double,int*,int*, int*);
double  media(int*);
int main() {
  int N, i, j, A[EXP]={0}, B[EXP]={0}, C[EXP]={0} ;
  double x, y, NA, NB ,NC;
  srand48(time(0));
  printf("il programma simula la caduta di grani di pepe\n");
  printf("inserisci ora il numero di grani di pepe tra 330 e 550\n");
  /*richiesta dati*/
  do {
    scanf("%d", &N);
    if (N<330 || N>550) {
      printf("valore errato, ritenta\n");
    }
  } while (N<330 || N>550);
  /* ciclo sugli esperimenti*/
  for(i=0; i<EXP; i++) {
    /* ciclo che simula la caduta del pepe*/
    for (j=0; j<N ; j++) {
      genCirc(&x, &y);
      contaPepe(x, y, A+i, B+i, C+i);
    }
  }
  /* calcolo delle medie*/
  NA=media(A) ;
  NB=media(B) ;
  NC=media(C) ;
  /*stampa i risultati*/
  printf("il numero medio di granelli sulla mattonella A vale: %lf\n il numero medio di granelli sulla mattonella B vale: %lf\n il numero medio di granelli sulla mattonella C vale: %lf\n", NA, NB, NC);
  exit(0);
}

double casuale(double a, double b) {
  return a+(b-a)*((double) lrand48()/RAND_MAX);
} 
void genCirc(double* xp, double* yp) {
  double x, y;
  /*genera coordinate entro i cerchio*/
  do{
 x =casuale(-R, R);
 y =casuale(-R, R);
  } while (x*x+y*y>R*R);
  *xp=x;
  *yp=y;
}
void contaPepe(double x, double y,int* A,int* B, int* C) {
  /*controlla la mattonella A*/
  if(x>=0 && x<=0.5 && y>=0 && y<=0.5) {
    *A+=1;
  }
/*controlla la mattonella B*/
  if (x>=0 && x<=0.5 && y>=0.5 && y<=1) {
    *B+=1 ;
  }
/*controlla la mattonella C*/
  if( x>=0.5 && x<=1 && y>=0.5 && y<=1) {
    *C+=1 ;
  }
}
double  media(int* mat) {
  int i ;
  double media=0;
  /* calcolo della media*/
  for (i=0; i<EXP; i++) {
    media+=*(mat+i) ;
  }
  return media/EXP;
}

