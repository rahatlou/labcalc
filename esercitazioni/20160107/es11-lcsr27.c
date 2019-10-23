#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NMAX 550
#define NMIN 350
#define LEN 100

double genCirc(double);

void azzera(double *);

void contaPepe(double *,double *, double *, double *, double *, int);

double media(double *);

int main(){

  int n,j,i;

  double r=0.77, pepex[NMAX+1],pepey[NMAX+1], a[LEN],b[LEN],c[LEN],na,nb,nc;


  srand48(time(0));

  printf("il programma simula la distribuzione casuale di grani di pepe su un pavimento e ne calcola il numero sulle mattonelle\n");

  printf("Inserire N grani di pepe caduti, N compreso tra 330 e 550\n");


  do{

    scanf("%d",&n);

    if(n>550||n<330){

      printf("valore non valido, ripetere\n");
    }

  }while(n>550||n<330);

  azzera(pepex);

  azzera(pepey);

  azzera(a);

  azzera(b);

  azzera(c);


  for(j=0;j<100;j++){

    for(i=0;i<n;i++){

    pepex[i]=genCirc(r);

    pepey[i]=sqrt(r*r-pepex[i]*pepex[i]);

    contaPepe(pepex,pepey,a,b,c,n);
  
    }

  }

  na=media(a);

  nb=media(b);

  nc=media(c);

  printf("Media di a:%lf\t Media di b:%lf\t Media di c:%lf\n",na,nb,nc);

  exit(0);

}

double genCirc(double r){

  double x;

  x=(drand48()*2*r)-r;

  return x;

}

void azzera(double *pepe){

  int i;

  for(i=0;i<NMAX;i++){


    *(pepe+i)=0;

      }

}


void contaPepe(double *pepex, double *pepey, double *a, double *b, double *c, int n){

  int i,j;
  
  for(j=0;j<LEN;j++){

    for(i=0;i<n;i++){

       if(pepex[i]>0 && pepex[i]<0.5 && pepey[i]>0 && pepey[i]<0.5){

	 a[j]++;
       
       }
       if(pepex[i]>0 && pepex[i]<0.5 && pepey[i]>0.5 && pepey[i]<1){

	 b[j]++;

       }

       if(pepex[i]>0.5 && pepex[i]<1 && pepey[i]>0.5 && pepey[i]<1){

	 c[j]++;

       }

    }
  }
}

double media(double *a){

 double tot=0;
 int i;
 
 for(i=0;i<LEN;i++){
   
   tot+=a[i];

 }

 tot/=LEN;

 return tot;

}
