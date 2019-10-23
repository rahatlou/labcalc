#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAXFIG 220
#define PACK 7

int dado(int);
float uniforme(float, float);
int packet(int, int bustina[]);
void update(int bustina[], int bimbo[], int);
void exchange(int paolo[], int pietro[], int);
int check(int bimbo[], int);




int main(){

  int nf, ipotesi,paolo[MAXFIG],pietro[MAXFIG], bustina[PACK],albumpi, albumpa, imax, packpi=0, packpa=0, prezzopi, prezzopa, doppionepa=0, doppionepi=0, i;

  srand48(time(0));
  printf("Il programma simula quanti pacchetti due bambini devono comprare per completare un album di figurine.\n");
  do{
    printf("Quante figurine ci sono nell'album? Il numero deve essere tra 180 e 220\n");
    scanf("%d",&nf); 
    if(nf<180 || nf>220){
      printf("ERRORE! Il numero deve essere tra 180 e 220\n");
    }
  }while(nf<180 || nf>220);
  do{
    printf("Gli utenti possono scambiarsi i doppioni? inserire 1 se si o 0 se no:\n");
    scanf("%d",&ipotesi);
    if(ipotesi!=1 && ipotesi!=0){
      printf("ERRORE! Inserire 1 se si o 0 se no");
    }
  }while(ipotesi!=1 && ipotesi!=0);

  do{
    albumpi=check(pietro, nf);
    albumpa=check(paolo,nf);

    if(albumpa==0){
      imax=packet(nf, bustina);
      packpa++;
      update(bustina, paolo, imax);
    }
   
    if(albumpi==0){
      imax=packet(nf,bustina);
      packpi++;
      update(bustina,pietro, imax);
    }
 if(ipotesi==1 && albumpa==0 && albumpi==0){
      exchange(paolo, pietro, nf);
    }
  }while(albumpi!=1 || albumpa!=1);
  prezzopi=packpi*1;
  prezzopa=packpa*1;
  printf("Numero di pacchetti\n Paolo:%d \t Pietro:%d\n", packpa, packpi);
  printf("Spesa\n Paolo:%d \t Pietro:%d\n", prezzopa, prezzopi);

  for(i=0;i<nf;i++){
    if(pietro[i]>1){
      doppionepi++;
    }
    if(paolo[i]>1){
      doppionepa++;
    }
  }

  printf("Doppioni \n Paolo:%d \t Pietro:%d", doppionepa, doppionepi);

  exit(0);


}



int dado(int a){
  int x;
  x=lrand48()%a;
  return (x);
}


float uniforme(float a,float b){
  float x;
  x=((float)lrand48()/RAND_MAX)*(b-a)+a;
  return (x);
}

int packet(int nf, int bustina[]){
  int a=4, b=7, i, x, doppia, j, imax;
  imax=uniforme(a, b);
  for(i=0; i<imax; i++){
    do{
      x=dado(nf);
      bustina[i]=x;
      for(j=0;j<i;j++){
	if(bustina[i]==bustina[j]){
	  doppia=1;
	}else{
	  doppia=0;
	}
      }
    }while(doppia==1);
	 
  }
  return (imax);
  
}

void update(int bustina[], int bimbo[], int imax){
  int i;   
  for(i=0; i<imax; i++){
    bimbo[bustina[i]]++;
  }
}

void exchange(int paolo[], int pietro[], int a){
  int i, j;

  for(i=0;i<a;i++){
    for(j=0;j<a;j++){
      if(paolo[i]>1 && pietro[i]==0 && paolo[j]==0 && pietro[j]>1){
	paolo[i]--;
	pietro[i]++;
	paolo[j]++;
	pietro[j]--;
      }
    }
  }
}

int check(int bimbo[], int a){
  int i;
  for(i=0;i<a;i++){
      
    if(bimbo[i]==0){
      return (0);
    }
   }
  return(1);
}
