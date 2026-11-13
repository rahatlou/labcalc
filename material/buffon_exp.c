/* Esercitazione 5, Parte 2: l'esperimento di Buffon ripetuto N_EXP volte.
   Array di stime, media, minimo, massimo, scrittura su file.
   Compilazione: gcc -Wall -Wextra -o buffon_exp.exe buffon_exp.c -lm
   Dati di prova (d L N_lanci; il seme e l'orologio, quindi i risultati variano):
     4 3 1000     -> media tra 3.11 e 3.18, minimo tra 2.7 e 3.0, massimo tra 3.3 e 3.7
     4 3 100000   -> media tra 3.13 e 3.15, minimo e massimo entro 0.06 da pi
   Dopo l'esecuzione il file pigreco.txt contiene N_EXP righe: numero dell'esperimento e stima. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_EXP 200

int main() {
    double d, L;
    int nlanci;
    double x, theta;
    int i, iexp, S;
    double pigreco[N_EXP];      /* le stime di pi, una per esperimento */
    double somma = 0., media, min, max;
    FILE *fp;

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

    srand48(time(NULL));

    /* Punti 1 e 2: il ciclo esterno ripete l'esperimento, il ciclo interno lancia l'ago.
       S va azzerato a ogni esperimento. */
    for (iexp = 0; iexp < N_EXP; iexp++) {
        S = 0;
        for (i = 0; i < nlanci; i++) {
            x = (d / 2) * drand48();
            theta = (M_PI / 2) * drand48();
            if (x < (L / 2) * sin(theta)) {
                S++;
            }
        }
        if (S == 0) {
            printf("errore: nessun incrocio, impossibile stimare pi\n");
            exit(-1);
        }
        pigreco[iexp] = 2 * L * nlanci / (S * d);
    }

    /* Punto 3: media, minimo e massimo (min e max partono dal primo elemento dell'array) */
    min = pigreco[0];
    max = pigreco[0];
    for (iexp = 0; iexp < N_EXP; iexp++) {
        somma += pigreco[iexp];
        if (pigreco[iexp] < min) {
            min = pigreco[iexp];
        }
        if (pigreco[iexp] > max) {
            max = pigreco[iexp];
        }
    }
    media = somma / N_EXP;
    printf("pi: media %.5f, minimo %.5f, massimo %.5f\n", media, min, max);

    /* Punto 4: file con il numero dell'esperimento (da 1) e la stima */
    fp = fopen("pigreco.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire pigreco.txt\n");
        exit(-1);
    }
    for (iexp = 0; iexp < N_EXP; iexp++) {
        fprintf(fp, "%d %.6f\n", iexp + 1, pigreco[iexp]);
    }
    fclose(fp);
}
