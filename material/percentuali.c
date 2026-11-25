// Esercitazione 6, esercizio facoltativo: quante medie cadono entro 1 e 2 sigma dal valore atteso.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NEXP 20000
#define A 10.0             // numeri uniformi in [0,A)
#define TAU 2.0            // numeri esponenziali di vita media TAU
#define NVALORI 6

int main() {
    int valori[NVALORI] = {1, 2, 5, 10, 30, 100};   // numero di dati per esperimento
    int k, iexp, j, ndati;
    double somma_u, somma_e, media_u, media_e, sig_u, sig_e;
    int u1, u2, e1, e2;                              // contatori entro 1 e 2 sigma
    FILE *fp;

    srand48(time(NULL));
    fp = fopen("percentuali.txt", "w");
    if (fp == NULL) {
        printf("Errore: impossibile aprire percentuali.txt\n");
        exit(-1);
    }

    printf("  ndati   unif 1s   exp 1s   unif 2s   exp 2s\n");
    for (k = 0; k < NVALORI; k++) {
        ndati = valori[k];
        sig_u = A / sqrt(12 * ndati);     // sigma attesa delle medie
        sig_e = TAU / sqrt(ndati);
        u1 = 0; u2 = 0; e1 = 0; e2 = 0;
        for (iexp = 0; iexp < NEXP; iexp++) {
            somma_u = 0;
            somma_e = 0;
            for (j = 0; j < ndati; j++) {
                somma_u += A * drand48();
                somma_e += -TAU * log(1 - drand48());
            }
            media_u = somma_u / ndati;
            media_e = somma_e / ndati;
            if (fabs(media_u - A / 2) < sig_u) u1++;
            if (fabs(media_u - A / 2) < 2 * sig_u) u2++;
            if (fabs(media_e - TAU) < sig_e) e1++;
            if (fabs(media_e - TAU) < 2 * sig_e) e2++;
        }
        printf("%7d %9.4f %8.4f %9.4f %8.4f\n", ndati,
               1.0 * u1 / NEXP, 1.0 * e1 / NEXP, 1.0 * u2 / NEXP, 1.0 * e2 / NEXP);
        fprintf(fp, "%d %.4f %.4f %.4f %.4f\n", ndati,
                1.0 * u1 / NEXP, 1.0 * e1 / NEXP, 1.0 * u2 / NEXP, 1.0 * e2 / NEXP);
    }
    fclose(fp);
    return 0;
}
