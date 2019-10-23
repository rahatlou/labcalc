#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

/* 1pt: inclusione di header file necessari */

#define DT      0.001
#define E0MIN   0.
#define E0MAX  10.0
#define fMin  0.03
#define fMax  0.10
#define ECUT    0.5
#define LMIN    0.
#define LMAX   17.0
#define kMin   0.05
#define kMax   0.08
#define NEXP   1000

int main() {

  double E0, L, En, ypos, ymax, tempo;
  double dE, dy;
  int iexp;

  int nPass, minPass=RAND_MAX,maxPass=0;
  double avgPass=0.;

  /* file di output */
  FILE* fout = NULL;
  char nomef[] = "risultati.txt";

  /* 1pt: inizializzare il seme correttamente */
  /* inizializza generatore num casuali */
  srand48(time(0));

  /* 1pt: stampa messaggio iniziale */
  printf("Simulazione del passaggio di un elettrone nella materia\n");

  /* 2pt: acquisizione E0 */
  /* acquisizione di E0 */
  do{
    printf("Inserisci energia iniziale E0 tra [%.2lf,%.2lf] MeV: ", E0MIN, E0MAX);
    scanf("%lf",&E0);
  } while( E0<E0MIN || E0>E0MAX );
  
  /* 1pt: acquisizione L */
  /* acquisizione di L */
  do{
    printf("Inserisci lato rivelatore L tra [%.2lf,%.2lf] cm: ", LMIN, LMAX);
    scanf("%lf",&L);
  } while( L<LMIN || L>LMAX );
  

  /* 1pt: corretta apertura del file */
  /* apertuta file */
  fout = fopen(nomef,"w");
  if( fout==NULL ) {
    printf("problemi con apertura file. termine programma...\n");
    exit(-1);
  }

  /* 2pt: scelta ciclo corretto */
  /* ciclo esperimenti */
  for(iexp=0; iexp<NEXP; iexp++) {

    /* 2pt: inizializzazione delle variabili per singolo esperimento */
    ypos = ymax = 0;
    En = E0; 
    tempo = 0.;
    nPass = 0;

    /* 2pt: ciclo e condizioni corrette per singolo esperimento */
    /* ciclo propagazione */
    do{
      
      dE  = En*(fMin +(fMax-fMin)*lrand48()/RAND_MAX);

      dy  = L*(kMin + (kMax-kMin)*lrand48()/RAND_MAX);
      /* 50% probabilita` di avere dy < 0 */
      if( (double)lrand48()/RAND_MAX < 0.5 ) dy = -dy;

      En -= dE;
      ypos += dy;
      tempo += DT;
      nPass++;

      /* 2pt : calcolo posizione massima */
      /* aggiorna posizione max */
      if( fabs(ypos) > fabs(ymax) ) ymax = ypos;

    } while( fabs(ypos) <= L && En > ECUT ); /* fine propagazione */

    /* 2pt: scrittura sul file */
    /* scrivere sul file i numeri al termine della propogazione */
    fprintf(fout,"%4.3lf\t %-4.3lf\t %3.3lf\n", En, ymax, tempo);

    /* tieni conto del numero di passi */
    avgPass += nPass;
    if(nPass>maxPass) maxPass = nPass;
    if(nPass<minPass) minPass = nPass;

  } /* ciclo esperimenti */

  avgPass /= NEXP;

  printf("fine esperimenti\n");
  printf("num min passi: %d  num medio passi: %.1f  num max passi: %d\n",
         minPass, avgPass, maxPass); 



  /* 1pt: chiusura del file */
  /* chiudere file */
  fclose(fout);
  printf("risultati scritti in %s\n", nomef);

  return 0; 
}
/* fine main*/


