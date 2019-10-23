#include <math.h>
#include<stdlib.h>
#include<stdio.h>

#define EPS 1.e-5

int main() {

  double a = 0., b = 0.7*M_PI, c;
  double delta = fabs(a-b);

  double p;
  int iter = 0;

  double eps = EPS;

  printf("inserisci la precisione:" );
  scanf("%lf", &eps);


  printf("calcolo zeri di cos(x)\n");



  while(delta > eps ) {
    int i = iter;
    iter++;

    c = 0.5*(a+b);

    p = cos(a)*cos(c);

    if( p > 0.) {
       a = c;
    } else if ( p < 0. ) {
       b = c;
    } else {
       a = b = c;
    }

    printf("iter: %3d  x = %.15f gradi\n", iter, c*180./M_PI); 

    delta  = fabs(a-b);

  }


}
