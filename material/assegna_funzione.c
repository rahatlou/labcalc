#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado(int nfacce) {
    int risultato;
    risultato = 1 + drand48() * nfacce;
    return risultato;
}

int main() {
    int x = 3;
    srand48(time(NULL));
    dado(6) = x;
    return 0;
}
