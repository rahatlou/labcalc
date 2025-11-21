#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define N_SIMUL 1000000
#define N_STEPS_MAX 100

/* 
---> random walk in una dimensione con passo (step) -1 o +1; 
compiere N_SIMUL simulazioni di NSTEP passi e riportare:
- la distribuzione della posizione finale
- la media della distanza tra posizione iniziale e posizione finale
*/

int main() {

  int seed;
  int iSimul, jStep, xStep, finalPos, kCoord;

  int nSteps; // numero di passi da fare
  do{
      printf("Numero passi <= %d: ", N_STEPS_MAX);
      scanf("%d", &nSteps);
  } while( nSteps <=0 || nSteps>N_STEPS_MAX);

  int nSims; // numero di simulazioni da fare
  do{
      printf("Numero simulazioni <= %d: ", N_SIMUL);
      scanf("%d", &nSims);
  } while( nSims <=0 || nSims>N_SIMUL);

  // variabili di appoggio per singola simulazione
  int thisMaxDistance, thisNZeroCrossings;

  // array per la distribuzione della massima distanza raggiunta nel cammino
  int maxDistance[N_STEPS_MAX+1] = {0};  

  // array per la distribuzione del numero di volte che, durante il cammino, si e' ritornati nell'origine x=0
  // al massimo ci puo` passare NSTEP/2 volte
  int nZeroCrossings[N_STEPS_MAX/2] = {0};         

  /* conta il numero di volte nel quale la simulazione termina in posizione: 
    -N_STEPS_MAX, -N_STEPS_MAX+2, ... +N_STEPS_MAX
    ad esempio -20, -18, -16, .... +16, +18, +20 con N_STEPS_MAX = 20) */
  int frequenza[N_STEPS_MAX+1] = {0}; // fondamentale azzerare l'array
  
  // media delle posizioni finali su tutte le simulazioni
  double finalPosMean = 0.;

  // apertura file di output
  FILE* fp;
  fp = fopen("frequenza.txt", "w");
  
  // esci se non posso creare il file
  if(fp==NULL) {
    printf("errore apertura file... exit\n");
    exit(-1);
  }
  

  // seme per la generazione dei numeri casuali
  seed = time(0);
  srand48(seed);

  // ciclo simulazioni
  for(iSimul = 0; iSimul < nSims; iSimul++) {
    
    finalPos = 0; // coordinata di partenza
    thisMaxDistance = 0; // massima distanza

    // numero di volte, durante il cammino, in cui sono ripassato per la posizione di partenza, x=0
    thisNZeroCrossings = 0; 
    
    // ciclo dei passi per il singolo random walk
    for(jStep = 0; jStep < nSteps; jStep++) {
      
      // passo +-1 in base a x in [0.,1.]
      if( (double) lrand48()/ RAND_MAX >0.5) {
        xStep = 1;
      } else {
        xStep = -1;
      }
      
      // aggiorno la posizione      
      finalPos += xStep;                  

      // stampa per debug durante lo sviluppo
      //printf("passo %+d  posizione: %2d\n", xStep, xCoord);

      // nuovo punto lontano
      if(abs(finalPos) > thisMaxDistance) {
	      thisMaxDistance = abs(finalPos);
      }
      
      // sono ripassato per x=0
      if(finalPos == 0)  thisNZeroCrossings++; 

    }

    // stampa ogni 500 simulazioni
    if((iSimul+1)%500 == 0) {
      printf("Simulazione: %6d \t Posizione finale: %+3d\n", iSimul+1, finalPos);
    }

    // relazione tra la posizione xCoord e l'indice kCoord del vettore frequenza
    kCoord = (finalPos + nSteps)/2;

    // printf("finalPos: %+d kCoord: %2d\n", finalPos, kCoord);
    frequenza[kCoord]++;
    
    maxDistance[thisMaxDistance]++;
    nZeroCrossings[thisNZeroCrossings]++;

    // calcolo della posizione finale media su tutte le simulazioni
    finalPosMean += abs(finalPos);
  }
  
  finalPosMean /= nSims;

  printf("*******************************************\n");
  printf("N_passi: %6d \t distanza finale media: %.1lf \n", nSteps, finalPosMean);
  
  printf("\n******************* Sommario posizioni finali *****************\n");
  for(int kCoord = 0; kCoord<(nSteps+1); kCoord++) {
    //printf("Ho terminato la simulazione %5d volte in posizione %+3d\n", frequenza[kCoord], 2*kCoord - N_STEPS_MAX);
    printf("posizione: %+5d \t simulazioni: %10d\n", 2*kCoord - nSteps, frequenza[kCoord]);

    //scrittura s file
    fprintf(fp, "%+5d \t %10d\n", 2*kCoord - nSteps, frequenza[kCoord]);

    
  }
 

  // stampa l'array per lo script in python usando matplotlib.pyplot.bar()
  printf("\n\nfinalPos = [");

  for(int j = 0; j<nSteps; j++) {
    printf("%d, ", frequenza[j]);
  }

  // formato python friendly
  printf("%d]\n\n", frequenza[N_STEPS_MAX]);

  fclose(fp);

} // fine main
