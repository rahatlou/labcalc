#include <stdlib.h>
#include <stdio.h>
#define LMAX 10

int main() {

  char nome[LMAX];
  char cognome[LMAX];

  printf("nome (max 9 lettere)? ");
  scanf("%s", nome);

  printf("nome inserito: |%s|\n", nome);

  for(int i=0; i<LMAX; i++) {
    printf("nome[%d] = |%c| \t ASCII: %d\n", i, nome[i], nome[i]);
  }

  // errore comune
  //cognome = "Einstein";
    
  sprintf(cognome, "%s", "Einstein");
  printf("cognome: |%s|\n", cognome);

  char nomecompleto[50];
  sprintf(nomecompleto, "%s %s", nome, cognome);
  printf("completo: |%s|\n", nomecompleto);

  
}
