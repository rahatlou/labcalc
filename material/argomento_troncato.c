#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado(int nfacce) {
    int risultato;
    risultato = 1 + drand48() * nfacce;
    return risultato;
}

int main() {
    int i, massimo = 0, r;
    double facce = 2.5;
    srand48(time(NULL));
    for (i = 0; i < 1000; i++) {
        r = dado(facce);
        if (r > massimo) {
            massimo = r;
        }
    }
    printf("massimo: %d\n", massimo);
    return 0;
}
