/* Esercitazione 5, esercizio facoltativo: la dispersione delle stime in funzione di N_lanci.
   Per N_lanci = 100, 1000, 10000, 100000 si ripete l'esperimento N_EXP volte e si calcola
   la deviazione standard delle stime. d = 4 cm e L = 3 cm sono fissi.
   Compilazione: gcc -Wall -Wextra -o dispersione.exe dispersione.c -lm
   Dopo l'esecuzione il file dispersione.txt contiene una riga per ogni N_lanci: N_lanci e sigma. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N_EXP 200
#define D 4.
#define L 3.

int main() {
    double x, theta;
    int nlanci, i, iexp, S;
    double pigreco[N_EXP];
    double somma, media, sigma;
    FILE *fp;

    srand48(time(NULL));
    fp = fopen("dispersione.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire dispersione.txt\n");
        exit(-1);
    }

    for (nlanci = 100; nlanci <= 100000; nlanci *= 10) {
        for (iexp = 0; iexp < N_EXP; iexp++) {
            S = 0;
            for (i = 0; i < nlanci; i++) {
                x = (D / 2) * drand48();
                theta = (M_PI / 2) * drand48();
                if (x < (L / 2) * sin(theta)) {
                    S++;
                }
            }
            if (S == 0) {
                printf("errore: nessun incrocio, impossibile stimare pi\n");
                exit(-1);
            }
            pigreco[iexp] = 2 * L * nlanci / (S * D);
        }
        /* media e poi deviazione standard campionaria: sigma^2 = somma (x - media)^2 / (N - 1) */
        somma = 0.;
        for (iexp = 0; iexp < N_EXP; iexp++) {
            somma += pigreco[iexp];
        }
        media = somma / N_EXP;
        somma = 0.;
        for (iexp = 0; iexp < N_EXP; iexp++) {
            somma += (pigreco[iexp] - media) * (pigreco[iexp] - media);
        }
        sigma = sqrt(somma / (N_EXP - 1));
        printf("%6d lanci: media %.4f, sigma %.5f\n", nlanci, media, sigma);
        fprintf(fp, "%d %.6f\n", nlanci, sigma);
    }
    fclose(fp);
}
