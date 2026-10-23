#include <stdio.h>

int main() {
    int n, i;
    unsigned long long a0 = 0, a1 = 1, an;   // F(0) e F(1)
    do {
        printf("n (1-93): ");
        scanf("%d", &n);
    } while (n < 1 || n > 93);
    printf("F(1) = %llu\n", a1);
    for (i = 2; i <= n; i++) {
        an = a0 + a1;
        a0 = a1;
        a1 = an;
        printf("F(%d) = %llu\n", i, an);
    }
}
