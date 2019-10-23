#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NMAX 220
#define NMIN 180
#define FIGMIN 4
#define FIGMAX 7



int generaint(int , int );
int packet(int *, int, int, int);
void update(int *, int *, int , int  ); 
void exchange(int *, int*, int );
int  check(int *, int);
int contadoppioni(int *, int);

int main(){

  int NFIG, scambi, k, v, completopaolo, completopietro, packpaolo, packpietro, i, doppionipaolo, doppionipietro;
  int paolo[NMAX], pietro[NMAX], pacchetto[FIGMAX];

 
 srand48(time(0));

  printf("Questo programma stima il numero di pacchetti che servono per completare un album\n");

  do{
    printf("Inserire numero di figurine tra [%d, %d]\n", NMIN, NMAX);
    scanf("%d", &NFIG);
    if(NFIG < NMIN || NFIG > NMAX){
      printf("Valore non valido, reinserire\n");
    }
  }while(NFIG < NMIN || NFIG > NMAX);

  do{
    printf("Se si possono fare scambi inserire 1, altrimenti inserire 0\n");
    scanf("%d", &scambi);
    if(scambi != 0 && scambi !=1){
      printf("Valore non valido, reinserire\n");
    }
  }while(scambi != 0 && scambi != 1);

  for(i=0; i<NFIG; i++){
    pietro[i] = 0;
    paolo[i] = 0;
  }

  completopaolo =0;
  completopietro =0;
  packpaolo = 0;
  packpietro = 0;

  do{

    if(completopaolo == 0){
      v = packet(pacchetto, FIGMIN, FIGMAX, NFIG);
      update(paolo, pacchetto, NFIG, v);
      packpaolo++;
    }

    if(completopietro == 0){
      k = packet(pacchetto, FIGMIN, FIGMAX, NFIG);
      update(pietro, pacchetto, NFIG, k);
      packpietro++;
    }

    if(scambi ==1 && completopaolo == 0 && completopietro == 0){
      exchange(paolo, pietro, NFIG);
    }

    completopaolo = check(paolo, NFIG);
    completopietro = check(pietro, NFIG);

  } while(completopaolo == 0 || completopietro == 0);

  doppionipaolo = contadoppioni(paolo, NFIG);
  doppionipietro = contadoppioni(pietro, NFIG);





    printf("Pacchetti comprati da ciascun bambino: paolo %d \t pietro %d\n", packpaolo, packpietro);
    printf("Numero di  doppioni Paolo %d \t Pietro %d\n", doppionipaolo, doppionipietro);

    return 0;
  

}




 




int generaint(int a, int b){
  int m;

  m = lrand48()%(b-a+1)+a;

  return m;
  }

int packet(int pacco[FIGMAX], int fmin, int fmax, int nfig){

  int n, i, doppione,j;

  n = generaint(fmin, fmax);

  /*printf("n vale %d\n",n);*/

  do{
    doppione  = 0;

  for(i=0; i<n; i++){

    pacco[i] = generaint(0, nfig-1);
   
    for(j=0; j<i; j++){
      if(pacco[j] == pacco[i]){
	doppione ++;
      }
    }
  }
  }while(doppione != 0);
  

  /* for(i=0; i<n; i++){
    
    printf("la figurina %d e %d\n", i, pacco[i]);
    }*/

  return n;
}

void update(int bimbo[NMAX], int pack[FIGMAX], int nfig, int npack){

  int k, temp;

  for(k=0; k<npack; k++){

    temp = pack[k];
    bimbo[temp]++;

  }

  /* for(k=0; k<nfig; k++){

   
 printf("bimbo[%d] e %d\n", k, bimbo[k]);

 } */
}

void exchange(int bimbo1[NMAX], int bimbo2[NMAX], int nfig){

  int t;

  for(t=0; t<nfig; t++){

    if(bimbo1[t] >=2 && bimbo2[t] == 0){
      bimbo1[t]--;
      bimbo2[t]++;
    }

    if(bimbo2[t] >=2 && bimbo1[t] == 0){
      bimbo2[t]--;
      bimbo1[t]++;
    }
  }
}

int check(int bambino[NMAX], int nfig){

  int i;

  for(i=0; i<nfig; i++){
    if(bambino[i]==0){
      return 0;
    }
  }

 return 1;
} 

int contadoppioni(int bimbo[NMAX], int nfig){

  int i, doppio, temp;

  doppio=0;

  for(i=0; i<nfig; i++){
    temp =0;

    if(bimbo[i] >= 2){
      temp = bimbo[i] - 1;
    }

    doppio += temp;
  }

  return doppio;
} 

  




