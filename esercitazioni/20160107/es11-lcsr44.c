#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define TOT 100
void genCirc(double *x, double *y);
void contaPepe(double *x, double *y, int N , int *A , int *B , int *C);
double media(int data[TOT]);

int main() {

  srand48(time(0));
  int N,i,AA[TOT],AB[TOT],AC[TOT],A,B,C;
  double x,y,na,nb,nc;
  

  printf("Il programma simula la posizione dei grani di pepe caduti su tre mattonelle e ne calcola il numero\n");
  printf("Inserire il valore intero N = numero di grani caduti compresi tra 330 e 550\n");
  do{
    scanf("%d",&N);
    if(N>550||N<330){
      printf("Valore errato, ripeti!\n");
    }
  }while(N>550||N<330);

  for(i=0;i<TOT;i++){
    genCirc(&x,&y);
    contaPepe(&x,&y,N,&A,&B,&C);
   &A=AA[i];
   &B=AB[i];
   &C=AC[i];
  }
  na=media(AA);
  nb=media(AB);
  nc=media(AC);
  printf("Media grani A = %lf  B = %lf  C = %lf\n",na,nb,nc);

  return 0;
}


void genCirc(double *x, double *y){
  do{
    *x=(1.0-0)+0*((double)lrand48()/RAND_MAX);
    *y=(1.0-0)+0*((double)lrand48()/RAND_MAX);
  }while(*x>0.5 && *y<0.5);
}


void contaPepe(double *x, double *y, int N , int *A , int *B , int *C){
  int i;
    


  for(i=0;i<N;i++){ 
  if(*x<=0.5 && *y<=0.5){

    *A++;
  } 
 else if(*x<=0.5 && *y>0.5){ 
   
   *B++;
  }
 else{
   
   *C++;
  }
 

  }
}


double media(int data[TOT]){
  int s,i;
  double med;
 
  for(i=0;i<TOT;i++){
    s+=data[i];
  }
  med=s/TOT;
  return med;
}

