#include <stdio.h>
#include <math.h>

int main() {
    double r, area, circ;
    printf("raggio (m): ");
    scanf("%lf", &r);
    area = M_PI * r * r;
    circ = 2. * M_PI * r;
    printf("area = %.3f\n", area);
    printf("circonferenza = %.3f\n", circ);
}
