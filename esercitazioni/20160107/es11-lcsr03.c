#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define NEXP 100
#define LATO 0.5
#define RAGGIO 0.77
#define MINPEPE 330
#define MAXPEPE 550
int GetInt (char[],int,int);
void GenCirc(float*);
float fintorno(float);
float pot(float,int);
void contaPepe(float,float,int*,int*,int*);
float media(int[]);

int main(){
  int N,i,j,A[NEXP],B[NEXP],C[NEXP];
  float pepe[2],NA,NB,NC;
  srand48(time(0));
  printf("Il programma calcola la frequenza con cui grani di pepe cadendo in un raggio di %.2f m  colpiscono tre mattonelle quadrate di lato %.2f m \n",RAGGIO,LATO);
  N = GetInt("Inserire numero grani di pepe",MINPEPE,MAXPEPE);
  for(i=0;i<NEXP;i++){
    A[i]=0;
    B[i]=0;
    C[i]=0;
    for(j=0;j<N;j++){
      GenCirc(pepe);
      contaPepe(pepe[0],pepe[1],&A[i],&B[i],&C[i]);
    }
  }
  NA=media(A);
  NB=media(B);
  NC=media(C);
  printf("Media dei granelli caduti in ogni mattonella a seguito di %d esperimenti:\nMattonella A (x in [0,%.2f] m, y in [0,%.2f] m )= %.2f \nMattonella B (x in [%.2f,%.2f] m, y in [0,%.2f] m )= %.2f \nMattonella C (x in [%.2f,%.2f] m, y in [%.2f,%.2f] m )= %.2f\n",NEXP,LATO,LATO,NA,LATO,2*LATO,LATO,NB,LATO,2*LATO,LATO,2*LATO,NC);
  exit(0);
}

int GetInt(char messaggio [],int min,int max){
  int X;
  do{
    printf("%s in [%d,%d]: ", messaggio, min, max);
    scanf("%d",&X);
    printf("\n");
    if(X<min||X>max){
      printf("Valore fuori intervallo!\n");
    }
  }while(X<min||X>max);
  return X;
}
void GenCirc(float * pepe){
  float x,y;
  do{
    x=fintorno(RAGGIO);
    y=fintorno(RAGGIO);
  }while(pot(x,2)+pot(y,2)>pot(RAGGIO,2));
  *pepe=x;
  *(pepe+1)=y;
}
float fintorno(float valore){
  float l;
  l=((float)lrand48()/RAND_MAX)*2*valore-valore;
  return l;
}
float pot(float base, int esp){
  float A=1;
  int i;
  for(i=0;i<esp;i++){
    A*=base;
  }
  return A;
}
void contaPepe(float x,float y,int*A,int*B,int*C){
  if(x>0&&y<LATO&&y>0){
    if(x<LATO){
      *A+=1;
    }else if(x<2*LATO){
      *B+=1;
    }
  }else if (x>LATO&&y>LATO&&x<2*LATO&&y<2*LATO){
    *C+=1;
  }
}

float media(int mattonella[]){
  int i;
  float media = 0;
  for(i=0;i<NEXP;i++){
    media += mattonella[i];
  }
   media/=NEXP;
   return media;
}
