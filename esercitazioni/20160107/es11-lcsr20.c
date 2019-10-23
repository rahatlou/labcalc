#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define dim 100
#define r 0.77

float media(int q[]);

void gencirc(float* x, float* y);

void contapepe(float coordX, float coordY, int* a, int* b, int* c);

int main (){

  int n, i, j, a[dim], b[dim], c[dim], ca, cb, cc;
  float coordX, coordY, na, nb, nc;
  int* contaA;
  int* contaB;
  int* contaC;
  float* x;
  float* y;

  contaA=&ca;
  contaB=&cb;
  contaC=&cc;
  x=&coordX;
  y=&coordY;

  srand48(time(0));

  printf("questo programma conta i grani di pepe caduti nelle mattonelle a,b e c\n");

  do{
    printf("inserire il numero di grani caduti, compreso fra 330 e 550\n");
    scanf("%d", &n);

    if(n<330 || n>550){
      printf("Errore! Il numero inserito non e' nei limiti indicati!\n");
    }

  } while (n<330 || n>550);

  for(i=0; i<100; i++){    
    ca=0;
    cb=0;
    cc=0;

    for(j=0; j<n; j++){
      gencirc(x, y);

      contapepe(coordX, coordY, contaA, contaB, contaC);
    }
    a[i]=*contaA;
    b[i]=*contaB;
    c[i]=*contaC;
  }

  na=media(a);
  nb=media(b);
  nc=media(c);

  printf("la media dei granelli caduti in A e': %.2f\n", na);
  printf("la media dei granelli caduti in B e': %.2f\n", nb);
  printf("la media dei granelli caduti in C e': %.2f\n", nc);

  return 0;
}


void gencirc(float* x, float* y){

  float cox, coy;

  cox=((float)lrand48()/RAND_MAX)*(2*r);
  cox-=r;
  coy=((float)lrand48()/RAND_MAX)*(2*r);
  coy-=r;

  *x=cox;
  *y=coy;

}


void contapepe(float coordX, float coordY, int* a, int* b, int* c){

  if(coordX>0 && coordY>0){

    if(coordX<=0.5 && coordY<=0.5){
      *a=*a+1;
    } else{
      if(coordX<=0.5 && coordY<=r){
	*b=*b+1;
      }else{
	if (coordX>0.5 && coordY>0.5){
	  *c=*c+1;
	}
      }
    }
  }


}


float media(int q[]){

  int i, somma=0;
  float med;

  for(i=0; i<dim; i++){
    somma=somma+q[i];
  }

  med=somma/dim;

  return med;

}
