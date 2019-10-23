#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define LEN 100
#define R 0.77

void genCirc(float* ,float*);
void contaPepe(float,float,int*,int*,int*);
void media(int*,int*,int*,float*,float*,float*);

int      main()       {

  int N,cond,a,b,c,i,j,A[LEN],B[LEN],C[LEN];
  float NA=0,NB=0,NC=0;
  float x,y;
  srand48(time(0));
  
  printf("Questo programma simula la caduta di N granelli di pepe su un pavimento.\n");

  do{

    printf("Inserire il numero N di granelli in [330,550]:\n");
    scanf("%d",&N);
    cond=(N<330)||(N>550);
 
    if(cond) printf("Errore! ");

    }  while(cond); 

   for(j=0;j<LEN;j++) {  
  
     a=0;
     b=0;
     c=0;

     for(i=0;i<N;i++) {

        genCirc(&x,&y);
 
        contaPepe(x,y,&a,&b,&c);

     }

  A[j]=a;
  B[j]=b;
  C[j]=c;

   }

   media(A,B,C,&NA,&NB,&NC);

   printf("Numero medio di granelli caduti in A: %.1f\n",NA);
   printf("Numero medio di granelli caduti in B: %.1f\n",NB);
   printf("Numero medio di granelli caduti in C: %.1f\n",NC);

   exit(0);

   }

void genCirc(float* x,float* y) {
  

  float dist;

  do{
    
    *x=((float)lrand48()/RAND_MAX)*(2*R)-R;
    *y=((float)lrand48()/RAND_MAX)*(2*R)-R;

    dist=sqrt((*x)*(*x)+(*y)*(*y));
 
  }  while (dist>R);
 
 
}
 
void contaPepe(float x,float y,int* a,int* b,int* c) {
  
  int condA,condB,condC;

  /* Si e' deciso convenzionalmente di considerare il lato comune tra A e B come appartenente a B e il lato comune tra B e C come appartenente a C. */

  condA=(x>=0) && (x<=0.5) && (y>=0) && (y<0.5);
  condB=(x>=0) && (x<0.5) && (y>=0.5);
  condC=(x>=0.5) && (y>=0.5);

 

  if(condA) (*a)++;
  if(condB) (*b)++;
  if(condC) (*c)++;


 

}


void media(int* A,int* B,int* C,float* NA,float* NB,float* NC) {

  int i;
 
  for(i=0;i<LEN;i++) {

    *(NA)+=*(A+i);
    *(NB)+=*(B+i);
    *(NC)+=*(C+i);

  }

  *(NA)/=LEN;
  *(NB)/=LEN;
  *(NC)/=LEN;

}

 

 

 
