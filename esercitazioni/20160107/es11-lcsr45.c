#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

#define GMIN 330
#define GMAX 550
#define R 0.77
#define RIP 100

void genCirc(double *, double*);
void contaPepe(double, double, int *, int *, int *);
double media(int *);

int main() {

  int N, A[RIP], B[RIP], C[RIP];
  int A1, B1, C1, i, h;

  double x, y, NA, NB, NC;

  srand48(time(0));

  printf("il programma simula la caduta dei grani di pepe sul pavimento\n\n");

  printf("inserire valore numero di grani (tra %d e %d): ",GMIN,GMAX);
  do{
    scanf("%d",&N);
    if(N>GMAX || N<GMIN) printf("errore! valore non valido, reinserire: ");
  } while (N>GMAX || N<GMIN);


  for(i=0; i<RIP; i++){

    A1=B1=C1=0;

    for(h=0;h<N;h++){

      genCirc(&x,&y);
      contaPepe(x,y,&A1,&B1,&C1);
    }
    A[i]=A1;
    B[i]=B1;
    C[i]=C1;

    /*controllo dei valori*/
    //printf("A: %d\tB: %d\tC:%d\n",A[i],B[i],C[i]);
  }

  NA=media(A);
  NB=media(B);
  NC=media(C);

  printf("Media grani nelle mattonelle:\nA: %.2lf\tB: %.2lf\tC: %.2lf\n\n",NA,NB,NC);




  exit(0);

}

void genCirc(double *x, double *y){

  double ip;

  do{

  *x=((float)lrand48()/RAND_MAX)*(R+R)-R;
  *y=((float)lrand48()/RAND_MAX)*(R+R)-R;
  
  ip=sqrt(((*x)*(*x))+((*y)*(*y))); 
 
 } while(ip>R);
}

void contaPepe(double x, double y, int *A, int *B, int *C){


  if((x<=0.5 && x>=0) && (y<0.5 && y>=0)) (*A)++;
  if((x<=0.5 && x>=0) && y>=0.5) (*B)++;
  if(x>0.5 && y>=0.5) (*C)++;

}


double media(int A[]){

  int j;
double m=0;

for(j=0;j<RIP;j++){
  m+=A[j];
 }
m/=RIP;

return m;
}























