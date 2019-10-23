#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
#define min 330
#define max 550
#define Nexp 100
#define L 0.5
#define WORDMAX 200
#define R 0.77

int getInt(char [], int, int);
float uniforme(float, float);
void genCirc(float*, float*);
void azzera(int []);
void contaPepe(float*, float*, int*, int*, int*);
float media(int []);

int main() {

  srand48(time(0));
  int N, i, j;
  float x, y;
  int A[Nexp], B[Nexp], C[Nexp];
  int a=0, b=0, c=0;
  float NA, NB, NC;

  printf("Questo programma conta il valore medio dei grani di pepe caduti su tre mattonelle.\n");

  N = getInt("un valore di grani di pepe", min, max);

  azzera(A);
  azzera(B);
  azzera(C);

  for (i=0;i<Nexp;i++) {
    
    for (j=0;j<N;j++) {

      a = 0;

      b = 0;
    
      c= 0;
      
      genCirc(&x, &y);
     
      contaPepe(&x, &y, &a, &b, &c);

      A[i] += a;

      B[i] += b;

      C[i] += c;

    }

  }

  NA = media(A);

  NB = media(B);

  NC = media(C);

  printf("Valore medio di grani su A: %.2f\nValore medio di grani su B: %.2f\nValore medio di grani su C: %.2f\n", NA, NB, NC);
 
  return 0;
  
}


int getInt(char stringa[WORDMAX], int a, int b) {

   int c;
 
   do {
 
    printf("Inserire %s compreso tra [%d,%d]:\n", stringa, a, b);

    scanf("%d", &c);

    if ( c < a || c > b ) printf("Valore non valido. Riprovare.\n");

   } while ( c < a || c > b );

   return c;

}

float uniforme(float a, float b) {

  return a + ((float)lrand48()/RAND_MAX)*(b-a);

}

void genCirc(float *x, float *y) {

  float f;

  do {

    *x = uniforme(-R, R);
    
    *y = uniforme(-R, R);
   
    f = (*x)*(*x) + (*y)*(*y);

  } while ( f > R*R );

}
    
void contaPepe(float *x, float *y, int *a, int *b, int *c) {
  
  if ( (*x <= L && *x >= 0) && (*y <= L && *y >= 0) ) {
    
    *a += 1;
    
  }
 
  if ( (*x <= L && *x >= 0) && (*y <= 2*L && *y >= L) ) {
    
    *b += 1;

  }
 
  if ( (*x <= 2*L && *x > L) && (*y <= 2*L && *y >= L) ) { 

    *c += 1;

  }

}
  
void azzera(int mat[Nexp]) {

  int i;

  for (i=0;i<Nexp;i++) {

    mat[i] = 0;

  }

}
  
float media(int mat[Nexp]) {

  int i, s=0;
  float m;

  for (i=0;i<Nexp;i++) {

    s += mat[i];
    
  }

  m = (float)s/Nexp;

  return m;

}
