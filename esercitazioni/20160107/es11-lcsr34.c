#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Nmin 330
#define Nmax 550
#define R 0.77
#define LEN 100

void genCirc(double*, double*);
void contaPepe(double, double, int A[], int B[], int C[], int);
void media(int A[], int B[], int C[], double*, double*, double*);

int main(){
  int N, i, j, A[LEN]={0}, B[LEN]={0}, C[LEN]={0};
  double x, y, NA, NB, NC;
  srand48(time(0));
  
  printf("Questo programma calcola il numero di granelli di pepe caduti su 3 mattonelle A, B, C di dimensioni date.\n");
  
  do{
    printf("Dichiarare numero N di grani di pepe compreso in [%d,%d]: ", Nmin, Nmax);
    scanf("%d",&N);
  }while(N<Nmin || N>Nmax);
  
  for(i=0; i<LEN; i++) {
    for (j=0; j<N; j++) {
      genCirc(&x, &y);
      
      contaPepe(x, y, A, B, C, i);
    }
  }

  media(A, B, C, &NA, &NB, &NC);
  printf("\nMedia granelli caduti su A: %lf\nMedia granelli caduti in B: %lf\nMedia granelli caduti in C: %lf\n\n", NA, NB, NC);

  
}


void genCirc(double *x, double *y) {
  do{
    (*x)=(((double)lrand48()/RAND_MAX)*2*R)-R;
    (*y)=(((double)lrand48()/RAND_MAX)*2*R)-R;
  }while((*x)*(*x)+(*y)*(*y)>R*R);
  
}


void contaPepe(double x, double y, int A[LEN], int B[LEN], int C[LEN], int i) {
  if ((x>=0 && x<= 0.5) && (y>=0 && y<=0.5)) {
    A[i]++;
  } else if ((x>=0 && x<= 0.5) && (y>0.5 && y<=0.77)) {
    B[i]++;
  } else if ((x>0.5 && x<= 0.77) && (y>0.5 && y<=0.77)){
    C[i]++;
  }
}

void media(int A[LEN], int B[LEN], int C[LEN], double *na, double *nb, double *nc) {
  int i;
  (*na)=0;
  (*nb)=0;
  (*nc)=0;
  for(i=0;i<LEN;i++) {
    (*na)+=A[i];
    (*nb)+=B[i];
    (*nc)+=C[i];
  }
  (*na)/=LEN;
  (*nb)/=LEN;
  (*nc)/=LEN;
}
