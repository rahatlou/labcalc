#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NEXP 100

void genCirc(float x, float y, float coord[]);
float uniforme(float, float);
void contaPepe(float coord[], int A[], int B[], int C[], int k);
float media(int A[]);

int main() {
  int N, A[NEXP], B[NEXP], C[NEXP], i=0, k=0;
  float x, y, coord[2], NA, NB, NC;
 
  printf("Questo programma simula la posizione e ne calcola il numero di grani di pepe caduti su tre mattonelle.\n");
  do{
    printf("Inserisca il numero intero N di grani caduti in [330,550]: \n");
    scanf("%d", &N);
    if(N<330||N>550)
      printf("Dato inserito non valido, ripeta.\n");
  } while(N<330||N>550);
  srand48(time(0));
  for(k=0;k<NEXP;k++){
    A[k]=0;
    B[k]=0;
    C[k]=0;
  for(i=0;i<N;i++) {
    genCirc(x, y, coord);
 
  contaPepe(coord, A, B, C, k);

  }
  }
  NA=media(A);
  NB=media(B);
  NC=media(C);
  printf("Il valore medio di grani caduti sulla mattonella A: %f\nIl valore medio di grani caduti sulla mattonella B: %f\nIl valore medio di grani caduti sulla mattonella C: %f", NA, NB, NC);
}

void genCirc(float x, float y, float coord[]) {
  float a, b;
  a=-0.77;
  b=0.77;
  do{
  x=uniforme(a, b);
  y=uniforme(a, b);
  } while((x*x+y*y)>b*b);
  coord[0]=x;
  coord[1]=y;
}

float uniforme(float a, float b) {
  float p;
  p=((float)lrand48()/RAND_MAX)*(b-a)+a;
  return p;
}

void contaPepe(float coord[], int A[], int B[], int C[], int k) {
  
 if(coord[0]>=0 && coord[0]<=0.5 && coord[1]>=0 && coord[1]<=0.5)
   A[k]+=1;
 else if(coord[0]>=0 && coord[0]<=0.5 && coord[1]>=0.5 && coord[1]<=1.0)
   B[k]+=1;
 else if(coord[0]>=0.5 && coord[0]<=1.0 && coord[1]>=0.5 && coord[1]<=1.0)
   C[k]+=1;
 }

float media(int A[]) {
  int i=0;
  float NA;
  NA=0;
  for(i=0;i<NEXP;i++) {
    NA+=A[i];
  }
  NA/=NEXP;
  return NA;
}




 
