#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
#define TMIN 8.     // minima media a Roma in novembre (gradi C)
#define TMAX 16.    // massima media a Roma in novembre (gradi C)

int main() {
    double t[N];
    double somma = 0., min, max;
    int i;
    srand48(time(NULL));
    for (i = 0; i < N; i++) {
        t[i] = TMIN + (TMAX - TMIN) * drand48();    // tra TMIN e TMAX
        printf("temperatura giorno %d: %.1f\n", i + 1, t[i]);
    }
    min = t[0];
    max = t[0];
    for (i = 0; i < N; i++) {
        somma += t[i];
        if (t[i] < min) {
            min = t[i];
        }
        if (t[i] > max) {
            max = t[i];
        }
    }
    printf("media %.2f, minimo %.2f, massimo %.2f\n",
           somma / N, min, max);
}
