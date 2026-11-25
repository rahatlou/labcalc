#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char tris[3][3];
    int i, j;

    for (i = 0; i < 3; i++) {       // tutte le caselle libere
        for (j = 0; j < 3; j++) {
            tris[i][j] = '.';
        }
    }
    tris[1][1] = 'X';               // il giocatore: il centro

    srand48(time(NULL));
    do {                            // il computer: una casella libera
        i = lrand48() % 3;
        j = lrand48() % 3;
    } while (tris[i][j] != '.');
    tris[i][j] = 'O';

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", tris[i][j]);
        }
        printf("\n");
    }
    return 0;
}
