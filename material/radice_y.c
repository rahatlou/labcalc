/* Esercitazione 4, Parte 2: l'inverso della radice quadrata con y_{n+1} = (3/2) y_n - (a/2) y_n^3.
   Come la Parte 1, ma il valore iniziale y_0 = 1/r_2 viene da due passi del metodo babilonese.
   Compilazione: gcc -Wall -Wextra -o radice_y.exe radice_y.c -lm
   Dati di prova (eps a, da inserire uno alla volta; r_0 = 1 scelto nel programma):
     0.1 7        -> 2 iterazioni, 1/y2 = 2.646092354490, differenza 3.4104e-04
     0.001 7      -> 3 iterazioni, 1/y3 = 2.645751376987, differenza 6.5922e-08
     0.000001 7   -> 4 iterazioni, 1/y4 = 2.645751311065, differenza 2.2204e-15
   Prima prova con y_0 = 1/r_0 = 1 (senza i due passi babilonesi), eps = 0.001, a = 7:
     1/y_n = 1, -0.5, 0.04, -0.000018298262, 0 -> 4 iterazioni, differenza 2.6458 (risultato sbagliato)
   Dopo l'esecuzione il file radice.txt contiene due colonne: n e 1/y_n. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    double eps, a;             /* precisione e numero di cui si calcola la radice */
    double r;                  /* stima babilonese: r_0 poi r_1 e r_2 */
    double y, ynuovo, diff;    /* stima di 1/sqrt(a) attuale e successiva, differenza fra le stime di sqrt(a) */
    int n;                     /* iterazioni del secondo metodo */
    FILE *fp;

    /* Punti 1 e 2: eps e a, ciascuno riletto finche non e valido */
    do {
        printf("precisione eps (tra 0.000001 e 0.1): ");
        scanf("%lf", &eps);
    } while (eps < 1.e-6 || eps > 0.1);

    do {
        printf("numero a (positivo): ");
        scanf("%lf", &a);
    } while (a <= 0.);

    /* Punto 3: r_0 scelto nel programma (qui 1), senza chiederlo; due iterazioni del metodo
       babilonese danno r_2. Se si usasse y_0 = 1/r_0 direttamente, il metodo nuovo potrebbe divergere. */
    r = 1.;
    r = 0.5 * (r + a / r);      /* r_1 */
    r = 0.5 * (r + a / r);      /* r_2 */

    fp = fopen("radice.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire radice.txt\n");
        exit(-1);
    }

    /* Punto 4: la successione y_n parte da y_0 = 1/r_2. Si stampa n e 1/y_n (la stima di sqrt(a)),
       e il ciclo si ferma quando |1/y_{n+1} - 1/y_n| < eps */
    y = 1. / r;
    n = 0;
    printf("%3d %.12f\n", n, 1. / y);
    fprintf(fp, "%d %.12f\n", n, 1. / y);
    do {
        ynuovo = 1.5 * y - 0.5 * a * y * y * y;
        diff = fabs(1. / ynuovo - 1. / y);
        y = ynuovo;
        n++;
        printf("%3d %.12f\n", n, 1. / y);
        fprintf(fp, "%d %.12f\n", n, 1. / y);
    } while (diff >= eps);

    fclose(fp);

    /* Punto 5: iterazioni eseguite e differenza dal valore di sqrt */
    printf("iterazioni: %d, differenza da sqrt(a): %.5g\n", n, fabs(1. / y - sqrt(a)));
}
