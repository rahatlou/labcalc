#include <stdio.h>

int main() {
    int cifra[8];
    double x[100];
    printf("int: %zu byte, cifra[8]: %zu byte\n", sizeof(int), sizeof(cifra));
    printf("double: %zu byte, x[100]: %zu byte\n", sizeof(double), sizeof(x));
}
