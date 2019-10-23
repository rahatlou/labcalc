#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define pmax 550
#define pmin 330
#define rip 100//numero di ripetizioni
#define R 0.77// raggio

double getDouble(double,double);
void genCirc(double *,double *);
void contaPepe(double, double, int*, int*, int*);
double media(int*);

int main()
{
  int N, i, j;
  double Na, Nb, Nc;//medie
  int A[rip]={0};
  int B[rip]={0};
  int C[rip]={0};
  double x,y;//coordinate granello generico
  srand48(time(0));
  printf("Conta dei granelli di pepe.\n");
  do{
    printf("Inserire N numero di granelli di pepe:\t");
    scanf("%d",&N);
    if((N>pmax)||(N<pmin)) printf("Errore N non corretto, reinserire!\n");
  }while(N>pmax||N<pmin);
  for(i=0; i<rip; i++)
    {
      for(j=0;j<N;j++)
	{
	  genCirc(&x, &y);
	  contaPepe(x, y, A+i, B+i, C+i);
	}
    }
  Na=media(A);
  Nb=media(B);
  Nc=media(C);
  printf("NA:\t%.4lf\nNB:\t%.4lf\nNC:\t%.4lf\n", Na, Nb, Nc);

  /* for(i=0; i<rip; i++) */
  /*   { */
  /*     printf("A[%d]: %d\tB[%d]: %d\tC[%d]: %d\n", i+1,*(A+i), i+1, *(B+i), i+1, *(C+i)); */
  /*   } */

}

double getDouble(double a,double b)
{
  double c;
  c=((double)lrand48()/RAND_MAX)*(b-a)+a;
  return c;
}
void genCirc(double *x,double*y)
{
  double a,b,c;
  do{
    a=getDouble((-1*R),R);
    b=getDouble((-1*R),R);
    c=sqrt(pow(a,2)+pow(b,2));
  }while(c>R);
  *(x)=a;
  *(y)=b;
}
void contaPepe(double x, double y, int*a, int*b, int*c)
{
  if(x>=0 && x<=0.5 && y>=0 && y<=0.5) *(a)+=1;
  else if(x>=0 && x<=0.5 && y>=0.5 && y<=1) *(b)+=1;
  else if(x>=0.5 && x<=1 && y>=0.5 && y<=1) *(c)+=1;
  else{}
}
double media(int*a)
{
  int i; 
  double tot=0;
  for(i=0; i<rip; i++)
    {
      tot+=*(a+i);
    }
  tot/=rip;
  return tot;
}
