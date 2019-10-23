#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define NG 2

/* 1 pt: interfaccia genera */
int genera(int,int);

/* 2 pt: interfaccia vincente */
int vincente(int*,int*);

/* 2 pt: interfaccia aggiorna */
void aggiorna(int,int*,int*);

int main() {

  int posta=0;
  int turni=0;
  int tasca[NG]={10.,10.};
  int mano[NG];
  int voce[NG];
  int vince;
  int i;
  /* 2 pt: corretto azzeramento delle variabili iniziali e nel ciclo */

  srand48(time(0));

  /* 3 pt: condizione e ciclo giusto */
  while( tasca[0]>0 && tasca[1]>0 ) {

    /* 1 pt: conteggio corretto turni */
    turni++;
    
    for(i=0;i<2;i++) {
      tasca[i]--;
      posta++;

      mano[i] = genera(1,5);

      /* 2 pt: corretta generazione di voce */
      voce[i] = genera(mano[i]+1,10);
    }
    
    /* 2 pt: corretta chiamata ed uso di funzioni */
    vince = vincente(mano,voce);
    aggiorna(vince, &posta, tasca); 

    /* 2 pt: stampa messaggio richiesto ogni 5 turni */
    if(turni%5==0) printf("turno: %d\t gioc. 1: %d\t gioc. 2: %d\n",
			  turni, tasca[0], tasca[1]);
    
  } // turni


  /* 1 pt: stampa messaggio finale */
  if(tasca[0]==0 && tasca[1]==0) {
    printf("pareggio dopo %d turni. ciascuno prende %d euro\n",
	   turni, posta/2);
  } else {

    vince = 0;
    if(tasca[1]>tasca[0]) vince = 1;

    printf("Vince giocatore %d dopo %d turni\n", vince+1, turni);

  }
 
}

/* 3 pt: generazione numeri casuali come richiesto */
int genera(int a, int b) {
  return a+lrand48()%(b-a+1);
}


int vincente(int* mano,int* voce) {
  int OK[NG];

  /* 2 pt: condizione vincitore */
  OK[0] = (voce[0] == mano[0]+mano[1]);
  OK[1] = (voce[1] == mano[0]+mano[1]);

  //printf("G1: %d  %d \t G2: %d  %d\n", mano[0],voce[0], mano[1], voce[1] );
  
  /* 4 pt: restituzione decisione giusta. deve corprire tutti i casi */
  if( OK[0] && OK[1] ) return 0;
  else if( OK[0] ) return 1;
  else if( OK[1] ) return 2;
  else return 0;
}

void aggiorna(int vincente, int* posta, int* tasca) {

  /* 3 pt: aggiornamento tasche e posta */

  if(vincente==0) {
    tasca[0] += *posta/2;
    tasca[1] += *posta/2;
  }else {
    tasca[vincente-1] += *posta;
  }
  *posta = 0;

  return;
}

