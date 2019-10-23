#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/* tutte queste costanti non sono necessarie ma utili
   per la lettura della soluzione
*/


#define dofMin 2
#define dofMax 13
#define NMIN  100
#define NMAX  1000


int   getInt(char* mess, int min, int max);
float gauss(float mu, float sig);
void  analisi(float* signif, int N, float* avg, float* var);


int main() {

  int Ndof, Nmis;
  int i, j;

  float dati[NMAX]={0.};
  float media, var;
  float Chi2;

  /* 2 pt: corretto uso di srand48() */
  srand48( time(0) );

  printf("Il programma simula generazione di una distribuzione di chi quadro.\n");

  /* 3 pt : corretta acquisizione con il controllo di min e max */
  Ndof = getInt("Numero gradi di liberta", dofMin, dofMax);

  /* 1 pt : acquisizione con il controllo */
  Nmis = getInt("Numero di misure da simulare", NMIN, NMAX);

  /* 2 pt : ciclo corretto */
  for(i=0; i<Nmis; i++) {

    /* 2 pt: azzerare Chi2 */
    Chi2 = 0;

    /* 3 pt: ciclo corretto per calcolo chi2 */
    for(j=0; j<Ndof; j++) {

       /* 3 pt: corretta chiamata di gauss per calcolo g_i */
       Chi2 += pow( gauss(0., 1.), 2 );
     
       /* NB: e` un errore grave fare gauss(0., 1.)*gauss(0., 1.) perche` in questo caso
          ciascuna chiamata genera un nuovo valore per cui si fa il prodotto di due valori diversi 
          e non il quadrato dello stesso valore.
       */ 
      
    }


    /* 1 pt: salvare significanza correttamente */
    dati[i] = Chi2;

  } /* fine ciclo esperimenti */

  analisi(dati, Nmis, &media, &var); 

  /* 1 pt: scrivere il risultato */
  printf("valore medio: %.2f \t varianza: %.2f\t dev std: %.2f\n", media, var,sqrt(var));

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

/* 3 pt: interfaccia */
float gauss(float mu, float sig) {
  float y1, y2;

  /* 2 pt: esclusione dello 0 */
  do{
    y1 = (float) lrand48()/RAND_MAX;
  } while(y1==0.); 

  do{
    y2 = (float) lrand48()/RAND_MAX;
  } while(y2==0.); 

  /* 2 pt: calcolo di x */
  return mu + sig*cos(2*M_PI*y1)*sqrt(-2*log(y2));

}


/* 3 pt: interfaccia con passaggio puntatori */
void analisi(float* signif, int N, float* avg, float* var) {

  int i;
  
  /* 2 pt: azzerare media e var prima di inziare i cicli */
  *avg = *var = 0.0;

  /* 3 pt: calcolo media */
  for(i=0; i<N; i++) {
    *avg += signif[i];
  }
  *avg /= N;

  /* 3 pt: calcolo varianza */
  for(i=0; i<N; i++) {
    *var += (signif[i]-*avg)*(signif[i]-*avg);
  }
  *var /= (N-1);

  return;

}



