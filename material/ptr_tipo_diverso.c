#include <stdio.h>

int main() {
    double x = 2.5;
    int *p = &x;   // x e un double

    printf("%d\n", *p);
    return 0;
}
