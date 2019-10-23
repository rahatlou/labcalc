#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define LEN 100
#define MAX 550
#define MIN 330
#define R 0.77
//*COORDINATE MATTONELLA A*//
#define XP1A 0.
#define YP1A 0.
#define XP2A 0.5
#define YP2A 0.5
//*COORDINATE MATTONELLA B*//
#define XP1B 0.
#define YP1B 0.5
#define XP2B 0.5
#define YP2B 1.
//*COORDINATE MATTONELLA C*//
#define XP1C 0.5
#define YP1C 0.5
#define XP2C 1.
#define YP2C 1.  

void genCirc(float *, float*);
void contaPepe(float, float, float, float, float, float, int [], int );
float media(int [],int );

int main(){
  int i, j, N, Na[LEN]={0};
  int Nb[LEN]={0};
  int Nc[LEN]={0};
  float x, y;
  srand48(time(0));
  
  printf("Il programma conta la media dei grani caduti su tre mettonelle A B e C\n");
  
  printf("Inserisci il numero dei grani di pepe caduti (%d<=N<=%d)\n",(int)MIN, (int)MAX);
  do{
    scanf("%d",&N);
    if(N<MIN || N>MAX){
      printf("Inserimento non valido. Ripeti.\n");
    }
  }while(N<MIN || N>MAX);

  
  for(i=0; i<LEN; i++){ 
    for(j=0; j<N; j++){
      genCirc(&x,&y);
      contaPepe(x, y, XP1A, YP1A, XP2A, YP2A, Na, i);
      contaPepe(x, y, XP1B, YP1B, XP2B, YP2B, Nb, i);
      contaPepe(x, y, XP1C, YP1C, XP2C, YP2C, Nc, i);
    }
  }

  printf("Media grani su A:%.2f\nMedia grani su B:%.2f\nMedia grani su C:%.2f\n",media(Na, LEN), media(Nb, LEN), media(Nc, LEN));

  exit(0);
} 


void genCirc(float *x,float *y){
  do{
    (*x)=((float)lrand48()/RAND_MAX)*(R+R)-R;
    (*y)=((float)lrand48()/RAND_MAX)*(R+R)-R;
  }while((*x)*(*x)+(*y)*(*y)>=(R*R));
}


void contaPepe(float x, float y, float xp1, float yp1, float xp2, float yp2, int A[],int i){  
  if(xp1<=x && x<=xp2 && yp1<=y && y<=yp2){
    (*(A+i))++;
  }
}
  

float media(int A[], int l){
  int i; 
  float m=0;
  for(i=0; i<l; i++){
    m+=(*(A+i));
  }
  return m/l;
} 
    


