#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

#define R 0.77
#define L 0.5
#define NEXP 100
#define GRANMIN 330
#define GRANMAX 550

double uniforme(double,double);
int getint(char*,int,int);
void gencirc(double*,double*);
void contapepe(double,double,int*,int*,int*);
void media(int*,int*,int*,double*,double*,double*);

int main(){

  int n, i,j, freqA[NEXP]={0}, freqB[NEXP]={0}, freqC[NEXP]={0};
  double x,y, medA, medB, medC;

  srand48(time(0));

  printf("Questo programma calcola la posizione dei grani di pepe caduti in modo uniforme su un pavimento\n");

  n=getint("Inserire numero grani di pepe caduti",GRANMIN,GRANMAX);

  for(j=0;j<NEXP;j++){
    for(i=0; i<n; i++){
      gencirc(&x,&y);
      contapepe(x,y,&freqA[j],&freqB[j],&freqC[j]);
    } 
  }

  media(freqA,freqB,freqC,&medA,&medB,&medC);

  printf("Media grani pepe caduti in A: %.2lf\nMedia grani pepe caduti in B: %.2lf\nMedia grani pepe caduti in C: %.2lf\n", medA, medB, medC);


  exit(0);
} 

double uniforme(double a, double b){

  return ((double)lrand48()/RAND_MAX)*(b-a)+a;
}

int getint(char nome[], int a, int b){

  int x;
  printf("%s [%d,%d]:\n",nome,GRANMIN,GRANMAX);

  do{
    scanf("%d",&x);
    if(x<a||x>b){
      printf("Valore non valido. Reinserire.\n");
    }
  }while(x<a||x>b);
  return x;
}

void gencirc(double *x, double *y){

  do{
    *x=uniforme(-R,R);
    *y=uniforme(-R,R);
  }while(*x**x+*y**y>R*R);

}

void contapepe(double x, double y,int *a, int *b, int *c){

  if(x>0 && x<L && y>0 && y<L){
    (*a)++;
  }
 
 if(x>0 && x<L && y>L && y<2*L){
    (*b)++;
  }
 
 if(x>L && x<2*L && y>L && y<2*L){
    (*c)++;
  }
}
 
void media(int freqA[],int freqB[], int freqC[], double *medA, double *medB, double *medC){

  int i;

  *medA=0;
  *medB=0;
  *medC=0;

  for(i=0; i<NEXP; i++){
    *medA+=freqA[i];
    *medB+=freqB[i];
    *medC+=freqC[i];
  }

  *medA/=NEXP;
  *medB/=NEXP;
  *medC/=NEXP;
}
