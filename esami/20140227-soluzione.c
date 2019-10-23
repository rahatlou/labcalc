#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <math.h>
#include <time.h>
#define MAX 20
#define COLPO 5

int getInt(char*,int, int);
int extract(int, int);
void checkFleet(int *, int *, int, int*, int *);

int main() {
  int terra[MAX]={0}, klingon[MAX]={0};
  int i, k;
  int N0, nks, nkt, hit;
  int Ksup, Tsup;

  /* percentuale navi per la sconfitta */
  double perc = 0.3;

  srand48(time(0));

  N0 = getInt("numero iniziale di navi",10, 20);

  /* 1 pt: azzerare correttamente il numero di navi */ 
  Ksup = N0;
  Tsup = N0;

  /* 1 pt: azzerare correttamente gli scudi */
  /* valore iniziale degli scudi per il numero di navi scelto dall'utente */
  for (i=0; i<N0; i++){
     terra[i] = 20;  //scudo terra
  }
  for(i=0; i<N0; i++) {
     klingon[i] = 10; //scudo klingon
  }

  printf("Numero iniziale di navi nelle due flotte: %d\n\n", N0);


  do {

     /* 2 pt: estrazione numero navi che sparano */
     nks = extract(1, Ksup); // quanti klingon sparano
     nkt = extract(1, Tsup); // quanti terrestri sparano

     printf("-- navi che sparano terra:%d klingon:%d\n",nkt,nks);

     /* 1 pt: corretto ciclo attacco klingon */
     for(k=0; k<nks; k++){   //l'attacco klingon

        do {
           hit = extract(0,N0-1); // indice della nave da colpire
        } while(terra[hit]<=0) ; //colpisco solo navi operative con scudo > 0
        /* 3 pt: corretta generazione di indici con solo navi attive scartando quelle distrutte */

        terra[hit] -= COLPO; // colpire la nave terrestre
     }

     /* 1 pt: corretto ciclo attacco terra */
     for(k=0; k<nkt; k++){  //contrattacco terra
        do {
           hit = extract(0,N0-1); // indice della nave da colpire
        } while(klingon[hit]<=0) ; //colpisco solo navi operative con scudo > 0
        /* 2 pt: corretta generazione di indici con solo navi attive scartando quelle distrutte */

        klingon[hit] -= COLPO; // colpire la nave klingon
     }

     // controllo flotte ed aggiorno numero navi rimaste
     checkFleet ( terra, klingon, N0, &Ksup, &Tsup);

     printf("-- Navi superstiti terra: %d (%.0f%s)   klingon: %d (%.0f%s) \n", Tsup,100.*Tsup/N0,"%", Ksup, 100.*Ksup/N0,"%");

  } while( (Ksup > perc*N0) && (Tsup > perc*N0) ); /* il gioco continua se entrambi hanno ancora almeno 30% */
  /* 3 pt: condizione corretta per il ciclo del gioco */

  /* 2 pt: messaggio finale */
  if(Ksup <= perc*N0) { /* vince la terra */
       printf("\nHa vinto la Terra! %d navi klingon distrutte (%.0f%s)\n",N0-Ksup,100.*(N0-Ksup)/N0,"%");
       printf("Perse %d navi terrestri\n\n", N0-Tsup); 
  } 

  if(Tsup <= perc*N0) {
       printf("\nLa Terra ha person con  %d (%.0f%s) navi distrutte\n",N0-Tsup,100.*(N0-Tsup)/N0,"%");
       printf("Distrutte  %d navi Klingon\n\n", N0-Ksup); 
  }
  
  printf("Navi superstiti della federazione: %d (%.0f%s)\n", Tsup,100.*Tsup/N0,"%");
  printf("Navi superstiti klingon: %d (%.0f%s)\n", Ksup,100.*Ksup/N0,"%");

} /* fine main */

/* 2 pt: interfaccia */
int getInt(char* nome, int min, int max) {
  int ris;

 /* 2 pt: ciclo do-while usato correttamente */
  do{
    printf("Inserisci %s tra %d e %d: ", nome, min, max);
    scanf("%d", &ris);
  } while( ris<min || ris> max);

  return ris;
}


/* 2 pt: interfaccia */
int extract(int a, int b){
  /* 2 pt: generazione corretta */
  return a + lrand48()%(b-a+1); /* numeri interi tra a e b inclusi */
}


/* 4 pt: interfaccia corretta */
void checkFleet (int* T, int* K, int N0, int *Ksup, int *Tsup) {
   int i, Kdead =0, Tdead=0;

   /* 3 pt: corretto conteggio delle navi distrutte */
   for(i=0; i<N0; i++) {
      if(K[i]<=0) {Kdead++;} 
      /* if(K[i]>0) printf("klingon[%d] : %d\n", i, K[i]); */
   }
    for(i=0; i<N0; i++) {
      if(T[i]<=0) {Tdead++;} 
      /* if(T[i]>0) printf("terra[%d] : %d\n", i, T[i]); */
   }  
   *Ksup = N0 - Kdead;
   *Tsup = N0 - Tdead;
}
