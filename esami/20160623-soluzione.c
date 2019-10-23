#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

/* 1 pt: uso libreria matematica */

#define Nmax 1000
#define p0 0.08
#define nexp 100

/* 1 pt: interfaccia */
int randInt(int);

/* 3 pt: interfaccia */
void analisi(double*, int, double*, double*);

int main() {

  srand48(time(0));

  int iexp, j, indice, k;
  int N, m;
  
  /* 1 pt: array di lunghezza giusta */
  int partita[Nmax] = {0};
  double difettosi[nexp], x, zmedia, zdev;


  /* prendi numero N di elementi in una partita */
  /* 2 pt: */
  do{
    printf("inserire numero auricolari 30 <= N<= 1000: ");
    scanf("%i", &N);
  } while( N< 30 || N>1000 );

  /* prendi numero auricolari da testare */
  /* assicurarsi che m sia almeno 1 e non piu` di N */
  /* 3 pt: */
  do{
    printf("inserire numero di aurcolari da testare 0 < m <= %d: ", N);
    scanf("%i", &m);
  } while( m<1 || m>=N );
  

  /* 1 pt: ciclo giusto */
  /* ciclo sulle partite da testare */
  for(iexp=0; iexp<nexp; iexp++) {

    // genera casualmente una partita con p0 probablita` di avere elementi difettosi
    /* 3 pt: */
    for(j=0; j<N; j++) {
      /* 1 pt: numeri casuali tra 0 e 1 */
      x = (double)lrand48()/RAND_MAX;
      if(x<p0)  partita[j] = 0;
      else  partita[j] = 1;
    }

    /* testa questa partita */
    /* 2 pt: */
    k = 0;
    for(j=0; j<m; j++) {
      /* genera casualmente m indici di elementi da testare */
      indice = randInt(N) - 1;
      /* conta k elementi difettosi su m testati */
      if(partita[indice]==0) k++;
    }

    /* 1 pt: */
    /* frazione difettosi nel campione */
    difettosi[iexp] = (double)k/m;

    /* DEBUG: stampare frazione elementi difettosi */
    /* printf("paritita: %d  frazione auricolari difettosi: %.3f\n", iexp+1, difettosi[iexp]);  */ 
    
  } /* fine esperimenti */

  /* 1 pt: chiamata giusta alla funzione */
  /* calcola media e deviazione standard di frazione di elementi difettosi */
  analisi(difettosi, nexp, &zmedia, &zdev);

  
  /* stampa i valori ottenuti */
  /* 2 pt: */
  printf("frazione media di auricolari difettosi: %.3f +- %.3f\n", zmedia, zdev/sqrt(nexp));  
  printf("dev std frazione di auricolari difettosi: %.3f\n", zdev);
}


/* genera numeri interi casuali tra 1 ed M compresi */
/* 2 pt: */
int randInt(int M) {
  return (lrand48()%M) + 1;
}

/* calcola media e dev std di array dati di lunghezza n */
void analisi(double* dati, int n, double* med, double* dev) {
  int i;

  /* calcolo media */
  /* 3 pt: */
  *med = 0;
  for(i=0; i<n; i++) {
    *med += *(dati+i);
  }
  *med /= n;

  /* calcolo dev std */
  /* 3 pt: */
  *dev = 0;
  for(i=0; i<n; i++) {
    *dev += (dati[i]-*med)*(dati[i]-*med);
  }
  *dev /= n-1;
  *dev = sqrt(*dev);
  
}
