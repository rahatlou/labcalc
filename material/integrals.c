#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double myf(double x) {
    return x*sin(x)*log(x);
}


double midPoint( double (*)(double), double, double, int);
double trapezio( double (*)(double), double, double, int);

int main() {

    double (*pf)(double);
    pf = &myf;
    //pf = &cos;
    //pf = &sinh;

    double a = 0.001, b = 2.5;

    for(int npt=10; npt<1e8; npt*=10) {
        double mpInt = midPoint( pf, a, b, npt);
        double trapInt = trapezio( pf, a, b, npt);
        printf("npt: %8d \t midpoint: %.6f \t trapezio: %.6f\n", npt, mpInt, trapInt);
    }

}

double midPoint( double (*f)(double), double a, double b, int npt)  {

    double dx = (b-a)/npt;

    double tot = 0.;
    for(int i=0; i<npt; i++) {
        double c1 = a + i*dx;
        double c2 = a + (i+1)*dx;
        double m = a + i*dx + 0.5*dx;
        tot += f(m)*dx;
    }
    return tot;

}


double trapezio( double (*f)(double), double a, double b, int npt)  {

    double dx = (b-a)/npt;

    double tot = 0.;
    for(int i=0; i<npt; i++) {
        double c1 = a + i*dx;
        double c2 = a + (i+1)*dx;
        tot += 0.5*(f(c1)+f(c2))*dx;
    }
    return tot;

}


