#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

#define LEN 110
#define len 100

void genCirc(double*, double*, double);
void contaPepe(double, double, int*, int*, int*);
void media(int[], int[], int[], double*, double*, double*);

int main(){
  printf("Questo programma simula la caduta casuale sul pavimento di granelli di pepe\n");
  srand48(time(0));

  int N, a=0, b=0, c=0, i;
  int A[LEN]={0};
  int B[LEN]={0};
  int C[LEN]={0};
  double x=0., y=0., raggio=0.77, NA, NB, NC;

  

  printf("Inserire numero di granelli di pepe caduti compreso fra 330 e 550\n");
  do{
    scanf("%d", &N);
    if(N<330||N>550) printf("Errore valore non valido reinserire!\n");
  }while(N<330||N>550);
 
  for(i=0;i<len;i++){
    genCirc(&x, &y, raggio);
    contaPepe(x, y, &a, &b, &c);

    A[i]=a;
    B[i]=b;
    C[i]=c;
    

  }
  

  media(A, B, C, &NA, &NB, &NC);
  printf("\nMedia della mattonella A:%.3lf\n\nMedia della mattonella B:%.3lf\n\nMedia della mattonella C:%.3lf\n", NA, NB, NC);
    
  return 0;
}

void genCirc(double *x, double *y, double raggio){

  double tempx, tempy;
  do{
    *x= -0.77+(double)lrand48()/RAND_MAX*(2*0.77);
    *y= -0.77+(double)lrand48()/RAND_MAX*(2*0.77);
    
    tempx= *x;
    tempy= *y;
 
  }while(tempx*tempx + tempy*tempy>=raggio*raggio);
}

void contaPepe(double x, double y, int *a, int *b, int *c){

  if(x>=0 && x<=0.5){
    if(y>=0 && y<0.5) *a+=1;
    if(y>=0.5 && y<=1) *b+=1;
  }

  if(x>0.5 && x<=1){
    if(y>0.5 && y<1) *c+=1;
  }

}

void media(int A[LEN], int B[LEN], int C[LEN], double *NA, double *NB, double *NC){ 
  int i;
  double a=0, b=0, c=0;

  for(i=0;i<len;i++){
    
    a+=A[i];
    b+=B[i];
    c+=C[i];

  }
   
  *NA=a/len;
  *NB=b/len;  
  *NC=c/len;

}































































