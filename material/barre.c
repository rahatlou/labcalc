#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void titolo(void) {
    printf("faccia   lanci\n");
}

void barra(int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    int conteggio[6] = {0};
    int lancio, faccia;
    srand48(time(NULL));
    for (lancio = 0; lancio < 60; lancio++) {
        faccia = 1 + drand48() * 6;
        conteggio[faccia - 1]++;
    }
    titolo();
    for (faccia = 1; faccia <= 6; faccia++) {
        printf("%4d     ", faccia);
        barra(conteggio[faccia - 1]);
    }
    return 0;
}
