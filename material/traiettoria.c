/* Esercitazione 3, Parte 3: la traiettoria passo dopo passo (copia di gittata.c con modifiche).
   Ciclo while sul tempo, if per il massimo, contatore con ++, confronto con le formule.
   Compilazione: gcc -Wall -Wextra -o traiettoria.exe traiettoria.c -lm
   Dati di prova (v0 theta, da inserire uno alla volta):
     25 35   -> ciclo: 59 passi, T = 2.900 s, H = 10.479 m, G = 59.389 m
                formule: T = 2.923 s, H = 10.480 m, G = 59.868 m
     Con DT = 0.2 la gittata del ciclo e 57.341 m, con DT = 0.01 e 59.798 m: il confronto
     con la formula migliora al diminuire di DT. */
#include <math.h>
#include <stdio.h>

#define GRAV 9.81   /* accelerazione di gravita, m/s^2 */
#define DT 0.05     /* secondi tra due istanti successivi */

int main() {
    double v0, theta, rad;
    double t, x, y;                 /* tempo e posizione */
    double tvolo, xmax, ymax;       /* risultati numerici: tempo di volo, gittata, altezza massima */
    int passi;                      /* quanti istanti con y >= 0 */

    /* Punto 1: stesse letture della Parte 1 (la distanza x non serve: la calcola il ciclo) */
    do {
        printf("v0 (m/s): ");
        scanf("%lf", &v0);
    } while (v0 <= 0.);
    do {
        printf("angolo theta (gradi, tra 0 e 90): ");
        scanf("%lf", &theta);
    } while (theta <= 0. || theta >= 90.);
    rad = theta / 180. * M_PI;

    /* Punto 2: ciclo sul tempo, come per la caduta del grave. Si parte da t = 0 e a ogni giro
       si calcolano x e y e si aumenta t di DT. Il ciclo si ferma appena y < 0, cioe quando il
       proiettile e arrivato a terra.
       Attenzione all'inizio: a t = 0 si ha y = 0, e la condizione y >= 0 e vera, quindi si entra.
       Per questo y si inizializza a 0. (e non a un valore negativo) prima del while.
       Gli accumulatori partono da 0: si aggiorneranno solo nei giri in cui y >= 0 */
    t = 0.;
    y = 0.;
    tvolo = 0.;
    xmax = 0.;
    ymax = 0.;
    passi = 0;
    while (y >= 0.) {
        x = v0 * cos(rad) * t;
        y = v0 * sin(rad) * t - 0.5 * GRAV * t * t;
        /* Punto 2 (continua): l'ultimo giro del ciclo ha y < 0, il proiettile e gia sotto terra:
           quei valori non vanno usati. Si aggiornano i risultati solo se y >= 0 */
        if (y >= 0.) {
            tvolo = t;       /* ultimo istante in aria */
            xmax = x;        /* ultima distanza raggiunta: la gittata del ciclo */
            passi++;         /* conta un istante in piu in aria: passi = passi + 1 */
            if (y > ymax) {  /* altezza massima: si tiene il valore piu grande visto finora */
                ymax = y;
            }
        }
        t += DT;
    }

    /* Punto 3: risultati del ciclo con tre decimali e, accanto, le formule
       T = 2 v0 sin(theta) / g, H = (v0 sin(theta))^2 / (2 g), G = v0^2 sin(2 theta) / g.
       pow(a, 2.) di math.h calcola a^2 */
    printf("passi con y >= 0: %d\n", passi);
    printf("tempo di volo: %.3f s   (formula: %.3f s)\n", tvolo, 2. * v0 * sin(rad) / GRAV);
    printf("altezza massima: %.3f m   (formula: %.3f m)\n", ymax, pow(v0 * sin(rad), 2.) / (2. * GRAV));
    printf("gittata: %.3f m   (formula: %.3f m)\n", xmax, v0 * v0 * sin(2. * rad) / GRAV);

    /* Punto 4: per verificare, eseguire con i dati di prova scritti in cima al file.
       Il ciclo e un po' diverso dalla formula perche il tempo avanza a passi di DT: il valore
       tvolo e l'ultimo istante con y >= 0, che precede di meno di DT l'istante in cui y = 0 */
}
