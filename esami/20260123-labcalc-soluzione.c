#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MODULI 25
#define NPARTITE 10000

/* dichiarazione funzioni */
void creaPonte(int ponte[]);
void visualizza(int ponte[]);
int scelta();

int giocaPartita(int ponte[]);
  
int main() {

    srand48(time(0));

    int ponte[MODULI];
    int conteggio[MODULI + 1];
    int maxSalti=0;

    /* inizializzo array conteggi */
    for(int i = 0; i <= MODULI; i++)
        conteggio[i] = 0;

    /* creo una sola volta la configurazione del ponte */
    creaPonte(ponte);

    printf("\nConfigurazione del ponte (+ sicura, 0 fragile):\n\n");
    visualizza(ponte);

    /* simulazione Monte Carlo */
    for(int i = 0; i < NPARTITE; i++) {

        int nSalti = giocaPartita(ponte);

	/* questra condizione e` superflua se la partita e` corretta */
        //if(nSalti >= 0 && nSalti <= MODULI)
	  conteggio[nSalti]++;
	
	if(nSalti>maxSalti) maxSalti = nSalti;
    }

    /* scrittura file per istogramma */
    FILE *fp = fopen("salti.txt", "w");
    if(!fp){
        printf("Errore apertura file salti.txt\n");
        exit(-1);
    }

    for(int k = 0; k <= MODULI; k++){
      fprintf(fp, "%d\t%f\n", k, (double)conteggio[k]/NPARTITE);
    }

    fclose(fp);

    
    printf("File 'salti.txt' creato correttamente.\n");
    printf("\nSimulazione completata.\n");
    printf("Numero massimo di salti consecutivi: %d\n", maxSalti);

    double mediaSalti=0;
    int totConteggi =0;
    for(int i=0; i<MODULI+1; i++) {
      mediaSalti += i*conteggio[i];
      totConteggi += conteggio[i];
    }
    mediaSalti /= totConteggi;
    
    printf("media pesata: %.1f \t conteggi: %d\n", mediaSalti, totConteggi);


    return 0;
}


/* -------------------------------------------------- */
/* genera configurazione del ponte */
void creaPonte(int ponte[]) {

    for(int i = 0; i < MODULI; i++) {

        /* 0 = fragile a sinistra, sicura a destra
           1 = fragile a destra,  sicura a sinistra */
        if(drand48() < 0.5)
            ponte[i] = 0;
        else
            ponte[i] = 1;
    }
}


/* -------------------------------------------------- */
/* stampa il ponte (prima coppia in fondo) */
void visualizza(int ponte[]) {

    for(int i = MODULI-1; i >= 0; i--) {

        if(ponte[i] == 0) {
            /* fragile a sinistra, sicura a destra */
            printf("0 +\n");
        }
        else {
            /* fragile a destra, sicura a sinistra */
            printf("+ 0\n");
        }
    }
}


/* -------------------------------------------------- */
/* scelta casuale: 0 = sinistra, 1 = destra */
int scelta() {

    if(drand48() < 0.5)
        return 0;
    else
        return 1;
}


/* -------------------------------------------------- */
/* simula una partita singola
   restituisce il numero di salti consecutivi riusciti */
int giocaPartita(int ponte[]) {

    int modulo = 0;
    int salti = 0;

    while(modulo < MODULI) {

        int lato = scelta();   /* 0 sinistra, 1 destra */

        /* controllo se la scelta è corretta */
        if(ponte[modulo] == lato) {
            /* ha scelto la lastra fragile -> cade */
            return salti;
        }  else {
            /* salto riuscito */
            salti++;
            modulo++;
        }
    }

    /* ha superato tutti i moduli */
    return MODULI;
}
