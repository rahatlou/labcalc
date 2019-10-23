#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define min 180
#define max 220
#define fmin 4
#define fmax 7 
#define uno 1

int getInt(int, int);
void packet(int, int, int, int, int bustina[]);
void azzera(int data[], int);
void update(int bustina [], int bimbo[], int);
void exchange(int bimbo1[], int bimbo2[], int);
int check(int bimbo[], int);


int main(){
  int N, scelta, pietro[max], paolo[max], bustina[max], x, y, p1=0, p2=0, i, d1=0, d2=0;
  srand48(time(0));

  printf("Il programma calcola quanti pacchetti di figurine servono a Paolo e Pietro per completare i loro album e quanti doppioni gli restano.\n");
  N=getInt(min, max);

  azzera(pietro, N);
  azzera(paolo, N);
  
  do{
    printf("Premere 0 se i bambini si possono scambiare i doppioni, altrimenti premere 1:\n");
    scanf("%d", &scelta);
  }while(scelta!=0 && scelta!=1);
  
  if(scelta==0){

    do{
      x=check(pietro, N);
      y=check(paolo, N);

      if(x==0){
	azzera(bustina, N);
	packet(fmin, fmax, uno, max, bustina);
	update(bustina, pietro, N);
	p1++;
      }
   
      if(y==0){
	azzera(bustina, N);
	packet(fmin, fmax, uno, max, bustina);
	update(bustina, paolo, N);
	p2++;
      }

      if(x==0 && y==0)
	exchange(paolo, pietro, N);
    }while(x==0 || y==0);
  
  }else{
    
    do{
      x=check(pietro, N);
      y=check(paolo, N);

      if(x==0){
	azzera(bustina, N);
	packet(fmin, fmax, uno, max, bustina);
	update(bustina, pietro, N);
	p1++;
      }
   
      if(y==0){
	azzera(bustina, N);
	packet(fmin, fmax, uno, max, bustina);
	update(bustina, paolo, N);
	p2++;
      }
    }while(x==0 || y==0);
  }

  for(i=0;i<N;i++){

    if(pietro[i]>1)
      d1+=pietro[i]-1;

    if(paolo[i]>1)
      d2+=paolo[i]-1;
  }
  
  printf("Pacchetti comprati da Pietro: %d\tDoppioni di Pietro:%d\n", p1, d1);
  printf("Pacchetti comprati da Paolo: %d\tDoppioni di Paolo:%d\n", p2, d2);

  exit(0);
}

int getInt(int a, int b){

  int N;

  do{
    printf("Inserire numero figurine contenuto nell album nell intervallo [%d,%d]:\t", a, b);
    scanf("%d", &N);
    if(N<a || N>b)
      printf("Numero non valido.\n");
  }while(N<a || N>b);
  return N;
}


void packet(int c, int d, int e, int f, int bustina[]){
  int n, i, r;

  n=lrand48()%(d-c+1)+c;

  for(i=0;i<n;i++){
    do{
      r=lrand48()%(f-e+1)+e;
    }while(bustina[r-1]==1);
    bustina[r-1]=1;
  }
}


void azzera(int data[], int n){
  int i;

  for(i=0;i<n;i++)
    data[i]=0;
}


void update(int bustina[], int bimbo[], int l){
  int i;

  for(i=0;i<l;i++)
    bimbo[i]+=bustina[i];
}


void exchange(int bimbo1[], int bimbo2[], int l){
  int i, n=-1, m=-1;

  for(i=0;i<l;i++){
    if(bimbo1[i]>1 && bimbo2[i]==0){
      n=i;
    }else if(bimbo2[i]>1 && bimbo1[i]==0){
      m=i;
    }
  }

  if(n>-1 && m>-1){
    bimbo1[n]--;
    bimbo2[n]++;

    bimbo1[m]++;
    bimbo2[m]--;
  }
}
    
int check(int bimbo[], int l){
  int i, x=1;

  for(i=0;i<l;i++){
    if(bimbo[i]==0)
      x=0;
  }
  return x;
}
