#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double a = 10., b = 80.;   // in gradi
    double angolo;
    int i;
    srand48(time(NULL));
    for (i = 0; i < 6; i++) {
        angolo = a + (b - a) * drand48();
        printf("%.2f\n", angolo);
    }
}
