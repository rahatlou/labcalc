#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define TESTA 0
#define CROCE 1

int main() {

  srand48( time(NULL) );

  // contatore di TESTA e CROCE
  int conteggio[2], moneta;

  for(int nexp=10; nexp <= 1e9; nexp*=10) {
    // per ogni nexp inizializzo i contatori
    conteggio[TESTA]= conteggio[CROCE] = 0;

    for(int lancio=0; lancio<nexp; lancio++) {
      moneta = TESTA;
      if( (double)lrand48()/RAND_MAX > 0.5) {
	moneta = CROCE;
      }
      // incremento il contatore per moneta
      conteggio[moneta]++;
      
    } // ciclo lanci
    printf("lanci: %10d \t frazione TESTA %.6f \t frazione CROCE: %.6f\n",
	   nexp, (double)conteggio[TESTA]/nexp, (double)conteggio[CROCE]/nexp);

  } // ciclo nexp


}
