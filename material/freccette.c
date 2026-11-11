#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 1.
#define NLANCI 8

int main() {
    double x, y;
    int i;
    srand48(time(NULL));
    for (i = 0; i < NLANCI; i++) {
        x = -R + 2 * R * drand48();      // x tra -R e R
        y = -R + 2 * R * drand48();      // y tra -R e R
        if (x * x + y * y < R * R) {
            printf("%6.3f %6.3f  dentro\n", x, y);
        } else {
            printf("%6.3f %6.3f  fuori\n", x, y);
        }
    }
}
