#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 1.
#define N 100000

int main() {
    double x, y, stima;
    int i, dentro = 0;
    srand48(time(NULL));
    for (i = 0; i < N; i++) {
        x = -R + 2 * R * drand48();
        y = -R + 2 * R * drand48();
        if (x * x + y * y < R * R) {
            dentro++;
        }
    }
    stima = 4. * dentro / N;
    printf("dentro %d su %d: pi = %.5f\n", dentro, N, stima);
}
