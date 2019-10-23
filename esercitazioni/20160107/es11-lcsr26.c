#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define r 0.77
#define NEXP 100
void genCirc (float*, float*);
void contaPepe (float, float, int*, int*, int*);
float media(int []);


int main(){
  
  int N, i, j, A, B, C, pA, pB, pC;
  float X, Y, mA, mB, mC;  
  srand48(time(0));
  float *x, *y;
  int a[NEXP]={0};
  int b[NEXP]={0};
  int c[NEXP]={0};
  int *contA, *contB, *contC;
  x = &X;
  y = &Y;
  contA = &A;
  contB = &B;
  contC = &C;
  
  printf("Calcolo grani di pepe in un'area\n");
  do{
    printf("Inserire il numero di grani di pepe da considerare, compreso tra 330 e 550:\n");
    scanf("%d", &N);
    if(N<330 || N>550) printf("Errore! Valore non valido.\n");
  }while(N<330 || N>550);
  
  for(j=0; j<NEXP; j++){
  pA = 0;
  pB = 0;
  pC = 0;
  for(i=0; i<N; i++){
    A = 0;
    B = 0;
    C = 0;
    genCirc(&X, &Y);
    contaPepe(X, Y, &A, &B, &C);
    pA += A;
    pB += B;
    pC += C;
  }
  a[j]=pA;
  b[j]=pB;
  c[j]=pC;
 }

  mA = media(&a);
  mB = media(&b);
  mC = media(&c);
  printf("I valori medi sono: A=%.2f B=%.2f C=%.2f\n", mA, mB, mC);

  exit(0);
}

void genCirc (float*x, float*y){
  float d;
  float X, Y;
  do{
    X = (float)lrand48()/RAND_MAX;
    Y = (float)lrand48()/RAND_MAX;
    d = sqrt((X*X)+(Y*Y));
  }while(d>r);
  *x = X;
  *y = Y;
}


void contaPepe (float X, float Y, int*contA, int*contB, int*contC){
  int z=0, s=0, k=0;
  
   if(X>0 && X<0.5 && Y>0 && Y<0.5){
     z++;
     *contA = z; 
   }
   if(X>0 && X<0.5 && Y>0.5 && Y<1){
     s++;
     *contB = s;
   }
   if(X>0.5 && X<1 && Y>0.5 && Y<1){
     k++; 
     *contC = k;
   }
 }

float media(int a[NEXP]){
   int i, s=0;
   float m;
   
   for(i=0; i<NEXP; i++){
     s += a[i];
   }
   m = (float)s/NEXP;
   return m;
 }
   
