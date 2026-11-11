#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TESTA 0
#define CROCE 1

int main() {
    FILE *fp;
    int n, i;                     // n arriva a 10 milioni
    int conteggio[2] = {0};
    int moneta;
    double f;
    srand48(time(NULL));
    fp = fopen("moneta_errore.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire moneta_errore.txt\n");
        exit(-1);
    }
    for (n = 10; n <= 10000000; n *= 10) {
        for (i = 0; i < n; i++) {
            moneta = CROCE;
            if (drand48() < 0.5) {
                moneta = TESTA;
            }
            conteggio[moneta]++;
        }
        f = (double) conteggio[TESTA] / n;
        printf("lanci: %-8d teste: %8d frequenza: %.6f\n",
               n, conteggio[TESTA], f);
        fprintf(fp, "%ld %.8f %.8f\n", n, f, fabs(f - 0.5));
    }
    fclose(fp);
}
