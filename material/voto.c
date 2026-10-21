#include <stdio.h>

int main() {
    int voto;
    do {
        printf("voto (0-30): ");
        scanf("%d", &voto);
    } while (voto < 0 || voto > 30);
    printf("voto %d registrato\n", voto);
}
