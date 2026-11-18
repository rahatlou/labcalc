#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

double uniforme(double a, double b) {
    return a + (b - a) * drand48();
}

int main() {
    FILE *fp;
    int i;
    srand48(time(NULL));
    fp = fopen("arrivi.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire arrivi.txt\n");
        exit(-1);
    }
    for (i = 0; i < N; i++) {
        fprintf(fp, "%.6f\n", uniforme(0., 30.));
    }
    fclose(fp);
    return 0;
}
