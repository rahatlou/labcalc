#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LATO 0.5
#define MIN 330
#define MAX 550
#define RAG 0.77
#define NRIP 100

void Gencirc(double *,double *,int);
void contaPepe(double, double,int *,int *,int *);
void media(int [],int [],int [],double *,double *,double *);

int main() {

  double X,Y,NA=0,NB=0,NC=0;
  int N,i,k,a,b,c,A[NRIP],B[NRIP],C[NRIP];

  srand48(time(0));

  printf("Questo programma simula la caduta di granelli di pepe sulle mattonelle di una cucina.\n");

  do {

    printf("\nInserire il numero intero di granelli caduti compreso tra %d e %d: ",MIN,MAX);
    scanf("%d",&N);

    if (N<MIN || N>MAX) printf("Errore, reinserire numero valido.\n");

  } while (N<MIN || N>MAX);

  for (k=0;k<NRIP;k++) {

    a=0;

    b=0;

    c=0;

     for (i=0;i<N;i++) {

       Gencirc(&X,&Y,N);

       contaPepe(X,Y,&a,&b,&c);

     }
       A[k]=a;

       B[k]=b;

       C[k]=c;

       printf ("A:%d B:%d C:%d\n",A[k],B[k],C[k]);

  }

  media(A,B,C,&NA,&NB,&NC);

  printf("Media di granelli caduti nelle mattonelle:\n A:%.3lf\t B:%.3lf\t C:%.3lf\n",NA,NB,NC);


  exit(0);

}

void Gencirc(double *A,double *B,int C) {

    do {
      /*i numeri non soddisfano mai la condizione di cadere sulla mattonella a ma non siamo risuciti a corregerlo*/

      *A=((double)lrand48()/(double)RAND_MAX)*(RAG-(-RAG))+(-RAG); 

      *B=((double)lrand48()/(double)RAND_MAX)*(RAG-(-RAG))+(-RAG);

    } while ((*A)*(*A)+(*B)*(*B)<=RAG*RAG);

}

void contaPepe(double q,double w,int *e,int *r,int *t) {

  if (q>0 && q<0.5 && w<0.5 && w>0) (*e)++;

  else if (q>0 && q<=0.5 && w>0.5) (*r)++;

  else if  (q>0.5 && w>0.5) (*t)++;

}

void media(int A[NRIP],int B[NRIP],int C[NRIP],double *NA,double *NB,double *NC) {

  int y,S=0,Sb=0,Sc=0;
 
  for (y=0;y<NRIP;y++) {

    S+=A[y];

    Sb+=B[y];

    Sc+=C[y];

  }

  *NA=S/NRIP;

  *NB=Sb/NRIP;

  *NC=Sc/NRIP;

}
 
