#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

#define MINALB 180
#define MAXALB 220
#define MINPAC 4
#define MAXPAC 7

int getint(int, int);
int dado(int,int);
void packet(int, int, int, int*); //la lunghezza dell array pacchetto e passata gia come numero massimo di figurine in un pacchetto
void update(int*, int*, int); //vedi implementazione
void exchange(int*,int*,int);//diamo per scontato che gli album debbano contenere lo stesso numero di figurine
int check(int*, int);
int totdop(int*, int);

int main(){

  int scelta, nalbum, Paolo[MAXALB]={0}, Pietro[MAXALB]={0}, pacchetto[MAXPAC]={0}, npacPaolo=0, npacPietro=0, complPaolo=0, complPietro=0, dopPaolo=0, dopPietro=0,k;

  srand48(time(0));

  printf("Questo programma stima il numero di pacchetti che due bambini devono comprare\n per completare un album di figurine\n");

  printf("Inserire numero di figurine contenute nell album [%d,%d]:\n", MINALB, MAXALB);
  nalbum=getint(MINALB,MAXALB);

  printf("I bambini possono scambiarsi i doppioni (1=SI  0=NO):\n");
  scelta=getint(0,1);

  do{
    if(complPaolo==0){
      packet(MINPAC,MAXPAC,nalbum,pacchetto);
      npacPaolo++;
      update(Paolo,pacchetto,MAXPAC);
      complPaolo= check(Paolo,nalbum);
    }
    if(complPietro==0){
      packet(MINPAC,MAXPAC,nalbum,pacchetto);
      npacPietro++;
      update(Pietro,pacchetto,MAXPAC);
      complPietro= check(Pietro,nalbum);
    }
    if(scelta==1 && complPaolo==0 && complPietro==0){
      for(k=0;k<nalbum;k++)     {
	exchange(Paolo, Pietro, nalbum);
    }
      complPaolo=check(Paolo,nalbum);
      complPietro=check(Pietro,nalbum);
    }
  
  }while(complPaolo==0 || complPietro==0);

  dopPaolo=totdop(Paolo,nalbum);  
  dopPietro=totdop(Pietro,nalbum);
  printf("npac Paolo=%d\tnpac Pietro=%d\nnumero di pacchetti totali:%d\nndopp Paolo=%d\tndopp Pietro=%d\n",npacPaolo,npacPietro,npacPaolo+npacPietro,dopPaolo,dopPietro);

  exit(0);
}

int getint(int a, int b){

  int x;
  do{
    scanf("%d",&x);
    if(x<a||x>b){
      printf("Errore, valore non valido. Ripetere\n");
    }
  }while(x<a||x>b);
  return x;
}

int dado(int a, int b){
  return lrand48()%(b-a+1)+a;
}

void packet(int a, int b, int n, int pacchetto[]){   //vedi dichiarazione

  int nfig,i,j,temp, si_no;

  nfig=dado(MINPAC,MAXPAC);
  for(i=0;i<b;i++){
    pacchetto[i]=0;
  }

  for(i=0;i<nfig;i++){
    do{
      temp=dado(1,n);
      si_no=0;
      for(j=0;j<i;j++){
	if(temp==pacchetto[j]){
	  si_no=1;
	}
      }
    }while(si_no==1);
    pacchetto[i]=temp;
  }

}

void update(int bambino[], int pacchetto[], int b){ //viene dato per scontato che il pacchetto contenga solo figurine che possono essere raccolte nell album

  int i;

  for(i=0;i<b;i++){
    if(pacchetto[i]!=0){
      bambino[pacchetto[i]-1]++;
    }
  }
}

void exchange(int bambino1[], int bambino2[], int nalbum){

  int i=0, j=0;
  
    while(bambino1[i]<2 && bambino2[i]!=0 && i<nalbum){
      i++;     
    }
    while(bambino2[j]<2 && bambino1[j]!=0 && j<nalbum){
      j++;
    }
    if(i<nalbum &&  j<nalbum){
      bambino1[i]--;
      bambino1[j]++;    
      bambino2[i]++;
      bambino2[j]--;
    }
  
}

int check(int bambino[], int nalbum){
  int i, risultato=1;

  for(i=0;i<nalbum;i++){
    if(bambino[i]==0){
      risultato=0;
    }
  }
  return risultato;
}

int totdop(int bambino[],int nalbum){
  int somma=0,i;

  for(i=0;i<nalbum;i++){
    somma+=bambino[i];
  }
  somma-=nalbum;
  return somma;
}
