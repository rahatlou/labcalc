#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 1.
#define NP 1000

int main() {
    FILE *fp;
    double x, y;
    int k, tentativi = 0;
    srand48(time(NULL));
    fp = fopen("cerchio.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire cerchio.txt\n");
        exit(-1);
    }
    for (k = 0; k < NP; k++) {
        do {
            x = -R + 2 * R * drand48();
            y = -R + 2 * R * drand48();
            tentativi++;
        } while (x * x + y * y > R * R);
        fprintf(fp, "%.6f %.6f\n", x, y);
    }
    fclose(fp);
    printf("%d punti, %d tentativi: efficienza %.3f\n", NP, tentativi, (double) NP / tentativi);
}
