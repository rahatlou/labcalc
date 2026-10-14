#include <math.h>
#include <stdio.h>

int main() {
    int scelta;
    double x;
    printf("0 = gradi->rad, 1 = rad->gradi: ");
    scanf("%d", &scelta);
    printf("valore: ");
    scanf("%lf", &x);
    if (scelta == 0) {
        printf("%lf gradi = %lf rad\n", x, x / 180. * M_PI);
    } else if (scelta == 1) {
        printf("%lf rad = %lf gradi\n", x, x / M_PI * 180.);
    } else {
        printf("scelta non valida: %d\n", scelta);
    }
}
