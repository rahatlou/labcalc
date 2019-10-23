#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

#define NMIN 180
#define NMAX 220
#define PACMIN 4
#define PACMAX 7
#define SCELTA1 0.
#define SCELTA2 1.
#define COSTO 0.5

int uniforme(int, int);
int getInt(int,int);
int scelta(double,double);
void packet(int,int,int,int pacchetto[NMAX]);
void update(int array[NMAX],int pacchetto[NMAX],int);
int check(int array[NMAX],int);
void exchange(int arraypa[NMAX],int arraypi[NMAX],int);

int main(){
  srand48(time(0));
  int N,S,i,PA=0,PI=0, doppa=0, doppi=0;
  int paolo[NMAX]={0};
  int pietro[NMAX]={0};
  int pacchetto[NMAX]={0};

  printf("Questo programma simula lo scambio di figurine tra due bambini\n");
  printf("Inserire il numero di figurine N [%d,%d]: ",NMIN,NMAX); 
  N=getInt(NMIN,NMAX);
  printf("Inserire 1 se i bambini possono scambiarsi i doppioni altrimenti premere 0\n");
  S=scelta(SCELTA1,SCELTA2);

  do{
    if(check(paolo,N)!=1){
      packet(N,PACMIN,PACMAX,pacchetto);
      PA++;
      update(paolo,pacchetto,N);
  
    }
    if(check(pietro,N)!=1){
      packet(N,PACMIN,PACMAX,pacchetto);
      PI++;
      update(pietro,pacchetto,N);
    }
    if(S==1){
      if(check(paolo,N)==0 && check(pietro,N)==0){
	exchange(paolo,pietro,N);
      }
    }
      

  }while(check(paolo,N)==0 || check(pietro,N)==0);    
  
  for(i=0;i<N;i++){ 
    // printf("%d    %d\n",paolo[i],pietro[i]);
    if(paolo[i]>1) doppa+=(paolo[i]-1);
    if(pietro[i]>1) doppi+=(pietro[i]-1);
  }
  printf("Numeri pacchetti di Paolo: %d\nNumero pacchetti di Pietro: %d\n",PA,PI); 
  printf("Paolo spende %.2lf, Pietro spende %.2lf (1 pacchetto=%.2lf euro)\n",PA*COSTO,PI*COSTO,COSTO);
  printf("Numero doppioni Paolo: %d\t Doppioni di Pietro: %d\n",doppa,doppi);  
  exit(0);
}

int uniforme(int a,int b){
  
  return a+lrand48()%(b-a+1);
}



int getInt(int a,int b){
  int x;
  do{
    scanf("%d",&x);
    if(x<a || x>b) printf("Errore! Reinserire valore\n");
  }while(x<a || x>b);
  return x;
}

int scelta(double a,double b){
  double S;
  do{
    scanf("%lf",&S);
    if(S!=0 && S!=1) printf("Errore! Reinserire valore\n");
  }while(S!=0 && S!=1);
  return (int)S;
} 

void packet(int N, int pacmin, int pacmax, int pacchetto[NMAX]){

  int x, i, n;

  for(i=0 ; i<N ; i++){
    pacchetto[i]=0;
  }
  x=uniforme(pacmin,pacmax);
  for(i=0 ; i<x ; i++){
    do{
      n=uniforme(0,N-1);
      //   printf("%d\n",n);
    }while(pacchetto[n]>=1);
    pacchetto[n]++;
    // printf("%d\n",n);
  }
  
}

void update(int array[NMAX], int pacchetto[NMAX], int N){
  
  int i;
  for(i=0 ; i<N ; i++){
    array[i]+=pacchetto[i];
  } 
}

int check(int array[NMAX],int N){
  int i,C=0;
  for(i=0 ; i<N ; i++){  
    if(array[i]==0) C++;
  }
  if(C==0){
    return 1;
  }
  else return 0;
} 

void exchange(int arraypa[NMAX], int arraypi[NMAX],int N){
  int i,j;
  for(i=0;i<N;i++){
    if(arraypa[i]>1 && arraypi[i]==0){
      j=-1;
      do{
	j++;
      }while(arraypi[j]<2 || arraypa[j]!=0);
      arraypa[i]--;
      arraypi[i]++;
      arraypa[j]++;
      arraypi[j]--;
    }
    if(arraypi[i]>1 && arraypa[i]==0){
      j=-1;
      do{
	j++;
      }while(arraypa[j]<2 || arraypi[j]!=0);
      arraypi[i]--;
      arraypa[i]++;
      arraypi[j]++;
      arraypa[j]--;


    }
  }
}
