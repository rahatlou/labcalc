#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NEXP 50
#define LANCI 100

int main() {
    FILE *fp;
    double frequenza[NEXP];       // una frequenza per esperimento
    double somma = 0., min, max;
    int e, i, teste;
    srand48(time(NULL));
    fp = fopen("frequenze.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire frequenze.txt\n");
        exit(-1);
    }
    for (e = 0; e < NEXP; e++) {
        teste = 0;
        for (i = 0; i < LANCI; i++) {
            if (drand48() < 0.5) {
                teste++;
            }
        }
        frequenza[e] = (double) teste / LANCI;
        fprintf(fp, "%d %.4f\n", e + 1, frequenza[e]);
    }
    fclose(fp);
    min = frequenza[0];
    max = frequenza[0];
    for (e = 0; e < NEXP; e++) {
        somma += frequenza[e];
        if (frequenza[e] < min) {
            min = frequenza[e];
        }
        if (frequenza[e] > max) {
            max = frequenza[e];
        }
    }
    printf("media %.4f, minimo %.2f, massimo %.2f\n", somma / NEXP, min, max);
}
