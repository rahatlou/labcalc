#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define Nexp 100
#define x0 0
#define y0 1

/*dichiarazione delle funzioni da utilizzare ai fini del programma*/
void genCirc(double, double, double, double, double*, double*);
void contaPepe(int, int*, int*, int*);
void media();

int main() {

  /*dichiarazione variabili da tastiera*/
  int N, A1, B1, C1, A[Nexp], B[Nexp], C[Nexp];
  int i, j;
  float NA, NB, NC;
  double x, y;
  srand48(time(0)); 

  /*descrizione del programma*/

  printf("Questo programma simula la posizione dei grani di pepe su delle mattonelle\n");

  /*richiesta all'utente il numero N dei granelli di pepe*/ 
  do{
    printf("inserisci valore di N tra 330 e 550:");
    scanf("%d" ,&N);

    if(N<330 || N>550){
      printf(" errore\n ");
    }
  } while(N<330 || N>550);

  /*simulazione di 100 esperimenti nei quali si determina il numero dei granelli di pepe nelle singole mattonelle*/

  for(j=0; j<Nexp; j++) {
    for(i=0; i<N; i++) {
      genCirc(x0,y0,x0,y0,&x,&y);
      contaPepe(N,&A1,&B1,&C1);
    }
    /*memorizzazione in array*/    
    A[j]=A1;
    B[j]=B1;
    C[j]=C1;
  }
  /*calcolo della media dei granelli di pepe nelle singole mattonelle*/
  media(A,B,C,Nexp,&NA,&NB,&NC);
  
  /*stampa delle singole medie*/
  printf("media mattonella A: %.2f\n", NA);
  printf("media mattonella B: %.2f\n", NB);
  printf("media mattonella C: %.2f\n", NC);
  return(0);
}

/*la funzione genera la posizione di un granello di pepe*/
void genCirc(double a, double b, double c, double d, double *x, double *y){
  *x=((double)lrand48()/RAND_MAX)*(b-a)+a;
  *y=((double)lrand48()/RAND_MAX)*(d-c)+c;
}

/*la funzione conta i granelli di pepe*/
void contaPepe(int n, int *A, int *B, int *C){
  int A1=0, B1=0, C1=0;
  int i;
  double a=x0, b=y0, c=x0, d=y0, x, y;
  for(i=0; i<n; i++) {
    genCirc(a,b,c,d,&x,&y);
    if(x<=0.5 && y<=0.5) {
      A1++;
    }
    if(x<=0.5 && y>0.5 && y<=1.) {
      B1++;
    }
    if(x>0.5 && x<=1. && y>0.5 && y<=1.) {
      C1++;
    }
  }
  *A=A1;
  *B=B1;
  *C=C1;
}

/*la funzione calcola la media dei granelli di pepe nelle singole mattonelle*/
void media(int *a, int *b, int *c, int n, float *ma, float *mb, float *mc){
  int i;
  int m1=0, m2=0, m3=0;
  for(i=0; i<n; i++){
    m1 += a[i];
    m2 += b[i];
    m3 += c[i];
  }
  *ma = m1/n;
  *mb = m2/n;
  *mc = m3/n;
}
