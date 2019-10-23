#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* 1 pt: definizone funzione */
double FromInput(double xmin, double xmax, char* varname);

/* 1 pt: definizone funzione */
double generaGauss ( double mi, double sigma);// genera secondo una distribuzione gaussiana

double generaNorm();// genera secondo una distribuzione normale (mu=0, sig=1)

/* 1 pt: definizone funzione */
double randReal(double min,double max);

int tiro(double mu,double sigma, double P);// valutazione successo calcio di rigore

int main(){
  /* 1 pt: inzializzare il seme casuale*/
  srand48(time(0));

  printf("questo programma simula una sfida a calci di rigore\n");

  /* 1 pt: inizializzazione corretta delle variabili */
  double mu1=0.8,P1=0.7,mu2=0.8,P2=0.7;
  int Ngoal1=0, Ngoal2=0,Ntiri=0;

  double sigma1=FromInput(0.05*mu1,0.2*mu1,"sigma1");
  double sigma2=FromInput(0.05*mu2,0.2*mu2,"sigma2");

  /* 2 pt: ciclo giusto */
  do{
    Ntiri++;
    int goal=0;
    printf("tiro %d ", Ntiri);

    /* 1 pt: contatori per le due squadre */
    if(Ntiri%2 == 1){  // squadra 1
      printf("squadra 1: ");
      goal=tiro(mu1,sigma1,P2);
      if(goal)Ngoal1++;
      
    } else { // squadra 2
      printf("squadra 2: ");
      goal=tiro(mu2,sigma2,P1);
      if(goal)	Ngoal2++;
    }
    
    if(goal){
      printf("Goal!\n");
    } else {
      printf("Niente da fare!\n");
    }
 
    printf("Punteggio: %d -- %d!\n",Ngoal1, Ngoal2);
    /* 1 pt: stampa esito tiro e aggiornamento punteggio */ 

    
  } while ( !(Ntiri==10 && Ngoal2!=Ngoal1) &&  !(Ntiri>10 && fabs(Ngoal2-Ngoal1)>1) ); 
  /* 3 pt: prima condizione dopo 10 tiri
     3 pt: seconda condizione per tiri ad oltranza
  */ 
  

  /* 1 pt: stampa risultato */
  if(Ngoal1>Ngoal2){
    printf("HA VINTO LA SQUADRA 1!!!\n");
  } else {
    printf("HA VINTO LA SQUADRA 2!!!\n");
  }
}


/* 3 pt: calcolo corretto variabile normale */
double generaNorm(){
  double sum=0;
  int i;
  for(i=0; i<12; i++){
    sum+= randReal(-0.5,0.5);
  }
  return sum;
}

/* 2 pt: calcolo gaussiana */
double generaGauss( double mi, double sigma){
  return mi+sigma*generaNorm();
}

/* 3 pt: acqusizione con condizioni corrette per la ripetizione */
double FromInput(double xmin, double xmax, char* varname){//funzione di controllo dei valori in input
  double res; 
  printf("inserisci valore di %s tra %lf e %lf\n",varname, xmin, xmax);
  scanf ("%lf",&res);
  while(res<=xmin || res>xmax){
    printf ("No! %s deve essere maggiore di %lf e minore  di %lf\n", varname, xmin,xmax);       
    scanf ("%lf", &res);
  }
  return res;
}


/* 2 pt: generazione numeri casuali tra min e max */
double randReal(double min, double max){
  return(min+(max-min))*lrand48()/RAND_MAX;
}

/* 6 pt: simulazione del tiro */
int tiro(double mu,double sigma, double P){
  // 1 == goal! 
  // 0 == sbagliato
  double T=generaGauss(mu,sigma);
  if(randReal(0,1)>T)return 0;
  if(randReal(0,1)<P)return 0;
  return 1;
}
