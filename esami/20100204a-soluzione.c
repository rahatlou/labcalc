#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define Natomi 500
#define Rmax 1.0

void generatePosition(double* x, double* y, double* z, double* raggio);
void scriviDistanze(double* d, int* imin, int* imax);
double frazione(double* d, double rin, double rout);

int main() {

  double R1=0., R2=0.; /* raggio interno ed esterno */
  double pos[Natomi][3]; /* posizioni degli atomi */
  double distanza[Natomi]; /* distanza degli atomi dall'origine */
  int i; /* indice degli atomi */
  int iDmin, iDmax; /* indice degli atomi con la distanza minima e massima */

  /* inizializza il generatore random */
  srand48( time(0) );

  /* chiedere i valori di input per R1 e R2 */
  do {
  	printf("Inserire il valore del raggio interno R1(0.0 - %lf): ", Rmax);
  	scanf("%lf", &R1);
  } while (R1 < 0. || R1 > Rmax);
  
  	
  do {
  	printf("Inserire il valore del raggio esterno R2(%lf - %lf): ", R1, Rmax);
  	scanf("%lf", &R2);
  } while (R2 <= R1 || R2 > Rmax);

  printf("Avete scelto i valori R1 = %lf e R2 = %lf\n", R1, R2);
  
  /* genera le posizioni e riempie i due array */
  for(i=0; i < Natomi; ++i) { 
    generatePosition(&pos[i][0], &pos[i][1], &pos[i][2], &distanza[i]); 
  }

  /* scrivi sul file e trova indice min e max distanza */
  scriviDistanze(distanza, &iDmin, &iDmax);

  /* se tutto corretto fino qua si ha la sufficienza */

  /* scrivi le coordinate degli atomi con distanza min e max sullo schermo */
  printf("atomo piu` lontano (x,y,z)=(%lf,%lf,%lf)   distanza: %lf\n", 
         pos[iDmax][0],pos[iDmax][1], pos[iDmax][2], distanza[iDmax] );
 
  printf("atomo piu` vicino (x,y,z)=(%lf,%lf,%lf)   distanza: %lf\n", 
         pos[iDmin][0],pos[iDmin][1], pos[iDmin][2], distanza[iDmin] );
  
  /* calcola la frazione degli atomi nella corona circolare */
  printf("frazione di atomi con R1 <= r <= R2: %lf\n", frazione(distanza,R1,R2) );

  /* calcola il  volume esatto della corona */
  printf("volume della corona sferica/volume sfera unitaria: %lf\n", pow(R2,3)-pow(R1,3) );


  return 0;
}


void generatePosition(double* x, double* y, double* z, double* raggio) {
   
  /* variabili locali */
  do {
    /* genera ciascuna coordinata */
    *x = -Rmax + (double)lrand48()*2.*Rmax/RAND_MAX;
    *y = -Rmax + (double)lrand48()*2.*Rmax/RAND_MAX;
    *z = -Rmax + (double)lrand48()*2.*Rmax/RAND_MAX;

    /* calcola il raggio */
    *raggio = sqrt( *x * *x + *y * *y + *z * *z );

    /* ripeti il ciclo se raggio < rin oppure raggio > rout */
  } while( *raggio > Rmax);

  return;
}

void scriviDistanze(double* d, int* imin, int* imax) {

  FILE* file;
  int i; /* indice per il loop */

  /* inizializza gli indici arbitrariamente*/
  *imin = 0;
  *imax=0;

  /* apri il file. controllo sulla riuscita e` facoltativo */
  file = fopen("distanze.dat","w+");

  /* ciclo su distanza */
  for(i=0; i < Natomi; ++i) {
    fprintf(file,"%d  %lf\n", i, d[i]); /* scrivi sul file */

    /* aggiorna max e min. NB: le condizioni non sono esclusive */
    if( d[i] > d[*imax] ) { *imax = i; }
    if( d[i] < d[*imin] ) { *imin = i; }
  }

  fclose(file);
  return;
}

double frazione(double* d, double rin, double rout) {
  int atomidentro=0; /* # atomi nella corona sferica*/
  int i;

  for(i = 0; i<Natomi; ++i) {
      if( d[i] >= rin && d[i] <= rout ) { atomidentro++; }
  }

  return (double) atomidentro/Natomi;
}
