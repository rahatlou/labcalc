#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define Nmin 180
#define Nmax 220
#define Fnew 7
#define cost 2

void packet (int [], int);
void update (int [], int []);
int Random (int, int);
int check (int [], int);

int main() {
  int N, scelta, c, d;
  int paolo[Nmax]={0}, pietro[Nmax]={0}, bustina[Fnew]={0};

  srand48(time(NULL));

  printf("Il programma stima il numero di pacchetti di figurine da comprare per completare l'album\n");
  do {
    printf("Quante figurine possono essere presenti in ogni album? (fra %d e %d):\t", Nmin, Nmax);
    scanf("%d", &N);
    if (N<Nmin || N>Nmax)
      printf("Valore inserito non valido!\n");
  } while (N<Nmin || N>Nmax);
  
  do {
    printf("I bambini possono scambiarsi i doppioni? Premi 1 per 'si' oppure premi 0 per 'no':\t");
    scanf("%d", &scelta);
    if (scelta!=0 && scelta!=1)
      printf("Premere 1 per 'si' o premere 0 per 'no'\n");
  } while (scelta!=0 && scelta!=1);
  c = 0;
  do {
    c++;
    packet(bustina, N);
    update(paolo, bustina);
  } while (!check(paolo, N));
  
  d = 0;
  do {
    d++;
    packet(bustina, N);
    update(pietro, bustina);
  } while (!check(pietro, N));
  
  printf("Paolo ha comprato %d pacchetti e ha speso %d euro\n"
	 "Pietro ha comprato %d pacchetti e ha speso %d euro\n", c, c*cost, d, d*cost);
}
  

int Random (int a, int b) {
  int r;
  r = lrand48()%((b-a)+1);
  r += a;
  return r;
}

void  packet (int card[], int N) {
  int n, i, k, b, cond=0;
  n = Random(4,7);
  N--;
  for (i=0;i<n;i++) {
    do {
      b = Random(0, N);
      for(k=0; k<i; k++) {
	if(b == *(card+k))
	  cond = 1;
	else
	  cond = 0;
      }
    } while (cond);
    *(card+i) = b;
  }
}

void update(int album[], int card[]) {
  int i;
  for (i=0;i<Fnew;i++)
    *(album+(card[i])) += 1;
}

int check (int album[], int N) {
  int i, c=1;
  for (i=0;i<N;i++)
    if (album[i] == 0){
      c = 0;
      break;
    }
  return c;
}
