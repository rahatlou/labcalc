#include <stdio.h>

int main() {
    double a, b;
    a = -1.2;
    b = 2.3;
    double c = a + b;
    printf("c = %lf\n", c);

    int x = 2, y = 3;
    int decisione = (x == y);       // 0 = falso, 1 = vero
    printf("2 == 3 : %d\n", decisione);
    decisione = (x != y);
    printf("2 != 3 : %d\n", decisione);
    decisione = (x > y);
    printf("2 >  3 : %d\n", decisione);

    x = y;                          // assegnazione: x diventa 3
    printf("dopo x = y:  x = %d, y = %d\n", x, y);
}
