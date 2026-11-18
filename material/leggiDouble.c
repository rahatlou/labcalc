#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double leggiDouble(double min, double max);
double uniforme(double a, double b);

int main() {
    double a, b, x;
    srand48(time(NULL));
    a = leggiDouble(0, 10);
    b = leggiDouble(a, 20);
    x = uniforme(a, b);
    printf("estratto: %.3f in [%g, %g]\n", x, a, b);
    return 0;
}

double leggiDouble(double min, double max) {
    double v;
    do {
        printf("Inserisci un valore tra %g e %g: ", min, max);
        scanf("%lf", &v);
    } while (v < min || v > max);
    return v;
}

double uniforme(double a, double b) {
    return a + (b - a) * drand48();
}
