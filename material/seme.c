#include <stdio.h>
#include <stdlib.h>

int main() {
    long seme;
    int i;
    printf("seme: ");
    scanf("%ld", &seme);
    srand48(seme);
    for (i = 0; i < 3; i++) {
        printf("%.4f\n", drand48());
    }
}
