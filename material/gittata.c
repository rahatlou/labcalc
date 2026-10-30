/* Esercitazione 3, Parte 1: dove arriva il proiettile.
   Cicli do/while con condizioni composte, math.h con gli angoli in radianti.
   Compilazione: gcc -Wall -Wextra -o gittata.exe gittata.c -lm
   Dati di prova (v0 theta x, da inserire uno alla volta):
     25 35 20       -> G = 59.87 m, h = 9.33 m
     25 35 70 30    -> x = 70 e rifiutato e riletto; poi G = 59.87 m, h = 10.48 m */
#include <math.h>
#include <stdio.h>

#define GRAV 9.81   /* accelerazione di gravita, m/s^2 */

int main() {
    double v0, theta, rad;   /* velocita iniziale, angolo in gradi e in radianti */
    double gitt, x, h;       /* gittata, distanza e altezza a quella distanza */

    /* Punto 1: v0 e theta, ciascuno riletto finche non e valido.
       Il do/while esegue il corpo almeno una volta (serve: prima si legge, poi si controlla)
       e ripete finche la condizione scritta dopo while e vera, cioe finche il valore NON e valido. */
    do {
        printf("v0 (m/s): ");
        scanf("%lf", &v0);
    } while (v0 <= 0.);

    /* theta deve stare tra 0 e 90 gradi, estremi esclusi. Il valore e NON valido se theta <= 0
       oppure theta >= 90: due condizioni unite dall'operatore || ("oppure") */
    do {
        printf("angolo theta (gradi, tra 0 e 90): ");
        scanf("%lf", &theta);
    } while (theta <= 0. || theta >= 90.);

    /* sin, cos e tan di math.h vogliono i radianti; i dati sono in gradi.
       Si lavora con 180. e non 180 per non fare una divisione fra interi */
    rad = theta / 180. * M_PI;

    /* Punto 2: gittata G = v0^2 sin(2 theta) / g, stampata con due decimali */
    gitt = v0 * v0 * sin(2. * rad) / GRAV;
    printf("gittata: %.2f m\n", gitt);

    /* Punto 3: distanza x con 0 < x <= G.
       Dentro il ciclo, a ogni valore non valido si stampa un messaggio che dice
       quali valori sono ammessi; il while ripete lo stesso controllo */
    do {
        printf("distanza x (m): ");
        scanf("%lf", &x);
        if (x <= 0. || x > gitt) {
            printf("x deve essere tra 0 e %.2f m\n", gitt);
        }
    } while (x <= 0. || x > gitt);

    /* Punto 4: altezza a distanza x, h = x tan(theta) - g x^2 / (2 v0^2 cos^2(theta)),
       e stampa di x e h con due decimali */
    h = x * tan(rad) - GRAV * x * x / (2. * v0 * v0 * cos(rad) * cos(rad));
    printf("a x = %.2f m il proiettile e alto h = %.2f m\n", x, h);

    /* Punto 5: per verificare, eseguire con i dati di prova scritti in cima al file */
}
