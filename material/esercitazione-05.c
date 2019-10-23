#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* per usare la funzione time() */
#include<time.h>

/* errore: non serve definire pi greco. usare M_PI definita in math.h */
/* #define pi 3.14 */

/* numero di esperimenti da fare */
#define NEXP  1000

/* numero max di lanci dell'ago */
#define NMAX  10000

/* distanza massima */
#define DMAX 5.

int main() { 

   int lanci, iexp, j, successi;
   double d, L, x, theta;
   double pi, piMin, piMax, piAvg;

   /* inizliazzare il seme della sequenza casuale una sola volta qua. MAI nelle funzioni */
   srand48(time(0));

   /* chiedere il numero di lanci da effettuare */
   do{
     printf("Inserire numero di lanci  0 < N <= %d: ", NMAX);
     scanf("%d", &lanci);
   } while( lanci<=0 || lanci>NMAX);

   /* acquisire la distanza tra le linee */
   do{
     printf("Inserire la distanza d tra le linee 0 < d <= %.1f cm: ", DMAX);
     scanf("%lf", &d);
   } while( d<=0 || d>DMAX);

   /* chiedere lunghezza dell'ago. passiamo d come argomento 
      per poter imporre la condizione che sia L < d */
   do{
     printf("Inserire la lunghezza ago  0 < L <= %.1f cm: ", d);
     scanf("%lf", &L);
   } while( L<=0 || L>d);


   /* dichiarare massimo, minimo e valore medio piMax, piMin, piAvg */
   /* azzerare il valore medio che usiamo per sommare i valori ottenuti */
   /* inizializzare il  massimo con un valore piccolo, e il minimo con un valore grande */
   piAvg = 0;
   piMin = 10.;
   piMax = 0.;

   /* ripetere NEXP esperimenti */ 
   for(iexp=0; iexp<NEXP; iexp++)  {

      /* azzerare il numero di successi per ciascun esperimento */
      successi = 0;

      for(j=0; j< lanci; j++) {
         /* generare il valore di x */
         x = 0.5*d*lrand48()/RAND_MAX;

         /* generare il valore di theta */
         theta = 0.5*M_PI*lrand48()/RAND_MAX;

         /* aumentare i successi se si verifica la condizione */
         if( x < (L/2.)*sin(theta) ) {
           successi++;
         }
      } /* fine lanci */

      /* calcolo pi_greco */
      pi = (2.*L*lanci)/(successi*d);

      /*aggiornare il massimo */
      if( pi > piMax ) piMax = pi;
      
      /*aggiornare il minimo */
      if( pi < piMin ) piMin = pi;
      
      /* aumentare la somma che poi useremo per la media */
      piAvg += pi;

   } /* fine esperimenti */

   /* calcolo della media DOPO aver terminato gli esperimenti */
   piAvg /= NEXP;
 
   printf("valore di pigreco massimo: %.12lf\n", piMax); 
   printf("valore di pigreco minimo: %.12lf\n", piMin); 
   printf("valore medio di pigreco: %.12lf\n", piAvg); 

   return 0;
} /* fine di main() */
