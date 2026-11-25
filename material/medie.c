// Esercitazione 6, Parte 1: distribuzione della media di Ndati numeri casuali uniformi in [0,a).
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NEXP_MAX 100000    // massimo numero di esperimenti
#define NDATI_MAX 1000     // massimo numero di dati per esperimento

int main() {
    int nexp, ndati;
    double a;
    double media[NEXP_MAX];       // la media di ogni esperimento
    double somma, mm, scarti, sigma;
    int iexp, j;
    FILE *fp;

    // input, uno alla volta, con validazione
    do {
        printf("Numero di esperimenti [2,%d]: ", NEXP_MAX);
        scanf("%d", &nexp);
    } while (nexp < 2 || nexp > NEXP_MAX);
    do {
        printf("Estremo a, numeri in [0,a) (0 < a <= 100): ");
        scanf("%lf", &a);
    } while (a <= 0 || a > 100);
    do {
        printf("Numero di dati per esperimento [1,%d]: ", NDATI_MAX);
        scanf("%d", &ndati);
    } while (ndati < 1 || ndati > NDATI_MAX);

    srand48(time(NULL));          // una sola volta, dopo gli input

    // ogni esperimento: media di ndati numeri uniformi in [0,a)
    for (iexp = 0; iexp < nexp; iexp++) {
        somma = 0;
        for (j = 0; j < ndati; j++) {
            somma += a * drand48();
        }
        media[iexp] = somma / ndati;
    }

    // media e deviazione standard campionaria delle medie
    somma = 0;
    for (iexp = 0; iexp < nexp; iexp++) {
        somma += media[iexp];
    }
    mm = somma / nexp;
    scarti = 0;
    for (iexp = 0; iexp < nexp; iexp++) {
        scarti += (media[iexp] - mm) * (media[iexp] - mm);
    }
    sigma = sqrt(scarti / (nexp - 1));

    // valori attesi dal teorema del limite centrale: mu = a/2, sigma = a/sqrt(12 ndati)
    printf("media delle medie:  %.5f   attesa %.5f\n", mm, a / 2);
    printf("sigma delle medie:  %.5f   attesa %.5f\n", sigma, a / sqrt(12 * ndati));

    fp = fopen("medie.txt", "w");
    if (fp == NULL) {
        printf("Errore: impossibile aprire medie.txt\n");
        exit(-1);
    }
    for (iexp = 0; iexp < nexp; iexp++) {
        fprintf(fp, "%.6f\n", media[iexp]);
    }
    fclose(fp);
    return 0;
}
