#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N    1000
#define dy   1.
#define dx   0.2
#define YMAX 100.


double uniforme(double, double);
void newPos(double*, double*, double, double);

int main() {
  double psec;
  double x[N] = {0.};
  double y[N] = {0.};
  int i=0;
  int j;
  int nPunti = 0;
  FILE* fout;
  char  fname[] = "fulmine.txt";
  double x0, y0;

  srand48(time(0));

  printf("Simulazione del fulmine\n");


  do{
    printf("inserire probabilita di scariche secondarie (<1.0):");
    scanf("%lf", &psec);
  } while(psec<=0 || psec>1.);

  /* scarica principale */
  x[0] = 0;
  y[0] = 0;
  while( i<N-1 && y[i]<YMAX ){
    i++;
    newPos( x+i, y+i, x[i-1], y[i-1] );
    /*
      printf("i: %4d\t x: %3.2f\t y: %3.2f\n", i, x[i], y[i]);
    */
  }

  nPunti = i;
  printf("Punti lungo la scarica principale: %d\n", i);


  /* Ciclo su punti scarica primaria */
  j = 1;
  while( j<=nPunti && i<N-1 ) {
    /* il ciclo si fa solo sui punti della scarica primaria
       E SOLO SE ci sono celle libere negli array dove scrivere le coordinate
    */

    /* decidi se fare scarica secondaria */
    if( uniforme(0,1) < psec ) {
      
      x0 = x[j];
      y0 = y[j];
      printf("inizio scarica secondaria dal punto j = %d\t x: %.2f \t y: %.2f \n", j, x0,y0);
 
      do {
	i++;
	newPos( x+i, y+i, x0, y0 );
	x0 = x[i];
	y0 = y[i];
        /*
	  printf("secondaria i: %4d \t x: %3.2f \t y: %3.2f\n", i, x[i], y[i]);
	*/
      } while(i<N-1 && y[i]<YMAX );
      /* numero di punti salvati ora include anche la scarica secondaria */

    }/* scarica secondaria */

    j++; /* prossimo punto lungo la scarica primaria */
    
  } /* fine ciclo su scarica primaria */

  printf("al termine del programma i = %d (<%d se tutto ok) \n", i, N);

  /* scrittura su file */
  fout = fopen(fname, "w");
  for(j=0; j<=i; j++){
    fprintf(fout, "%.1f \t %.1f\n", x[j], y[j]);
  }
  fclose(fout);

  return 0;
} /* end of main */

double uniforme(double a, double b) {
  return a +(b-a)*lrand48()/RAND_MAX;
}

void newPos(double* xout, double* yout, double xin, double yin) {

  *xout = xin + uniforme(-dx,dx);
    *yout = yin + dy;
}
