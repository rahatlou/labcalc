#include <stdio.h>

int main() {
    int n, i;
    unsigned long long fatt = 1;
    do {
        printf("n (>= 0): ");
        scanf("%d", &n);
    } while (n < 0);
    for (i = 1; i <= n; i++) {
        fatt *= i;
    }
    printf("%d! = %llu\n", n, fatt);
}
