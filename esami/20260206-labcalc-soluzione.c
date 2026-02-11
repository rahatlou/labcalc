#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXGIOCATORI 6
#define ULTIMACELLA 63
#define FACCEDADO 6

/* prototipi */
int dado();
int controllo(int pos, int *fermo, int* penalty);

/* in alternativa passare indice del giocatore e puntatore ad array */
int controllo_alternativo(int iGiocatore, int* posizione, int *fermo, int* penalty);

/* 
notare bene che gli argomenti sono sempre dello stesso tipo nei 
due casi ma con significati diversi
*/

int main(){

  int N;                      /* numero di giocatori */
  int posizione[MAXGIOCATORI];
  int fermo[MAXGIOCATORI];
  int penalty[MAXGIOCATORI];

  FILE *fp;

  srand48(time(NULL));

  /* --- input numero giocatori --- */
  do{
    printf("Inserire numero di giocatori (2-6): ");
    scanf("%d", &N);
  }while(N < 2 || N > 6);

  /* --- inizializzazione --- */
  for(int i = 0; i < N; i++){
    posizione[i] = 0;
    fermo[i] = 0;
    penalty[i] = 0;
  }

  fp = fopen("posizione.txt", "w");
  if(fp == NULL){
    printf("Errore apertura file posizione.txt\n");
    return 1;
  }

  /* --- ciclo principale sui turni --- */
  int turno = 0;
  int vincitore = -1;
  
  while(vincitore == -1){

    turno++;

    /* ciclo sui giocatori */
    for(int i = 0; i < N; i++){

      if(fermo[i] == 1){
        /* il giocatore salta il turno e si prepara per il turno successivo */
        fermo[i] = 0;
      } else{
        int passo = dado();
        posizione[i] += passo;

        /* controllo caselle speciali */
        int delta = controllo(posizione[i], &fermo[i], &penalty[i]);

	/* versione alternativa */
	//int delta =  controllo(i, posizione, fermo, penalty);
	
        posizione[i] += delta;
      }

      /* controllo vittoria */
      if(posizione[i] >= ULTIMACELLA && vincitore == -1){
        vincitore = i;
      }
    }

    /* scrittura su file a fine turno */
    fprintf(fp, "%d ", turno);
    for(int i = 0; i < N; i++){
      fprintf(fp, "%d ", posizione[i]);
    }
    fprintf(fp, "\n");
  }

  fclose(fp);

  printf("\nVincitore: giocatore %d dopo %d turni\n", vincitore + 1, turno);

  /* troviamo il giocatore con la massima penalita` */
  int max_penalty = penalty[0];
  int giocatore_penalizzato = 0;

  for(int i = 1; i < N; i++){
    if(penalty[i] > max_penalty){
      max_penalty = penalty[i];
      giocatore_penalizzato = i;
    }
  }

  printf("Giocatore %d  con %d penalita\n",
	 giocatore_penalizzato + 1, max_penalty);

  
  return 0;
}

/* ---------------- FUNZIONI ---------------- */

int dado(){
  return drand48()*FACCEDADO + 1;
}

int controllo(int pos, int * fermo, int* penalty){

  /* prigione */
  if(pos == 13 || pos == 17 || pos == 29){
    *fermo = 1;
    (*penalty)++; 
    return 0;
  }

  /* oche */
  if(pos % 7 == 0){
    return 3;
  }

  /* labirinto */
  if(pos % 10 == 0){
    (*penalty)++; 
    return -2;
  }


  return 0;
}


/* versione alternativa */
int controllo_alternativo(int iG, int* posizione, int *fermo, int* penalty){

 int pos = posizione[iG];
 
  /* prigione */
  if(pos == 13 || pos == 17 || pos == 29){
    fermo[iG] = 1;
    penalty[iG]++; 
    return 0;
  }

  /* oche */
  if(pos % 7 == 0){
    return 3;
  }

  /* labirinto */
  if(pos % 10 == 0){
    penalty[iG]++; 
    return -2;
  }


  return 0;
}
