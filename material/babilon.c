/* Esercitazione 4, Parti 1 e 2: metodo babilonese per la radice quadrata.
   Cicli do/while, math.h, scrittura dei dati su file.
   Compilazione: gcc -Wall -Wextra -o babilon.exe babilon.c -lm
   Dati di prova (eps r0 a, da inserire uno alla volta):
     0.1 1 7        -> 4 iterazioni, r4 = 2.645767044190, differenza 1.5733e-05
     0.001 1 7      -> 5 iterazioni, r5 = 2.645751311111, differenza 4.6779e-11 (il file ha 6 righe)
     0.0001 30 7    -> 7 iterazioni, r7 = 2.645751311846, differenza 7.8152e-10
     0.5 0.0000001 0.001 0 -2 1 0 -3 7 -> input rifiutati e riletti, poi come la seconda riga
   Dopo l'esecuzione il file babilon.txt contiene due colonne: n e r_n. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    double eps, r0, a;          /* precisione, valore iniziale e numero di cui si calcola la radice */
    double r, rnuovo, diff;     /* stima attuale, stima successiva, differenza tra le due */
    int n;                      /* numero di iterazioni eseguite */
    FILE *fp;

    /* Punti 1, 2 e 3 della Parte 1: tre input, ciascuno riletto finche non e valido.
       Il do/while esegue il corpo almeno una volta (prima si legge, poi si controlla) e ripete
       finche la condizione scritta dopo while e vera, cioe finche il valore NON e valido. */
    do {
        printf("precisione eps (tra 0.000001 e 0.1): ");
        scanf("%lf", &eps);
    } while (eps < 1.e-6 || eps > 0.1);

    do {
        printf("valore iniziale r0 (positivo): ");
        scanf("%lf", &r0);
    } while (r0 <= 0.);

    do {
        printf("numero a (positivo): ");
        scanf("%lf", &a);
    } while (a <= 0.);

    /* Punto 5 della Parte 1: apertura del file in scrittura, con il controllo di fopen */
    fp = fopen("babilon.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire babilon.txt\n");
        exit(-1);
    }

    /* Punto 4: il metodo babilonese. Si parte da r_0 e si stampa subito la riga n = 0,
       poi a ogni giro si calcola r_{n+1} = (r_n + a / r_n) / 2.
       Il ciclo si ferma quando la differenza |r_{n+1} - r_n| e minore di eps. */
    r = r0;
    n = 0;
    printf("%3d %.12f\n", n, r);
    fprintf(fp, "%d %.12f\n", n, r);       /* solo numeri nel file: n e r_n */
    do {
        rnuovo = 0.5 * (r + a / r);
        diff = fabs(rnuovo - r);
        r = rnuovo;
        n++;
        printf("%3d %.12f\n", n, r);
        fprintf(fp, "%d %.12f\n", n, r);
    } while (diff >= eps);

    fclose(fp);

    /* Punto 4, ultima riga: iterazioni eseguite e differenza dal valore di sqrt (formato %.5g) */
    printf("iterazioni: %d, differenza da sqrt(a): %.5g\n", n, fabs(r - sqrt(a)));
}
