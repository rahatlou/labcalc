#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define Fmin 180
#define Fmax 220
#define Pmin 4
#define Pmax 7

int packet(int , int , int , int *); /*dichiaro funzioni*/
void update(int , int *, int *);
void exchange(int , int * , int * , int);
int check(int * , int);

int main() {

  int Nf,S,paolo[Fmax],pietro[Fmax];             /*dichiaro variabili da tastiera*/     
  int figpaolo, figpietro, costpaolo, costpietro;
  int x, pack[Fmax];
  srand48(time(0));

  printf("questo programma stima il numero di pacchetti da comprare per terminare l'album\n");

  do{
    printf("inserisci numero di figurine Nf tra 180 e 220: ");  /* chiedo all'utente di inserire il numero delle figurine dell'album*/
    scanf("%d",&Nf);
    if(Nf<Fmin || Nf>Fmax) printf("errore\n");
  }while(Nf<Fmin || Nf>Fmax);
  
  /*chiedo all'utente di scegliere se fare scambi di doppioni o meno*/
  do{
    printf("inserisci 1 (se i bambini si scambiano i doppioni) o 2 (se non avviene lo scambio)\n");
    scanf("%d" ,&S);
    if(S==1){
      printf("avviene lo scambio\n");
    } else if(S==2){
      printf("non avviene lo scambio\n");
    } else{
      printf("ripeti l`inserimento\n");
    }
  }while(S!=1 && S!=2);

  figpaolo=figpietro=0;
  costpaolo=costpietro=0;
  
  /*algoritmo che descrive il processo di scambi di figurine tra Pietro e Paolo*/
  do {
    printf("SHR before paolo  figpaolo: %d\n", figpaolo);
    if(figpaolo==0){
      x=packet(Pmin,Pmax,Nf,pack);
      update(x,pack,paolo);
      costpaolo++;
      figpaolo++;
      figpaolo=check(paolo,Nf);
      printf("SHR figpaolo: %d \t costpaolo: %d\n", figpaolo, costpaolo);
    }

    printf("SHR before pietro  figpietro: %d\n", figpietro);
    if(figpietro==0){
      x=packet(Pmin,Pmax,Nf,pack);
      update(x,pack,pietro);
      costpietro++;
      figpietro++;
      figpietro=check(pietro,Nf);
      printf("SHR figpietro: %d \t costpietro: %d\n", figpietro, costpietro);
    }

    if(figpaolo==0 && figpietro==0 && S==1){
      exchange(S,paolo,pietro,Nf);
      figpaolo=check(paolo,Nf);
      figpietro=check(pietro, Nf);
    }

  }while( (figpaolo==0 || figpietro==0) );

  for(x=0;x<Nf;x++) printf("paolo[%d]: %d\n", x, paolo[x]);
  for(x=0;x<Nf;x++) printf("pietro[%d]: %d\n", x, pietro[x]);

  /*il costo dei pacchetti e` uguale al numero di pacchetti*/
  printf("numero di pacchetti comprati da paolo: %d\n" ,costpaolo);
  printf("numero di pacchetto comprati da pietro: %d\n" ,costpietro);
  return(0);
}

int packet(int P1, int P2 , int nf, int *pack){
  int z,i,j,f; /* f e` la variabile che controlla i doppioni */
 
 
  z=lrand48()%(P2-P1+1)+P1; /* genero un numero casuale di figurine in un pacchetto */
  for(i=0; i<z; i++){
    do{
      f=0; /*genero quali figurine ci sono nel pacchetto*/
      pack[i]=lrand48()%(nf-1);
      for(j=0; j<i; j++){
	if (pack[j]==pack[i]){
	  f++;
	}
      }
    }while(f>0);
    printf("i: %d \t val: %d\n", i, pack[i]);
  }
  return z;
}

void update(int z , int *packet , int *bambino){
  int i, fig;
  for(i=0; i<z; i++){
    fig=packet[i];
    bambino[fig]++;
  }
}

void exchange(int s , int *bambinoA , int *bambinoB , int nf){
  int i;
  if(s==2){
    exit(0);
  }
  for(i=0; i<nf; i++){
    if(bambinoB[i]>=2 && bambinoA[i]==0){ /*avviene lo scambio di doppioni per entrambi i bambini*/
      bambinoB[i]--;
      bambinoA[i]++;
    }
    if(bambinoA[i]>=2 && bambinoB[i]==0){
      bambinoA[i]--;
      bambinoB[i]++;
    }
  }
}

/*controlla se l'album e` terminato*/
int check(int *bambino, int nf){
  int i;
  for(i=0; i<nf; i++){
    if(bambino[i]==0){
      return 0;
    }
  }
  return 1;
}
