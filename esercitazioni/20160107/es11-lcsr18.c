#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define L 0.5
#define NMIN 330
#define NMAX 550
#define R 0.77
#define NEXP 100

#define PAX 0.0
#define PAY 0.0

#define PBX 0.0
#define PBY 0.5

#define PCX 0.5
#define PCY 0.5

int getInt(char*,int,int);
void genCirc(double*,double*);
void contaPepe(double,double,int*,int*,int*);
double uniforme(double,double);
double distanza ( double, double);
double media(int *);
void controlla(double,double,int*,double,double);

int main() {
  double x,y,mediaa,mediab,mediac;
  int A[NEXP]={0};
  int B[NEXP]={0};
  int C[NEXP]={0};
  int n, i,j;

  srand48(time(0));

  printf("\n\nSimulazione caduta di grani di pepe su tre piastrelle\n");
  n=getInt("numero di grani caduti",NMIN,NMAX);

  for(i=0;i<NEXP;i++) {
    for(j=0;j<n;j++) {
      genCirc(&x,&y);
      contaPepe(x,y,A+i,B+i,C+i);
    }
  }

  mediaa=media(A);
  mediab=media(B);
  mediac=media(C);
  printf("\nMedia di grani caduti:\n");
  printf("-nella piastrella A: %.3f\n",mediaa);
  printf("-nella piastrella B: %.3f\n",mediab);
  printf("-nella piastrella C: %.3f\n",mediac);
  exit(0);
}

int getInt ( char *nome, int min, int max) {
  int r;
  do {
    printf("\nInserire %s tra %d e %d: ",nome, min, max);
    scanf("%d",&r);
    if ( r > max || r < min) printf("\nErrore, ripetere inserimento");
  } while ( r > max || r < min);
  return r;
}

void genCirc ( double *x, double *y) {
  do { 
    *x=uniforme(-R, R);
    *y=uniforme(-R, R);
  } while ( distanza(*x,*y)>R );

}

double uniforme ( double a, double b) {
  return (((double)lrand48()/RAND_MAX)*(b-a))+a;
}

double distanza ( double x, double y) {
  return sqrt(x*x+y*y);
}

void contaPepe(double x,double y,int *A,int *B, int *C) {
  controlla(x,y,A,PAX,PAY);
  controlla(x,y,B,PBX,PBY);
  controlla(x,y,C,PCX,PCY);
} 

void controlla(double x,double y,int *P,double px,double py) {
  if((x>px && x< px+L) && (y>py && y<py + L)) *P+=1;
}

double  media( int *P) {
  int k;
  double med;

  med=0;
  for( k=0; k < NEXP; k++) {
    med+=*(P+k);
  }
  med/=NEXP;
  return med;

}
