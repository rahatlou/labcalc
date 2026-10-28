#include <stdio.h>
#define GRAV 9.81

int main() {
    double h, dt, t, y;
    printf("altezza h (m): ");
    scanf("%lf", &h);
    printf("passo dt (s): ");
    scanf("%lf", &dt);
    t = 0.;
    y = h;
    printf("   t\t   y\n");
    while (y > 0.) {
        y = h - 0.5 * GRAV * t * t;
        printf("%6.2f\t%6.2f\n", t, y);
        t += dt;
    }
}
