#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define NMIN 330
#define NMAX 550
#define RAGGIO 0.77
#define LEN 100


void genCirc(float *, float*, float);
void contaPepe(float, float, int*, int*, int*);
float media(int*, int);


int main(){

  int N, i, npepeA, npepeB, npepeC, A[LEN], B[LEN],  C[LEN];
  float x, y, NA, NB, NC;
  int j;

  srand48(time(0));

  printf("Il programma calcola il numero di grani di pepe caduti in A, B, C\n");
 

  do{
    printf("inserire numero di grani di pepe in [%d, %d]:\n", NMIN, NMAX);
    scanf("%d", &N);
    if(N<NMIN || N>NMAX){
      printf("valore non valido, reinserire...\n");
    }
  }while(N<NMIN || N>NMAX);

  for(j=0; j<N; j++){
    npepeA = 0;
    npepeB =0;
    npepeC =0;

    for(i=0; i< LEN; i++){
  
    genCirc(&x , &y, RAGGIO);
    contaPepe(x, y, &npepeA, &npepeB, &npepeC);



    /*printf("granelli in A: %d \t in B: %d \t in C:%d\n", npepeA, npepeB, npepeC);*/


   }

    A[j] = npepeA;
    B[j] = npepeB;
    C[j] = npepeC;
  }


  for(i=0; i<LEN; i++){

    /* printf("nel lancio %d ho %d in A \t ho %d in B \t ho %d in C\n", i, A[i], B[i], C[i]);*/
  }
  
  NA = media(A, LEN);
  NB = media(B, LEN);
  NC = media(C, LEN);

  printf("media granelli in A:%.3f \t in B:%.3f \t in C:%.3f\n", NA, NB, NC);


return 0;
}

void genCirc(float *x, float *y, float r){
 
 do{

   *x = -r + 2*r*((float)lrand48()/RAND_MAX);
   *y = -r + 2*r*((float)lrand48()/RAND_MAX);

 }while((*x)*(*x) + (*y)*(*y) > r*r);

}

void contaPepe(float x, float y, int *a, int *b, int *c){

  

  if(x>=0. && x<=0.5 && y>=0. && y<0.5){
    (*a)++;
  }else if(y>=0.5 && y<=1){
    (*b)++;
  }else if(x > 0.5 && x <=1){
    (*c)++;
  }
}

float media(int A[LEN], int n){
   
 int k;
 float average=0;

  for(k=0; k<n; k++){
    average += A[k];
  }

  average /= n;

  return average;
}


