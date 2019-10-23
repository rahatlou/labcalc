#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/* tutte queste costanti non sono necessarie e servono solo
   per aiutare la lettura della soluzione
*/

#define LAMBDA 0.0025
#define NSMIN  10
#define NSMAX  30
#define NBMIN  30
#define NBMAX  200
#define dNBKG  10
#define XMIN   100.
#define XMAX   150.
#define TAGLIO 5.
#define NEXP   100
#define SIGMA  2.5
#define M0  125.

int   getInt(char* mess, int min, int max);
float getFloat(char* mess, float min, float max);
float segnale(float mu, float sig);
float fondo(float lambda, float xmin, float xmax);
void  analisi(int* s, int* b, int n, float* smin, float* smax, float* smedia);


int main() {

  int Nsig, Nbkg;
  int i, j, Bcut[NEXP], Scut[NEXP];
  float massa;
  float smedia, smin, smax;

  srand48( time(0) );

  printf("Ricerca di segnale gaussiano (mu=%.1f, sig=%.1f) e fondo esponenziale (lambda=%.1e) in [%.0f,%.0f]\n", 
         M0,SIGMA,LAMBDA,XMIN, XMAX);

  /* 2 pt: acquisizione con il controllo */
  Nsig = getInt("Numero di eventi di segnale", NSMIN, NSMAX);


  /* 2 pt: ciclo per Nbkg */
  for(Nbkg=NBMIN; Nbkg<=NBMAX; Nbkg+=dNBKG) {

      /* 2 pt: ciclo corretto esperimenti */
      for(i=0; i<NEXP; i++) {

        /* 2 pt: azzera contatori */
        Scut[i] = Bcut[i] = 0;


        /* 2 pt: cicli corretti e disgiunti per segnale e fondo */
        /* 2 pt: corretto calcolo di Bcut e Scut */
        for(j=0; j<Nsig; j++) {
          massa = segnale(M0, SIGMA);
          if( fabs(massa-M0) <= TAGLIO ) Scut[i]++;
        }

        for(j=0; j<Nbkg; j++) {
          massa = fondo(LAMBDA, XMIN, XMAX);
          if( fabs(massa-M0) <= TAGLIO ) Bcut[i]++;
        }

      } /* fine ciclo esperimenti */

      analisi(Scut, Bcut, NEXP, &smin, &smax, &smedia);

      /* 1 pt: scrivere il risultato */
      printf("segnale: %d  \t fondo: %d \t Significanza min: %.2f \t max: %.2f \t media: %.2f\n", Nsig, Nbkg, smin, smax, smedia);
  }
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
    y = pdfb+(pdfa-pdfb)*lrand48()/RAND_MAX;
   } while( y==pdfa || y==pdfb );

   /* 1 pt: calcolo di x */
   x = - log(y)/lambda;

  return x;

}

/* 3 pt: interfaccia con passaggio puntatori */
void analisi(int* S, int* B, int n, float* min, float* max, float* avg) {

  int i;
  float sig;
  
  /* 2 pt: azzerare media min, max prima di inziare i cicli */
  *min = 100;
  *max = 0.; 
  *avg = 0.0;

  /* 2 pt: calcolo media, min, max */
  for(i=0; i<n; i++) {

    sig = S[i]/sqrt(B[i]);
    *avg += sig;
    if(sig>*max) *max = sig;
    if(sig<*min) *min = sig;
  }
  *avg /= n;

  return;
}



