#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define Nmin 50
#define Nmax 100
#define Nrane  3

void stampa(int* p);
/* 3 pt : interfaccia muovi */
int muovi(int);
void scivola(int*);
void cade(int*);

/* 2 pt : interfaccia sensata di vincitore */
int vincitore(int*);

int main() {

  int N, i;

  int pos[Nrane] = {0};
  int cadute[Nrane] = {0};

  int salti = 0;
  
  srand48(time(0));

  /* 2 pt : acquisizione numero gradini */
  do{
    printf("Inserire il numero gradini compreso tra %d e %d:", Nmin, Nmax);
    scanf("%d", &N);
  } while( N<Nmin || N>Nmax );				     
  

  /* 3 pt : ciclo corretto e condizione per ripetere */
  /* 3 pt :  uso di % per chiamare scivola e caduta e la stampa */ 
  do{
    salti++;

    /* ciclo per spostare ciascuna rana */
    for(i=0; i<Nrane; i++) {
      /* si muove */
      pos[i] = muovi( pos[i]);

      /* scivola ogni 5 salti */
      if(salti%5==0) scivola( pos+i );

      /* cade ogni 7 salti */
      if(salti%13==0) cade( pos+i );

    }
    if(salti%20==0) {
      printf("Numero salti: %-4d \t", salti);
      stampa(pos);
    }

  } while( pos[0] < N && pos[1]<N && pos[2] < N);

  
  /* 1 pt : numero salti corretto
     1 pt : rana vincitrice 
     1 pt : posizione finale delle rane 
  */
  printf("\nNumero finale salti: %d per salire %d gradini\n", salti,N);
  printf("Vincitore e` la rana: %d\n", vincitore(pos) );

  printf("Posizione finale delle rane:\n");
  stampa(pos);


}

/* 3 pt : corretta e sensata generazione numeri casuali */
double uniforme(double a, double b) {
  return a+(b-a)*lrand48()/RAND_MAX;
}


int muovi(int pin) {
  double p = uniforme(0.,1.);
  int pout = pin;

  /* 3 pt : if/else esclusivo */
  /* 2 pt :  calcolo nuova posizione */
  if(p<0.5) {
    pout--;
    if(pout<0) pout = 0;
  }else if(p<0.8) {
    pout++;
  } else {
    pout +=2;
  }

  return pout;

}
 
void scivola(int*pin) {

  /* 2 pt :  scivolo */
  double p = uniforme(0,1);
  if(p<0.2) (*pin) -= 3;
  if( *pin < 0 ) (*pin) = 0;
}


void cade(int*pin) {
  double p = uniforme(0,1);
  if(p<0.02) (*pin)  = 0;
  /* 2 pt :  implementazione caduta */
}

/* 2 pt :  stampa  sullo schermo della posizione */
void stampa(int* pin) {
  int i;
  for(i=0;i<Nrane;i++) {
    printf("Rana %d: %d\t", i+1, *(pin+i));
  }
  printf("\n");
}

int vincitore(int* pin) {

  int j, iv = 0;
  for(j=1; j<Nrane; j++) {
    if( pin[j] > pin[iv]) iv = j;
  }
    
  return iv+1;
}
