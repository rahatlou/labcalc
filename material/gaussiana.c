#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 100000
#define MU 25.00      // valore vero (mm)
#define SIGMA 0.04    // errore della misura (mm)

int main() {
    FILE *fp;
    double u1, u2, z, x;
    int i, entro1 = 0, entro2 = 0;
    srand48(time(NULL));
    fp = fopen("misure.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire misure.txt\n");
        exit(-1);
    }
    for (i = 0; i < N; i++) {
        u1 = drand48();
        u2 = drand48();
        z = sqrt(-2. * log(1. - u1)) * cos(2. * M_PI * u2);
        x = MU + SIGMA * z;
        fprintf(fp, "%.6f\n", x);
        if (fabs(x - MU) < SIGMA) {
            entro1++;
        }
        if (fabs(x - MU) < 2. * SIGMA) {
            entro2++;
        }
    }
    fclose(fp);
    printf("entro 1 sigma: %.1f%%\n", 100. * entro1 / N);
    printf("entro 2 sigma: %.1f%%\n", 100. * entro2 / N);
}
