// Per curiosi (usa gli array, che arrivano dopo): confronta i primi P valori con i P successivi.
// lrand48() % 2 si ripete identico dopo P = 2^18 = 262144 estrazioni; drand48() < 0.5 no.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define P 262144

int a[2 * P], b[2 * P];

int main() {
    int i, uguali_a = 0, uguali_b = 0;
    long seme = time(NULL);      // lo stesso seme per le due prove
    srand48(seme);
    for (i = 0; i < 2 * P; i++)
        a[i] = lrand48() % 2;
    srand48(seme);
    for (i = 0; i < 2 * P; i++)
        b[i] = drand48() < 0.5;
    for (i = 0; i < P; i++) {
        if (a[i] == a[i + P])
            uguali_a++;
        if (b[i] == b[i + P])
            uguali_b++;
    }
    printf("con il resto:  %d uguali su %d\n", uguali_a, P);
    printf("con drand48(): %d uguali su %d\n", uguali_b, P);
}
