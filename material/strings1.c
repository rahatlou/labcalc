#include <stdlib.h>
#include <stdio.h>

int main() {

  // stringa di 10 caratteri al max
  char nome1[10] = "roberta";

  // stampa stringa
  // descrittore %s per stringa caratteri
  printf("nome1: %s\n\n", nome1);
  
  // stampa singoli caratteri e codice ASCII
  for(int i=0; i<10; i++) {
    printf("nome1[%d] = |%c| \t ASCII: %d\n", i, nome1[i], nome1[i]);
  }

  // modifica  carattere con indice 4
  nome1[4] = 'Z';
  printf("\nnome1: %s\n", nome1);

  // modifica  carattere con indice 4 tramite codice ASCII
  nome1[4] = (char)82;
  printf("\nnome1: %s\n", nome1);

  // modifica  carattere con indice 8
  nome1[8] = 'G';
  printf("\nnome1: %s\n", nome1);
  // stampa singoli caratteri e codice ASCII
  for(int i=0; i<10; i++) {
    printf("nome1[%d] = |%c| \t ASCII: %d\n", i, nome1[i], nome1[i]);
  }

  
  // modifica tutta la stringa
  sprintf( nome1, "%s", "giovanni");
  printf("\nnome1: %s\n", nome1);

}// fine main
