#include <stdio.h>

#define N 6

int main() {
    // temperature in gradi
    double t[N] = {18.5, 21.0, 19.5, 23.5, 20.0, 22.5};
    double *p;
    double somma = 0., max = t[0];

    for (p = t; p < t + N; p++) {    // p scorre il vettore
        somma = somma + *p;
        if (*p > max) {
            max = *p;
        }
    }
    printf("media %.2f, massima %.1f\n", somma / N, max);
    return 0;
}
