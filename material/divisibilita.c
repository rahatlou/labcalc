#include <stdio.h>

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("%d pari\n", n);
    } else {
        printf("%d dispari\n", n);
    }

    if (n % 3 == 0 && n % 5 == 0) {
        printf("multiplo di 3 e 5\n");
    } else if (n % 3 == 0 || n % 5 == 0) {
        printf("multiplo di 3 o 5\n");
    } else {
        printf("nessun multiplo\n");
    }

    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
        printf("anno %d bisestile\n", n);
    } else {
        printf("anno %d non bisestile\n", n);
    }
}
