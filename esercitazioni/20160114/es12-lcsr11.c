#include <stdio.h>
#include <stdlib.h>
#include <math.h> /*non sono state utilizzate funzioni della libreria*/
#include <time.h>
#define MINF 180 /*numero minimo possibile di figurine*/
#define MAXF 220 /*numero massimo possibile di figurine*/
#define MINP 4   /*numero minimo di figurine in un pacchetto*/
#define MAXP 7   /*numero massimo di figurine in un pacchetto*/

int getint(char *,int,int);       /*acquisizione di un numero intero in un intervallo*/
void packet(int *,int,int, int);  
int casuale(int,int);             /*generazione di un numero intero casuale tra due estremi (inclusi)*/
void update(int *,int *,int);
void exchange(int*,int*,int);
int check(int *,int);
int doppioni(int *, int);         /*conta i doppioni in un array*/

int main(){
  int scelta,nf,p,npa=0,npi=0,endpa=0,endpi=0, dpa=0,dpi=0,i;   /*endpa e endpi indicano se gli album sono stati completati*/
  int paolo[MAXF];
  int pietro[MAXF];
  int bustina[MAXP];
  srand48(time(0));
  for(i=0;i<MAXF;i++){  /*azzera gli array pietro e paolo*/
    *(paolo+i)=0;
    *(pietro+i)=0;
  }
  printf("Il programma stima il numero di pacchetti di figurine necessari a due bambini per completare i loro album.\n");
  nf=getint("il numero totale di figurine",MINF,MAXF);
  do{ 
    printf("I bambini possono scambiarsi i doppioni?\n");     
    printf("SI -> 1 \t NO -> 0\n");
    scanf("%d",&scelta);
  }while(scelta!=0 && scelta!=1);
  do{
    if(endpa==0){
      packet(bustina,MINP,MAXP,nf);
      update(paolo,bustina,MAXP);
      npa++;
    }
    if(endpi==0){
      packet(bustina,MINP,MAXP,nf);
      update(pietro,bustina,MAXP);
      npi++;
    }
    if(scelta==1 && endpa==0 && endpi==0){
      exchange(paolo,pietro,nf);
    }
    endpa=check(paolo,nf);
    endpi=check(pietro,nf);
  }while(endpa==0 || endpi==0);
  dpa=doppioni(paolo,nf);  /*doppioni di paolo*/
  dpi=doppioni(pietro,nf); /*doppioni di pietro*/
  printf("Numero di pacchetti totali : %d\n", npa+npi);
  printf("Numero di pacchetti comprati da Paolo : %d\n", npa);
  printf("Numero di doppioni di rimasti a Paolo : %d\n", dpa);
  printf("Numero di pacchetti comprati da Pietro : %d\n",npi);
  printf("Numero di doppioni di rimasti a Pietro : %d\n", dpi);
}
int getint(char frase[],int min,int max){
  int ris;
  do{
    printf("Inserire %s tra %d e %d: ",frase,min,max);
    scanf("%d",&ris);
  }while(ris<min || ris>max);
  return ris;
}
int casuale(int a, int b){
  return lrand48()%(b-a+1)+a;
}
void packet(int pack[],int minp, int maxp, int nf){
  int i, N, j, p;        /*p viene utilizzata per controllare che non ci siano doppioni in una bustina*/
  for(i=0;i<maxp;i++){
    *(pack+i)=0;
  }
  N=casuale(minp,maxp);
  for(i=0;i<N;i++){
    do{
      *(pack+i)=casuale(1,nf);
      p=0;
      for(j=0;j<i;j++){
	if((*(pack+i))==(*(pack+j))){
	  p=1;
	}
      }
    }while(p==1);
  }
}
void update(int bimbo[],int busta[],int maxp){
  int i;
  int pos;
  for(i=0;i<maxp;i++){
    pos=*(busta+i);
    if(pos!=0){
      (*(bimbo+(pos-1)))++;
    }
  }
}
void exchange(int bimA[],int bimB[],int nf){
  int i,j,s;
  for(i=0;i<nf;i++){
    if(*(bimA+i)>1 && *(bimB+i)==0){
      for(j=0;j<nf;j++){
	if(*(bimB+j)>1 && *(bimA+j)==0){
	  s=j;
	}
      }
      (*(bimB+i))++;
      (*(bimA+i))--;
      (*(bimB+s))--;
      (*(bimA+s))++;
    }
  }
} 
int check(int nome[],int l){
  int i;
  for(i=0;i<l;i++){
    if(*(nome+i)==0){
      return 0;
    }
  }
  return 1;
}
int doppioni(int kid[],int num){
  int i, dop=0;
  for(i=0;i<num;i++){
    if(*(kid+i)>1){
      dop+=*(kid+i)-1;
    }
  }
  return dop;
}
