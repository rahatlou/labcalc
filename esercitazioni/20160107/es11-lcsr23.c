#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

#define r 0.77
#define EXP 100

void genCirc(float,float, float*, float*);
void contaPepe(float, float, float*, float*, float*);
float media(float array[EXP]);

int main(){
  int n, i, j;
  float*X,*Y;
  float x, y, mediaA, mediaB, mediaC;
  float NA[EXP], NB[EXP], NC[EXP];
  srand48(time(0));

  for(i=0;i<EXP;i++){
    NA[i]=0;
    NB[i]=0;
    NC[i]=0;

  }

  printf("Questo programma calcola la distribuzione dei grani di pepe rovesciati da un\n cuoco maldestro su tre mattonelle A, B e C\n");


  do{
    printf("Inserire il numero di grani di pepe compreso tra 330 e 550\n");
    scanf("%d", &n);
    if(n<330 || n>550){
      printf("Errore! Valore non valido\n");
    }
  }while(n<330 || n>550);
 
  
  X = &x;
  Y = &y;

  for(j=0; j<EXP; j++){

    for(i=0; i<n; i++){

      genCirc(r,-r, X, Y);
      contaPepe(x, y, NA+j, NB+j, NC+j);
    }
  }   

  mediaA =  media(NA);
  mediaB = media(NB);
  mediaC = media(NC);
 
  printf("La media di grani di pepe rovesciati sulla mattonella A vale %f\n su B vale %f\n su C vale %f\n", mediaA, mediaB, mediaC);





  exit(0);

}

void genCirc(float R,float S, float* x, float* y){
  float a, b;

  a = ((float)lrand48()/RAND_MAX) * (R-S) + S;
  b = ((float)lrand48()/RAND_MAX) * (R-S) + S;

  *x = a;
  *y = b;
}


void contaPepe(float x, float y, float*NA, float*NB, float*NC){
  if(x>=0 && x<=0.5 && y>=0 && y<=0.5){
    *NA+=1;
  }else if(x>=0 && x<=0.5 && y>0.5 && y<=1){
    *NB+=1;
  }else if(x>0.5 && x<=1 && y>=0.5 && y<=1){
    *NC+=1;
  }
  
}

float media(float array[EXP]){
  float m;
  int i;

  for(i=0; i<EXP; i++){
    m += array[i];
  }
  m = m / EXP;
  return m;
}










