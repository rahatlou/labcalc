/* Esercizio facoltativo: la fibra ottica.
   Nucleo n1 = 1.48, mantello n2 = 1.46; la luce entra dall'aria (n = 1) con l'angolo theta0
   rispetto all'asse della fibra.
   Compilazione: gcc -Wall -Wextra -o fibra.exe fibra.c -lm
   Dati di prova (theta0):
     10 -> theta_r = 6.74, theta_p = 83.26, theta_c = 80.57, guidata
     20 -> theta_r = 13.36, theta_p = 76.64, theta_c = 80.57, persa
     95 -> angolo non valido */
#include <math.h>
#include <stdio.h>

int main() {
    /* Punto 6: per provare altri indici di rifrazione basta cambiare queste due righe
       (ad esempio n2 = 1.40, oppure n2 = n1) e ricompilare */
    double n1 = 1.48;   /* nucleo */
    double n2 = 1.46;   /* mantello */
    double theta0, thetar, thetap, thetac, thetamax;   /* angoli in gradi */

    /* Punto 1: si chiede solo l'angolo di ingresso, n1 e n2 sono fissi */
    printf("angolo di ingresso (gradi): ");
    scanf("%lf", &theta0);

    /* Punto 3: controllo di validita, condizione composta con &&;
       fuori da [0, 90] non si fa nessun altro calcolo */
    if (theta0 >= 0. && theta0 <= 90.) {
        /* Punto 1: theta_r dalla legge di Snell aria -> nucleo (n dell'aria = 1) */
        thetar = asin(sin(theta0 / 180. * M_PI) / n1) / M_PI * 180.;
        /* theta_p: angolo di incidenza sulla parete, rispetto alla sua perpendicolare */
        thetap = 90. - thetar;
        /* theta_c: angolo critico tra nucleo e mantello */
        thetac = asin(n2 / n1) / M_PI * 180.;
        printf("theta_r = %6.2f\n", thetar);
        printf("theta_p = %6.2f\n", thetap);
        printf("theta_c = %6.2f\n", thetac);

        /* Punto 2: se theta_p >= theta_c c'e riflessione totale e la luce resta nella fibra */
        if (thetap >= thetac) {
            printf("guidata\n");
        } else {
            printf("persa\n");
        }

        /* Punto 5: angolo di accettazione, sin(theta_max) = sqrt(n1^2 - n2^2) */
        thetamax = asin(sqrt(n1 * n1 - n2 * n2)) / M_PI * 180.;
        printf("theta_max = %6.2f\n", thetamax);
    } else {
        printf("angolo non valido\n");
    }
}
