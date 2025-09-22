#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// bonus +1: funzioni aggiuntive utili e riutilizzabili
// -3: mancata compilazione
// -1: mancata separazione di dichirazione e implemetazione di funzione
// -2: errore di sintassi di base:
//      dichiarazione funzioni dentro main()
//      indice array fuori range
// -2: errori di logica


// 1 pt: direttive pre-compilatore
#define dofMin 2
#define dofMax 17
#define NMIN  100
#define NMAX  1000

int   getInt(char* mess, int min, int max);
double uniforme(double,double);

// 6 pt: 2 per interfacc: tipo di ritorno e argomenti sensati 
//                        per avere funzioni riutilizzabili
double gauss(double mu, double sig);
double media(double* , int );
double stddev(double*, int);

int main() {

  int Ndof, Nmis;
  int i, j;

  // 1 pt:  lunghezza dati
  double dati[NMAX]={0.};
  double avg, var;
  double Chi2;

  int hist_chi2[dofMax*2]={0};

  /* 1 pt: corretto uso di srand48() */
  srand48( time(0) );

  printf("Il programma simula generazione di una distribuzione di chi quadro.\n");

  /* 2 pt : corretta acquisizione con il controllo di min e max */
  Ndof = getInt("Numero gradi di liberta", dofMin, dofMax);

  /* 1 pt : acquisizione con il controllo */
  Nmis = getInt("Numero di misure da simulare", NMIN, NMAX);
  
  for(i=0; i<Nmis; i++) {
    
    /* 1 pt: azzerare Chi2 per ciascuna misura */
    Chi2 = 0;
    
    /* 2 pt: ciclo corretto e calcolo chi2 */
    for(j=0; j<Ndof; j++) {
      Chi2 += pow( gauss(0., 1.), 2 );
      
      /* NB: e` un errore grave fare gauss(0., 1.)*gauss(0., 1.) perche` in questo caso
	 ciascuna chiamata genera un nuovo valore per cui si fa il prodotto di due 
	 valori diversi e non il quadrato dello stesso valore.
      */ 
    }

    // 1 pt: salvataggio di chi2 in array
    dati[i] = Chi2;

    // 2 pt: conteggio per intervallo di chi2
    hist_chi2[ (int)Chi2 ]++;
    
  } /* fine ciclo misure */

  // 2 pt: chiamata alle funzioni
  avg = media(dati, Nmis);
  var = stddev(dati, Nmis);
  
  /* 2 pt: stampa del risultato */
  printf("Nmis: %4d \t Ndof: %2d \t media: %.2f \t dev std: %.2f\n",
	 Nmis, Ndof, avg, var);


  // 1 pt: apertura e chiusura file
  FILE* fp;
  char fname[100] = "chi2.dat";
  fp = fopen(fname, "w+");
  if(!fp) {
    printf("problema con la creazione di %s.. exit.\n", fname);
    exit(-1);
  }

  // 1 pt: scrittura sul file
  for(int i=0; i<Ndof*2; i++) {
    fprintf(fp, "%4d  %4d\n", i, hist_chi2[i]);
  }
  
  fclose(fp);
  
  return 0;
  
} /* fine main */


int getInt(char* mess, int min, int max) {
  int in;
   do{
     printf("%s in [%d,%d]:", mess, min, max);
     scanf("%d", &in);
   } while( in<min || in>max);
   return in;
}


double gauss(double mu, double sig) {
  double y1, y2;
  
  /* 2 pt: generazione esclusione dello 0 */
  do{
    y1 = (double) lrand48()/RAND_MAX;
  } while(y1==0.); 
  
  do{
    y2 = (double) lrand48()/RAND_MAX;
  } while(y2==0.); 
  
  /* 1 pt: calcolo di gauss */
  return mu + sig*cos(2*M_PI*y1)*sqrt(-2*log(y2));
  
}


/* 2 pt: calcolo media e azzeramento sum */
double media(double* x, int n) {
  int i;
  double sum=0;
  for(int i=0; i<n; i++){
    sum += x[i];
  }
  return sum/n;
  
}

/* 2 pt: calcolo std dev e azzeramento sum */
double stddev(double* x, int n) {
  int i;
  double sum=0;
  double m = media(x,n); // calcolo media con la funzione gia` fatta
  for(int i=0; i<n; i++){
    sum += (x[i]-m)*(x[i]-m);
  }
  return sqrt(sum/(n-1));
}
