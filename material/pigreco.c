#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>

int main() {
  
  // inizializza seme numeri
  srand48(time(0));

  int npoint=10;
  int ncerchio;
  double r=1., x,y;
  double mypi=0.;
  
  while(npoint<=1e8){
    ncerchio = 0;
    for(int j=0; j<npoint; j++){
      x = -r + 2.*r*lrand48()/RAND_MAX;
      y = -r + 2.*r*lrand48()/RAND_MAX;
      if( x*x+y*y < r*r ) ncerchio++;
    }

    
    mypi =  2.*2.*ncerchio/npoint;
    
    printf("npoint: %-10d \t  stima: %.10lf\n", npoint, mypi);

    npoint *=10;
    
  }
  printf("pi: %.10lf \t |stima - pi| = %.2g\n", M_PI, fabs(mypi-M_PI));

}
