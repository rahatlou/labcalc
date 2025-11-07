#include <stdlib.h>
#include <stdio.h>
#define LMAX 10

int main() {

  // dichiarazione di stringhe
  char nome[LMAX];
  char cognome[LMAX];

  printf("nome (max 9 lettere)? ");
  // input variabile stringa
  // NB: non serve & prima della variabile stringa
  scanf("%s", nome);

  // descrittore %s per stringa caratteri
  printf("nome inserito: |%s|\n", nome);

  // errore comune
  //cognome = "Einstein";

  // assegnare un nuovo valore alla stringa cognome
  sprintf(cognome, "%s", "Einstein");
  printf("cognome: |%s|\n", cognome);

  // creazione di una nuova stringa unendo due stringhe
  char nomecompleto[50];
  sprintf(nomecompleto, "%s %s", nome, cognome);
  printf("completo: |%s|\n", nomecompleto);

} // fine main
