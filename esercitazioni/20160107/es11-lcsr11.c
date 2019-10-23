#include <stdio.h>
#include <stdlib.h>
#include <math.h> /*non sono state usate funzioni presenti nella libreria*/
#include <time.h>

#define L 0.5     /* lato di una singola mattonella*/
#define RIP 100   /* numero di ripetizioni per ogni caduta di barattolo*/
#define NMIN 330  /* numero minimo di granelli di pepe caduti*/
#define NMAX 550  /* numero massimo di granelli di pepe caduti*/
#define R 0.77    /* raggio del cerchio in cui si distribuiscono i granelli*/

int getint(char *, int, int);  /* acquisizione di un numero intero tra due estremi*/
float casuale(float,float);    /* generazione di un numero casuale razionale tra due estremi*/
void genCirc(float*,float*);
void contaPepe(float*,float*,int*,int*,int*);
void media(int*, int*, int*, float*, float*, float*);

int main(){
  int N,a,b,c,i,j;
  int A[RIP], B[RIP], C[RIP];
  float x,y,NA,NB,NC;

  srand48(time(0));  /* inizializzazione del seme*/

  printf("Questo programma simula N granelli di pepe che cadono sul pavimento.\n");
  N=getint("Inserire il numero N di granelli",NMIN,NMAX);
  
  for(i=0;i<RIP;i++){  /* ciclo sulle 100 ripetizioni*/

    a=0;
    b=0;
    c=0;

    for(j=0;j<N;j++){  /*ciclo sui singoli granelli caduti*/

      genCirc(&x,&y);
      contaPepe(&x,&y,&a,&b,&c);
    }

    *(A+i)=a;
    *(B+i)=b;
    *(C+i)=c;
    /* printf("A : %d  B: %d  C: %d\n", *(A+i), *(B+i), *(C+i));  debug */
  }
  
  media(A,B,C,&NA,&NB,&NC);
  
  printf("-----Valore medio di granelli nelle mattonelle-----\n");
  printf("A : %f\n", NA);
  printf("B : %f\n", NB);
  printf("C : %f\n", NC);    
}
 
int getint(char frase[], int a, int b){
  int r;
  do{
    printf("%s fra %d e %d : ", frase, a, b);
    scanf("%d",&r);
    if(r<a || r>b){
      printf("Valore non valido, ripetere l'acquisizione.\n");
    }
  }while(r<a || r>b);
  return r;
}

float casuale(float c, float d){
  return c+(d-c)*(float)lrand48()/RAND_MAX;
}

void genCirc(float* X,float* Y){
  do{
    *X=casuale(-R,R);
    *Y=casuale(-R,R);
  }while((*X)*(*X)+(*Y)*(*Y)>R*R);
}

void contaPepe(float* X,float* Y,int* a,int* b,int* c){
   if((*X)>=0 && (*X)<=L && (*Y)>=0 && (*Y)<=L) (*a)++;
   else if((*X)>=0 && (*X)<=L && (*Y)>=L && (*Y)<=2*L) (*b)++;
   else if((*X)>=L && (*X)<=2*L && (*Y)>=L && (*Y)<=2*L) (*c)++;
}

void media(int a[RIP], int b[RIP], int c[RIP], float *vma, float *vmb, float *vmc){
  int i;
  *vma=0;
  *vmb=0;
  *vmc=0;
  for(i=0;i<RIP;i++){
    (*vma)+= *(a+i);
    (*vmb)+= *(b+i);
    (*vmc)+= *(c+i);
  }
  (*vma)/= RIP;
  (*vmb)/= RIP;
  (*vmc)/= RIP;

}
    
