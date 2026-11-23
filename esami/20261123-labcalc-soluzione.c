#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPITALE0 10000.0   /* capitale iniziale in euro */
#define NGIORNI 250         /* giorni di borsa simulati */
#define NSIM 1000           /* numero di investitori simulati */

double inserimento(double a, double b);
double variazione(double P);
double massimo(double v[], int n);
double media(double v[], int n);

int main() {

    double capitale[NGIORNI + 1];   /* capitale[i] = capitale alla fine del giorno i */
    double finale[NSIM];            /* capitale finale di ogni investitore */
    double P;
    int sim, i;
    int perdite = 0;                /* investitori che hanno perso soldi */
    FILE *fp;

    srand48(time(NULL));

    /* massima fluttuazione giornaliera, in percentuale */
    P = inserimento(0.5, 5.5);

    for (sim = 0; sim < NSIM; sim++) {

        /* ogni investitore riparte dal capitale iniziale */
        capitale[0] = CAPITALE0;
        for (i = 1; i <= NGIORNI; i++) {
            double p = variazione(P);
            capitale[i] = capitale[i - 1] * (1.0 + p / 100.0);
            /* stampa dei singoli giorni solo per il primo investitore */
            if (sim == 0)
                printf("Giorno %3d: variazione %6.2f %%, capitale %9.2f euro\n",
                       i, p, capitale[i]);
        }

        finale[sim] = capitale[NGIORNI];
        if (finale[sim] < CAPITALE0)
            perdite++;

        /* risultati del primo investitore: stampa e file capitale.dat */
        if (sim == 0) {
            printf("\nCapitale finale: %.2f euro\n", capitale[NGIORNI]);
            printf("Capitale massimo raggiunto: %.2f euro\n",
                   massimo(capitale, NGIORNI + 1));
            printf("Guadagno: %.2f euro\n", capitale[NGIORNI] - CAPITALE0);

            fp = fopen("capitale.dat", "w");
            if (fp == NULL) {
                printf("Errore nell'apertura del file capitale.dat\n");
                return 1;
            }
            for (i = 0; i <= NGIORNI; i++)
                fprintf(fp, "%d %f\n", i, capitale[i]);
            fclose(fp);
        }
    }

    /* statistiche su tutti gli investitori */
    printf("\nInvestitori simulati: %d\n", NSIM);
    printf("Capitale finale medio: %.2f euro\n", media(finale, NSIM));
    printf("Capitale finale massimo: %.2f euro\n", massimo(finale, NSIM));
    printf("Investitori in perdita: %d (%.1f %%)\n",
           perdite, 100.0 * perdite / NSIM);

    return 0;
}

/* chiede un numero reale nell'intervallo [a, b] e lo restituisce */
double inserimento(double a, double b) {
    double x;
    do {
        printf("Inserisci la fluttuazione massima P (%g <= P <= %g): ", a, b);
        scanf("%lf", &x);
    } while (x < a || x > b);
    return x;
}

/* variazione percentuale giornaliera, uniforme in [-P, +P] */
double variazione(double P) {
    return -P + 2.0 * P * drand48();
}

/* valore massimo di un array di n elementi */
double massimo(double v[], int n) {
    int i;
    double max = v[0];
    for (i = 1; i < n; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}

/* valore medio di un array di n elementi */
double media(double v[], int n) {
    int i;
    double somma = 0.0;
    for (i = 0; i < n; i++)
        somma += v[i];
    return somma / n;
}
