#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define Nmin 330
#define Nmax 550
#define L 0.5
#define R 0.77
#define imax 100

void genCirc(double x0, double y0);

int main() {

  /*Definizione variabili*/

  int N,i,j,A1,B1,C1,NA,NB,NC; 
  double x, y;
  int A[Nmax],B[Nmax],C[Nmax];

  /*Spiegazione dell intento del programma*/

  printf("Il programma simula la posizione dei grani di pepe e calcola\n"
	 " il numero dei grani caduti, su tre mattonelle.\n");
  /*Richiesta del valore N di numero di grani di pepe*/
  printf("Inserire un valore intero N del numero dei grani di pepe caduti,\n"
	 "appartenente all intervallo [%d,%d]:\n",Nmin,Nmax);
  scanf("%d", &N);
  /*verifica che il valore N appartenga all intervallo [330,550]*/
  while(N<Nmin || N>Nmax){
    printf("Il valore inserito non e corretto. Reinserire un valore di N:\n");
    scanf("%d", &N);
  }
  /*Ciclo for per ripetere 100 volte l esperimento*/
  for(i=0; i<imax; i++){
    /*Ciclo per ripetere il calcolo della posizione di un grano di pepe
      per tutti i grani di pepe N*/
    for(j=0; j<N; j++){
      /*Chiamo funzione per generare le coordinate di un grano di pepe*/
      genCirc(0,0);
      A1=0;
      B1=0;
      C1=0;
      /*Verifica che le coordinate del grano di pepe siano comprese 
	nell area del cerchio*/
      if(x>=0 && x<=0.5 && y>=0 && y<=0.5){
	printf("Il granello di pepe e caduto sulla mattonella A\n");
	A1++;
      }else if(x>=0 && x<=0.5 && y>=0.5 && y<=1){
	printf("Il granello di pepe e caduto sulla mattonella B\n");
	B1++;
      }else if(x>=0.5 && x<=1 && y>=0.5 && y<=1){
	printf("Il granello di pepe e caduto sulla mattonella C\n");
	C1++;
      } else {
    return 0;
  }
  printf("A1: %d  B1: %d  C1: %d\n",A1,B1,C1);

  /*Salvo i valori del numero di grani caduti su ogni mattonella*/
      A[i]=A1;
      B[i]=B1;
      C[i]=C1;
      printf("A1[%d]: %d    B1[%d]: %d   C1[%d]: %d\n",i,A1,i,B1,i,C1);
      /*Inizio il calcolo della media*/
      NA+=A[i];
      NB+=B[i];
      NC+=C[i];
    }
  }
  /*Divido la somma dei valori di media per tutti i valori 
    del numero di esperimenti*/
  NA/=imax;
  NB/=imax;
  NC/=imax;
  /*Stampa valori media*/
  printf("Il valore medio dei granelli di pepe in ciascuna delle mattonelle e\n"
	 "A: %d    B: %d   C: %d ",NA,NB,NC);
  return 0;
}
/*definizione funzione genCirc*/
void genCirc(double x0, double y0){
  double x,y;
  do{
    x=(double)lrand48()/RAND_MAX*2*(R-x0)+x0;
    y=(double)lrand48()/RAND_MAX*2*(R-y0)+y0;
  }while(x*x+y*y>R*R);
    printf("x: %lf   y:%lf\n",x,y);
}
    
  
  
  
