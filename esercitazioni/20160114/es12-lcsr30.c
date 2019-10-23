#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define FMAX 7
#define FMIN 4
#define AMAX 220
#define AMIN 180




void packet (int[], int);

void update (int[], int[], int);

void exchange (int[], int[], int);

int check (int[], int);

int calcdop (int[], int);




int main() {

  srand48(time(0));

  int n, s, paolo[AMAX] = {0}, pietro[AMAX] = {0}, pack[FMAX] = {0}, pie = 0, pal = 0, a = 0, b = 0;






  printf ("Calcolatore di paccheti necessari per completare due album figurine.\n");                                      /*punto 1-2*/

  do {

    printf("Inserire numero figurine contenute dal album (%d<=N<=%d)\nN:", AMIN, AMAX);
    
    scanf("%d",&n); 
    
    if (n < AMIN || n > AMAX) {

      printf ("Errore! Numero non valido! Ripetere.\n");
    }
  } while (n < AMIN || n > AMAX);

 

 do{                                                                                                                     /*punto 3*/
 
    printf("Inserire 0 se sono permessi scambi tra figurine doppioni,\ninserire 1 se non sono permessi.\n Scambi:");

    scanf("%d",&s);

    if (s != 0 && s != 1) {

      printf ("Errore! Numero non accettabile! Ripetere.\n");

    }

  } while (s != 0 && s != 1);



 do {                                                                                                                    /*Azioni pro colmpletamento album*/

   if (a == 0) {                                                                                   /*all pietro*/

     packet(pack, n);

     update(pietro, pack, n);

     pie++;

   }

   if (b == 0) {                                                                                   /*all paolo*/

     packet(pack, n);

     update(paolo, pack, n);

     pal++;

   }

   if (s == 0) {

     exchange(pietro, paolo, n);

   }

   if (a == 0) {

     a = check(pietro, n);

   }

   if (b == 0) {

     b = check(paolo, n);

   }

 } while (a == 0 || b == 0);                                                                                           /*punto 4f*/


 a = calcdop(pietro, n);

 b = calcdop(paolo, n);

 s = pie + pal;



 printf("RISULTATI:\n==========\nPacchetti comprati Pietro: %d\nPacchetti comprati Paolo: %d\nDoppioni rimasti Pietro: %d\nDoppioni rimasti Paolo: %d\nSpesa totale: %d Euro\n", pie, pal, a, b, s);   




 















}



void packet (int pack[FMAX], int n) {                                                           /*punto 4b generatore di pacchetti*/

  int e, i, j;

 
  for(i=0;i<FMAX;i++) {

    pack[i] = 0;

  }


  e = (lrand48()%(FMAX - FMIN + 1) + FMIN)-1;

  for(i=0;i<e;i++) {

    pack[i] = lrand48()%n + 1;

    for(j=0;j<e;j++) {

      if ( pack[i] == pack[j] && i != j) {

	i--;

      }

    }
    printf("SHR: pack[%d]: %d\t", i, pack[i]);

  }
  printf("\n");
 
}



void update (int array[AMAX], int pack[FMAX], int n) {                                                     /*punto 4c aggiornamento album*/

  int i;

  for(i=0;i<FMAX;i++) {

    if(pack[i] != 0) {
     
      //	array[pack[i]]++:

      /* SHR: corretto l'errore per compilare */
      array[pack[i]]++;

    }

  }

}



void exchange (int pietro[AMAX], int paolo[AMAX], int n) {                                                 /*punto 4d scambio doppioni*/

  int i, j;

for(i=0;i<n;i++) {

  if (paolo[i] > 1 && pietro[i] == 0) {

    for(j=0;j<n;j++) {

      if (pietro[j] > 1 && paolo[j] == 0) {

	paolo[i]--;

	pietro[i]++;

	pietro[j]--;

	paolo[j]++;

      }

    }

  }

 }

}



int check (int array[AMAX], int n) {                                                                        /*punto 4e controllo album*/

  int i, c, s = 0;

  for(i=0;i<n;i++) {

    if (array[i] > 0) {

      s++;

    }

  }

  if (s == n) {

    c = 1;

  } else {

    c = 0;

  }

  return c;

}



int calcdop (int array[AMAX], int n) {

  int i, s = 0;

  for (i=0;i<n;i++) {

    s += array[i];

  }

  s -= n;

  return s;

}


	   




	





