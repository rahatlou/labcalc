#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 10

int main() {
    double punti[N][2];            // riga i = punto i: x e y
    double cx = 0., cy = 0., dx, dy, d, dmax = 0.;
    int i;
    srand48(time(NULL));
    for (i = 0; i < N; i++) {
        punti[i][0] = -1 + 2 * drand48();
        punti[i][1] = -1 + 2 * drand48();
        printf("punto %d: %6.3f %6.3f\n", i, punti[i][0], punti[i][1]);
        cx += punti[i][0];
        cy += punti[i][1];
    }
    cx /= N;
    cy /= N;
    printf("baricentro: %6.3f %6.3f\n", cx, cy);
    for (i = 0; i < N; i++) {
        dx = punti[i][0] - cx;
        dy = punti[i][1] - cy;
        d = sqrt(dx * dx + dy * dy);
        if (d > dmax) {
            dmax = d;
        }
    }
    printf("distanza massima dal baricentro: %.3f\n", dmax);
    return 0;
}
