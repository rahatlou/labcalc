#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 220
#define MIN 180
#define NUM 7

void packet(int *, int);
int casuale(int, int);
void update(int*, int*, int);
void exchange (int*,int*, int);
int check(int*, int);
int contadoppioni(int*, int);

int main() {
  int a=0, b=0, N, risp, A=0, B=0,  paolo[MAX]={0}, pietro[MAX]={0}, pacchetto[7];
  srand48(time(0));
  printf("il programma stima il numero di pacchetti per completare due album\n");
  printf("inserisci il numero di figurine per ciascun album tra %d e %d\n", MIN, MAX);
  do {
    scanf("%d", &N);
    if(N<MIN || N>MAX) {
      printf("valore errato, ritenta\n");
    }
  } while (N<MIN || N>MAX);
 printf("vuoi che i bambini possano scambiarsi le figurine?\n scrivi 1 per no e 2 per si\n");
  do {
    scanf("%d", &risp);
    if(risp!=1 && risp!=2) {
      printf("valore errato, ritenta\n");
    }
  } while (risp!=1 && risp!=2);
  do {
    if( A==0) {
    packet(pacchetto, N);
    update(paolo, pacchetto, N);
    a++;
    }
    if( B==0) {
    packet(pacchetto, N);
    update(pietro, pacchetto, N);
    b++;
    }
    A=check(paolo, N);
    B=check(pietro, N);
    if (risp==2 && A==0 && B==0 ) {
      exchange(paolo, pietro, N);
    }
    A=check(paolo, N);
    B=check(pietro, N);
  } while(A==0 || B==0 ) ;

  printf("paolo ha comprato %d pacchetti con %d doppioni\n pietro invece ne ha comprati %d ed ha %d doppioni\n in totale  i due hanno comprato %d pacchetti\n", a, contadoppioni(paolo,N), b, contadoppioni(pietro, b), a+b );

  exit(0);
}

int casuale(int a, int b) {
  return a+lrand48()%(b-a+1);
}

void packet(int* pac, int N) {
  int i, j, s, n=casuale(4,7);
  for(i=0; i<NUM; i++) {
    pac[i]=0;
  }
  for (i=0; i<n; i++) {
    do{
      s=0;
    pac[i]=casuale(1, N);
    for(j=0;j<i;j++){
      if(pac[j]==pac[i]){
	s++;
      }
    }
    } while(s!=0);
  }
    
}

void update(int* album, int* pac, int N) {
  int i, j;
  for (i=0; i<N; i++) {
    for (j=0; j<NUM; j++) {
      if( i==pac[j]-1) {
	album[i]++ ;
      }
    }
  }
}

void exchange (int* paolo ,int* pietro, int N) {
  int i, j, s;
  for (i=0; i<N; i++) {
    if (paolo[i]>1 && pietro[i]==0) {
      j=0;
      s=0;
      do {
	if (pietro[j]>1 && paolo[j]==0) { 
	  paolo[i]--;
	  paolo[j]++;
	  pietro[j]--;
	  pietro[i]++;
	  s++;
	} 
	j++; 
      } while (s==0 && j<N) ;
    }
  }
}

int check(int* album, int N) {
  int i, s=0;
  for (i=0; i<N; i++) {
    if (album[i]==0) {
      s++;
    }
  }
  if (s>0) {
    return 0;
  }
  else {
    return 1;
  }
}

int contadoppioni(int* album, int N) {
  int i, s=0;
  for (i=0; i<N ; i++) {
    if (album[i]>1) {
      s+=album[i]-1;
    }
  }
  return s;
}
