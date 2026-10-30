/* Esercitazione 3, esercizio facoltativo per casa: l'angolo migliore (parte da gittata.c).
   Due cicli for su angoli interi, ricerca del massimo, confronto fra double con una tolleranza.
   Compilazione: gcc -Wall -Wextra -o angolo.exe angolo.c -lm
   Dati di prova (v0 theta_r, da inserire uno alla volta):
     18 40   -> gittata massima 33.028 m a 45 gradi; la gittata di 40 gradi (32.526 m)
                si ottiene a 40 e a 50 gradi */
#include <math.h>
#include <stdio.h>

#define GRAV 9.81   /* accelerazione di gravita, m/s^2 */

int main() {
    double v0, rif;              /* velocita iniziale e angolo di riferimento, in gradi */
    double theta, gitt;          /* angolo di prova e la sua gittata */
    double gmax, thmax;          /* gittata massima trovata e angolo che la da */
    double gittrif;              /* gittata dell'angolo di riferimento */

    /* Letture come nella Parte 1 (qui theta_r e intero, ma si legge un double: va bene) */
    do {
        printf("v0 (m/s): ");
        scanf("%lf", &v0);
    } while (v0 <= 0.);
    do {
        printf("angolo di riferimento (gradi, tra 0 e 90): ");
        scanf("%lf", &rif);
    } while (rif <= 0. || rif >= 90.);

    /* Punto 1: angolo di gittata massima, provando gli interi da 1 a 89 gradi con un for.
       Ricerca del massimo: si parte con gmax = 0 e si tiene il valore piu grande visto finora,
       insieme all'angolo che lo ha dato */
    gmax = 0.;
    thmax = 0.;
    for (theta = 1.; theta <= 89.; theta += 1.) {
        gitt = v0 * v0 * sin(2. * theta / 180. * M_PI) / GRAV;
        if (gitt > gmax) {
            gmax = gitt;
            thmax = theta;
        }
    }
    printf("gittata massima: %.3f m con theta = %.0f gradi (formula: %.3f m)\n", gmax, thmax, v0 * v0 / GRAV);

    /* Punto 2: tutti gli angoli con la stessa gittata di theta_r. Due double calcolati in modo
       diverso non sono mai esattamente uguali (errori di arrotondamento): non si scrive
       gitt == gittrif, ma si controlla che la differenza in valore assoluto sia piccola */
    gittrif = v0 * v0 * sin(2. * rif / 180. * M_PI) / GRAV;
    printf("gittata a %.0f gradi: %.3f m\n", rif, gittrif);
    for (theta = 1.; theta <= 89.; theta += 1.) {
        gitt = v0 * v0 * sin(2. * theta / 180. * M_PI) / GRAV;
        if (fabs(gitt - gittrif) < 0.001) {
            printf("stessa gittata a %.0f gradi\n", theta);
        }
    }
    /* Devono comparire due angoli: theta_r e 90 - theta_r, perche sin(2 theta) = sin(180 - 2 theta).
       Se theta_r = 45 compare un solo angolo */

    /* Punto 3: per verificare, eseguire con i dati di prova scritti in cima al file */
}
