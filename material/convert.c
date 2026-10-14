#include <math.h>
#include <stdio.h>

int main() {
    printf("inserisci angolo in gradi: ");
    double angolo;
    scanf("%lf", &angolo);

    double radianti;
    radianti = (angolo / 180.) * M_PI;
    printf("gradi: %lf, rad: %lf\n", angolo, radianti);
}
