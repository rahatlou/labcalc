#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

int main() {
    int i, pari = 0, rivelati = 0;
    double eff = 0.85;           // efficienza del rivelatore
    srand48(time(NULL));
    for (i = 0; i < 20; i++) {
        if (drand48() < 0.5)
            printf("P ");
        else
            printf("D ");
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        if (drand48() < 0.5)     // p = 0.5
            pari++;
        if (drand48() < eff)     // p = eff
            rivelati++;
    }
    printf("pari: %d su %d\n", pari, N);
    printf("rivelati: %d su %d\n", rivelati, N);
}
