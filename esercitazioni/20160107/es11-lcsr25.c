#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define R 0.77
#define L 0.5
#define MAX 100
#define S 550

void genCirc(float*, float*, float);
void contaPepe(float); 
void media(int*, int*, int*, float*, float*, float*);

int main(){

  int N, i;
  int A[S], B[S], C[S];
  float x, y;


  printf("Questo programma simula la posizione di N granelli di pepe caduti a terra e calcola il numero di granelli caduti in 3 mattonelle\n");
  
  do{

  printf("Inserisci valore intero di N granelli di pepe caduti compreso tra 330 e 550 : \n");
  scanf("%d", &N);

  if(N<=330 || N>=550){
    printf("Errore, valore non valido, inserire nuovamente : \n");
  }

  } while(N<=330 || N>=550);
   
  A[S]=0;
  B[S]=0;
  C[S]=0;
 

 for(i=0; i<MAX; i++){
    contaPepe(L);

    A[i]=A;
    B[i]=B;
    C[i]=C;

 }



}

void genCirc(float* x, float* y, float r){
 

  do{
  *x=(lrand48()/RAND_MAX)*2*r;
  *y=(lrand48()/RAND_MAX)*2*r;

   

 }while(x*x+y*y > r*r);
}

void contaPepe(float l){
  int* A; 
  int* B;
  int* C;
  float x, y;

  *A=0;
  *B=0;
  *C=0;

  genCirc(&x, &y, R);
  
  if(x>0 || x<l && y>0 || y<l){
    *A++;
  }else if( x>0 || x<L && y> l || y<2*l){
    *B++;
  }else if( x>l || x<2*l && y>l || y<2*l){
    *C++;
  }
}








