#include <stdio.h>

int main() {
  double a = 4, b = 3., c=2, d;


  printf("a = %f \t b = %lf \t c = %lf\n\n", a,b,c);
  
  d = a*b/c;
  printf("a*b/c = %f\n\n", d);
  

  d = a/b*c;
  printf("a/b*c = %f\n\n", d);

  
  d = a/(b*c);
  printf("a/(b*c) = %f\n\n", d);

    
    return 0;
}


