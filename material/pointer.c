#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NMAX 3

int main() {

  // variabili
  double x = M_PI;
  int a = 2;

  // stampa a e x
  printf("a = %d   x = %f\n\n", a, x);

  // stampa indirizzo di a e x con oil descrittore %p
  printf("&a = %p   &x = %p \n\n", &a, &x);
  
  // puntatore a int e double sono diversi
  int* ptr1;
  double* ptr2;

  // valore dei puntatore con %p
  printf("ptr1 = %p   ptr2 = %p \n\n", ptr1, ptr2);
  
  // assegnazione puntatore
  ptr1 = &a;
  ptr2 = &x;

  // valore dei puntatore con %p
  printf("ptr1 = %p   ptr2 = %p \n\n", ptr1, ptr2);
  
  // stampa valore di valore di *ptr1 e *ptr2
  printf("*ptr1 = %d \n", *ptr1);  
  printf("*ptr2 = %f \n\n", *ptr2);

  // modifica valore di variabili a cui puntano ptr1 e ptr2
  *ptr1 = 56;
  *ptr2 = -1.2322;

  // valore dei puntatore con %p
  printf("ptr1 = %p   ptr2 = %p\n\n", ptr1, ptr2);

  // stampa a e x
  printf("a = %d   x = %f\n", a, x);

  // stampa valore di valore di *ptr1 e *ptr2
  printf("*ptr1 = %d \n", *ptr1);  
  printf("*ptr2 = %f \n\n", *ptr2);
  
  // indirizzo dei puntatore
  printf("indirizzo dei puntatore:\n");
  printf("&ptr1 = %p   &ptr2 = %p\n\n", &ptr1, &ptr2);  

  // errori comuni con puntatori
  printf("======= errori comuni =====\n");
  printf("ptr1 = %d \n", ptr1);
  printf("ptr1 = %f \n\n", ptr1);

  int* p3;
  double y = -12.23;

  p3 = &y;

  printf("p3 = %p \n", p3);
  printf("*p3 = %d \n", *p3);
  
}  
