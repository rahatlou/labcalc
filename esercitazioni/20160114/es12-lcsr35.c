#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define Nmin 180
#define Nmax 220
#define Figmax 7
#define Figmin 4

int packet(int *figurine, int dimensionealbum);
void update(const int figurine[], const int packdim, int bambino[]);
int check(const int bambino[], const int dimensionealbum);
void exchange(int bambino1[], int bambino2[], int dimensionealbum);

int main(){
  srand48(time(0));
  int costoPaolo, costoPietro;
  int Nfig,scambio;
  int bustina[Figmax];
  int checkpaolo=0, checkpietro=0;
  int Paolo[Nmax]={0};
  int Pietro[Nmax]={0};
  int npackPaolo =0, npackPietro=0;
  printf("Il programma calcola il numero di pacchetti che due bambini "
	 "devono comprare per completare i rispettivi album di figurine.\n");
  do{
    printf("Inserire un numero compreso tra %d e %d di figurine contenute"
	   " in ciascun album:\n",Nmin,Nmax);
    scanf("%d", &Nfig);
  
  }while(Nfig<Nmin || Nfig>Nmax);
  do{
    printf("Inserire 1) se i bambini possono scambiarsi i doppioni,"
	   " altrimenti inserire 0):\n");
    scanf("%d", &scambio);
   }while(scambio!=0 && scambio!=1);
  do{
    if(checkpaolo==0){
      update(bustina, packet(bustina, Nfig),Paolo);
      npackPaolo++;
      checkpaolo=check(Paolo,Nfig);
    }
    if(checkpietro==0){
      update(bustina, packet(bustina,Nfig),Pietro);
      npackPietro++;
      checkpietro=check(Pietro,Nfig);
    }
    if(checkpaolo==0 && checkpietro==0 && scambio==1){
      checkpaolo=check(Paolo,Nfig);
      checkpietro=check(Pietro,Nfig);
    }
  }while(checkpaolo==0 || checkpietro==0);
  printf("\n Paolo ha acquistato %d pacchetti,"
	 " mentre Pietro ne ha acquistati %d",npackPaolo,npackPietro);
  costoPaolo=1*npackPaolo;
  costoPietro=1*npackPietro;
  printf("\n Paolo ha speso %d euro per completare il suo album, "
	 "mentre pietro ne ha spesi %d.",costoPaolo,costoPietro);
}
int packet(int *figurine, int dimensionealbum){
  int x,a,b,p;
  int check;
  x=(double)lrand48()/RAND_MAX*3+4;
  for(a=1; a<Figmax; a++){
    figurine[a]=0;
  }
  for(a=1; a<x+1; a++){
    p=(double)lrand48()/RAND_MAX*dimensionealbum;
    figurine[a]=p;
    do{
      check=0;
      for(b=0; b<a; b++){
	if(figurine[a]==figurine[b]){
	  figurine[a]=(double)lrand48()/RAND_MAX*dimensionealbum;
	  check=1;
	}
      }
    }while(check!=0);
  }
  return x;
}  
void update(const int figurine[], const int packdim, int bambino[]){
  int a;
  for(a=1; a<packdim; a++){
    bambino[figurine[a]]++;
  }
}
int check(const int bambino[], const int dimensionealbum){
  int a;
  for(a=1; a<dimensionealbum; a++){
    if(bambino[a]==0){
      return 0;
    }
  }
  return 1;
}
void exchange(int bambino1[], int bambino2[], int dimensionealbum){
  int a, b=0, k=0;
  int doppioni1[dimensionealbum], doppioni2[dimensionealbum];
  for(a=1; a<dimensionealbum; a++){
    if(bambino1[a]>1 && bambino2[a]>1){
      if(bambino1[a]>1 && bambino2[a]==0){
	doppioni1[b]=a;
	b++;
      }
      if(bambino2[a]>1 && bambino1[a]==0){
	doppioni2[b]=a;
	k++;
      }
    }
  }
  if(b>0 && k>0){
    int change1, change2;
    change1=(double)lrand48()/RAND_MAX*(b-1);
    change2=(double)lrand48()/RAND_MAX*(k-1);
    bambino1[doppioni1[change1]]--;
    bambino2[doppioni1[change1]]++;
    bambino2[doppioni2[change2]]--;
    bambino1[doppioni2[change2]]++;
  }
}
