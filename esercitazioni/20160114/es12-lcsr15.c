#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define WORDMAX 200
#define min 180
#define max 220
#define minfig 4
#define maxfig 7
#define costo 1.20

int getInt(char [], int, int);
int uniforme(int, int);
void packet(int, int [], int, int, int*);
void update(int [], int [], int);
int check(int [], int);
void exchange(int [], int[], int);
int doppione(int [], int);
void inizializza(int [], int, int);

int main() {

  srand48(time(0));
  int nfig, scelta;
  int paolo[max], pietro[max], bustina[maxfig];
  int figgen, controllo1, controllo2;
  int packpaolo=0, packpietro=0, doppionipaolo, doppionipietro;
  float spesa1, spesa2;

  printf("Questo simula la raccolta di figurine su un album da parte di due ragazzi.\n");
  
  nfig = getInt("Inserire il numero totale di figurine dell'album compreso tra 180 e 220", min, max);

  scelta = getInt("Se si vuole permettere lo scambio dei doppioni tra i due ragazzi premere 1; in caso contrario premere 0.", 0, 1);

  inizializza(pietro, nfig, 0);
  inizializza(paolo, nfig, 0);
  inizializza(bustina, maxfig, 0);
   
  do {

    if (controllo1 != 1) {

      packet(nfig, bustina, minfig, maxfig, &figgen);
      
      update(paolo, bustina, figgen);
    
      packpaolo++;

    }
   
    if (controllo2 != 1) {
    
      packet(nfig, bustina, minfig, maxfig, &figgen);
      
      update(pietro, bustina, figgen);

      packpietro++;
    
    }

    if ( scelta == 1 && controllo1 != 1 && controllo2 != 1 ) {

      exchange(pietro, paolo, nfig);
      
    }

    controllo1 = check(paolo, nfig);
    
    controllo2 = check(pietro, nfig);

  } while ( controllo1 != 1 || controllo2 != 1); 
    
  doppionipaolo = doppione(paolo, nfig);

  doppionipietro = doppione(pietro, nfig);
  
  spesa1 = packpaolo*costo;

  spesa2 = packpietro*costo;

  printf("Costo pacchetto: 1.20 euro.\nPacchetti comprati da Paolo: %d Costo totale: %.2f\nPacchetti comprati da Pietro: %d Costo totale: %.2f\nNumero doppioni di Paolo: %d\nNumero doppioni di Pietro: %d\n", packpaolo, spesa1, packpietro, spesa2, doppionipaolo, doppionipietro);

  return 0;

}

int getInt(char stringa[WORDMAX], int a, int b) {

  int c;

  do {

    printf("%s\n", stringa);

    scanf("%d", &c);

    if ( c < a || c > b ) printf("Valore non valido.\n");

  } while ( c < a || c > b );

  return c;

}

int uniforme(int a, int b) {

  return a + lrand48()%(b-a);

}

void packet(int nfig, int figurina[maxfig], int a, int b, int *c) {

  int i, k, z=0;

  *c = uniforme(a, b);

  inizializza(figurina, *c, nfig);

  for ( i=0;i<*c;i++) {
    
    do {

      z = 0;

      figurina[i] = uniforme(0, nfig);
    
      for ( k=0;k<*c;k++) {

	if (figurina[i] == figurina[k]) z++;

      }
    
    } while ( z !=  1 );
    
  }

}

int check(int album[max], int a) {

  int i, c=0, l;

  for (i=0;i<a;i++) {

    if ( album[i] != 0 ) c++;

  }

  if ( c == a ) {

    l = 1;

  } else {

    l = 0;

  }

  return l;

}


void update(int album[max], int bustina[maxfig], int k) {

  int i, c;

  for (i=0;i<k;i++) {

    c = bustina[i];

    album[c] += 1;

  }

}

void exchange(int paolo[max], int pietro[max], int n) {

  int i, k;

  for (i=0;i<n;i++) {

    for (k=0;k<n;k++) { 

      if ( ( paolo[i] == 0 && pietro[i] >= 2) && ( pietro[k] == 0 && paolo[k] >=2) ) {

      pietro[i] -= 1;

      paolo[i] += 1;

      paolo[k] -= 1;

      pietro[k] += 1;

      }
  
    }
 
  }

}

int doppione(int album[max], int n) {

  int i, c=0;

  for (i=0;i<n;i++) {

    if (album[i] >= 2) {

      c += album[i] - 1;
      
    }

  }

  return c;

}

void inizializza(int array[max], int n, int k) {

  int i;

  for (i=0;i<n;i++) {

    array[i] = k;

  }

}
