#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NMAX 3

int main() {

  // pointer di interi
  int a=2, voti[NMAX]={-1, 3, -5};
  int* ptr1;
  
  printf("indirizzo di a: %p\n", &a);

  ptr1 = &a;
  printf("ptr1 = %p  &ptr1 = %p\n", ptr1, &ptr1);

  for(int i = 0; i<NMAX;i++) {
    printf("voti[%d] = %d \t &voti[%d] = %p\n", i, voti[i], i, &voti[i] );
  }

    // pointer di double
  double x=M_PI, y=sqrt(2), dati[NMAX] = {1.2232, M_PI, -3.2e-4};
  double* ptr2;

  for(int i = 0; i<NMAX;i++) {
    printf("dati[%d] = %lf \t &dati[%d] = %p\n", i, dati[i], i, &dati[i] );
  }


  // uso di pointer
  ptr2 = &x;

  printf("x = %lf prima di pointer\n", x);
  
  *ptr2 = -3.3;

  printf("x = %lf dopo pointer\n", x);
  
  
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
  
