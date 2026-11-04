#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 100000
#define TAU 2.5      // tempo medio di attesa (s)

int main() {
    FILE *fp;
    double u, t, somma = 0.;
    int i, oltre = 0;
    srand48(time(NULL));
    fp = fopen("arrivi.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire arrivi.txt\n");
        exit(-1);
    }
    for (i = 0; i < N; i++) {
        u = drand48();
        t = -TAU * log(1. - u);    // l'esponenziale
        fprintf(fp, "%.6f\n", t);
        somma += t;
        if (t > TAU) {
            oltre++;
        }
    }
    fclose(fp);
    printf("media dei tempi: %.4f\n", somma / N);
    printf("frazione oltre tau: %.4f\n", (double) oltre / N);
}
