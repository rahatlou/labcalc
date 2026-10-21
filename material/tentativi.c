#include <stdio.h>

int main() {
    int voto = -1;          // -1 = non valido
    int ntentativi = 0;
    do {
        printf("voto (0-30): ");
        scanf("%d", &voto);
        ntentativi = ntentativi + 1;
    } while (voto < 0 || voto > 30);
    printf("voto %d registrato\n", voto);
    printf("tentativi: %d\n", ntentativi);
}
