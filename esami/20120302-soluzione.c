#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NFMAX 20

/* ci saranno al massimo (500-100)/15 esperimenti */
#define LEN 30

double casuale(double, double);
void analisi(double* frac, int nf, int* min, int* max);
void stampa(char*, int*, int*, int);

int main() {

  int Np, Nf,  min[LEN]={0.}, max[LEN]={0.};
  double frazione[NFMAX+1]={0.};
  char  name[100];
  int  i, j, imin, imax, nexp;
  double pos;
  int  cella;

  srand48(time(0));

  /* chiedi Nf <= 20 */
  do{
    printf("inserire numero di file <= %d: ", NFMAX);
    scanf("%d", &Nf);

  } while(Nf<=0 || Nf>NFMAX) ;


  /* chiedi nome file */
  printf("inserire nome del file senza spazi: ");
  scanf("%s", name);

  /* messaggio per l'utente */
  printf("avete inserito Nf= %d e nome = %s\n", Nf, name);


  /* contatore esperimento */
  nexp = 0;

  /* varia numero di palline */
  for(Np=100; Np<=500; Np+=15) {

     /*azzera frazioni */
     for(i=0; i<Nf+1; i++) {
       frazione[i] = 0.;
     }

     /* simula le palline */
     for(i=0; i<Np; i++) {

         /* scelta arbitraria della posizione iniziale */
         pos = 0.;

        /* deve scendere Nf file di chiodi */
        for(j=1; j<=Nf; j++) {
          if(casuale(0.,1.)>0.5) pos += 0.5;
          else                   pos -= 0.5;
        }

        /* calcola l'indice della cella */
        cella = (Nf/2.) + pos;

        /* determinare la cella in cui finisce la pallina */
        printf("pos:%1.1f \t cella: %d\n", pos, cella);

        /* aumenta frazione palline in questa cella */
        frazione[cella] += 1./Np;
     }

     /* chiama analisi per calcolo cella con frazione min e max */
     analisi(frazione, Nf, &imin, &imax);

     /* immagazzina in array */
     min[nexp] = imin;
     max[nexp] = imax;

     /* aumenta contatore esperimenti */
     nexp++;
  }

  /* stampa valori min e max sul file */
  stampa(name, min, max, nexp-1);

  return 0;
}

double casuale(double a, double b) {
  return a+(b-a)*lrand48()/RAND_MAX;
}

void analisi(double* frac, int nf, int* min, int* max) {

  int i;

  /* indice iniziale delle celle con la frazione minima e massima */
  *min = 0;
  *max = 0;

  /* ciclo sugli elementi per trovare le celle min e max */
  for(i=1; i<=nf;i++) {
    if(frac[i] < frac[*min])  *min = i;
    if(frac[i] > frac[*max])  *max = i;  
  }

  /* fine delle funzione */

}


void stampa(char* nome, int* min, int*max, int nexp) {

  int i;
  FILE* fout;

  /* apri il file con il nome passato dall'utente */
  fout = fopen(nome, "w+");
  if(fout==NULL) {
    printf("non posso aprire file con il nome %s ... exit\n", nome);
    exit(-1);
  }

  /* ciclo sugli elementi degli array e stampa sul file */
  for(i=0; i<nexp; i++) {
   fprintf(fout, "palline: %d  cella min: %d  cella max: %d\n",
                 100+i*15, min[i], max[i] ); 

  }

  /* chiusura file */
  fclose(fout);
}

