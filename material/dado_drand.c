#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 1, m = 6;    // facce da 1 a 6
    int faccia, i;
    srand48(time(NULL));
    for (i = 0; i < 12; i++) {
        faccia = n + (int)(drand48() * (m - n + 1));
        printf("%d ", faccia);
    }
    printf("\n");
}
