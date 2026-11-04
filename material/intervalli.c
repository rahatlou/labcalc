#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

int main() {
    int i, n1 = 0, n2 = 0, n3 = 0;
    double x;
    srand48(time(NULL));
    for (i = 0; i < N; i++) {
        x = 7. * drand48();       // un numero in [0, 7)
        if (x < 1)                // [0, 1): larghezza 1
            n1++;
        else if (x < 3)           // [1, 3): larghezza 2
            n2++;
        else                      // [3, 7): larghezza 4
            n3++;
    }
    printf("[0, 1): %d\n", n1);
    printf("[1, 3): %d\n", n2);
    printf("[3, 7): %d\n", n3);
}
