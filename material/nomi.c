#include <stdio.h>
#include <string.h>

int main() {
    char nome[20], cognome[20], completo[40];
    int n;

    printf("Nome (max 19 lettere): ");
    scanf("%19s", nome);                        // niente &
    n = strlen(nome);                           // le lettere
    printf("Ciao %s: %d lettere\n", nome, n);

    sprintf(cognome, "%s", "Fermi");            // assegnare
    sprintf(completo, "%s %s", nome, cognome);  // unire due stringhe
    printf("%s\n", completo);

    if (strcmp(nome, "Enrico") == 0) {          // confrontare
        printf("Sei Enrico\n");
    }
    return 0;
}
