#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define PREZZO 1
#define MAXALBUM 220
#define MINALBUM 180
#define MINPACK 4
#define MAXPACK 7
int GetInt(char [], int,int);
int Domanda(char[]);
void Packet (int,int,int,int[],int*);
int IntRand(int,int);
void Update(int[],int[],int);
int check(int[],int);
void exchange (int[],int[],int);
int doppioni(int[],int);
int main(){
  srand48(time(0));
  int i, nfig,scambio,paolo[MAXALBUM],pietro[MAXALBUM],packPaolo=0,packPietro=0,npack,pacchetto[MAXPACK];
  printf("Il programma simula la collezione di figurine da parte di Pietro e Paolo\n");
  nfig= GetInt("Inserire numero figurine nell'album",MINALBUM,MAXALBUM);
  scambio = Domanda("I bambini possono scambiarsi le figurine?");
  for(i=0;i<MAXALBUM;i++){
  paolo[i]=0;
  pietro[i]=0;
  }
  do{
    if(check(paolo,nfig)==0){
      Packet(MINPACK,MAXPACK,nfig,pacchetto,&npack);
      packPaolo ++;
      Update(paolo,pacchetto,npack);
    }
    if(check(pietro,nfig)==0){
      Packet(MINPACK,MAXPACK,nfig,pacchetto,&npack);
      packPietro ++;
      Update(pietro,pacchetto,npack);
    }
    if(scambio == 1 && check(pietro,nfig)==0 && check(paolo,nfig)==0){
      exchange(pietro,paolo,nfig);
    }
  }while(check(pietro,nfig)== 0 || check(paolo,nfig) == 0);
  printf("Ad album completato \nPietro ha comprato %d pacchetti, pagando %d,  con %d doppioni  \nPaolo ne ha comprati %d, pagando %d, con %d doppioni\n",packPietro,packPietro*PREZZO,doppioni(pietro,nfig),packPaolo,packPaolo*PREZZO,doppioni(paolo,nfig));
  exit(0); 
}

int GetInt(char messaggio [],int min,int max){
  int risultato;
  do{
    printf ("%s in [%d,%d]: ", messaggio, min, max);
    scanf("%d",&risultato);
    printf("\n");
    if(risultato<min|| risultato>max){
      printf("ERRORE!Valore fuori intervallo\n");
    }
  }while(risultato<min||risultato>max);
  return risultato;
}
int Domanda(char messaggio[]){
  int risultato;
  do{
    printf ("%s (1=si, 0=no) ", messaggio);
    scanf("%d",&risultato);
    printf("\n");
    if(risultato!=0 && risultato!=1){
      printf("ERRORE!Valore non valido\n");
    }
  }while(risultato!=0&&risultato!=1);
  return risultato;
}
void Packet ( int minpack, int maxpack, int nfig,int m[],int *npack){
  int i,j;
  *npack = IntRand(minpack,maxpack);
  for(i=0;i<maxpack;i++){
    m[i]=0;
  }
  for(i=0;i<*npack;i++){
    m[i]= IntRand(0,nfig);
    j=0;
      do{
	if(m[i]==m[j]){
	  m[i]=IntRand(0,nfig);
	  j=0;
	}else{
	  j++;
	}
      }while(j<i);
  }
}

int IntRand(int min,int max){
  int m;
  m =((float)lrand48()/RAND_MAX)*(max-min)+min;
  return m;
}

void Update(int album[], int pacchetto[], int nfig){
  int i;
  for(i=0;i<nfig;i++){
    album[pacchetto[i]] ++;
  }
}
int check(int collezione[], int nfig){
  int i;
  for(i=0;i<nfig;i++){
    if(collezione[i]==0){
      return 0;
    }
  }
  return 1;
}
void exchange(int bimbo1[], int bimbo2[], int nfig){
  int i,j,effettuato;
  for(i=0;i<nfig;i++){
    effettuato=0;
    j=0;
    if(bimbo1[i]>1&&bimbo2[i]==0){
      do{
	if(bimbo2[j]>1&&bimbo1[j]==0){
	    bimbo1[i]--;
	    bimbo2[i]++;
	    bimbo2[j]--;
	    bimbo1[j]++;
	    effettuato =1;
	}
	j++;
      }while(j<nfig && effettuato==0);
    }
  }
}

int doppioni (int album[],int nfig){
  int i,somma=0;
  for(i=0;i<nfig;i++){
    if(album[i]>1){
      somma += album[i]-1;
    }
  }
  return somma;
}
