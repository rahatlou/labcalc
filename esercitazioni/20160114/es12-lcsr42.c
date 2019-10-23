#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define NMIN 180
#define NMAX 220
#define NPMIN 4
#define NPMAX 7
#define COSTO 1.50

int getInt(int, int);
void packet(int*, int, int, int);
void update(int*, int, int*);
void exchange(int*, int*, int);
int check(int*, int);

int main() {
  int N, scelta, i, npa=0, npi=0, doppa=0, doppi=0;
  int paolo[NMAX]={0}, pietro[NMAX]={0}, bustina[NPMAX];

  srand48(time(0));
  
  printf ("Questo programma simula il completamento degli album di figurine di due bambini\n");
  printf ("Inserire il numero di figurine contenute negli album (tra %d e %d): ", NMIN, NMAX);
  do {
    scanf("%d",&N);
    if (N<NMIN || N>NMAX) printf ("Input errato, ripeti\n");
  } while (N<NMIN || N>NMAX);
  printf ("Vuoi che i bambini si scambino i doppioni (inserire 1) oppure no (inserire 2)?\n");
  do {
    printf ("Scelta dell'utente: ");
    scanf("%d",&scelta);
    if (scelta!=1 && scelta!=2) printf ("Input errato, riepti\n");
  } while (scelta!=1 && scelta!=2);

  do {
    if (check(paolo, N)==0) {
      for (i=0; i<NPMAX; i++) {
	bustina[i]=0;
      }
      packet(bustina,NPMIN,NPMAX,N);
      npa++;
      update(paolo, NPMAX, bustina);
    }
    if (check(pietro, N)==0) {
      for (i=0; i<NPMAX; i++) {
	bustina[i]=0;
      }
      packet(bustina,NPMIN,NPMAX,N);
      npi++;
      update(pietro, NPMAX, bustina);
    }
    if (scelta==1 && check(paolo, N)==0 && check(pietro, N)==0) {
      exchange(paolo, pietro, N);
    }
  } while (check(paolo, N)==0 || check(pietro, N)==0);
  
  for (i=0; i<N; i++) {
    doppa+=paolo[i]-1;
    doppi+=pietro[i]-1;
  }
  printf ("Pacchetti comprati da Paolo: %d\n", npa);
  printf ("Pacchetti comprati da Pietro: %d\n", npi);
  printf ("Costo totale per competare gli album (costo di un pacchetto=%.1f$): %.1f$\n", COSTO, (npa+npi)*COSTO);
  printf ("Doppioni rimasti a Paolo: %d\n", doppa);
  printf ("Doppioni rimasti a Pietro: %d\n", doppi);

  exit(0);
}


int getInt(int a, int b) {
  return ((lrand48()%(b-a+1))+a);
}

void packet(int bustina[NPMAX], int npmin, int npmax, int N) {
  int np, i, j, r;
  
  np=getInt(npmin,npmax);
  for (i=0; i<np; i++) {
    do {
      r=0;
      bustina[i]=getInt(1,N);
      for (j=0; j<i; j++) {
	if (bustina[j]==bustina[i]) r++;
      }
    } while (r!=0);
  }
}

void update(int A[NMAX], int npmax, int bustina[NPMAX]) {
  int i;

  
  for (i=0; i<npmax; i++) {
    if (bustina[i]!=0) {
      A[bustina[i]-1]++;
    }
  }
}

void exchange(int A[NMAX], int B[NMAX], int N) {
  int i;
  
  for (i=0; i<N; i++) {
    if (A[i]>=2 && B[i]==0) {
      A[i]--;
      B[i]++;
    }
    if (B[i]>=2 && A[i]==0) {
      B[i]--;
      A[i]++;
    }
  }
}

int check(int A[NMAX], int N) {
  int i;
  
  for (i=0; i<N; i++) {
    if (A[i]==0) return 0;
  }
  return 1;
}
