#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NLANCI 600

int main() {
    int conteggio[6] = {0};       // un contatore per faccia
    int i, faccia;
    srand48(time(NULL));
    for (i = 0; i < NLANCI; i++) {
        faccia = 1 + drand48() * 6;      // da 1 a 6
        conteggio[faccia - 1]++;      // faccia 1 nella casella 0
    }
    for (i = 0; i < 6; i++) {
        printf("faccia %d: %d\n", i + 1, conteggio[i]);
    }
}
