#include <stdio.h>

int main() {
    double prezzo[3][2] = {{1.20, 0.80},
                           {1.10, 0.95},
                           {1.35, 0.70}};
    int quantita[2] = {4, 2};      // pezzi per prodotto
    double costo[3];               // uno per negozio
    int i, j;

    for (i = 0; i < 3; i++) {
        costo[i] = 0.;
        for (j = 0; j < 2; j++) {
            costo[i] += prezzo[i][j] * quantita[j];
        }
        printf("negozio %d: %.2f euro\n", i, costo[i]);
    }
    return 0;
}
