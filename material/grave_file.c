#include <stdio.h>
#include <stdlib.h>
#define GRAV 9.81

int main() {
    FILE *fp;
    double h, dt, t, y;
    printf("altezza h (m): ");
    scanf("%lf", &h);
    printf("passo dt (s): ");
    scanf("%lf", &dt);
    fp = fopen("grave.txt", "w");
    if (fp == NULL) {
        printf("errore: impossibile aprire grave.txt\n");
        exit(-1);
    }
    t = 0.;
    y = h;
    while (y > 0.) {
        y = h - 0.5 * GRAV * t * t;
        fprintf(fp, "%.2f %.2f\n", t, y);
        t += dt;
    }
    fclose(fp);
}
