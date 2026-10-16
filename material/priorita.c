#include <stdio.h>

int main() {
    double a = 4, b = 3, c = 2;
    printf("a*b/c   = %f\n", a * b / c);
    printf("a/b*c   = %f\n", a / b * c);
    printf("a/(b*c) = %f\n", a / (b * c));
}
