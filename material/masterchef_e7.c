// Esercitazione 7: grani di sale che cadono in un cerchio di raggio R sul pavimento della cucina.
// Funzioni: leggiInt (input valido), uniforme (numero casuale in [a,b)), mattonella (zona del punto).
// Parte 1: una caduta di N grani, conteggio per mattonella, posizioni in grani.txt.
// Parte 2: la stessa caduta ripetuta NRIP volte, medie dei conteggi, risultati in conteggi.txt.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 1.0         // raggio del cerchio (m)
#define NMIN 500      // minimo numero di grani
#define NMAX 2000     // massimo numero di grani
#define NRIP 1000     // numero di ripetizioni della Parte 2

// prototipi delle funzioni (le definizioni sono dopo il main)
int leggiInt(int min, int max);
double uniforme(double a, double b);
int mattonella(double x, double y);

int main() {
    int n, i, k, rip;
    int conta[4];                 // grani in A, B, C e fuori
    double x, y;
    int NA[NRIP], NB[NRIP], NC[NRIP];
    double sa, sb, sc;
    FILE *fp;

    n = leggiInt(NMIN, NMAX);

    srand48(time(NULL));          // una sola volta, dopo l'input

    // ---------------- Parte 1: una caduta di n grani ----------------
    for (k = 0; k < 4; k++) {
        conta[k] = 0;
    }
    fp = fopen("grani.txt", "w");
    for (i = 0; i < n; i++) {
        // rigetto: punto uniforme nel quadrato [-R,R) x [-R,R), accettato se sta nel cerchio
        do {
            x = uniforme(-R, R);
            y = uniforme(-R, R);
        } while (x * x + y * y > R * R);
        k = mattonella(x, y);
        conta[k]++;
        fprintf(fp, "%f %f %d\n", x, y, k);
    }
    fclose(fp);

    printf("Mattonella A: %d grani, frazione %.3f\n", conta[0], (double) conta[0] / n);
    printf("Mattonella B: %d grani, frazione %.3f\n", conta[1], (double) conta[1] / n);
    printf("Mattonella C: %d grani, frazione %.3f\n", conta[2], (double) conta[2] / n);
    printf("Fuori:        %d grani, frazione %.3f\n", conta[3], (double) conta[3] / n);

    // ---------------- Parte 2: NRIP cadute con lo stesso n ----------------
    for (rip = 0; rip < NRIP; rip++) {
        for (k = 0; k < 4; k++) {
            conta[k] = 0;
        }
        for (i = 0; i < n; i++) {
            do {
                x = uniforme(-R, R);
                y = uniforme(-R, R);
            } while (x * x + y * y > R * R);
            conta[mattonella(x, y)]++;
        }
        NA[rip] = conta[0];
        NB[rip] = conta[1];
        NC[rip] = conta[2];
    }

    fp = fopen("conteggi.txt", "w");
    sa = 0;
    sb = 0;
    sc = 0;
    for (rip = 0; rip < NRIP; rip++) {
        fprintf(fp, "%d %d %d\n", NA[rip], NB[rip], NC[rip]);
        sa += NA[rip];
        sb += NB[rip];
        sc += NC[rip];
    }
    fclose(fp);

    printf("Valori medi su %d cadute: <NA> = %.2f, <NB> = %.2f, <NC> = %.2f\n",
           NRIP, sa / NRIP, sb / NRIP, sc / NRIP);
    return 0;
}

// legge un intero e ripete la domanda finche non sta tra min e max
int leggiInt(int min, int max) {
    int v;
    do {
        printf("Inserisci un intero tra %d e %d: ", min, max);
        scanf("%d", &v);
    } while (v < min || v > max);
    return v;
}

// numero casuale uniforme in [a, b)
double uniforme(double a, double b) {
    return a + (b - a) * drand48();
}

// mattonella in cui cade il punto (x,y): 0 = A, 1 = B, 2 = C, 3 = fuori dalle mattonelle
int mattonella(double x, double y) {
    if (x >= -0.4 && x < 0.4 && y >= -0.4 && y < 0.4) return 0;    // A: quadrato
    if (x >= 0.4 && x < 0.8 && y >= -0.4 && y < 0.4) return 1;     // B: rettangolo
    if (x >= -0.4 && x < 0.4 && y >= 0.4 && y < 0.7) return 2;     // C: rettangolo
    return 3;
}
