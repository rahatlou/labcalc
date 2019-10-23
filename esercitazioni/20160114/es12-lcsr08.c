#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 220
#define LPACK 6 /* da figurina 0 a 7 */
#define COSTO 2 /*variare a seconda del prezzo delle carte*/

int casuale(int, int);

int chiediInt(char*, int, int);

void packet(int *,int, int, int, int *); /*array del pack, n minimo di figurine, n max di figurine (LPACK), numero totale nell'album (LEN), n di carte nel pacchetto */

void update(int *, int, int *, int);

int check(int *, int);

void exchange(int *, int *, int);



int main(){

  srand48( time(0));

  int paolo[LEN] = {0};
  int pietro[LEN] = {0};
  int pack[LPACK] = {0};

  char msg[] = "numero di figurine totali nell'album";
  char domanda[] = "scelta";

  int N, scelta, i, mtemp;


  int paolocheck = 0;
  int pietrocheck = 0;
  int nsoldipaolo = 0;
  int nsoldipietro = 0;
  int doppaolo = 0;
  int doppietro = 0;


  printf("Benvenuti alla simulazione degli album di figurine di pietro e paolo!\n");

  N= chiediInt(msg, 180, LEN);

  printf("I bambini possono scambiarsi le figurine? '1' = si, '0' = no\n");

  scelta = chiediInt(domanda, 0, 1);


  do{ /*do while enorme */


    paolocheck =  check(paolo, N);

    pietrocheck = check(pietro, N); 



    /*paolo*/

    if(paolocheck == 0){
    
    packet(pack, 4, LPACK, N, &mtemp);

    nsoldipaolo++;
 
    update(pack, mtemp, paolo, N);

    }

     paolocheck =  check(paolo, N);


  /*pietro*/

     if(pietrocheck == 0){

  packet(pack, 4, LPACK, N, &mtemp);

  nsoldipietro++;

  update(pack, mtemp, pietro, N);

     }

     pietrocheck = check(pietro, N); 



     if(scelta == 1 && pietrocheck == 0 && paolocheck == 0){

       exchange(paolo, pietro, N);

     }



  
  }while(paolocheck == 0 || pietrocheck == 0); /* fine do while enorme */

  doppaolo = contadoppioni(paolo, N);
  doppietro = contadoppioni(pietro, N);

  printf("Paolo ha comprato %d pacchetti spendendo %d euro e ha ancora %d doppioni\n", nsoldipaolo, nsoldipaolo*COSTO, doppaolo);

  printf("Pietro ha comprato %d pacchetti spendendo %d euro e ha ancora %d doppioni\n", nsoldipietro, nsoldipietro*COSTO, doppietro);

  printf("Insieme hanno speso %d euro per completare i loro album.\n", (nsoldipietro+nsoldipaolo)*COSTO);

}















int casuale(int a,int b){
  return lrand48()%(b-a+1)+a;
}





int chiediInt(char * msg, int a, int b){
  int x;
 do{
    
    printf("Inserire %s tra %d e %d: ", msg, a, b);

    scanf("%d", &x);

    if(x < a || x > b){
      printf("errore! riprova\n");
    }
 }while(x < a || x > b);

 return x;
}


void packet(int *array,int a, int b, int raccolta, int * tp){ /*array del pack, n minimo di figurine, n max di figurine (LPACK), numero totale nell'album (LEN), n carte nel pacchetto */

  int i, k;

  int doppione;

  int temp = casuale(a, b);

  *(tp) = temp;

  do{

  for(i=0; i < temp; i++){

    *(array + i) =  casuale(0, raccolta);

    for(k = 0; k < i; k++){

      if( *(array + i) == *(array + k) ){

	doppione = 1;
      }else 
	doppione = 0;

    }

  }
      
 

  }while(doppione == 1);

  }




void update(int * pacchetto, int temp, int * bimbo, int len){

  int i, casella;

  for(i = 0; i < temp; i++){
    
    casella = *(pacchetto + i);

    (*(bimbo + casella))++;

  }
  
}


int check(int *array, int len){

  int i;

   for(i = 0; i < len; i++){

    if( *(array + i) == 0){

      return(0);

    }

     
   }

   return(1);


}


void exchange(int *bimbo1, int *bimbo2, int len){

  int i, k;

  for(i=0; i<len; i++){

    if((*(bimbo1+i)>1) && (*(bimbo2+i)=0)){

      for(k=0; k<len; k++){

	if((*(bimbo2+k)>1) && (*(bimbo1+k)=0)){

	  (*(bimbo1+i))--;
	  (*(bimbo2+i))++;

	  (*(bimbo2+k))--;
	  (*(bimbo1+k))++;
	}
      }
    }
  }
}

int contadoppioni(int *array, int len){
  int i;
  int ndopp = 0;
  
  for(i=0;i<len;i++){

    if((*(array+i)) > 1){

      ndopp += (*(array+i)-1);

    }

  }

  return(ndopp);

}
