#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  // tutti i valori di tempo devono essere in ms
  double t0, sigma, periodo, t, G;

  // messaggio informativo
  printf("\n\nesercitazione 3, canale Pet-Z, simulazione segnale onda gravitazionale\n");

  printf("Modello semplificato G(t) = exp( -0.5 (t-t0)^2/sigma^2 ) x sin (2*pi*t/T0 ) \n");
  printf("valori tipici: t0 ~ 0.4 ms, sigma ~ 0.03 ms, T0 ~ 0.015 ms\n\n");

  // input di t0
  do{
    printf("inserire parametro t0>0 (ms): ");
    scanf("%lf", &t0);
    if(t0<=0) printf("errore. si richiede t0>0\n");
  } while(t0<=0);
  
  // input di sigma
  do{
    printf("inserire parametro sigma>0 (ms): ");
    scanf("%lf", &sigma);
    if(sigma<=0) printf("errore. si richiede sigma>0\n");
  } while(sigma<=0);

  do{
    printf("inserire periodo T0>0 (ms): ");
    scanf("%lf", &periodo);
    if(periodo<=0) printf("errore. si richiede T0>0\n");
  } while(periodo<=0);
  
  // input di t
  int cond;
  do{
    printf("inserire tempo di osservazione 0 < t < %.4lf (ms): ", 10*t0);
    scanf("%lf", &t);
     // condizione di errore se non  0 < t < 10t0
    cond = t<=0 || t>=10*t0;
    if(cond) printf("errore. si richiede 0 < t < 10*t0\n");
  } while( cond );
  
  // calcolo di G
  G = exp( -0.5 * (t-t0)*(t-t0)/sigma/sigma ) * sin( 2*M_PI*t/periodo );

  // stampa di messaggio
  // 1 ms = 1000 micro secondi
  // tempi con precisione di 0.1 ms e G con precisione per mille ( 1 parte su 1000)
  printf("\nG(%.1lf microsec) = %.4g\n", t*1000, G);


  printf("\nModello G(t) = exp( -0.5 (t-t0)^2/sigma^2 ) x sin ( 2*pi*t/T(t) ) \n"
	 "T(t) = T exp( -t/tau ), con tau = 0.2 ms\n");


  double tau = 0.2; // si assume ms anche per tau

  // calcolo nuovo periodo usando il valore inserito dall'utente
  periodo = periodo * exp(-t/tau);

  // nuovo calcolo di G
  G = exp( -0.5 * (t-t0)*(t-t0)/sigma/sigma ) * sin( 2*M_PI*t/periodo );

  //stampa nuovo valore di G
  printf("\nG(%.1lf microsec) = %.4g\n", t*1000, G);

  
  
}
