#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define FMIN 180
#define FMAX 220
#define PMIN 4
#define PMAX 7
#define COS 1

void packet(int*, int, int*);
void update(int*, int*, int);
int check(int*, int);
void exchange(int*, int*, int);

int main (){ 

  srand48(time(0));

  int Nf, scelta, n,i, packpietro=0, packpao=0, dpietro=0, dpaolo=0;
  int paolo[FMAX] = {0};
  int pietro[FMAX] = {0};
  int figurine[PMAX];

  printf("Il programma simula il completamento di un album di figurine di due  bambini\n");

  do{
    printf("Inserire il numero di figurine nell'intervallo [%d,%d]\n", FMIN, FMAX);
    scanf("%d", &Nf);
  } while ( Nf < FMIN || Nf > FMAX);
 
  do{
    printf("Inserire 1 se bambini scambiano, 0 se no\n");
    scanf("%d", &scelta);
  } while ( scelta != 0 && scelta !=1 );


  do{

    if(check(paolo,Nf) == 0){
      packet(figurine,Nf,&n);
      update(paolo, figurine,n);
      packpao++;
    }
 
    if(check(pietro,Nf) == 0){
      packet(figurine,Nf,&n);
      update(pietro,figurine,n);
      packpietro++;
    }

    if(scelta && check(paolo,Nf) == 0 && check(pietro,Nf)==0 ){
      exchange(paolo, pietro, Nf);
    }


  }while(check(paolo,Nf) == 0 || check(pietro,Nf) == 0);

  for(i=0;i<Nf;i++){
    dpaolo+= *(paolo+i);
    dpietro+= *(pietro+i);
  }

  dpaolo -= Nf;
  dpietro -= Nf;

  printf("Paolo ha comprato %d pacchetti, spende %d euro ed ha %d doppioni rimanenti\n", packpao,packpao*COS, dpaolo);
  printf("Pietro ha comprato %d pacchetti, spende %d euro ed ha %d doppioni rimanenti\n", packpietro,packpietro*COS, dpietro);


  return 0;
}


void packet(int* array, int Nf, int *n){

  int i,j;
 
 *n = PMIN + lrand48()%(PMAX-PMIN+1);

  for(i=0;i<*n;i++){
    
    *(array+i) = lrand48()%Nf;
    for(j=0;j<i;j++){
      if(*(array+i) == *(array+j)){
	j=i;
	i--;
      }
    }
  }
 }

void update(int* ragazzo, int* array, int n){
  int i;
  for(i=0;i<n;i++){
    (*(ragazzo+ *(array+i)))++;
  }
}

void exchange(int* paolo, int* pietro, int Nf){
  int i,k, cond;

  for(i=0 ; i<Nf ; i++){
    
    if ( *(paolo+i)>1 && *(pietro+i)==0){

      cond=1;

      for( k=0; k<Nf && cond;k++){

	if( *(pietro+k)>1 && *(paolo+k)==0){
	    (*(pietro+i))++;
	    (*(paolo+i))--;
	    (*(pietro+k))--;
	    (*(paolo+k))++;
	    cond=0;
	  }
      }
    }
  }
}
	
      

int check(int* array, int len){
  int i=0, cond = 1;
  for(i=0;i<len;i++){
    if(*(array+i) == 0){
      cond = 0;
      i=len;
    }
  }
   return cond;
}
    
  
