#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Nmin 180
#define Nmax 220
#define Npack 7
#define npack 4

int RandInt(int, int); 
int packet(int, int*);
void update(int*, int*, int, int);
int check(int*, int);
void exchange(int*, int*, int);
//int doppioni(int*, int); Metodo alternativo per il calcolo dei doppioni

int main() {
  int Nfig, scelta, x, CPa, CPi, s=0, t=0, dopPa=0, dopPi=0, i;
  int pacchetto[Npack]={0};
  int Paolo[Nmax]={0};
  int Pietro[Nmax]={0};
  srand48(time(NULL));

  printf("\nPaolo e Pietro vogliono completare i propri album di figurine comprando pacchetti e scambiandosi doppioni.\nIl programma stima il numero di pacchetti necessari.");

  do {
    printf("\nInserire il numero di figurine in un album tra %d e %d: ", Nmin, Nmax);
    scanf("%d", &Nfig);
    if(Nfig<Nmin || Nfig>Nmax) printf("\nErrato.");
  } while(Nfig<Nmin || Nfig>Nmax);

  do {
    printf("\nVuole consentire scambi di doppioni?\n1 --> Si'\n2 --> No\n");
    scanf("%d", &scelta);
    if(scelta!=1 &&  scelta!=2) printf("\nErrato.");
  } while(scelta!=1 && scelta!=2);
  
   do {
     CPa=check(Paolo, Nfig);
     CPi=check(Pietro, Nfig);
     if(CPa==0) {
      x=packet(Nfig, pacchetto);
      s++;
      update(Paolo, pacchetto, Nfig, x);
    }
     if(CPi==0) {
      x=packet(Nfig, pacchetto);
      t++;
      update(Pietro, pacchetto, Nfig, x);
    }
     if(scelta==1 && CPa==0 && CPi==0) exchange(Paolo, Pietro, Nfig);
   } while(CPa==0 || CPi==0); 
   
   //dopPa=doppioni(Paolo, Nfig);
   //dopPi=doppioni(Pietro, Nfig);

   for(i=0;i<Nfig;i++) {
     dopPa+=Paolo[i];
     dopPi+=Pietro[i];
   }
   dopPa-=Nfig;
   dopPi-=Nfig;
   
   printf("\nPaolo ha comprato %d pacchetti.\nPietro ha comprato %d pacchetti.\nCosto totale dei pacchetti: %d\nDoppioni rimasti a Paolo: %d\nDoppioni rimasti a Pietro: %d\n", s, t, s+t, dopPa, dopPi);

  return 0;
}

int RandInt(int a, int b){
  return lrand48()%(b-a+1)+a;
}

int packet(int Nfig, int* pacchetto) {
  int x=RandInt(npack,Npack), i, j;
  for(i=0;i<x;i++) {
      pacchetto[i]=RandInt(0,Nfig-1);
      for(j=i-1;j>0;j--) {
	if(pacchetto[j]==pacchetto[i]) i--;
      } 
  }
  return x;
}

void update(int* Bambino, int* pacchetto, int Nfig, int x) {
  int i;
  for(i=0;i<x;i++) {
    Bambino[pacchetto[i]]++;
  }
}

int check(int* Bambino, int Nfig) {
  int i;
  for(i=0;i<Nfig;i++){
    if(Bambino[i]==0) return 0;
  }
  return 1;
}

void exchange(int* BambinoA, int* BambinoB, int Nfig) {
  int i,j;
  for(i=0;i<Nfig;i++) {
    if(BambinoA[i]>1 && BambinoB[i]==0) {
      for(j=0;j<Nfig;j++) {
	if(BambinoB[j]>1 && BambinoA[j]==0) {
	  BambinoA[i]--;
	  BambinoB[i]++;
	  BambinoA[j]++;
	  BambinoB[j]--;
	}
      }
    }
  }
}

/* int doppioni(int* Bambino, int Nfig) {
  int i,x=0;
  for(i=0;i<Nfig;i++) {
    if(Bambino[i]>1) {
       x++;	
       Bambino[i]--;
       if(Bambino[i]>1) i--;
    }
  }
  return x;
  } */

