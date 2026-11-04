#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

int main() {
    FILE *fp;
    int i;
    srand48(time(NULL));
    fp = fopen("casuali.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire casuali.txt\n");
        exit(-1);
    }
    for (i = 0; i < N; i++) {
        fprintf(fp, "%.8f\n", drand48());
    }
    fclose(fp);
}
