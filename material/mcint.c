#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double myf(double);

int main() {

  double sum = 0;

  double a=0., b=3;

  int npt;
  for(npt=10; npt<=1e6; npt*=10) {
    sum = 0;
    for(int i=0; i<npt; i++) {
      double x = a + (b-a)*lrand48()/RAND_MAX;
      sum += myf(x);
    }
    sum = (b-a)*sum/npt;
    
    printf("#punti: %8d \t Integral: %.5f\n", npt, sum);
  }

  return 0;
}

double myf(double x) {
  return x*x;
}


