#include <stdio.h>

double quadrato(double x) {
    double r = x * x;          // r di quadrato
    return r;
}

double meta(double x) {
    double r = x / 2;          // altra r, di meta
    return r;
}

int main() {
    double r = 100;            // la r di main
    printf("quadrato(3) = %.1f\n", quadrato(3));
    printf("meta(3)     = %.1f\n", meta(3));
    printf("r di main   = %.1f\n", r);
    return 0;
}
