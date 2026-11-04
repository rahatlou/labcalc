// Variante per approfondire (non e nelle slide): si sceglie l'intervallo con una estrazione e il punto con un'altra.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

int main() {
    FILE *fp;
    int i;
    double u, x;
    srand48(time(NULL));
    fp = fopen("intervalli_prob.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire intervalli_prob.txt\n");
        exit(-1);
    }
    for (i = 0; i < N; i++) {
        u = drand48();                // intervallo
        if (u < 0.5)                  // 50%: [0, 1)
            x = 0. + 1. * drand48();
        else if (u < 0.8)             // 30%: [1, 3)
            x = 1. + 2. * drand48();
        else                          // 20%: [3, 7)
            x = 3. + 4. * drand48();
        fprintf(fp, "%.8f\n", x);
    }
    fclose(fp);
}
