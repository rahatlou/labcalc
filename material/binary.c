#include <stdio.h>
#define NMAX 32

int main() {
    int n, i, ncifre = 0;
    int cifra[NMAX];             // le cifre binarie
    do {
        printf("numero intero positivo: ");
        scanf("%d", &n);
    } while (n <= 0);
    while (n > 0) {
        cifra[ncifre] = n % 2;   // il resto va nella casella ncifre
        n = n / 2;
        ncifre++;
    }
    for (i = ncifre - 1; i >= 0; i--) {   // dall'ultima alla prima
        printf("%d", cifra[i]);
    }
    printf("\n");
}
