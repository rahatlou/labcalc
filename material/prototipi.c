#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado(int nfacce);
double uniforme(double a, double b);

int main() {
    int i;
    srand48(time(NULL));
    for (i = 0; i < 5; i++) {
        printf("dado a 20 facce: %2d   tensione: %.3f V\n", dado(20), uniforme(3.0, 3.6));
    }
    return 0;
}

int dado(int nfacce) {
    return 1 + drand48() * nfacce;
}

double uniforme(double a, double b) {
    return a + (b - a) * drand48();
}
