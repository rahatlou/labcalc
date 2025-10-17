#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

  unsigned long long int a0, a1, an;
  int i, n;

  a0=0;
  a1=1;

  printf("calcolo della serie di Fibonacci\n");

  do{
    printf("Quanti elementi della serie vuoi calcolare (0 < n < 100)? ");
    scanf("%d", &n);
  } while( n<0 || n>=100 );

  printf("a_1 : %llu\n", a1);

  for(i=2; i<n+1; i++) {

    an = a0 + a1;
    printf("a_%-2d: %llu\n", i, an);

    a0 = a1;
    a1 = an;

  }

}
