#include <stdio.h>

int main() {
    int n = 12;
    double x = 2.5;
    int *p = &n;
    double *q = &x;

    printf("sizeof(n)  = %zu\n", sizeof(n));
    printf("sizeof(x)  = %zu\n", sizeof(x));
    printf("sizeof(p)  = %zu\n", sizeof(p));
    printf("sizeof(q)  = %zu\n", sizeof(q));
    return 0;
}
