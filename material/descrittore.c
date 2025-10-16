#include <stdio.h>

int main() {
    double a = 12345678.123456789;
    double b = 0.0001234567;

    printf("Con %%f:senza specificare numero di decimali\n");
    printf("Valore di a = %f\n", a);
    printf("Valore di b = %f\n\n", b);

    printf("Con %%5.3f: almeno 5 cifre (incluso .) e 3 decimali\n");
    printf("a = %5.3f\n", a);
    printf("b = %5.3f\n\n", b);

    printf("Con %%5.3e: notazione esponenziale/scientifica con 3 decimali\n");
    printf("a = %5.3e\n", a);
    printf("b = %5.3e\n\n", b);

    printf("Con %%5.3g: notazione compatta con 3 cifre significative ed almeno 5 cifre totali (incluso .) \n");
    printf("a = %5.3g\n", a);
    printf("b = %5.3g\n\n", b);

    printf("Con %%.15f: con 15 cifre decimali\n");
    printf("a = %.15f\n", a);
    printf("b = %.15f\n\n", b);

    
    return 0;
}
