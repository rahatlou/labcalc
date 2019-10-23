#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 220
#define COSTO 1.50
int getint(char*,int,int);
void packet(int*,int,int,int,int*);	 
int casuale(int,int);
void update(int*,int*,int);
void exchange(int*,int*,int);
int check(int*,int);


int main(){
  srand48(time(0));
  int maxpack = 7;
  int minpack = 4;
  int packpaolo=0,packpietro=0,i,x,dopPa=0,dopPi=0,completoPa,completoPi,nfig,scelta,paolo[MAX]={0};
  int pietro[MAX]={0};
  int busta[7]={0};

  printf("Il programma stima quanti pacchetti di figurine serviranno a Paolo e Pietro per completare il loro album,un pacchetto costa %.2f\n",COSTO);

  nfig = getint("numero di figurine album",180,220);
  do{

  printf("Se i bambini si scambieranno i doppioni premere 1 altrimenti premere 0\n");
  scanf("%d",&scelta);
  }while( scelta != 1 && scelta != 0);

  for(i=0;i<nfig;i++){
    paolo[i] = 0;
    pietro[i]= 0;
  }
  for(i=0;i<maxpack;i++){
    busta[i]=0;
  }

  


  completoPa = 0;
completoPi = 0;

  while(completoPa == 0 || completoPi == 0){

    if(completoPa == 0){
      packet(busta,nfig,minpack,maxpack,&x);
      update(paolo,busta,x);
      packpaolo++;
    }

    if(completoPi == 0){
      packet(busta,nfig,minpack,maxpack,&x);
      update(pietro,busta,x);
      packpietro++;
    }

    if(scelta == 1 && completoPa==0 && completoPi==0){
      exchange(pietro,paolo,nfig);
    }

    completoPa = check(paolo,nfig);
    completoPi = check(pietro,nfig);

    printf("%d\n",completoPa);
    printf("--- %d",completoPi);
  }

  for(i=0;i<nfig;i++){
    if(pietro[i]>1){ dopPi++;}
    if(paolo[i]>1){ dopPa++;}
  }

  printf(" n pacchetti Paolo: %d --- costo: %.2f --- n doppioni rimasti: %d\nn pacchetti Pietro: %d --- costo: %.2f --- n doppioni rimasti: %d\n",packpaolo,(packpaolo*COSTO),dopPa,packpietro,(packpietro*COSTO),dopPi);



  exit(0);
}

int getint(char msg[],int min,int max){

  int x ;
  do {
    printf("Inserire %s compreso fra %d e %d:\n",msg,min,max);
    scanf("%d",&x);
  }while(x<min || x>max);

  return x;



}


void exchange(int pietro[],int paolo[],int nfig){

  int i,j;

  for(i=0;i<nfig;i++){

    if(paolo[i]>1 && pietro[i]==0){

      for(j=0;j<nfig;j++){
    
        if(pietro[j]>1 && paolo[j]==0){
	  paolo[i]--;
	  pietro[i]++;
	  paolo[j]++;
	  pietro[j]--;
	}
      }
    }
  }

}


int check(int nome[],int nfig){
  int i;

  for(i=0;i<nfig;i++){

    if(nome[i] == 0){ 
      return 0;
    }
  }
   
  return 1;
    
}


void packet(int busta[],int nfig,int minpack,int maxpack,int *x){
  int i,j,doppioni;
  *x = casuale(minpack,maxpack);

  for(i=0;i<(*x);i++){
    doppioni =0;   
 do{

    busta[i]= casuale(0,nfig);
    for(j=0;j<i;j++){
      if(busta[j] == busta[i]){
	doppioni++;
      }
    }
 }while(doppioni >0);

  }
}

int casuale(int a,int b){
  return lrand48()%(b-a+1)+a;
}

void update(int nome[],int busta[],int x){
  int i,new;

  for(i=0;i<x;i++){

    new = busta[i];
    nome[new]++;
  }
}
