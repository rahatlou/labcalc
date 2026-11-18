#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado(int nfacce) {
    int risultato;
    risultato = 1 + drand48() * nfacce;
    return risultato;
}

int main() {
    srand48(time(NULL));
    dado(6);
    printf("ho tirato il dado\n");
    return 0;
}
