#include <stdio.h>
#include <stdlib.h>

/* ===========================================================
   MACRO (1 punto)
   =========================================================== */
#define L 100
#define PROB 0.8
#define WARMUP 1000
#define MEASURE 2000

/* ===========================================================
   PROTOTIPO DELLA FUNZIONE sweep() (2 punti)
   =========================================================== */
int sweep(int strada[]);

int main() {

    /* =======================================================
       Inizializzazione del generatore di numeri casuali (1 punto)
       ======================================================= */
    srand48(123456);

    FILE *fp = fopen("traffico.dat","w");
    if (fp == NULL) {
        printf("Errore apertura file\n");
        return 1;
    }

    /* =======================================================
       Ciclo sui valori di N (2 punti)
       ======================================================= */
    for (int N=5; N<=95; N+=5) {

        /* ===================================================
           Inizializzazione dell'array strada (2 punti)
           =================================================== */
        int strada[L];
        for (int i=0; i<L; i++) {
            if (i < N)
                strada[i] = 1;
            else
                strada[i] = 0;
        }

        /* ===================================================
           Variabile movimenti (1 punto)
           =================================================== */
        int movimenti = 0;

        /* ===================================================
           WARMUP sweep di randomizzazione (2 punti)
           =================================================== */
        for (int t=0; t<WARMUP; t++)
            sweep(strada);

        /* ===================================================
           MEASURE sweep e conteggio degli avanzamenti (3 punti)
           =================================================== */
        for (int t=0; t<MEASURE; t++)
            movimenti += sweep(strada);

        /* ===================================================
           Calcolo di rho e del flusso medio J (2 punti)
           =================================================== */
        double rho = N / (double)L;
        double J = movimenti / ((double)MEASURE * L);

        /* ===================================================
           Scrittura del file traffico.dat (2 punti)
           =================================================== */
        fprintf(fp,"%f %f\n",rho,J);
    }

    fclose(fp);

    return 0;
}

/* ===========================================================
   CORPO DELLA FUNZIONE sweep() (6 punti + 3 punti)
   =========================================================== */

int sweep(int strada[]) {

    /* =======================================================
       Inizializzazione del contatore avanzamenti (1 punto)
       ======================================================= */
    int avanzamenti = 0;

    /* =======================================================
       L tentativi di movimento ed estrazione casuale della
       cella (1 punto)
       ======================================================= */
    for (int k=0; k<L; k++) {

        int i = (int)(drand48()*L);

        /* ===================================================
           Gestione delle condizioni periodiche (3 punti)
           =================================================== */
        int next = (i+1)%L;

        /* ===================================================
           Applicazione delle regole del modello:
           auto presente e cella successiva libera (2 punti)
           =================================================== */
        if (strada[i]==1 && strada[next]==0) {

            /* ===============================================
               Probabilità di avanzamento, aggiornamento
               della strada e conteggio degli avanzamenti
               (2 punti)
               =============================================== */
            if (drand48() < PROB) {

                strada[i] = 0;
                strada[next] = 1;

                avanzamenti++;
            }
        }
    }

    return avanzamenti;
}
