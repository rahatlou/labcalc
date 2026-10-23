/* Esercitazione 2, Parte 3: la riflessione totale.
   Copia di snell.c con il controllo della riflessione totale.
   Compilazione: gcc -Wall -Wextra -o riflessione.exe riflessione.c -lm
   Dati di prova (n1 n2 theta1):
     1.50 1.00 30  -> rifratto, theta2 = 48.59 gradi
     1.50 1.00 60  -> riflessione totale, angolo critico 41.81 gradi
     1.50 1.00 45  -> riflessione totale, angolo critico 41.81 gradi
     1.00 1.50 80  -> rifratto, theta2 = 41.04 gradi (nessuna riflessione totale) */
#include <math.h>
#include <stdio.h>

int main() {
    double n1, n2;
    double theta1, theta2, thetac;   /* incidenza, rifrazione, angolo critico (gradi) */
    double rad1;
    double arg;                      /* argomento di asin: n1 / n2 * sin(theta1) */

    printf("n1: ");
    scanf("%lf", &n1);
    printf("n2: ");
    scanf("%lf", &n2);
    printf("angolo di incidenza (gradi): ");
    scanf("%lf", &theta1);

    rad1 = theta1 / 180. * M_PI;
    arg = n1 / n2 * sin(rad1);

    /* Punto 1: con 1.50 1.00 60 vale arg = 1.30, fuori dall'intervallo [-1, 1] in cui
       asin e definita: senza il controllo del punto 2 il programma stamperebbe nan */

    /* Punto 2: condizione composta con &&, valutata PRIMA di chiamare asin:
       riflessione totale se si va da un mezzo piu denso a uno meno denso (n1 > n2)
       e l'argomento di asin supera 1 */
    if (n1 > n2 && arg > 1.) {
        printf("riflessione totale\n");

        /* Punto 3: angolo critico, theta_c = arcsin(n2 / n1) */
        thetac = asin(n2 / n1) / M_PI * 180.;
        printf("angolo critico: %6.2f gradi\n", thetac);
    } else {
        theta2 = asin(arg) / M_PI * 180.;
        printf("angolo rifratto: %6.2f gradi\n", theta2);
    }

    /* Punto 5: con n1 < n2 l'argomento arg e sempre minore di 1, quindi il ramo
       della riflessione totale non viene mai eseguito (provare con 1.00 1.50 80) */
}
