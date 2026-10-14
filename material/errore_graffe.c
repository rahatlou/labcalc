#include <stdio.h>

int main() {
    double x;
    printf("x = ");
    scanf("%lf", &x);
    if (x < 0)
        printf("x negativo: cambio il segno\n");
        x = -x;
    printf("|x| = %lf\n", x);
}
