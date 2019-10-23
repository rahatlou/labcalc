#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MIN 330
#define MAX 550
#define R 0.77
#define LEN 100

void getInfo(int*);
void genCirc(float*, float*);
int contaPepe();
void media(int*, int*, int*, int*, float*, float*, float*, float*);

 
int main () {
  
  srand48(time(0));
  float Ma, Mb, Mc, Mf;
  int N, i, j, CADO;
  int A[LEN] = {0};
  int B[LEN] = {0};
  int C[LEN] = {0};
  int F[LEN] = {0};

  printf("Questo programma simula la caduta di grani di pepe su un pavimento\n");

  getInfo(&N);

  for (j = 0; j < LEN; j ++) {

    for (i = 0; i < N; i ++) {

      CADO = contaPepe();

      if (CADO == 1)  A[j] ++;
      
      else if (CADO == 2) B[j] ++;
      
      else if (CADO == 3) C[j] ++;
      
      else { F[j] ++; }

    }

  }

  media(A, B, C, F, &Ma, &Mb, &Mc, &Mf);

  printf("Media pepe su A = %f \nMedia pepe su B = %f \nMedia pepe su C = %f \n Media pepe fuori dalle mattonelle = %f \n", Ma, Mb, Mc, Mf);

  exit(0);

}



void getInfo(int* n) {
  
  do {
    
    printf("Inserire numero granelli di pepe caduti [%d, %d]:\n", MIN, MAX);
    scanf("%d", &*n);
    
    if (*n < MIN || *n > MAX) {

      printf("ERRORE!!!\n");

    }

  } while (*n < MIN || *n > MAX);

}


void genCirc(float* x, float* y) {

  do {

    *x = ((float)lrand48()/RAND_MAX)*(2*R) - R;
    *y = ((float)lrand48()/RAND_MAX)*(2*R) - R;

  } while (*x**x + *y**y > R*R);
  
}


int contaPepe() {

  float x, y;

  genCirc(&x, &y);

  if (x <= 0.5 && x >= 0 && y <= 0.5 && y >= 0) return 1;
  else if (x <= 0.5 && x >= 0 && y <= 1 && y > 0.5) return 2;
  else if (x <= 1 && x > 0.5 && y <= 1 && y > 0.5) return 3;
  else { return -1; }

}


void media(int a[], int b[], int c[], int f[], float* ma, float* mb, float* mc, float* mf) {

  int i;
  *ma = 0;
  *mb = 0;
  *mc = 0;
  *mf = 0;

  for (i = 0; i < LEN; i ++) {

    *ma += a[i];
    *mb += b[i];
    *mc += c[i];
    *mf += f[i];

  }

  *ma /= i;
  *mb /= i;
  *mc /= i;
  *mf /= i;

}
