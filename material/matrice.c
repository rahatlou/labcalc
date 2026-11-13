#include <stdio.h>

int main() {
    // 3 negozi (righe) x 2 prodotti (colonne)
    double prezzo[3][2] = {{1.20, 0.80},
                           {1.10, 0.95},
                           {1.35, 0.70}};
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("%6.2f", prezzo[i][j]);
        }
        printf("\n");
    }
    return 0;
}
