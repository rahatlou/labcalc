/* Esercitazione 2, Parte 1: che giorno della settimana (formula di Zeller).
   Solo interi, operatori / e %, if/else.
   Compilazione: gcc -Wall -Wextra -o zeller.exe zeller.c
   Dati di prova (giorno mese anno):
     1 1 2000   -> h = 0, sabato
     29 2 2024  -> h = 5, giovedi
     14 7 1789  -> h = 3, martedi
     32 5 2020  -> data non valida */
#include <stdio.h>

int main() {
    int giorno, mese, anno;   /* la data inserita dall'utente */
    int m, a;                 /* mese e anno da usare nella formula */
    int K, J, h;

    /* Punto 1: tre scanf separati, ciascuno preceduto da un printf */
    printf("giorno: ");
    scanf("%d", &giorno);
    printf("mese (1-12): ");
    scanf("%d", &mese);
    printf("anno: ");
    scanf("%d", &anno);

    /* Punto 2: controllo di validita con la condizione composta ||;
       i calcoli dei punti seguenti stanno nel ramo else */
    if (giorno < 1 || giorno > 31 || mese < 1 || mese > 12) {
        printf("data non valida\n");
    } else {
        /* Punto 3: gennaio e febbraio sono i mesi 13 e 14 dell'anno precedente */
        if (mese == 1 || mese == 2) {
            m = mese + 12;
            a = anno - 1;
        } else {
            m = mese;
            a = anno;
        }
        K = a % 100;   /* le ultime due cifre dell'anno: resto della divisione per 100 */
        J = a / 100;   /* le prime due cifre: divisione intera per 100 */

        /* Punto 4: la formula di Zeller. Con gli interi 13 * (m + 1) / 5 calcola
           prima il prodotto e poi la divisione intera, come richiede la formula;
           anche K / 4 e J / 4 sono divisioni intere */
        h = (giorno + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
        /* printf("h = %d\n", h);    stampa di controllo del punto 4, sostituita dal punto 5 */

        /* Punto 5: h = 0 e sabato, 1 domenica, ..., 6 venerdi (nomi senza accento) */
        if (h == 0) {
            printf("sabato\n");
        } else if (h == 1) {
            printf("domenica\n");
        } else if (h == 2) {
            printf("lunedi\n");
        } else if (h == 3) {
            printf("martedi\n");
        } else if (h == 4) {
            printf("mercoledi\n");
        } else if (h == 5) {
            printf("giovedi\n");
        } else {
            printf("venerdi\n");   /* resta solo h == 6 */
        }
    }
}
