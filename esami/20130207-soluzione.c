#include <stdlib.h>
#include <stdio.h>
#include<time.h>

#define NP      7
#define NFIGMIN 100
#define NFIGMAX 1000

/* aggiorna un album con una bustiuna di figurine */
void update(int* album, int* bustina);

/* scambia i duplicati tra i due album */
void duplicates(int* alb1, int* alb2, int N);

/* controlla che l'album sia completo */
int check(int* album, int N);

/* genera una nuova bustina con NP figurine tra 1 e Nmax */
void generaBusta(int* bustina, int N);

/* genera numero intero casuale tra min e max */
int genInt(int min, int max);



int main() {

  int nfig;  /* numero di figurine nell'album */

  int  finitoPietro, finitoPaolo, fareScambi;

  /* 2 pt azzerare gli  array */
  int pietro[NFIGMAX]={0}, paolo[NFIGMAX]={0}; /* contatore di figurine per i due album */

  int bustePaolo=0, bustePietro=0; /* numero di bustine acquistate */
  int bustina[NP]={0}; /* una bustina */

  /* inizializzare seme numeri casuali */
  srand48(time(0));


  /* 1 pt  messaggio */
  printf("questo programma stima il numero di pacchetti che paolo e pietro devono comprare\n");
  printf("per completare i loro album di figurine\n");

  /* 2 pt acq nfig */
  do{
    printf("Numero %d <= N <= %d di figurine in ciascun album: ", NFIGMIN, NFIGMAX);
    scanf("%d", &nfig);
  } while( nfig < NFIGMIN || nfig > NFIGMAX );  

  /* 1 pt scelta scambi */
  do{
    printf("Inserire 1) se i bambini posso scambiare i doppioni  0) se non ci sono scambi: ");
    scanf("%d", &fareScambi);

   if(fareScambi !=0 && fareScambi != 1) printf("valore inserito non valido! inserire 0 o 1. riprova.\n");

  } while( fareScambi !=0 && fareScambi != 1 );  


  /* variabili di appoggio */
  finitoPietro=finitoPaolo=0;

 /* 3 pt scelta del ciclo giusto. fai la simulazione finche` entrambi gli album sono completi */
  while( finitoPietro == 0 || finitoPaolo == 0 ) {

    /* 1 pt compra bustine solo se non ha ancora finito */
    if( finitoPietro == 0 ) {

      /* genera una nuova bustina per Pietro*/
      generaBusta(bustina, nfig);

      /* aggiorna l'album di Pietro */
      update(pietro, bustina);

      /* aggiorna numer di bustine */
      bustePietro++;
    }


    /* 1 pt compra bustine solo se non ha ancora finito */
    if( finitoPaolo == 0 ) {

      /* genera una nuova bustina per Paolo*/
      generaBusta(bustina, nfig);

      /* aggiorna l'album di Paolo */
      update(paolo, bustina);

      /* aggiorna numer di bustine */
      bustePaolo++;
    }

    /* fai gli scambi solo se sono vere le tre condizioni
       l'utente ha scelto di scambiare i doppioni
       paolo non ha finito il suo album
       paolo non ha finito il suo album

       2 pt condizione giusta

    */
    if( fareScambi == 1 && finitoPaolo == 0 && finitoPietro == 0 ) duplicates( pietro, paolo, nfig );

    /* 2 pt corretta chiamata a check ed aggiornamnto stato album */

    /* controlla se Paolo ha finito */
    finitoPaolo = check(paolo, nfig);

    /* controlla se Pietro ha finito */
    finitoPietro = check(pietro, nfig);

  }

  /* 1 pt stampa # finale di buste */

  printf("Totale buste pietro : %d\n", bustePietro); 
  printf("Totale buste paolo  : %d\n", bustePaolo); 


  return 0;
}


/* 1 pt : genera numero intero casuale tra min e max, estremi inclusi */
int genInt(int min, int max) {
  return min + lrand48()%(max-min+1);
}

/* 1 pt genera una nuova bustina con NP figurine */
void generaBusta(int* bustina, int Nmax) {

  int i,j, rip;

  for(i=0; i<NP; i++) {

    /* bonus 2 pt evitare doppioni */
    do{
      rip = 0;
      bustina[i] = genInt(1, Nmax);

      for(j=0; j<i; j++) {
        if(bustina[i] == bustina[j]) rip++;
      }
    } while(rip > 0);

  } /* fine geneazione figurine nella bustina */


}

/* 2 pt interfaccia. aggiorna un album con una bustiuna di figurine */
void update(int* album, int* bustina) {

   int figurina, i;

   /* ciclo sulle figurine contenute nell'album */
   for(i=0; i<NP; i++) {

     /* prendi la i-esima figurina */
     figurina = bustina[i];
     
     /* 2 pt aggiorno il conto di questa figurina nell'album */
     album[figurina-1]++;

   }

}


/* 2 pt interfaccia. scambia i duplicati tra i due album */
void duplicates(int* alb1, int* alb2, int N) {

  int i;

  /* 
    ciclo sulle figurine per fare gli scambi 
    avviene uno scambio se un album ha almeno 2 copie e l'altro album non ne ha nessuna copia 
  */
  for(i=0; i<N; i++) {
   
    /* 2 pt */
    /* doppione in album1 che manca in album 2 */
    if( alb1[i] >= 2 && alb2[i]==0 ) { 
       alb1[i]--; /* cedi da album 1*/
       alb2[i]++; /* incolla in album 2*/
    }

    /* 1 pt */
    /* doppione in album2 che manca in album 1 */
    if( alb2[i] >= 2 && alb1[i]==0 ) { 
       alb2[i]--; /* cedi da album 2*/
       alb1[i]++; /* incolla in album 1*/
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
