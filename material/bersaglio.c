/* Esercitazione 3, Parte 2: colpire un bersaglio (copia di gittata.c con aggiunte).
   Ciclo do/while che aumenta l'angolo, fabs di math.h, if/else finale.
   Compilazione: gcc -Wall -Wextra -o bersaglio.exe bersaglio.c -lm
   Dati di prova (v0 L, da inserire uno alla volta):
     25 60   -> 350 righe, ultima 35.00 59.868; colpito a 35.00 gradi, formula 35.17 gradi
     25 40   -> 194 righe, ultima 19.40 39.921; colpito a 19.40 gradi, formula 19.45 gradi */
#include <math.h>
#include <stdio.h>

#define GRAV 9.81     /* accelerazione di gravita, m/s^2 */
#define THETA0 0.1    /* angolo iniziale, gradi */
#define DTHETA 0.1    /* passo dell'angolo, gradi */
#define EPS 0.2       /* tolleranza sulla distanza, m */

int main() {
    double v0, L;            /* velocita iniziale e distanza del bersaglio */
    double theta, gitt;      /* angolo in gradi e gittata corrispondente */
    double teorico;          /* angolo dato dalla formula, in gradi */

    /* Punto 1: v0 positiva e distanza L con 0 < L < v0^2 / g.
       v0^2 / g e la gittata massima (theta = 45 gradi): oltre non si arriva mai.
       Nel messaggio si stampa il limite, calcolato con v0 gia letta */
    do {
        printf("v0 (m/s): ");
        scanf("%lf", &v0);
    } while (v0 <= 0.);
    do {
        printf("distanza L (m, tra 0 e %.2f): ", v0 * v0 / GRAV);
        scanf("%lf", &L);
    } while (L <= 0. || L >= v0 * v0 / GRAV);

    /* Punto 2: si parte da theta = 0.1 gradi e a ogni passo si calcola G(theta) e si stampa
       una riga "theta G" con due e tre decimali, separati da uno spazio e senza altro testo.

       Punto 3: il ciclo si ferma quando |G - L| < EPS (fabs e il valore assoluto per i double)
       oppure quando theta arriva a 90 gradi. Il controllo e nel while, quindi si continua
       finche |G - L| >= EPS E theta < 90 (condizione composta con &&).
       Trucco: theta aumenta solo se il bersaglio NON e stato colpito. Cosi ogni riga stampata
       contiene theta e la G calcolata con quello stesso theta, e all'uscita dal ciclo
       theta e proprio l'angolo trovato (senza dover sottrarre DTHETA) */
    theta = THETA0;
    do {
        gitt = v0 * v0 * sin(2. * theta / 180. * M_PI) / GRAV;
        printf("%.2f %.3f\n", theta, gitt);
        if (fabs(gitt - L) >= EPS) {
            theta += DTHETA;
        }
    } while (fabs(gitt - L) >= EPS && theta < 90.);

    /* Punto 4: dopo il ciclo bisogna capire PERCHE e finito: bersaglio colpito oppure 90 gradi */
    if (fabs(gitt - L) < EPS) {
        printf("bersaglio colpito con theta = %.2f gradi\n", theta);
        /* Punto 5: angolo esatto dalla formula theta = 0.5 arcsin(g L / v0^2); asin da radianti,
           quindi alla fine si converte in gradi. I due angoli non coincidono: il ciclo si ferma
           appena G e entro EPS da L, non quando G = L (qui 35.00 contro 35.17 gradi) */
        teorico = 0.5 * asin(GRAV * L / (v0 * v0)) / M_PI * 180.;
        printf("angolo dalla formula: %.2f gradi\n", teorico);
    } else {
        printf("nessuna soluzione\n");
    }
    /* Il ciclo parte da angoli piccoli e trova l'angolo basso: poiche G(theta) = G(90 - theta),
       anche 90 - theta colpisce il bersaglio */

    /* Punto 6: per verificare, eseguire con i dati di prova scritti in cima al file */
}
