#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define FMAX 220
#define FMIN 180
#define BMAX 7
#define BMIN 4
void packet(int, int [], int*);
void update(int [], int [], int);
void exchange(int [], int[], int);
int check(int [], int);
int doppioni(int[], int);

int main() {
  
  int i, n, N, C, pack1=0, pack2=0, dop1, dop2, finepaolo = 0, finepietro = 0, pietro[FMAX]={0};
  int paolo[FMAX]={0};
  int bpaolo[BMAX], bpietro[BMAX];
  int *pn;
  pn = &n;
  
  printf("Questo programma stima il numero di pacchetti per completare un album di figurine!\n");
 
  do{
    printf("Inserire il numero di figurine nell'album, compreso tra %d e %d: \n", FMIN, FMAX);
    scanf("%d", &N);
  }while(N<FMIN || N>FMAX);
 
  do{
    printf("Possono scambiarsi i doppioni? 0: No, 1: Si\n");
    scanf("%d", &C);
  }while(C!=0 && C!=1);
   
    do{

      for(i=0;i<BMAX;i++) {
	bpaolo[i] = 0;
	bpietro[i] = 0;
      }
      if(finepaolo==0) { 
	printf("SHR: chiama packet per paolo\n");
	packet(N, bpaolo, &n);
	//update(paolo, paolo, n);
	/* SHR correggo l'errore */
	update(paolo, bpaolo, n);
	pack1++;
      }
      printf("SHR: dopo paolo %d\n",pack1);

      if(finepietro==0) {
	printf("SHR: chiama packet per pietro\n"); 
	packet(N, bpietro, &n);
	update(pietro, bpietro, n);
	pack2++;
      }
      printf("SHR: dopo pietro %d\n", pack2);  
    
    if(C==1 && finepaolo==0 && finepietro==0) {
      exchange(paolo,pietro,N);
    }
    
    finepaolo = check(paolo, N);
    finepietro = check(pietro, N);

    printf("SHR: dopo check nel ciclo  paolo: %d  pietro: %d\n",finepaolo,finepietro);

    }while(finepaolo==0 || finepietro==0);

    printf("SHR: fuori dal ciclo\n");

    dop1 = doppioni(paolo,N);
    dop2 = doppioni(pietro,N);

    printf("Paolo ha comprato %d pacchetti, rimanendo con %d doppioni\n",pack1,dop1);
    printf("Pietro ha comprato %d pacchetti, rimanendo con %d doppioni\n", pack2, dop2);

    exit(0);

}
  
  void packet(int N,int busta[BMAX], int*pn) {

  int i, j, n, f;

  n = lrand48()%(BMAX-BMIN+1)+BMIN;

  for(i=0;i<n;i++) {
    f = lrand48()%(N+1);
      busta[i] = f;
      for(j=0;j<i;j++) {
	if(f==busta[j]) {
	  do{
	    f = lrand48()%(N+1);
	    busta[i] = f;
	  }while(f==busta[j]);
	}
      }
  }
  *pn = n;
  printf("SHR: fine packet\n");
}

 void update(int album[FMAX], int busta[BMAX], int n) {
   
   int i, fig;

   for(i=0;i<n;i++) {
     fig = busta[i];
     album[fig]++;
   }
 }

void exchange(int paolo[FMAX], int pietro[FMAX], int N) {
  
  int i, j, d1, d2, z1=0, z2=0, zmin=FMAX;
  int app1[FMAX]={0};
  int app2[FMAX]={0};

  for(i=0; i<N; i++) {
    if(paolo[i]>1){
      while(pietro[i]==0) {
	app1[z1]=i;
	z1++;
      }
    }
    if(pietro[i]>1){
      while(paolo[i]==0) {
	app2[z2]=i;
	z2++;
      }
    }
  }
 
  if(z2<z1) zmin = z2;
  if(z1<z2) zmin = z1;
  if(z1==z2) zmin = z2;
  if(zmin!=0) {
    for(j=0; j<zmin; j++) {
      d1 = app1[j];
      d2 = app2[j];
      paolo[d1]--;
      paolo[d2]++;
      pietro[d1]++;
      pietro[d2]--;
    }
  }
}
      
int check(int album[FMAX], int N) {
  
  int i, n;

  /* SHR: aggiungo l'azzeramento */
  n = 0;
  printf("SHR: dentro check\n");

  for(i=0; i<N; i++) {
    if(album[i]==0) n=0 ;
  }
  
  if(n!=0) n=1;

  return n;
}

int doppioni(int album[FMAX], int N) {

   int i, somma=0, tot;

   for(i=0; i<N; i++) {
     somma += album[i];
   }

   tot = somma-N;
   return tot;
 }
