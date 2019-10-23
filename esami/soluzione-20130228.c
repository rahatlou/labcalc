#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/* tutte queste costanti non sono necessarie e servono solo
   per aiutare la lettura della soluzione
*/

#define LAMBDA 0.08 
#define NSMIN  10
#define NSMAX  30
#define NBMIN  20
#define NBMAX  100
#define MASMIN 8.1
#define MASMAX 12.3
#define XMIN   1.
#define XMAX   20.
#define TAGLIO 1.5
#define NEXP   10000
#define SIGMA  0.7

int   getInt(char* mess, int min, int max);
float getFloat(char* mess, float min, float max);
float segnale(float mu, float sig);
float fondo(float lambda, float xmin, float xmax);
void  analisi(float* signif, int N, float* avg, float* var);


int main() {

  int Nsig, Nbkg;
  int i, j, Bcut, Scut;
  float m0, massa;
  float significanza[NEXP];
  float media, devstd;

  srand48( time(0) );

  printf("Il programma simula una ricerca con segnale gaussiano e fondo esponenziale\n");

  /* 2 pt : acquisizione con il controllo */
  Nsig = getInt("Numero di eventi di segnale", NSMIN, NSMAX);

  /* 1 pt : acquisizione con il controllo */
  Nbkg = getInt("Numero di eventi di fondo", NBMIN, NBMAX);

  /* 1 pt : acquisizione con il controllo */
  m0 = getFloat("Inserisci il valore di m0", MASMIN, MASMAX);


  /* 2 pt : ciclo corretto */
  for(i=0; i<NEXP; i++) {

    /* 2 pt: azzera contatori */
    Scut = Bcut = 0;


    /* 2 pt: cicli corretti e disgiunti per segnale e fondo */
    /* 3 pt: corretto calcolo di Bcut e Scut */
    for(j=0; j<Nsig; j++) {
      massa = segnale(m0, SIGMA);
      if( fabs(massa-m0) <= TAGLIO ) Scut++;
    }

    for(j=0; j<Nbkg; j++) {
      massa = fondo(LAMBDA, XMIN, XMAX);
      if( fabs(massa-m0) <= TAGLIO ) Bcut++;
    }

    /* 1 pt: salvare significanza correttamente */
    significanza[i] = Scut/sqrt(Scut+Bcut);

  } /* fine ciclo esperimenti */

  analisi(significanza, NEXP, &media, &devstd); 

  /* 1 pt: scrivere il risultato */
  printf("Significanza  valore medio: %.2f \t varianza: %.2f\n", media, devstd);

  return 0;

} /* fine main */


int   getInt(char* mess, int min, int max) {
   int in;
   do{
     printf("%s in [%d,%d]:", mess, min, max);
     scanf("%d", &in);
   } while( in<min || in>max);
   return in;
}

float   getFloat(char* mess, float min, float max) {
   float in;
   do{
     printf("%s in [%.1f,%.1f]:", mess, min, max);
     scanf("%f", &in);
   } while( in < min || in>max );
   return in;
}

/* 2 pt: interfaccia */
float segnale(float mu, float sig) {
  float y1, y2;

  /* 1 pt: esclusione dello 0 */
  do{
    y1 = (float) lrand48()/RAND_MAX;
  } while(y1==0.); 

  do{
    y2 = (float) lrand48()/RAND_MAX;
  } while(y2==0.); 

  /* 2 pt: calcolo di x */
  return mu + sig*cos(2*M_PI*y1)*sqrt(-2*log(y2));

}


/* 2 pt: interfaccia */
float fondo(float lambda, float a, float b) {
   float x,y;

   /* 1 pt: calcolo degli estremi */
   float pdfa = exp(-lambda*a);
   float pdfb = exp(-lambda*b);

   /* 2 pt: calcolo di p */
   do{
    y = pdfb+(pdfa-pdfb)*(float)lrand48()/RAND_MAX;
   } while( y==pdfa || y==pdfb );

   /* 1 pt: calcolo di x */
   x = - log(y)/lambda;

  return x;

}

/* 3 pt: interfaccia con passaggio puntatori */
void analisi(float* signif, int N, float* avg, float* var) {

  int i;
  
  /* 2 pt: azzerare media e var prima di inziare i cicli */
  *avg = *var = 0.0;

  /* 2 pt: calcolo media */
  for(i=0; i<N; i++) {
    *avg += signif[i];
  }
  *avg /= N;

  /* 3 pt: calcolo varianza */
  for(i=0; i<N; i++) {
    *var += (signif[i]-*avg)*(signif[i]-*avg);
  }
  *var /= (N-1);
  *var = sqrt( *var );

  return;

}



