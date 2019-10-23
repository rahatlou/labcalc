#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define NMAX 20

/* 2 pt: funzione generatore */
int flatInt (int N);

/* 1 pt: interfaccia funzione input */
int getInt(const char *, int min, int max);

/* 1 pt: interfaccia funzione */
int sceltaCandidato(int i, int* vincitori, int N);

/* +1 pt: punto bonus se scritta funzione sensata */
void stampaArray(int data[],int ndata);

int main (){
	
  /* 2 pt: azzerare */
  int vincitori[NMAX]= {0};
  
  /* 1 pt : azzerrare numero iscritti */
  int numeroTrasferiti=0;
  int N;
  int i, scelta;	


  /* 1 pt: il seme dei numeri */
  srand48(time(0));	

  /* 1 pt : stampa sensata */  
  printf("Il programma simula la fase B della Buona Scuola");

  N = getInt("numero cattedre",1,NMAX);


  /* 2 pt: ciclo con limiti corretti */	
  for(i=1; i<=N; i++){

    scelta=sceltaCandidato(i,vincitori,N);

    /* 1 pt: aggiornare numero trasferiti */
    if(scelta>1)numeroTrasferiti++;
  }

  /* 2 pt: stampa finale risultati */
  printf("assegnazioni alle regioni:\n");
  stampaArray(vincitori,N);
  printf("sono stati trasferiti %d candidati\n",numeroTrasferiti);
}

//La funzione assegna il  singolo candidato alle cattedre sulla base delle cattedre gia' assegnate e ritorna 
//il numero di scelte che il candidato fa prima di venire assegnato
int sceltaCandidato(int i, int* vincitori, int N){
  int Nscelta=0,ok, regioneScelta;
  do {
    ok=0;// non accora assegnato a regione
    
    /* 2 pt: estrazione scelta */
    regioneScelta = flatInt(N); //effettuo scelta regione


    /* 4 pt: corretta scelta tenendo conto delle regioni occupate */
    if(vincitori[regioneScelta] == 0){
      vincitori[regioneScelta] = i;//assegnazione del candidato alla regione
      ok=1;//Candidato assegnato
    }

    /* 2  pt: conteggio scelte ripetute */
    Nscelta++;
  } while (ok==0);
  return Nscelta;
}


//Ritorna intero uniforme tra 0 ed N-1
int flatInt(int N){
  /* 3 pt: generazione numeri interi casuali */
  return lrand48()%N;;
}

int getInt(const char *s, int min , int max) {

  /* 4 pt: acquisizione del numero intero e controllo sui limiti */
	printf("%s compreso fra %d <= N <= %d\n", s, min, max);
	int var;
	do { 
	    scanf("%d",&var);
	    if(var < min || var > max) printf("Il valore inserito e' fuori range, reinserirlo!\n");
	} while(var < min || var > max); 
        //la funzione continua a chiedere anche nei casi in cui i valori inseriti coincidono con gli estremi
	return var;
}

void stampaArray(int data[], int N){
  int k;
  /* 1 pt: estremi corretti del ciclo */
  for (k=0;k<N;k++) {
    /* 2 pt: stampa informazione */
    printf ("regione: %2d\t candidato:%2d\n",k+1, data[k]);
  }
}
