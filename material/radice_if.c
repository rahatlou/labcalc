#include <math.h>
#include <stdio.h>

int main() {
    double x;
    printf("x = ");
    scanf("%lf", &x);
    if (x >= 0) {
        printf("radice di %lf = %lf\n", x, sqrt(x));
    } else {
        printf("%lf e' negativo: niente radice reale\n", x);
    }
}
