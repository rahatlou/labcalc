#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Definizione delle macro come da specifiche */
#define SIZE 30
#define NITER 1000

/* Prototipi delle funzioni obbligatorie */
void inserimento(double *talto, double *tbasso);
void inizializza(double t[], double talto, double tbasso);
void rilassamento(double t[]);

int main() {
    double temperatura[SIZE];
    double talto, tbasso;
    int i;
    FILE *fp;

    /* Inizializzazione del generatore di numeri casuali */
    srand(time(NULL));

    /* 1. Acquisizione e validazione input */
    inserimento(&talto, &tbasso);

    /* 2. Inizializzazione della sbarra (bordi fissi e interni casuali) */
    inizializza(temperatura, talto, tbasso);

    /* 3. Ciclo di evoluzione (Metodo di Rilassamento) */
    for (i = 0; i < NITER; i++) {
        rilassamento(temperatura);
    }

    /* 4. Scrittura dei risultati su file .dat */
    fp = fopen("temperatura.dat", "w");
    if (fp == NULL) {
        printf("Errore: impossibile creare il file temperatura.dat\n");
        return 1;
    }

    for (i = 0; i < SIZE; i++) {
        /* Stampa indice e temperatura con 5 cifre decimali */
        fprintf(fp, "%d %.5f\n", i, temperatura[i]);
    }

    fclose(fp);
    printf("Simulazione completata. Dati salvati in temperatura.dat\n");

    return 0;
}

/**
 * Chiede Talto e Tbasso assicurandosi che siano positive
 * e che Talto > Tbasso.
 * Utilizza puntatori per restituire i valori al main.
 */
void inserimento(double *talto, double *tbasso) {
    int valido = 0;

    do {
        printf("Inserire temperatura Talto (estremita' sinistra): ");
        scanf("%lf", talto);

        printf("Inserire temperatura Tbasso (estremita' destra): ");
        scanf("%lf", tbasso);

        if (*talto > 0 && *tbasso > 0 && *talto > *tbasso) {
            valido = 1;
        } else {
            printf("Errore: le temperature devono essere positive e Talto > Tbasso.\n");
        }

    } while (!valido);
}

/**
 * Inizializza gli estremi e riempie i punti interni con valori casuali
 * nell'intervallo [Tbasso, Talto).
 */
void inizializza(double t[], double talto, double tbasso) {
    int i;

    t[0] = talto;
    t[SIZE - 1] = tbasso;

    for (i = 1; i < SIZE - 1; i++) {

        /* Generazione numero casuale uniforme tra Tbasso e Talto */
        t[i] = tbasso +
               ((double) rand() / RAND_MAX) * (talto - tbasso);
    }
}

/**
 * Esegue un singolo passo di rilassamento applicando
 * l'equazione di Laplace discretizzata:
 * ogni punto interno diventa la media dei suoi vicini.
 */
void rilassamento(double t[]) {
    int i;

    /* Si aggiornano solo i punti interni (da 1 a SIZE-2) */
    for (i = 1; i < SIZE - 1; i++) {
        t[i] = (t[i - 1] + t[i + 1]) / 2.0;
    }
}
