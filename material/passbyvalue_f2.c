#include <stdio.h>

void svaluta(double prezzo) {
    prezzo = prezzo * 0.8;               // sconto del 20%
    printf("dentro svaluta:  prezzo = %.2f\n", prezzo);
}

double scontato(double prezzo) {
    return prezzo * 0.8;
}

int main() {
    double prezzo = 45.0, nuovo;
    printf("main prima:      prezzo = %.2f\n", prezzo);
    svaluta(prezzo);
    printf("main dopo:       prezzo = %.2f\n", prezzo);
    nuovo = scontato(prezzo);
    printf("con il return:   nuovo  = %.2f\n", nuovo);
    return 0;
}
