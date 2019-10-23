#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 100
void genCirc(double, double*, double*);
int getint(char*,int,int);
void contaPepe(double,double,int*,int*,int*,double,int);
double media(int*);



int main(){
  srand48(time(0));
  int i,j, N, A[MAX]={0};
  int B[MAX]={0};
  int C[MAX]={0};
  double NA,NB,NC,x,y,R= 0.77;
  double l=0.5;
  int a=0,b=0,c=0;
  printf("Questo programma simula la distribuzione di grani di pepe caduti sul pavimento\n");

  N = getint( "numero di grani caduti",550,330);

  for(j=0;j<MAX;j++){
    A[j]=0;
    B[j]=0;
    C[j]=0;

    for(i=0;i<N;i++){

     genCirc(R,&x,&y);
   
     contaPepe(x,y,&a,&b,&c,l,N);
       }

  A[j] = a;
  B[j] = b;
  C[j] = c;

  }

  NA = media(A);
  NB = media(B);
  NC = media(C);



  printf("numero medio di grani in mattonella A: %.3lf\nnumero medio di grani in mattonella B: %.3lf\nnumero medio di grani in mattonella C: %.3lf\n",NA,NB,NC);


  exit(0);
}



int getint(char msg[],int max,int min){

  int x;

  do{
    printf("Inserire %s compreso tra %d e %d:\n", msg,min,max);
    scanf("%d",&x);
    if(x<min || x>max){ printf("errore! ripetere\n");}
  }while(x<min || x> max);

  return x;
}

void genCirc(double R,double *x,double *y){

  do{
    *x = ((double)lrand48()/RAND_MAX)*(2*R)-R;
    *y = ((double)lrand48()/RAND_MAX)*(2*R)-R;
  }while((*x)*(*x) + (*y)*(*y) > R*R);

}


void contaPepe(double x,double y, int *a,int *b,int *c,double l,int N){

    if(x>0 && x<l && y>0 && y<l){ (*a)++; }
    if(x>0 && x<l && y>l) { (*b)++; }
    if(x>l && y>l){ (*c)++;}

  
}


double media(int D[]){

  int i;
  double x=0;
  for(i=0;i<MAX;i++){

    x += D[i];
  }

  return x/=MAX;

}
