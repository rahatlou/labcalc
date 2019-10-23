#include <stdlib.h>
#include <stdio.h>
#include<time.h>

#define NPMIN      4
#define NPMAX      7
#define NFIGMIN 180
#define NFIGMAX 220

/* aggiorna un album con una bustiuna di figurine */
void update(int* album, int* bustina, int nb);

/* scambia i duplicati tra i due album */
void exchange(int* alb1, int* alb2, int N);

/* conta numero duplicati */
int duplicates(int* album, int N);

/* controlla che l'album sia completo */
int check(int* album, int N);

/* genera una nuova bustina con NP figurine tra 1 e Nmax */
int generaBusta(int* bustina, int N);

/* genera numero intero casuale tra min e max */
int genInt(int min, int max);



int main() {

  int nfig;  /* numero di figurine nell'album */
  int nb; /* numero figurine in una busta */

  int  finitoPietro, finitoPaolo, fareScambi;

  /* 1 pt scelta sensata di array */
  int pietro[NFIGMAX]={0}, paolo[NFIGMAX]={0}; /* contatore di figurine per i due album */

  int bustePaolo=0, bustePietro=0; /* numero di bustine acquistate */
  int bustina[NPMAX]={0}; /* una bustina */

  /* inizializzare seme numeri casuali */
  srand48(time(0));


  /* 1 pt  messaggio */
  printf("questo programma stima il numero di pacchetti che paolo e pietro devono comprare\n");
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
  finitoPietro=finitoPaolo=0;

 /* 3 pt scelta del ciclo e condizioni. fai la simulazione finche` entrambi gli album sono completi */
  while( finitoPietro == 0 || finitoPaolo == 0 ) {

    /* 1 pt compra bustine solo se non ha ancora finito */
    if( finitoPietro == 0 ) {

      /* genera una nuova bustina per Pietro*/
      nb = generaBusta(bustina, nfig);

      /* aggiorna l'album di Pietro */
      update(pietro, bustina, nb);

      /* aggiorna numer di bustine */
      bustePietro++;
    }


    /* 1 pt compra bustine solo se non ha ancora finito */
    if( finitoPaolo == 0 ) {

      /* genera una nuova bustina per Paolo*/
      nb = generaBusta(bustina, nfig);

      /* aggiorna l'album di Paolo */
      update(paolo, bustina, nb);

      /* aggiorna numer di bustine */
      bustePaolo++;
    }

    /* fai gli scambi solo se sono vere le tre condizioni:
       l'utente ha scelto di scambiare i doppioni
       paolo non ha finito il suo album
       paolo non ha finito il suo album

       2 pt condizione giusta

    */
    if( fareScambi == 1 && finitoPaolo == 0 && finitoPietro == 0 ) exchange( pietro, paolo, nfig );

    /* 1 pt corretta chiamata a check ed aggiornamnto stato album */

    /* controlla se Paolo ha finito */
    finitoPaolo = check(paolo, nfig);

    /* controlla se Pietro ha finito */
    finitoPietro = check(pietro, nfig);

  }

  /* 1 pt stampa # finale di buste */

  printf("Pietro Totale buste: %d \t doppioni: %d\n", bustePietro, duplicates(pietro,nfig) ); 
  printf("Paolo Totale buste: %d \t doppioni: %d\n", bustePaolo, duplicates(paolo,nfig) ); 



  return 0;
}


/* 1 pt genera numero intero casuale tra min e max, estremi inclusi */
int genInt(int min, int max) {
  return min + lrand48()%(max-min+1);
}

/* 2 pt genera una nuova bustina con NP figurine */
int generaBusta(int* bustina, int Nmax) {

  int i,j, rip;

  
  /* 2 pt numero figurine nella busta */
  int nb; /* numero di figurine in questa busta */
  nb = genInt(NPMIN,NPMAX);
  
  for(i=0; i<nb; i++) {

    /* 3 pt evitare doppioni */
    do{
      rip = 0;
      bustina[i] = genInt(0, Nmax-1);

      for(j=0; j<i; j++) {
        if(bustina[i] == bustina[j]) rip++;
      }
    } while(rip > 0);

  } /* fine geneazione figurine nella bustina */

  return nb;

}

/* 2 pt interfaccia. aggiorna un album con una bustiuna di figurine */
void update(int* album, int* bustina, int nb) {

   int figurina, i;

   /* ciclo sulle figurine contenute nell'album */
   for(i=0; i<nb; i++) {

     /* prendi la i-esima figurina */
     figurina = bustina[i];
     
     /* 2 pt aggiorno il conto di questa figurina nell'album */
     album[figurina]++;

   }

}


/* BONUS 4 pt  per questa funzione */
/*  interfaccia. scambia i duplicati tra i due album */
void exchange(int* alb1, int* alb2, int N) {

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


/* 1 pt interfaccia check() 
   2 pt controlla che l'album sia completo */
int check(int* album, int N) {

  int i;

  for(i=0; i<N; i++) {

    /* se manca almeno una figurina l'album non e` finito */
    if( album[i]==0 ) return 0; /* album incompleto */

  }

  /* se siamo arrivati a questo punto vuol dire che c'e` almeno una copia di ciascuna figurina */
  return 1; /* album completo */

}

/* 1 pt: conteggio duplicati */
int duplicates(int* album, int N) {
  int i;
  int tot = 0;

  /* conta quante figurine hanno almeno un duplicato */
  for(i=0; i<N; i++) {
    /* se manca almeno una figurina l'album non e` finito */
    if( album[i]>1 ) tot++;
  }

  return tot; /* album completo */
}
