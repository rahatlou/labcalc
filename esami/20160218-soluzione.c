#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define NG 2

int genera(int,int);
int vincente(int*,int*);
void aggiorna(int,int*,int*);

int main() {

  int posta=0;
  int turni=0;
  int tasca[NG]={10.,10.};
  int mano[NG];
  int voce[NG];
  int vince;
  int i;

  srand48(time(0));

  while( tasca[0]>0 && tasca[1]>0 ) {

    turni++;
    
    for(i=0;i<2;i++) {
      tasca[i]--;
      posta++;

      mano[i] = genera(1,5);
      voce[i] = genera(mano[i]+1,mano[i]+5);
    }
    
    vince = vincente(mano,voce);
    aggiorna(vince, &posta, tasca); 

    if(turni%2==0) printf("turno: %d\t posta: %d\t gioc. 1: %d\t gioc. 2: %d\n",
			  turni, posta, tasca[0], tasca[1]);
    
  } // turni

  if(tasca[0]==0 && tasca[1]==0) {
    printf("pareggio dopo %d turni. ciascuno prende %d euro\n",
	   turni, posta/2);
  } else {

    vince = 0;
    if(tasca[1]>tasca[0]) vince = 1;

    printf("Vince giocatore %d dopo %d turni\n", vince+1, turni);

  }
 
}

int genera(int a, int b) {
  return a+lrand48()%(b-a+1);
}

int vincente(int* mano,int* voce) {
  int OK[NG];
  OK[0] = (voce[0] == mano[0]+mano[1]);
  OK[1] = (voce[1] == mano[0]+mano[1]);

  //printf("G1: %d  %d \t G2: %d  %d\n", mano[0],voce[0], mano[1], voce[1] );
  
  if( OK[0] && OK[1] ) return 0;
  else if( OK[0] ) return 1;
  else if( OK[1] ) return 2;
  else return -1;
}

void aggiorna(int vincente, int* posta, int* tasca) {

  if(vincente<0) {
    return;
  } else if(vincente==0) {
    tasca[0] += *posta/2;
    tasca[1] += *posta/2;
  }else {
    tasca[vincente-1] += *posta;
  }
  *posta = 0;

  return;
}

