#include <stdlib.h>
#include <stdio.h>

void pbyValue(double);
void pbyPtr(double*);

int main() {

    double a = 1.32, x = 2.3;
    printf("main inizio:\t a = %f , x = %f\n\n", a, x);

    pbyValue(a);

    printf("main dopo pbyValue: a = %f , x = %f\n\n", a, x);

    
    double* ptr = &a;
    
    pbyPtr( ptr );

    printf("main fine:\t a = %f , x = %f\n\n", a, x);
}

void pbyValue(double x) {
    double a = 33;
    printf("inizio pbyValue: a = %f , x = %f\n", a, x);

    x = -5.;
    printf("fine pbyValue: a = %f , x = %f\n\n", a, x);

}

void pbyPtr(double* x) {
    double a = 33;
    printf("inizio pbyPtr: a = %f , *x = %f\n", a, *x);

    *x = -5.;
    printf("fine pbyPtr: a = %f , *x = %f\n\n", a, *x);

}


