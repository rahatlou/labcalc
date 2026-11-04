#include <stdio.h>

int main() {
    int x = 7;          // il seme, come in piccolo.c
    int i;
    printf("  x  x%%2  x/8\n");
    for (i = 0; i < 12; i++) {
        // x % 2: ultima cifra; x / 8: prima cifra
        printf("%3d   %d    %d\n", x, x % 2, x / 8);
        x = (5 * x + 3) % 16;
    }
}
