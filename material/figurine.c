#include <stdlib.h>
#include <stdio.h>
#include<time.h>

#define NPMIN      4
#define NPMAX      7
#define NB 7
#define NFIGMIN 180
#define NFIGMAX 220

/* genera numero intero casuale tra min e max */
int genInt(int min, int max);


/* genera una nuova bustina con NP figurine in [1,Nmax] */
void acquista(int* bustina, int N);

/* aggiorna un album con una bustiuna di figurine */
void riempi(int* album, int* bustina);

/* controlla che l'album sia completo */
int controllo(int* album, int N);

/* scambia i duplicati tra i due album */
void scambio(int* alb1, int* alb2, int N);

/* conta numero duplicati */
int duplicates(int* album, int N);




int main() {

  int nfig;  /* numero di figurine nell'album */
  int nb; /* numero figurine in una busta */

  int  finitoElena, finitoApollo, fareScambi;

  /* 1 pt scelta sensata di array */
  int elena[NFIGMAX]={0}, apollo[NFIGMAX]={0}; /* contatore di figurine per i due album */

  int busteApollo=0, busteElena=0; /* numero di bustine acquistate */
  int bustina[NPMAX]={0}; /* una bustina */

  /* inizializzare seme numeri casuali */
  srand48(time(0));

  /* 1 pt  messaggio */
  printf("questo programma stima il numero di pacchetti che apollo e elena devono comprare\n");
  printf("per completare i loro album di figurine\n");

  /*1 pt acq nfig */
  do{
    printf("Numero %d <= N <= %d di figurine in ciascun album: ", NFIGMIN, NFIGMAX);
    scanf("%d", &nfig);
  } while( nfig < NFIGMIN || nfig > NFIGMAX );  

  /* 2 pt scelta scambi */
  do{
    printf("Inserire 1) se i bambini posso scambiare i doppioni  0) se non ci sono scambi: ");
    scanf("%d", &fareScambi);

   if(fareScambi !=0 && fareScambi != 1) printf("valore inserito non valido! inserire 0 o 1. riprova.\n");

  } while( fareScambi !=0 && fareScambi != 1 );  


  /* variabili di appoggio */
  finitoElena=finitoApollo=0;

 /* 3 pt scelta del ciclo e condizioni. fai la simulazione finche` entrambi gli album sono completi */
  do {

    /* 1 pt compra bustine solo se non ha ancora finito */
    if( finitoElena == 0 ) {

      /* genera una nuova bustina per Elena*/
      acquista(bustina, nfig);

      /* aggiorna l'album di Elena */
      riempi(elena, bustina);

      /* aggiorna numer di bustine */
      busteElena++;
    }


    /* 1 pt compra bustine solo se non ha ancora finito */
    if( finitoApollo == 0 ) {

      /* genera una nuova bustina per Apollo*/
      acquista(bustina, nfig);

      /* aggiorna l'album di Apollo */
      riempi(apollo, bustina);

      /* aggiorna numer di bustine */
      busteApollo++;
    }

    /* fai gli scambi solo se sono vere le tre condizioni:
       l'utente ha scelto di scambiare i doppioni
       apollo non ha finito il suo album
       apollo non ha finito il suo album

       2 pt condizione giusta

    */
    if( fareScambi == 1 && finitoApollo == 0 && finitoElena == 0 ) scambio( elena, apollo, nfig );

    /* 1 pt corretta chiamata a controllo ed aggiornamnto stato album */

    /* controlla se Apollo ha finito */
    finitoApollo = controllo(apollo, nfig);

    /* controlla se Elena ha finito */
    finitoElena = controllo(elena, nfig);
    
  } while( finitoElena == 0 || finitoApollo == 0 );

  /* 1 pt stampa # finale di buste */

  printf("Elena Totale buste: %d \t doppioni: %d\n", busteElena, duplicates(elena,nfig) ); 
  printf("Apollo Totale buste: %d \t doppioni: %d\n", busteApollo, duplicates(apollo,nfig) ); 



  return 0;
}


/* 1 pt genera numero intero casuale tra min e max, estremi inclusi */
int genInt(int min, int max) {
  return min + lrand48()%(max-min+1);
}

/* 2 pt genera una nuova bustina con nb figurine per un album con Nfig figurine totali */
void acquista(int* bustina, int Nfig) {

  int i,j, rip;
  
  /* 1 pt ciclo numero figurine nella busta */  
  for(i=0; i<NB; i++) {

    /* 4 pt evitare doppioni */
    do{
      rip = 0;
      bustina[i] = genInt(0, Nfig-1);

      for(j=0; j<i; j++) {
        if(bustina[i] == bustina[j]) rip++;
      }
    } while(rip > 0);

  } /* fine geneazione figurine nella bustina */

}

/* 2 pt interfaccia. aggiorna un album con una bustiuna di figurine */
void riempi(int* album, int* bustina) {

   int figurina, i;

   /* ciclo sulle figurine contenute nell'album */
   for(i=0; i< NB; i++) {

     /* prendi la i-esima figurina dalla busta */
     figurina = bustina[i];
     
     /* 2 pt aggiorno il conto di questa figurina nell'album */
     album[figurina]++;

     // NB: si puo` fare direttamente album[ busitina[i] ]++
     
   }

}



/* 1 pt interfaccia controllo() 
   2 pt controlla che l'album sia completo */
int controllo(int* album, int N) {

  for(int i=0; i<N; i++) {
    /* se manca almeno una figurina l'album non e` finito */
    if( album[i]==0 ) return 0; /* album incompleto */
  }

  /* se siamo arrivati a questo punto vuol dire che c'e` almeno una copia di ciascuna figurina */
  return 1; /* album completo */

}

/* BONUS 4 pt  per questa funzione */
/*  interfaccia. scambia i duplicati tra i due album */
void scambio(int* alb1, int* alb2, int N) {

  int i;

  int nd, nd1, nd2; /* numero di duplicati da scambiare */
  int ns; /* numero discambi fatti */

  /* numero di duplicati in album 1  e album 2*/
  nd1 = duplicates(alb1, N);
  nd2 = duplicates(alb2, N);
 
  /* determina quanti scambi si possono fare */ 
  if(nd1 < nd2) nd = nd1;
  else          nd = nd2; 

  /* 
    ciclo sulle figurine per fare nd  scambi 
    avviene uno scambio se:
        un album ha almeno 2 copie e l'altro album non ne ha nessuna copia 
        ci sono ancora nd scambi da fare (nd > 0)
  */

  ns = 0; /* scambi fatti */
   
  /* doppione in album1 che manca in album 2 */
  for(i=0; i<N && ns<=nd; i++) {

    if( alb1[i] >= 2 && alb2[i]==0 ) { 
      alb1[i]--; /* cedi da album 1*/
      alb2[i]++; /* incolla in album 2*/
      ns++;
    }
  }

  ns = 0; /* scambi da fare in album 2 */

  /* doppione in album2 che manca in album 1 */
  for(i=0; i<N && ns<=nd; i++) {
    if( alb2[i] >= 2 && alb1[i]==0 ) { 
      alb2[i]--; /* cedi da album 2*/
      alb1[i]++; /* incolla in album 1*/
      ns++;
    }
 
  } /* fine ciclo sulle figurine */

}



/* 1 pt: conteggio duplicati */
int duplicates(int* album, int N) {

  int tot = 0; // numero duplicati

  /* conta quante figurine hanno almeno un duplicato */
  for(int i=0; i<N; i++) {
    // si ha un duplicato se numero di copia della figurana i e` > 1
    if( album[i]>1 ) tot++;
  }

  return tot; 
}
