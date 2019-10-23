#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


#define Nmin 180
#define Nmax 220
#define fig 7
#define mfig 4


int getInt(char*, int, int);
void packet(int, int, int, int[]);
void update(int[], int[]);
int main() { 

  srand48(time(0));
  printf("questo programma stima il numero di pacchettti di figurine che due bambini devono comprare per completare i loro album\n");
 
  int n,  t, f;
  n = getInt("numero di figurine in ogni album", Nmin, Nmax);
  int s;

  do {
  printf("i due bambini possono scambiarsi i doppioni? se si premi 1, altrimenti premi 2\n");
  scanf("%d",&s);

  if( ! (s==1 || s==2) )  printf("scelta non valida\n");

  } while( ! (s==1 || s==2));

  int paolo[Nmax]={0};
  printf("ciao1\n");
  int  pietro[Nmax]={0}; int pack[fig];
  int kpaolo = 0; int kpietro =0;
  int i=0, p1=1, p2=1;
  printf("ciao2\n");

  if (s=2){ 
    printf("ciao1\n");


    do {
      for(t=0; t< fig; t++){
	pack[t] = 0;}
printf("ciao2\n");

      packet(mfig, fig, n, pack);
printf("ciao3\n");

      update(paolo, pack);
      printf("ciao4\n");

      for(i=0; i< n ; i++){ 
	p1 = p1 * paolo[i];
      }
      printf(" prodotto: %d\n", p1);
      kpaolo++;
    }while(p1 = 0);

    printf("pacchetti paolo: %d\n", kpaolo);


 do {
   for(f=0; f< fig; f++){
	pack[f] = 0;}

      packet(mfig, fig, n, pack);
      update(pietro, pack);
      
      for(i=0; i< n ; i++){ 
	p2 = p2 * pietro[i];
      }
      kpietro++;
    }while(p2 = 0);

 printf(" pacchetti di paolo: %d    pacchetti di pietro: %d \n", kpaolo, kpietro);

  }



}



int getInt(char* msg, int min, int max){

  int x;

  do{ printf("inserisci %s compreso tra (%d, %d): ", msg, min, max);
    scanf("%d", &x);
    if((x <= min) || (x>= max)) { 
      printf("valore non valido\n");}

  } while ((x <= min) || (x>= max));

  return x;
}


void packet( int min, int max, int  num, int pa[]){
  int p,i;
  
  p=(( lrand48())%(max-min+1)) +min; 

  pa[0]= lrand48()%(num) +1;

  for(i=1;i<p;i++) {
    do{
      pa[i]= lrand48()%(num) + 1;
    }while (pa[i]=pa[i--]);
  }
}

void update (int album[], int pa[]){

  int i=0, j;
  for(i=0; i<fig; i++){
    j = pa[i];
    album[j]++;
	  };
  }
