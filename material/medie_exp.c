// Esercitazione 6, Parte 2: stessa media per numeri uniformi in [0,a) e per numeri esponenziali.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NEXP_MAX 100000
#define NDATI_MAX 1000
#define TAU 2.0            // vita media della distribuzione esponenziale

int main() {
    int nexp, ndati;
    double a;
    double media_u[NEXP_MAX];     // medie dei numeri uniformi
    double media_e[NEXP_MAX];     // medie dei numeri esponenziali
    double somma_u, somma_e, mm_u, mm_e, scarti_u, scarti_e, sigma_u, sigma_e;
    int iexp, j;
    FILE *fe;

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

    srand48(time(NULL));

    for (iexp = 0; iexp < nexp; iexp++) {
        somma_u = 0;
        somma_e = 0;
        for (j = 0; j < ndati; j++) {
            somma_u += a * drand48();
            somma_e += -TAU * log(1 - drand48());   // esponenziale per inversione
        }
        media_u[iexp] = somma_u / ndati;
        media_e[iexp] = somma_e / ndati;
    }

    somma_u = 0;
    somma_e = 0;
    for (iexp = 0; iexp < nexp; iexp++) {
        somma_u += media_u[iexp];
        somma_e += media_e[iexp];
    }
    mm_u = somma_u / nexp;
    mm_e = somma_e / nexp;
    scarti_u = 0;
    scarti_e = 0;
    for (iexp = 0; iexp < nexp; iexp++) {
        scarti_u += (media_u[iexp] - mm_u) * (media_u[iexp] - mm_u);
        scarti_e += (media_e[iexp] - mm_e) * (media_e[iexp] - mm_e);
    }
    sigma_u = sqrt(scarti_u / (nexp - 1));
    sigma_e = sqrt(scarti_e / (nexp - 1));

    printf("uniforme:     media %.5f (attesa %.5f)   sigma %.5f (attesa %.5f)\n",
           mm_u, a / 2, sigma_u, a / sqrt(12 * ndati));
    printf("esponenziale: media %.5f (attesa %.5f)   sigma %.5f (attesa %.5f)\n",
           mm_e, TAU, sigma_e, TAU / sqrt(ndati));

    fe = fopen("medie_exp.txt", "w");
    if (fe == NULL) {
        printf("Errore: impossibile aprire medie_exp.txt\n");
        exit(-1);
    }
    for (iexp = 0; iexp < nexp; iexp++) {
        fprintf(fe, "%.6f\n", media_e[iexp]);
    }
    fclose(fe);
    return 0;
}
