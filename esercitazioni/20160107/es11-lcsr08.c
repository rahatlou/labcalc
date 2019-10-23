#include <stdio.h>
#include <stdlib.h>
#define NEXP 100
#define RAGGIO 0.77

double casuale(double, double);

int chiediInt(char*, int, int);

void genCirc(double*, double*);

void contaPepe(double, double, int*, int*, int*);

double media(int[]);




int main(){

  char msg[] = "numero di granelli di pepe";

  int a = 330;
  int b = 550;
  int N, i, k;
  int aesp, besp, cesp;
  double NA, NB, NC;

  int A[NEXP]={0}, B[NEXP]={0}, C[NEXP]={0};

  /* puntatori */
  
  double *xp, *yp;

  int *ap, *bp, *cp;
  
  double x, y;

  xp = &x;

  yp = &y;

  ap = &aesp;

  bp = &besp;

  cp = &cesp;

  srand48(time(0));


  printf("Questo programma conta il numero di grani di pepe caduti su 3 mattonelle.\n");

  N = chiediInt(msg, a, b);




  for(k=0; k< NEXP; k++){
    
    *ap = 0;
    *bp = 0;
    *cp = 0;

  for(i=0; i < N; i++){

  genCirc(xp, yp);

  contaPepe(x, y, ap, bp, cp);

  *(A + k)+= aesp;
  *(B + k)+= besp;
  *(C + k)+= cesp;

  }


  }
  
  NA = media(A);
  NB = media(B);
  NC = media(C);

  printf("Media di granelli in A: %f\n", NA);
  printf("Media di granelli in B: %f\n", NB);
  printf("Media di granelli in C: %f\n", NC);

}/*chiusura main*/










double casuale(double a, double b){
  
  double c;

  return  c = (double)lrand48()/RAND_MAX*(b - a) + a;
}










int chiediInt(char msg[], int a, int b){

  int x;

  do{

  printf("Inserisci %s compreso tra %d e %d: ", msg, a, b);

  scanf("%d", &x);

  if(x<a || x>b){


    printf("Valore inserito errato, riprova\n");

  }

  }while(x<a || x>b);

  return x;
}






void genCirc(double*xp, double*yp){
  
  double x, y;

  do{

    x= casuale(-RAGGIO, RAGGIO);

    y= casuale(-RAGGIO, RAGGIO);

  }while((x*x)+(y*y)>RAGGIO*RAGGIO);

  *xp = x;

  *yp = y;
  
}








void contaPepe(double x, double y, int *ap, int *bp, int *cp){

  int countA= 0, countB=0 , countC=0;

  if(x<0.5 && x>0 && y<0.5 && y> 0){

    countA++;

  }

  if(x<0.5 && x>0 && y<1 && y> 0.5){

    countB++;

  }

  if(x<1 && x>0.5 && y<1 && y> 0.5){

    countC++;

  }

  *ap = countA;
  *bp = countB;
  *cp = countC;

}







double media(int A[]){

  int i;
  double m=0;

  for(i=0; i < NEXP; i++){
   
    m += *(A + i); 
  }

  return m/NEXP;
}
