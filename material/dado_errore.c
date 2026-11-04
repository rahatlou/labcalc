#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 1, m = 6;
    int faccia, i, sei = 0;
    srand48(time(NULL));
    for (i = 0; i < 1000; i++) {
        faccia = lrand48() % (m - n) + n;    // manca + 1
        if (faccia == 6) {
            sei++;
        }
    }
    printf("su 1000 lanci il 6 compare %d volte\n", sei);
}
