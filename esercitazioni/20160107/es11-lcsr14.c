#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define L 0.5
#define R 0.77
#define NMIN 330
#define NMAX 550
#define NEXP 100

void genCirc(float*, float*);
void contaPepe(float, float, int*, int*, int*);
void media(int*, float*);

int main(){

  srand48(time(0));
  int np, i, j;
  float x, y, NA, NB, NC, k;
  int a[NEXP]={0}, b[NEXP]={0}, c[NEXP]={0};


  printf("Il programma calcola la media di grani di pepe caduti in 3 mattonelle\n");

  printf("Inserire numero granelli di pepe in [%d,%d]\n", NMIN, NMAX);

  do{

    scanf("%d", &np);
    
    if ( np < NMIN || np > NMAX) {
      printf("Reinserire in [%d,%d]\n", NMIN, NMAX);
    }
    
  } while ( np < NMIN || np > NMAX);


  for(i=0; i < NEXP ; i++){

    for(j=0 ; j < np ; j++){

      genCirc(&x, &y);

      if ( x>= 0 && y >= 0){
	contaPepe( x, y, &a[i], &b[i], &c[i]);
	k++;
      }
    }
  }

  media(a, &NA);
  media(b, &NB);
  media(c, &NC);

  printf("La media di grani di pepe sulla mattonella A e'\t %.2f\n", NA);
  printf("La media di grani di pepe sulla mattonella B e'\t %.2f\n", NB);
  printf("La media di grani di pepe sulla mattonella C e'\t %.2f\n", NC);
  
  return(0);
}

void genCirc(float* x, float* y){

  float dist;

  do{

    *x = -R + 2*R*(float)lrand48()/RAND_MAX;
    *y = - R + 2*R*(float)lrand48()/RAND_MAX;

    dist = sqrt( (*x)*(*x) + (*y)*(*y));

  } while (dist > R);

}

    
void contaPepe(float x, float y, int* A, int* B, int* C){

  if(x < L &&  y < L){
    (*A)++;
  } else if(x < L && y >= L){
    (*B)++;
  } else if(x >= L && y >= L){
    (*C)++;
  }

}

void media(int* array, float*med){

  int i;

  for(i=0 ; i<NEXP ; i++){

    *med+= *(array+i);
  }

  *med/=NEXP;
}
