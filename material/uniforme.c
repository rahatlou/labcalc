#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

double uniforme(double a, double b) {
    return a + (b - a) * drand48();
}

int main() {
    double t, somma = 0.;
    int i;
    srand48(time(NULL));
    for (i = 0; i < 5; i++) {
        t = uniforme(0., 30.);
        printf("arrivo %d: %6.2f minuti\n", i, t);
    }
    for (i = 0; i < N; i++) {
        somma += uniforme(0., 30.);
    }
    printf("media su %d arrivi: %.2f minuti\n", N, somma / N);
    return 0;
}
