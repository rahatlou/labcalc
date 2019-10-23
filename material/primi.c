#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

int main() {

  int i,j,jMax;
  printf("numeri primi tra 1 e %d:\n", N);
  for(i=1; i<=N; i++) {
    j = 2;
    jMax = (int)sqrt(i)+1;

    while( (j<jMax) && (i%j) ) {
      j++;
    }
    if(j == jMax) printf("%d\n", i);

  }


}
