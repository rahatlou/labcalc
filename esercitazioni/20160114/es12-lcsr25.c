#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 220
#define MIN 180

int  packet(int*, int);
void update(int*, int);
int check(int*, int);


int main(){

  srand48(time(0));

  int fpa, fpi, scelta;
  int paolo[MAX], pietro [MAX], figurina;


  printf("Questo programma stima il numero di pacchetti che due bambini devono comprare per completare i loro album di figurine\n");

  do{
    printf("Inserisci numero tra 180 e 220 di figurine contenute nell'album di Paolo :   \n");
    scanf("%d", &fpa); 
  }while(fpa<MIN || fpa>MAX);

  do{
  printf("Inserisci numero tra 180 e 220 di figurine contenute nell'album di Pietro  :   \n");
    scanf("%d", &fpi); 
  }while(fpi<MIN || fpi>MAX);

 
  printf("I bambini possono scambiarsi i doppioni? Inserisci 1 per si, o 0 per no :   \n");
  scanf("%d", &scelta);

  if(scelta==1){
    printf("I bambini possono scambiarsi i doppioni\n");
  
 }


  if(scelta==0){
    printf("I bambini non possono scambiarsi i doppioni\n");
 


 }


  


}
int packet(int fig[], int nfalbum){
  int nf, i, j, c;
 nf=(lrand48()/RAND_MAX)*(7-4)+4;
 
 for(i=0; i<7;i++){
  fig[i]=0;
  }
  for(i=0;i<nf;i++){

    fig[i]=(lrand48()/RAND_MAX)*nfalbum;
    do{
      c=0;
      for(j=0; j<i; j++){
	if(fig[i]==fig[j]){

	  fig[i]=((double)lrand48()/RAND_MAX)*nfalbum;
	  c=1;
	}
      }
    }while(c!=0);

  }return nf; 

}
void update(int P[],int F){
  int pk=0, i, tot;
  for(i=0; i<F; i++){
    do{
      pk++;
      tot+=pk:
      P[i]=tot;
    }while(tot!=F);
  }
}

int check(int P[], int F){
  int i;
  for(i=0; i<F-1; i++){
  if(P[i]!=0){
    printf("Album completo!\n");
    return 1;
  }else{
    return 0;
      }
    }
  }



