#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define R 0.77
#define L 0.5    //Metri
#define NMIN 330
#define NMAX 550
#define RIP 100

double uniforme(double, double);

int getint(int, int);

void genCirc(double *,double *);

void contaPepe(int, int *A, int *B, int *C); 

double media(int D[RIP]);

int main(){

  int N,j;
  double NA, NB, NC;
  int A[RIP]={0}; 
  int B[RIP]={0};
  int C[RIP]={0}; 

  srand48(time(0));

  printf("Questo programma simula la caduta di grani di pepe sul pavimento\n");
  printf("Inserire N grani di pepe caduti [%d;%d]: ", NMIN, NMAX); 
  N=getint(NMIN,NMAX);

  for(j=0; j<RIP; j++){
    contaPepe(N,&A[j],&B[j],&C[j]);  
  }
  /*Ciclo conta Pepe*/

  NA=media(A);
  NB=media(B);
  NC=media(C);
  /*Calcolo Medie*/

  printf("Media sulla mattonella:\nA-->%.2lf\nB-->%.2lf\nC-->%.2lf\n",NA,NB,NC);

  exit(0);
}

int getint(int a, int b){

  int x;
  do{
    scanf("%d",&x);
    if(x<a || x>b) printf("Valore inserito non valido. Ripetere\n");
  }while(x<a || x>b);

  return x;
}

double uniforme(double a,double b){

  return a+((double)lrand48()/RAND_MAX)*(b-a);

}

void genCirc(double *x,double *y){

  do{
    (*x)=uniforme(-R,R);
    (*y)=uniforme(-R,R);
  }while((fabs(*y))>sqrt(R*R+(*x)*(*x)));

}

void contaPepe(int N, int *A, int *B, int *C){

  int i;
  double x, y;

  for(i=0; i<N; i++){
    
    genCirc(&x,&y);
    if(x>=0 && x<=L){
      if(y>=0 && y<L){
	(*A)++;
      }
      else if(y>=L){
	(*B)++;   
      }
    }
    else if(x>L && y>=L){
      (*C)++;
    }
  }
}
	
double media(int D[RIP]){

  int k;
  double med=0;

  for(k=0; k<RIP; k++){
    med+=D[k];
  }
  med/=RIP;
  return med;

}

