#include <stdio.h>

int main() {
    double x;
    double *p;

    p = &x;   // p contiene &x
    printf("Inserisci un valore: ");
    scanf("%lf", p);   // come con &x
    printf("x vale %.2f\n", x);
    return 0;
}
