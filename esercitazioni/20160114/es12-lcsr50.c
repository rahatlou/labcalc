#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FMIN 180
#define FMAX 220
#define NFMIN 4
#define NFMAX 7


int casuale(int, int);
void packet(int*, int);
void update(int*, int*, int);
int check(int*, int);
void exchange(int*, int*, int);


int main () {

  srand48(time(0));

  int i, Nfig, decisione, pietrofin, paolofin,  Npack1 = 0, Npack2 = 0, doppioni1 = 0, doppioni2 = 0;
  int paolo[FMAX] = {0};
  int pietro[FMAX] = {0};
  int pacchetto[NFMAX] = {0};

  printf("Questo programma simula lo scambio di figurine tra due bambini!\n");

  do {

    printf("Inserire numero figurine contenute nell'album [%d, %d]:\n", FMIN, FMAX);
    scanf("%d", &Nfig);

    if (Nfig < FMIN || Nfig > FMAX) printf("ERRORE!!!\n");

  } while (Nfig < FMIN || Nfig > FMAX);

  do {

    printf("Possono scambiarsi le figurine? (1 = SI; 0 = NO):\n");
    scanf("%d", &decisione);

    if (decisione != 0 && decisione != 1) printf("ERRORE!!!\n");

  } while (decisione != 0 && decisione != 1);
  
  paolofin = pietrofin = 0;

  do {

    if (paolofin == 0) {

      Npack1 ++;
      packet(pacchetto, Nfig);
      update(paolo, pacchetto, NFMAX);
      paolofin = check(paolo, Nfig);
      
    }

    if (pietrofin == 0) {

      Npack2 ++;
      packet(pacchetto, Nfig);
      update(pietro, pacchetto, NFMAX);
      pietrofin = check(pietro, Nfig);

    }

    if (decisione == 1 && pietrofin == 0 && paolofin == 0) exchange(paolo, pietro, Nfig);

  } while (paolofin == 0 || pietrofin == 0);

  for (i = 1; i <= Nfig; i++) {

    if (paolo[i] > 1) doppioni1 ++;
    if (pietro[i] > 1) doppioni2 ++;

  }
      
  printf("Paolo compra %d pacchetti e gli restano %d doppioni\n", Npack1, doppioni1);
  printf("Pietro compra %d pacchetti e gli restano %d doppioni\n", Npack2, doppioni2);

  exit(0);

}


int casuale(int a, int b) {

  return lrand48()%(b-a+1)+a;

}


void packet(int pacchetto[NFMAX], int N) {

  int n;
  int i, j;

  for (i = 0; i < NFMAX ; i++) {

    pacchetto[i] = 0;

  }

  n = casuale(NFMIN, NFMAX);

    for (i = 0; i < n; i++) {

      cost = 0;
     
      pacchetto[i] = casuale(1, N);
	
      do {

	if (i >= 1) {
	  
	  for (j = 0; j < i; j++) {
	    
	    if (pacchetto[i] == pacchetto[j]) cost++;
	    
	  }
	  
	}
	
      } while (cost > 0);
      
    }

}


void update(int alb[FMAX], int pack[NFMAX], int np) {

  int j, figurina;

    for (j = 0; j < np; j++) {

      figurina = pack[j];

      alb[figurina] ++;
 
    }

}


int check(int alb[FMAX], int n) {

  int i;

  for (i = 1; i <= n; i++) {
   
    if (alb[i] == 0)  return 0;

  }

  return 1;

}


void exchange(int alb1[FMAX], int alb2[FMAX], int n) {

  int i;

  for (i = 1; i <= n; i++) {
    
    if (alb1[i] > 1 && alb2[i] == 0) {

      alb1[i] --;
      alb2[i] ++;

    }

    if (alb2[i] > 1 && alb1[i] == 0) {

      alb2[i] --;
      alb1[i] ++;

    }

  }

}
