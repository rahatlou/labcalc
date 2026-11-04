#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    srand48(time(NULL));   // seme = secondi passati dal 1 gennaio 1970
    for (i = 0; i < 4; i++) {
        printf("%.4f\n", drand48());
    }
}
