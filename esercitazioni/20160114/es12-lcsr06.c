#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAX 221

void packet(int,int*);
void update(int,int*,int*);
void exchange(int*,int*,int);
int check(int*,int);


int  main()  {

  int paolo[MAX]={0};
  int pietro[MAX]={0};  
  int bustina[MAX]={0};
  int N,scelta,completoPaolo=0,completoPietro=0;
  int npi=0,npa=0,dpi=0,dpa=0,m;
  srand48(time(0));

  printf("Questo programma stima il numero di pacchetti di figurine che due bambini\n");
  printf("devono comprare per completare un album a testa.\n");

  do {

     printf("Inserire il numero N di figurine in ciascun album in [180,220]:");
     scanf("%d",&N);
     if(N<180 || N>220) printf("Valore non valido.\n");

  } while (N<180 || N>220);

  do {
 
    printf("Inserire 1 se e' possibile scambiare doppioni e 2 se cio' non e' possibile:");
    scanf("%d",&scelta);
  
    if(scelta!=1 && scelta!=2)  printf("Errore! Valore inserito non valido.\n");
  
    }  while (scelta!=1 && scelta!=2);

  do {

    if(completoPietro==0) {
  
      packet(N,bustina);
      update(N,pietro,bustina);
      completoPietro=check(pietro,N);
      npi++;

    }

    if(completoPaolo==0) {

      packet(N,bustina);
      update(N,paolo,bustina);
      completoPaolo=check(paolo,N);
      npa++;

    }

    if(scelta==1 && completoPaolo==0 && completoPietro==0) {

      exchange(pietro,paolo,N);

    }
       
    completoPietro=check(pietro,N);
    completoPaolo=check(paolo,N);


 } while ( completoPaolo==0 || completoPietro==0);

 for(m=1;m<=N;m++) {

   dpi+= pietro[m]-1;
   dpa+= paolo[m]-1;

 }  


 printf("Numero totale di pacchetti comprati da Pietro: %d\n",npi);
 printf("Numero totale di pacchetti comprati da Paolo: %d\n",npa);

 printf("Numero di doppioni rimasti a Pietro: %d\n",dpi);
 printf("Numero di doppioni rimasti a Paolo: %d\n",dpa);

 exit(0);

}

void packet(int n,int* bustina) {

  int i,j,k,s;
  int rip[MAX]={0};
  i=lrand48()%4+4;

  for(s=1;s<=n;s++) {

    bustina[s]=0;
  }

  for(j=1;j<=i;j++) {
   
    do{

     k=lrand48()%(n+1);
     rip[k]++;

    } while(k==0 || rip[k]!=1 );

    bustina[k]++;
    
  }

}
 
void update(int n,int* bambino,int* bustina) {

  int i;
  for(i=1;i<=n;i++) {

    bambino[i]+=bustina[i];

  }

}

void exchange(int* pietro,int* paolo,int n) {

  int i,j,scambio;

  for(i=1;i<=n;i++) {

    scambio=0;
   
    if( pietro[i]==0 && paolo[i]>1) {
     
      j=1;

      do{

        if(paolo[j]==0 && pietro[j]>1) {
                  
	     paolo[i]--;
             pietro[i]++;
	     paolo[j]++;
	     pietro[j]--;
	     scambio++;
	   }

        j++;

      } while (scambio==0 && j<=n);
	 

      }

   }

}
         



int check(int* bambino,int n){

  int i,conto=0;

  for(i=1;i<=n;i++){
   
    if(bambino[i]>=1) conto++;

  }

  if(conto==n) return 1;
  else return 0;

}



