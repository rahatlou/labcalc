#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define N_SIMUL 10000
#define N_STEPS_MAX 1000

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
  
  // variabili di appoggio per singola simulazione
  int thisMaxDistance, thisNStepsToZeroAgain, thisNZeroCrossings;

  // array per la distribuzione della massima distanza raggiunta nel cammino
  int maxDistance[N_STEPS_MAX+1] = {0};  

  // array per la distribuzione del numero di volte che, durante il cammino, si e' ritornati nell'origine x=0
  // al massimo ci puo` passare NSTEP/2 volte
  int nZeroCrossings[N_STEPS_MAX+1] = {0};         


  /* conta il numero di volte nel quale la simulazione termina in posizione: -N_STEPS_MAX, -N_STEPS_MAX+2, ... +N_STEPS_MAX
  ad esempio -20, -18, -16, .... +16, +18, +20 con N_STEPS_MAX = 20) */
  int frequenza[N_STEPS_MAX+1] = {0}; // fondamentale azzerare l'array
  
  // media delle posizioni finali tra tutte le simulazioni per numero passi fissato
  double finalPosMean = 0.;

  // seme per la generazione dei numeri casuali
  seed = time(0);
  srand48(seed);

  // ciclo per variare nSteps
  for(nSteps = 2; nSteps<N_STEPS_MAX; nSteps *=2){ 

    // azzerare tutte le quantita` visto che vogiamo ripetere al variare di nSteps
    for(int i=0; i< N_STEPS_MAX; i++) {
      maxDistance[i] = nZeroCrossings[i] = frequenza[i] = 0;
    }

    finalPosMean = 0;
    
    // ciclo simulazioni
    for(iSimul = 0; iSimul < N_SIMUL; iSimul++) {
      
      finalPos = 0; // coordinata di partenza
      thisMaxDistance = 0; // massima distanza
      thisNZeroCrossings = 0; // numero di volte, durante il cammino, in cui sono ripassato per la posizione di partenza, x=0
    
      // ciclo dei passi per il random walk
      for(jStep = 0; jStep < nSteps; jStep++) {
	// passo +-1 in base a x in [0.,1.]
	if( (double) lrand48()/ RAND_MAX >0.5) {	\
	  xStep = 1;
	} else {
	  xStep = -1;
	}
	// aggiorno la posizione        
	finalPos += xStep;  
	
	if(abs(finalPos) > thisMaxDistance) {thisMaxDistance = abs(finalPos);}
	if(finalPos == 0) thisNZeroCrossings++; // sono ripassato per x=0
      } // fine random walk
      
      // relazione tra la posizione finalPos e l'indice kCoord del vettore frequenza
      kCoord = (finalPos + nSteps)/2;
      // printf("finalPos: %+d kCoord: %2d\n", finalPos, kCoord);
      frequenza[kCoord]++;
    
      maxDistance[thisMaxDistance]++;
      nZeroCrossings[thisNZeroCrossings]++;

      // calcolo della posizione finale media su tutte le simulazioni
      finalPosMean += abs(finalPos);

    } // ciclo simulazioni
    finalPosMean /= N_SIMUL;

    printf("nsteps: %4d \t Average max dist: %.1f\n", nSteps, finalPosMean);

  } // fine ciclo nSteps 


} // end of main
