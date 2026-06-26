#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 100
#define A 2.0

double input(char nome[], double a, double b);
double posIdeal(double omega, double t);
double errorMax(double xth[], double xmis[], int n);

int main() {

    double M, K, Delta;
    double omega, T, dt;

    double tempo[N];
    double xth[N];
    double xmis[N];

    int i;

    FILE *fp;

    srand48(time(NULL));

    M = input("M [kg]", 0.1, 2.5);

    K = input("K [N/m]", 0.5, 5.0);

    Delta = input("Delta [m]", 0.05, 0.5);

    omega = sqrt(K/M);

    T = 2.0*M_PI/omega;

    dt = 2.0*T/(N-1);

    for(i=0; i<N; i++) {

        double errore;

        tempo[i] = i*dt;

        xth[i] = posIdeal(omega, tempo[i]);

        errore = -Delta + 2.0*Delta*drand48();

        xmis[i] = xth[i] + errore;
    }

    printf("\n");
    printf("Errore massimo = %.3f m\n",
           errorMax(xth, xmis, N));

    fp = fopen("posizione.dat", "w");

    if(fp == NULL) {

        printf("Errore apertura file\n");
        return 1;
    }

    for(i=0; i<N; i++) {

        fprintf(fp,
                "%lf %lf %lf\n",
                tempo[i],
                xth[i],
                xmis[i]);
    }

    fclose(fp);

    printf("File posizione.dat scritto correttamente\n");

    return 0;
}

/* acquisizione di una variabile reale nell'intervallo [a,b] */
double input(char nome[],
             double a,
             double b) {

    double x;

    do {

        printf("Inserisci %s nell'intervallo [%.2f, %.2f]: ",
               nome, a, b);

        scanf("%lf", &x);

    } while(x < a || x > b);

    return x;
}

/* posizione teorica dell'oscillatore armonico */
double posIdeal(double omega,
                double t) {

    return A*cos(omega*t);
}

/* massimo errore assoluto */
double errorMax(double xth[],
                double xmis[],
                int n) {

    int i;

    double err;
    double max;

    max = fabs(xmis[0] - xth[0]);

    for(i=1; i<n; i++) {

        err = fabs(xmis[i] - xth[i]);

        if(err > max)
            max = err;
    }

    return max;
}
