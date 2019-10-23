#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define NRIP 100
#define NMAX 550
#define NMIN 330
#define RAGGIO 0.77


void genCirc(double xy[2])
{
  double distanza;
  do
  {
    xy[0]=((double)lrand48()/RAND_MAX)*(2*RAGGIO)-RAGGIO;
  xy[1]=((double)lrand48()/RAND_MAX)*(2*RAGGIO)-RAGGIO;
    distanza=sqrt(xy[0]*xy[0]+xy[1]*xy[1]);
  }while(distanza>RAGGIO);
  //printf("\nx=%lf y=%lf",xy[0],xy[1]);
}

void contaPepe(double xy[2],int i,int A[NRIP],int B[NRIP], int C[NRIP])
{
  if(xy[0]>=0 && xy[0]<=0.5)
  {
    if(xy[1]>=0 && xy[1]<=0.5)
      A[i]++;
    else if (xy[1]>0.5 && xy[1]<=1.0)
      B[i]++;
  }else if (xy[0]>0.5 && xy[0]<=1.0 && xy[1]>=0.5 && xy[1]<=1.0)
    C[i]++;

}

double media(int contatore[NRIP])
{
  int i;
  double media=0;
  for(i=0;i<NRIP;i++)
    media+=contatore[i];
  media/=NRIP;
  return media;
}

int main()
{
  double seed=time(0);
  srand48(seed);
  double xy[2]={0};
  int N,i,j;
  double NA,NB,NC;
  int A[NRIP]={0};
  int B[NRIP]={0};
  int C[NRIP]={0};
  printf("\nIl programma simula la posizione dei grani di pepe caduti e calcola la loro distribuzione sulle mattonelle.\n");
  do
  {
    printf("\nInserire il numero grani di pepe caduti compreso tra %d e %d: ", NMIN,NMAX);
    scanf("%d",&N);
    if(N<NMIN || N>NMAX)
      printf("\nIl valore inserito non rispetta le condizioni indicate.");
  }while(N<NMIN || N>NMAX);

  for(i=0;i<NRIP;i++)
  {
    for(j=0;j<N;j++)
    {
      genCirc(xy);
      contaPepe(xy,i,A,B,C);
    }
  }
  /*for(i=0;i<NRIP;i++)
    printf("\n %d %d %d",A[i],B[i],C[i]);*/
  NA=media(A);
  NB=media(B);
  NC=media(C);
  printf("\nMedia mattonella A: %lf \nMedia mattonella B: %lf\nMedia mattonella C: %lf\n\n", NA,NB,NC);

  return 0;
}
