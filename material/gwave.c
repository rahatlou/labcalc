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
  printf("inserire parametro t0 (ms): ");
  scanf("%lf", &t0);

  // input di sigma
  printf("inserire parametro sigma (ms): ");
  scanf("%lf", &sigma);
  
  printf("inserire periodo T0 (ms): ");
  scanf("%lf", &periodo);

  // input di t
  printf("inserire tempo di osservazione t (ms): ");
  scanf("%lf", &t);

  // messaggio di errore se t0<0
  if(t0<0) {
    printf("calcolo possibile solo per t0 > 0 ... exit\n");
    exit(-1);
  }

  // messaggio di errore se t > 10*t0
  if(t>10*t0) {
    printf("calcolo non attendibile per t > 10 x t0 ... exit\n");
    exit(-1);

  }

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
