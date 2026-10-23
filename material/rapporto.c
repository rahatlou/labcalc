#include <math.h>
#include <stdio.h>

int main() {
    int i;
    unsigned long long a0 = 1, a1 = 1, an;   // F(1) e F(2)
    printf(" n\tF(n+1)/F(n)\n");
    for (i = 1; i <= 15; i++) {
        printf("%2d\t%.10f\n", i, (double) a1 / a0);
        an = a0 + a1;
        a0 = a1;
        a1 = an;
    }
    printf("phi\t%.10f\n", (1. + sqrt(5.)) / 2.);
}
