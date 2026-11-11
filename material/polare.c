#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define R 1.
#define NP 1000

int main() {
    FILE *fp;
    double r, theta;
    int k;
    srand48(time(NULL));
    fp = fopen("polare.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire polare.txt\n");
        exit(-1);
    }
    for (k = 0; k < NP; k++) {
        r = R * drand48();                 // raggio uniforme tra 0 e R
        theta = 2 * M_PI * drand48();      // angolo uniforme tra 0 e 2 pi
        fprintf(fp, "%.6f %.6f\n", r * cos(theta), r * sin(theta));
    }
    fclose(fp);
}
