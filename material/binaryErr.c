#include <stdio.h>

int main() {
    int n, resto;
    printf("numero intero positivo: ");
    scanf("%d", &n);
    while (n > 0) {
        resto = n % 2;
        printf("%d", resto);    // stampo subito il resto
        n = n / 2;
    }
    printf("\n");
}
