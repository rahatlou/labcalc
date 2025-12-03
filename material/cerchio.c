#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NMAX 3

// genera distribuzione uniforme in [a,b]
double uniforme(double,double);

// genera punti (x,y) nel cerchio di raggio R
void cerchio(double, double*, double* );

// stampa coordinate punto
void stampa(double, double);

void stampaVec(double*);


int main() {
  double R = 2.2;

  double x,y;

  // genera un punto nel cerchio passando puntatore a x e y
  cerchio(R, &x, &y);
  stampa(x,y);

  printf("--------------------------------------\n");

  // array 1D di lunghezza 2 per le coordinate di un punto
  double punto[2];

  cerchio(R, &punto[0], &punto[1]);
 
  stampa(punto[0],punto[1]);
  
  //stampa con funzione dedicata
  stampaVec(punto);

  printf("--------------------------------------\n");

  // uso dell'array come puntatore
  cerchio(R, punto, punto+1);
  stampaVec(punto);

  printf("--------------------------------------\n");

  // array 2D
  double disco[NMAX][2];

  for(int i=0; i<NMAX; i++) {
    printf(" --- i: %2d -----\n", i);

    cerchio(R, &x, &y);
    disco[i][0] = x;
    disco[i][1] = y;
    
    stampa(x,y);
    stampa( disco[i][0], disco[i][1] );

    //  *(disco+i) e` un puntatore alla riga i-esima
    stampaVec( *(disco+i) );
    printf("--------------------------------------\n");

    // puntatore a singola cella di array con &
    cerchio(R, &disco[i][0], &disco[i][1]);
    stampaVec( *(disco+i) );

    printf("--------------------------------------\n");

    // uso del nome di array come puntatore
  
    // *(disco+i) punta alla riga i-esima
    // ossia punta alla colonna 0 della riga i
    // *(disco+i)+1 puntatore alla colonna di indice 1 della riga i
    
    cerchio(R, *(disco+i), *(disco+i)+1 );
    stampaVec( *(disco+i) );
	    
  }

}

double uniforme(double a, double b) {
  return a+(b-a)*lrand48()/RAND_MAX;  
}


void cerchio(double R, double* x, double* y) {
  do {
    *x = uniforme(-R,R);
    *y = uniforme(-R,R);
  } while( *x**x + *y**y >= R*R );
}

 void stampa(double x, double y) {
   printf("x: %.1f, y: %.1f, raggio: %.1f\n",
	  x, y, sqrt(x*x+y*y) );
     
 }

  void stampaVec(double* p) {
   printf("x: %.1f, y: %.1f, raggio: %.1f\n",
	  *p, *(p+1), sqrt(*p**p+*(p+1)**(p+1)) );

 }
