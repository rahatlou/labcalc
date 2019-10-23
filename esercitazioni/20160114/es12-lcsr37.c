#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxF 220
#define minF 180
#define Maxp 7
#define minp 4


void packet( int, int, int, int [], int*);
void update( int, int [], int []); 
int check( int[], int);
int doppioni(int[], int); 

int main(){
  int temp, N, scambio, Fg[Maxp], comprate[2];
  int paolo[MaxF]={0};
  int pietro[MaxF]={0};

  srand48(time(0));
  
  printf("Il programma calclo quanti pacchetti compra ciascun bambino e il numero di doppioni di ogni bambino.\n");

  printf("Inserire il numero di figurine nell album (%d<=N<=%d):\n", minF, MaxF); 
  do{
    scanf("%d",&N);
    if(N<minF || N>MaxF){
      printf("Errore! Riepeti\n");
    }
  }while(N<minF || N>MaxF);

  printf("Inserire 1 se i bambini si scambiano le figurine altrimenti inserire 0:\n");
  do{
    scanf("%d",&scambio);
    if(scambio!=1 && scambio!=0){
      printf("Errore! Ripeti.\n");
    }
  }while(scambio!=1 && scambio!=0);


  if(scambio==0){

    do{

      packet(minp, Maxp, N, Fg, &temp);
      update(temp, Fg, paolo);
      comprate[0]++;
    }while(check(paolo,N)==0);



    do{

      packet(minp, Maxp, N, Fg, &temp);
      update(temp, Fg, pietro);
      comprate[1]++;
    }while(check(pietro,N)==0);
    
    printf("pacchetti comprati da paolo: %d doppioni di paolo:%d \npacchetti comprati da Pietro: %d doppioni di Pietro:%d",comprate[0], doppioni(paolo,N),comprate[1],doppioni(pietro,N));

  }

  exit(0);

}


void packet(int A, int B, int N, int Q[], int*k){
  int  j, i, c=0;
  *k=lrand48()/RAND_MAX*(B-A)+A;
  for(i=0; i<(*k); i++){
    
    do{
      *(Q+i)=(double)lrand48()/RAND_MAX*N;
      
      if(i!=0){
	for(j=i-1; j>=0; j--){
	  if(  (*(Q+i)) == (*(Q+j))  ){
	    c=1;
	  }
	}
      }
      
    }while(c==1);

  }
  
}



void update(int n, int fg[], int A[]){
  int i;  
  for(i=0; i<n; i++){
    (*(A+( *(fg+i) ) ))  ++;
  }
}



void exchange(int A[],int B[],int N) {
  int i, c, b, scambi=0, maxscambi;
  
  //*c = doppioni di A*//

  for(i=0; i<N; i++){
    if( *(A+i)>1){
      c++;
    }
  }
 
  //*b = doppioni di B*//
  
  for(i=0; i<N; i++){
    if( *(B+i)>1){
      b++;
    }
  }

  if(c<b){
    maxscambi=c;
  }
  if(b<c){
    maxscambi=b;
  }

  i=0;
  do{   
    if( (*(A+i))==0 && (*(B+i))>1){
      (*(A+i))++;
      (*(B+i))--;
      scambi++;
    }
    if( (*(A+i))>1 && (*(B+i))==0){
      (*(A+i))--;
      (*(B+i))++;
      scambi++;
    }
    i++;
  }while(scambi<=maxscambi);

}


int check(int A[], int N){
  int i, m=0;
  for(i=0; i<N; i++){
    if( (*(A+i))==0){
      m=1;
    }
  }
  
  if(m==1){
    printf("esce con 0"); 
    return 0;
  }
  if(m==0){
    return 1;
  }
}


int doppioni(int A[], int N){
  int i,s=0;
  for(i=0; i<N; i++){
   s+=(*(A+i))--;
  }
 
  return s;
}
