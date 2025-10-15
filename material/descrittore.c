#include <stdio.h>

int main() {
    double a = 1234.567;
    double b = 0.0001234567;

    printf("Con %%f:\n");
    printf("Valore di a = %f\n", a);
    printf("Valore di b = %f\n\n", b);

    printf("Con %%5.3f:\n");
    printf("a = %5.3f\n", a);
    printf("b = %5.3f\n\n", b);

    printf("Con %%5.3e:\n");
    printf("a = %5.3e\n", a);
    printf("b = %5.3e\n\n", b);

    printf("Con %%5.3g:\n");
    printf("a = %5.3g\n", a);
    printf("b = %5.3g\n", b);

    return 0;
}
