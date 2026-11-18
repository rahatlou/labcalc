#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado(int nfacce) {
    int risultato;
    risultato = 1 + drand48() * nfacce;
    return risultato;
}

int main() {
    int a, b;
    srand48(time(NULL));
    a = dado(6);
    b = dado(6);
    printf("giocatore A: %d\n", a);
    printf("giocatore B: %d\n", b);
    printf("dado a 20 facce: %d\n", dado(20));
    printf("moneta (1 o 2): %d\n", dado(2));
    return 0;
}
