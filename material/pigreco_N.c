#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define R 1.

int main() {
    FILE *fp;
    double x, y, stima, errore;
    int n, i, dentro;
    srand48(time(NULL));
    fp = fopen("pigreco.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire pigreco.txt\n");
        exit(-1);
    }
    for (n = 100; n <= 10000000; n *= 10) {
        dentro = 0;
        for (i = 0; i < n; i++) {
            x = -R + 2 * R * drand48();
            y = -R + 2 * R * drand48();
            if (x * x + y * y < R * R) {
                dentro++;
            }
        }
        stima = 4. * dentro / n;
        errore = fabs(stima - M_PI);
        printf("freccette: %-8d pi: %.5f errore: %.5f\n",
               n, stima, errore);
        fprintf(fp, "%d %.8f %.8f\n", n, stima, errore);
    }
    fclose(fp);
}
