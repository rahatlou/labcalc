#include <stdio.h>

int main() {
    double d1 = 3 / 4;          // divisione tra interi: 0
    double d2 = 3. / 4;         // reale / intero -> reale / reale: 0.75
    printf("3/4  = %lf\n3./4 = %lf\n", d1, d2);

    int a = 2, b = 3;
    double d3 = a / b;                  // interi: 0
    double d4 = (double)a / b;          // cast di a: 0.666...
    double d5 = (double)(a / b);        // cast dopo la divisione: 0
    printf("a/b = %lf\n(double)a/b = %lf\n(double)(a/b) = %lf\n", d3, d4, d5);
}
