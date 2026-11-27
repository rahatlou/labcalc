#include <stdio.h>

int main() {
    // 3 negozi (righe) x 2 prodotti (colonne)
    double prezzo[3][2] = {{1.20, 0.80},
                           {1.10, 0.95},
                           {1.35, 0.70}};
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("prezzo[%d][%d] = %.2f  %p  %.2f\n", i, j,
                   prezzo[i][j], &prezzo[i][j],
                   *(prezzo[0] + i * 2 + j));
        }
    }

    for (i = 0; i < 3; i++) {
        printf("prezzo[%d] = %p   *(*(prezzo+%d)+1) = %.2f\n",
               i, prezzo[i], i, *(*(prezzo + i) + 1));
    }
    return 0;
}
