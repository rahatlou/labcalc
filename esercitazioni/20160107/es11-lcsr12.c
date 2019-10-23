#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define Gmin 330
#define Gmax 550
#define R 0.77
#define d 100

void genCirc(float*, float*);
void contaPepe(float, float, int *, int *, int *);
float media(int data[]);
int getInt(int, int);

int main(){

  int N, i, j, A[d], B[d], C[d];
  float x, y, NA, NB, NC;
  srand48(time(0));
  
  for(i=0;i<d;i++){
    A[i]=0;
    B[i]=0;
    C[i]=0;
  }

  printf("Questo programma simula la caduta di grani di pepe in un cerchio di raggio 0.77 m e ne calcola il numero medio nelle mattonelle A, B e C.\n");

  N=getInt(Gmin, Gmax);
 
  for(i=0;i<d;i++){
    for(j=0;j<N;j++){
      genCirc(&x, &y);

      contaPepe(x, y,  A+i, B+i, C+i);
    }
  } 

  NA=media(A);
  NB=media(B);
  NC=media(C);

  printf("Media mattonella A:%.2f\nMedia mattonella B:%.2f\nMedia mattonella C:%.2f\n", NA, NB, NC);



  exit(0);
}

int getInt(int A, int B){
  int N;
    do{
    printf("Inserire numero grani di pepe caduti nell intervallo [330,550]:\t");
    scanf("%d", & N);
    if(N<A || N>B)
      printf("Numero non valido, ripetere.\n");
  }while(N<A || N>B);
    return N;
}

void genCirc(float *x, float *y){
  do{
    *x=(2*R)*lrand48()/RAND_MAX-R;
    *y=(2*R)*lrand48()/RAND_MAX-R;
  }while((*x)*(*x)+(*y)*(*y)>R*R);
}

void contaPepe(float x, float y, int *A, int *B, int *C){

  if(x>0 && x<0.5 && y>0 && y<0.5){
    (*A)++;
  }else if(x>0 && x<0.5 && y>0.5 && y<1.0){
    (*B)++;
  }else if(x>0.5 && x<1.0 && y>0.5 && y<1.0){
    (*C)++;
  }
}

float media(int data[]){
  int c;
  float media=0;
  for(c=0;c<d;c++){
    media+=data[c];
  }
  return media/d;
}

