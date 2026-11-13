/* Esercitazione 5, Parte 1: stima di pi con l'ago di Buffon (un solo esperimento).
   Numeri casuali con drand48(), cicli do/while, math.h.
   Compilazione: gcc -Wall -Wextra -o buffon.exe buffon.c -lm
   Dati di prova (d L N_lanci, da inserire uno alla volta; il seme e l'orologio, quindi i risultati variano):
     4 3 100000   -> S circa 47700, pi tra 3.10 e 3.18
     2 1 100000   -> S circa 31800, pi tra 3.09 e 3.19
     5 0 4  4 7 3  10 2000000 100000 -> input rifiutati e riletti, poi come la prima riga */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double d, L;                /* distanza tra le linee e lunghezza dell'ago, in cm */
    int nlanci;                 /* numero di lanci */
    double x, theta;            /* distanza del centro dell'ago dalla linea piu vicina e angolo */
    int i, S = 0;               /* contatore e numero di lanci in cui l'ago incrocia una linea */
    double pigreco;

    /* Punto 1: tre input, ciascuno riletto finche non e valido (ordine d, L, N_lanci).
       Prima si controlla d, cosi la condizione su L (L < d) ha senso. */
    do {
        printf("distanza d tra le linee in cm (0 < d < 5): ");
        scanf("%lf", &d);
    } while (d <= 0. || d >= 5.);

    do {
        printf("lunghezza L dell'ago in cm (0 < L < %g): ", d);
        scanf("%lf", &L);
    } while (L <= 0. || L >= d);

    do {
        printf("numero di lanci (1000 <= N_lanci <= 1000000): ");
        scanf("%d", &nlanci);
    } while (nlanci < 1000 || nlanci > 1000000);

    /* Il seme si inizializza una sola volta, all'inizio della parte che usa i numeri casuali */
    srand48(time(NULL));

    /* Punti 2 e 3: ogni lancio estrae x in [0, d/2] e theta in [0, pi/2];
       l'ago incrocia una linea se x < (L/2) sin(theta) */
    for (i = 0; i < nlanci; i++) {
        x = (d / 2) * drand48();
        theta = (M_PI / 2) * drand48();
        if (x < (L / 2) * sin(theta)) {
            S++;
        }
    }

    /* Punto 4: con S = 0 la formula divide per zero */
    if (S == 0) {
        printf("errore: nessun incrocio, impossibile stimare pi\n");
        exit(-1);
    }
    pigreco = 2 * L * nlanci / (S * d);

    /* Punto 5 */
    printf("incroci S = %d su %d lanci\n", S, nlanci);
    printf("pi stimato = %.5f\n", pigreco);
}
