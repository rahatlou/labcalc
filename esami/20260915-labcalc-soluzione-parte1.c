#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NNUMERI 90
#define NESTRATTI 5
#define NMAX 50


void estrazione(int estratti[]);
void print_array(int estratti[]);
int check_numero(int estratti[], int M);


int main()
{
    int M;
    int estratti[NESTRATTI];
    int n;
    int trovato;

    /* Inizializza il generatore di numeri casuali */
    srand48(time(NULL));

    /* Acquisisce e controlla il numero da cercare */
    do {
        printf("Inserisci un numero tra 1 e 90: ");
        scanf("%d", &M);
    } while (M < 1 || M > NNUMERI);


    /* Esegue le estrazioni fino alla comparsa di M o a NMAX */
    n = 0;
    trovato = 0;

    while (n < NMAX && trovato == 0) {
        n++;

        estrazione(estratti);

        printf("Estrazione %d: ", n);
        print_array(estratti);

        trovato = check_numero(estratti, M);
    }


    /* Stampa il risultato della simulazione */
    if (trovato == 1)
        printf("Numero %d uscito in estrazione %d\n", M, n);
    else
        printf("Numero %d non uscito in %d estrazioni\n", M, NMAX);

    return 0;
}


/* Estrae NESTRATTI numeri distinti tra 1 e NNUMERI */
void estrazione(int estratti[])
{
    int i, j;
    int ripeti;

    for (i = 0; i < NESTRATTI; i++) {

        do {
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
        printf("%d ", estratti[i]);

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

