#include <stdio.h>

int main() {
    int n, i;
    double fatt = 1.;
    do {
        printf("n (>= 0): ");
        scanf("%d", &n);
    } while (n < 0);
    for (i = 1; i <= n; i++) {
        fatt *= i;
    }
    printf("%d! = %e\n", n, fatt);
    printf("%d! = %g\n", n, fatt);
}
