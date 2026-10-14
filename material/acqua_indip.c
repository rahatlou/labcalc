#include <stdio.h>

int main() {
    double T;
    printf("temperatura (C): ");
    scanf("%lf", &T);
    if (T < 0)
        printf("ghiaccio\n");
    if (T < 100)
        printf("acqua liquida\n");
    if (T >= 100)
        printf("vapore\n");
}
