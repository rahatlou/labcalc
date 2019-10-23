#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

  int a1, a2, an;
  int i, n;

  a1=1;
  a2=1;

  printf("calcolo della serie di Fibonacci\n");

  do{
    printf("Quale elemento F_n della serie vuoi calcolare (0 < n < 100)? ");
    scanf("%d", &n);
  } while( n<0 || n>=100 );

  for(i=3; i<n+1; i++) {

    an = a1 + a2;
    printf("a_%-2d: %d\n", i, an);

    a1 = a2;
    a2 = an;

  }

}
