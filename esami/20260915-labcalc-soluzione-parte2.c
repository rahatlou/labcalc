#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NNUMERI 90
#define NESTRATTI 5
#define NMAX 50
#define NSIM 10000


void estrazione(int estratti[]);
void print_array(int estratti[]);
int check_numero(int estratti[], int M);


int main()
{
    int M = 37;
    int estratti[NESTRATTI];
    double cumulativa[NMAX + 1];
    double prob[NMAX + 1];

    int sim, n, i;
    int trovato;
    int non_uscito;

    FILE *fp;

    /* Inizializza il generatore di numeri casuali */
    srand48(time(NULL));

    /*
     * Nella prima parte M veniva inserito da terminale.
     * Nella seconda parte M è fissato uguale a 37.
     *
     * do {
     *     printf("Inserisci un numero tra 1 e 90: ");
     *     scanf("%d", &M);
     * } while (M < 1 || M > NNUMERI);
     */

    /* Inizializza i contatori della probabilità cumulativa */
    for (n = 1; n <= NMAX; n++)
        cumulativa[n] = 0.0;

    non_uscito = 0;

    /* Esegue NSIM esperimenti indipendenti */
    for (sim = 1; sim <= NSIM; sim++) {

        n = 0;
        trovato = 0;

        /* Cerca la prima uscita di M */
        while (n < NMAX && trovato == 0) {
            n++;

            estrazione(estratti);

            /* Stampa solo i primi 5 esperimenti */
            if (sim <= 5) {
                printf("Simulazione %d \t Estrazione %2d: ", sim, n);
                print_array(estratti);
            }

            trovato = check_numero(estratti, M);
        }

        /* Aggiorna la probabilità cumulativa */
        if (trovato == 1) {

            /*
             * Se M è uscito all'estrazione n,
             * l'esperimento vale da n fino a NMAX.
             */
            for (i = n; i <= NMAX; i++)
                cumulativa[i]++;

        } else {
            non_uscito++;
        }

        /* Stampa il risultato dei primi 5 esperimenti */
        if (sim <= 5) {
            if (trovato == 1)
                printf("Numero %d uscito in estrazione %d\n\n", M, n);
            else
                printf("Numero %d non uscito in %d estrazioni\n\n",
                       M, NMAX);
        }
    }

    /* Normalizza i risultati della simulazione */
    for (n = 1; n <= NMAX; n++)
        cumulativa[n] /= NSIM;

    /* Calcola la probabilità teorica */
    for (n = 1; n <= NMAX; n++)
        prob[n] = 1.0 -
                  pow(1.0 - (double)NESTRATTI / NNUMERI, n);

    /* Stampa il numero di esperimenti senza uscita di M */
    printf("Numero %d non uscito in %d esperimenti (%.1f%%)\n",
           M, non_uscito, 100.0 * non_uscito / NSIM);

    /* Salva i risultati nel file */
    fp = fopen("cumulativa.dat", "w");

    if (fp == NULL) {
        printf("Errore nell'apertura del file cumulativa.dat\n");
        return 1;
    }

    for (n = 1; n <= NMAX; n++)
        fprintf(fp, "%d %f %f\n", n, cumulativa[n], prob[n]);

    fclose(fp);

    return 0;
}


/* Estrae NESTRATTI numeri distinti tra 1 e NNUMERI */
void estrazione(int estratti[])
{
    int i, j;
    int ripeti;

    for (i = 0; i < NESTRATTI; i++) {

        do {
            /* Genera un numero casuale tra 1 e NNUMERI */
            estratti[i] = (int)(drand48() * NNUMERI) + 1;

            /* Controlla se il numero è già presente */
            ripeti = 0;

            for (j = 0; j < i; j++) {
                if (estratti[j] == estratti[i])
                    ripeti = 1;
            }

        } while (ripeti == 1);
    }
}


/* Stampa i numeri contenuti nell'array */
void print_array(int estratti[])
{
    int i;

    for (i = 0; i < NESTRATTI; i++)
        printf("%2d\t ", estratti[i]);

    printf("\n");
}


/* Restituisce 1 se M è presente nell'array, 0 altrimenti */
int check_numero(int estratti[], int M)
{
    int i;

    for (i = 0; i < NESTRATTI; i++) {
        if (estratti[i] == M)
            return 1;
    }

    return 0;
}
