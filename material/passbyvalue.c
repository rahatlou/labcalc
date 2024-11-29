#include <stdlib.h>
#include <stdio.h>

void azzera(double);

int main() {

    double a = 0., y = 2.3;
    printf("inizio main: a = %f , y = %f\n", a, y);
    azzera(a);
    printf("fine main: a = %f , y = %f\n", a, y);
}

void azzera(double x) {
    double y = -2.;
    printf("inizio azzera: x = %f, y = %f\n", x , y);
    x = -5.;
    printf("fine azzera: x = %f, y = %f\n", x , y);
}



