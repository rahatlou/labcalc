// bonus +1: funzioni aggiuntive utili e riutilizzabili
// -3: mancata compilazione
// -1: mancata separazione di dichirazione e implemetazione di funzione
// -2: errore di sintassi di base:
//      dichiarazione funzioni dentro main()
//      indice array fuori range
// -2: errori di logica
// -1: mancata inclusione di header delle librerie

#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<math.h>


// 1 pt: uso di pre-compilatore per costanti
#define TMIN 0
#define TMAX M_PI

#define M_min 0.9
#define M_max 5.4

#define E_min 0.1
#define E_max 7.3

/* dichiarazione funzioni richieste*/
// 8 = 2 x 4 pt: per ciascuna interfaccia corretta
double getVal(char*, double min, double max);
double Ediff(double t, double M, double E0);
double integrale(double M, double E0, double tmin, double tmax);
double probAvanti(double M, double E0);
// in alternativa per chi preferisce il metodo MC
// basta solo cambiare una riga in probAvanti() con tutto il resto invariato
double integraleMC(double M, double E0, double tmin, double tmax);

int main() {

  srand48(time(0)); // per chi usa il metodo MC
  
  /*dichiarazione variabili*/
  double M, E0,p;

  /*input*/

  M  = getVal("Massa nucleo M", M_min, M_max);
  E0 = getVal("energia inziale E0",E_min, E_max);

  // 1 pt: stampa risultato come richiesto
  printf("M: %.3f GeV\t E0: %.3f GeV\t p(E0): %.3f\n", M, E0,probAvanti(M, E0));

  //  ============= seconda parte ============= 

  // 1 pt: array di dimensione e lunghezza corrette
  // numero di righe = (E_max - E_min)/0.15 = 48
  // colonna 0: E0 colonna 1: p(E0)
  double dati[50][2];

  E0 = E_min;
  double dE = 0.15; // GeV
  int counter=0;

   // 2 pt: ciclo con variabili e passo corretti
  while(E0 <= E_max) {
    // cacolo frazione per ciascun valore di E0
    p = probAvanti(M, E0);

    // 1 pt: uso corretto dell'array
    dati[counter][0] = E0;
    dati[counter][1] = p;

    printf("M: %.3f GeV\t E0: %.3f GeV\t p(E0): %.3f\n", M, E0,p);

    // variazione di E0 e counter
    E0 += dE;
    counter++;
  }

  // 1 pt: apertura e chisura su file
  FILE* f;
  f = fopen("elettroni.txt", "w+");

  // 1 pt: ciclo su dati per la stampa
  // 1 pt: scrittura su file con formato corretto
  for(int i=0; i<counter; i++) {
    fprintf(f," %.5f  %.5f\n", dati[i][0], dati[i][1]);
  }
  
  fclose(f);

  return 0;
}


// 2 pt: corretta implementazione con limiti e nome variabile
double getVal(char* var, double min, double max){
  double x;
  do{
    printf("inserire %s in [%.3f,%.3f]: ", var, min,max);
    scanf("%lf", &x);
    if(x<min || x>max)  printf("valore errato!\n");
  }while(x<min || x>max);
  return x;
}

// 1 pt: corretta implementazione della formula
double Ediff(double t, double M, double E0) {
  return E0/(1+(E0/M)*(1-cos(t)));
}


// 6 pt: calcolo integrale
double integrale(double M, double E0, double tmin, double tmax){

  // metodo punto di mezzo
  int nbins = 1000;
  double h = (tmax-tmin) / nbins; // larghezza intervallo
  double somma = 0., t;
  
  for(int i=0; i<nbins; i++) {
    t = tmin + (i + 0.5) * h; //calcolo punto medio del singolo intervallo
    //printf("%lf %lf\n",t,Ediff(t,M,E0));
    somma += Ediff(t,M,E0)*h;
  }

  return(somma);
  
}

// 2 pt: calcolo frazione in avanti
double probAvanti(double M, double E0){
  double p = integrale(M,E0,TMIN,TMAX/2)/integrale(M,E0,TMIN,TMAX);
  // per usare il metodo MC basta sostituire integrale -> integraleMC
  // 
  
  return p;
}


double integraleMC(double M, double E0, double tmin, double tmax){
  int nbins = 1000;
  double h = (tmax-tmin) / nbins; // larghezza intervallo
  double somma = 0., t;
  
  for(int i=0; i<nbins; i++) {
    t = tmin + (tmax-tmin)*lrand48()/RAND_MAX;
    somma += Ediff(t,M,E0)*h;
  }

  return(somma);
  
}
