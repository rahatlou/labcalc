#include <stdio.h>

int main() {
    int n, i;
    printf("n = ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("%d\t%d\n", i, i * i);
    }
}
