/* Esercitazione 2, Parte 2: la legge di Snell.
   Compilazione: gcc -Wall -Wextra -o snell.exe snell.c -lm
   Dati di prova (n1 n2 theta1, da inserire uno alla volta):
     1.00 1.50 30  -> theta2 = 19.47 gradi (aria -> vetro)
     1.00 1.50 0   -> theta2 = 0.00 gradi (incidenza perpendicolare) */
#include <math.h>
#include <stdio.h>

int main() {
    double n1, n2;          /* indici di rifrazione dei due mezzi */
    double theta1, theta2;  /* angoli di incidenza e di rifrazione, in gradi */
    double rad1, rad2;      /* gli stessi angoli in radianti */

    /* Punto 1: n1, n2 e l'angolo di incidenza in gradi, chiesti separatamente */
    printf("n1: ");
    scanf("%lf", &n1);
    printf("n2: ");
    scanf("%lf", &n2);
    printf("angolo di incidenza (gradi): ");
    scanf("%lf", &theta1);

    /* Punto 2: sin e asin lavorano in radianti, quindi gradi -> radianti prima... */
    rad1 = theta1 / 180. * M_PI;
    /* ... legge di Snell: theta2 = arcsin(n1 / n2 * sin(theta1)); asin(x) e arcsin x ... */
    rad2 = asin(n1 / n2 * sin(rad1));
    /* ... e radianti -> gradi dopo */
    theta2 = rad2 / M_PI * 180.;

    /* Punto 1 (stampa): l'angolo rifratto in gradi con il formato %6.2f */
    printf("angolo rifratto: %6.2f gradi\n", theta2);

    /* Punto 3: per verificare, eseguire con i dati di prova scritti in cima al file */
}
