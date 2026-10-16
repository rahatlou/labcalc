#include <stdio.h>

int main() {
    double p;
    printf("p = ");
    scanf("%lf", &p);

    if (p >= 0 && p <= 1) {
        printf("p valida\n");
    } else {
        printf("p non valida\n");
    }

    int dentro = (p >= 0 && p <= 1);
    int fuori = (p < 0 || p > 1);
    printf("dentro = %d, fuori = %d, !dentro = %d\n", dentro, fuori, !dentro);
}
