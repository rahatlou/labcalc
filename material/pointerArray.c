#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NMAX 3

int main() {

  // variabili
  int a = 2;
  
  printf("indirizzo di a: %p\n", &a);

  int* ptr1 = &a;

  int voti[NMAX] = {30, 18, 25};
  
  for(int i = 0; i<NMAX;i++) {
    printf("voti[%d] = %d \t &voti[%d] = %p\n", i, voti[i], i, &voti[i] );
  }



  double x = M_PI;
  double* ptr2;
  ptr2 = &x;

  printf("x = %lf prima di pointer\n", x);
  
  *ptr2 = -3.3;

  printf("x = %lf dopo pointer\n", x);

  double y;
  
  printf("y = %lf\n", y);
  y = (*ptr2) * sqrt(3);
  printf("y = %lf\n", y);


  // array name as pointer
  for(int i = 0; i<NMAX;i++) {
    printf("voti[%d] = %d \t &voti[%d] = %p\n", i, voti[i], i, &voti[i] );
  }

  printf("voti = %p\n", voti);

  printf("*voti = %d\n", *voti);

  for(int i = 0; i<NMAX;i++) {
    printf("voti+%d = %p \t *(voti+%d) = %d\n", i, voti+i, i, *(voti+i) );
  }

  
}
