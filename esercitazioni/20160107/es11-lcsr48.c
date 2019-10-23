#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void genCirc(double *, double *);
void contaPepe(double, double, int *, int *, int *);
#define NEXP 100
double media(int A[NEXP]);


int main(){
  int n, i, a, b, c, j, A[NEXP], B[NEXP], C[NEXP];
 
  double x, y, NA, NB, NC;
  
  srand48(time(0));
 
  for(i=0;i<NEXP;i++){
    A[i]=0;
    B[i]=0;
    C[i]=0;
  }

  printf("Questo programma simula la posizione di  grani di pepe caduti ad un cuoco e calcola quanti ne sono caduti in determinate mattonelle.\n");
  printf("\n");
  do{
    printf("Inserire il numero di grani di pepe caduti tra 330 e 550, estremi compresi:\n");
    scanf("%d",&n);
    if(n<330 || n>550){
      printf("ERRORE! Inserire di nuovo il numero.\n");
    }
  }while(n<330 || n>550);
  
  for(j=0;j<NEXP;j++){
    a=0;
    b=0;
    c=0;
    for(i=0;i<n;i++){
      genCirc(&x,&y);
      contaPepe(x, y, &a, &b, &c);
     
    }
    A[j]=a;
    B[j]=b;
    C[j]=c;
  }
  NA=media(A);
  NB=media(B);
  NC=media(C);

  printf("Media A=%lf \t Media B=%lf \t Media C=%lf\n",NA, NB, NC); 

  exit(0);

}

void genCirc(double *x, double *y){
  do{
    *x=((float)lrand48()/RAND_MAX)*(1.54)-0.77;
    *y=((float)lrand48()/RAND_MAX)*(1.54)-0.77;
  }while((*x*(*x))+(*y*(*y))>(0.77*0.77));
}

void contaPepe(double x, double y, int *a, int *b, int *c){
  if(x<=0.5 && x>=0 && y<=0.5 && y>=0){
    (*a)++;
  }
  else if(x>=0 && x<=0.5 && y>0.5 && y<=1){
    (*b)++;
  }
  else if(x>0.5 && x<=1 && y>=0.5 && y<=1){
    (*c)++;
  }
} 

double media(int A[]){
  int i;
  double media;
  for(i=0;i<NEXP;i++){
    media+=A[i];
  }
  media/=NEXP;
  return(media);
}
