#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

#define R 0.77
#define NMIN 330
#define NMAX 550
#define NEXP 100

int getInt (char*, int, int);
void genCirc (float, float*, float*);
float casuale(float, float);
void contaPepe(int, float*, float*, int*, int*, int*);
float media(int*);

int main () {
  int N, i, k;
  float ma, mb, mc;
  int NA[NEXP]={0}; int NB[NEXP]= {0}; int  NC[NEXP]= {0};
 
  float coordx[NMAX] = {0};
 float coordy[NMAX]= {0};

 
  srand48(time(0));

  printf("questo programma calcola il numero di grani di pepe caduti in tre mattonelle A, B, C\n");
 
  N = getInt("numero di grani di pepe", NMIN, NMAX);
 
 
  for( k=0; k< NEXP; k++){

 for(i=0;i<N;i++){
    genCirc(R, &coordx[i], &coordy[i]);
  }

  contaPepe(N, coordx, coordy, &NA[k], &NB[k], &NC[k]);

  }
  ma = media(&NA);
  mb = media(&NB);
  mc = media(&NC);

  printf("media a : %f, media b : %f, media c : %f\n", ma, mb, mc);


}




int  getInt ( char* msg, int min, int max) {
  int x;
  
  do{ 
    printf (" inserisci %s compreso tra (%d,%d):\n", msg, min, max);
    scanf ("%d",&x);
  }while((x < min) ||( x > max));
  return x;
}



float casuale(float min, float max){
  return ((max-min) *( (float)lrand48()/RAND_MAX ) +min   );
}




void genCirc(float r, float*x, float*y){
  float dist;
  do { 
    *x = casuale((-r),r);
    *y = casuale((-r),r);
    dist = sqrt( (*x)*(*x) + (*y)*(*y));
  }while( dist > r);

} 

void contaPepe (int n, float a[], float b[], int*NA, int*NB, int*NC) {

  int j;
  for(j=0; j< n; j++){
    if( a[j] >= 0 && a[j] <0.5){

      if(b[j]>=0 && b[j] <= 0.5){
	(*NA)++;
      } else if(b[j] > 0.5) { (*NB)++;}
    }

    else if( a[j] >= 0.5) {
      if (b[j] >= 0.5) {
	(*NC)++;
      }

    }
    } 

}


float media(int  array[]){
  int i; float m=0;
  for (i=0; i< NEXP; i++){
    m += array[i];
  }
  m /= NEXP;
  return m; 
}
