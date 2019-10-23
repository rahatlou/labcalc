#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX_FIGU 220
#define MIN_FIGU 180
#define NEW_MAX_FIGU 7
#define NEW_MIN_FIGU 4
#define ARRAY 220
int getint (char* messaggio, int min, int max);
int packet (int max, int min);
void update (int array[], int n, int figura, int* esiste);

int main () {
  int paolo[ARRAY]= {0};
  int pietro[ARRAY]= {0};
  int pacchetto[ARRAY]= {0};
  int x, scelta, y0, y1, i, z0 = 0, z1 = 0, j ,y0Pa, y0Pi, y1Pi,  y1Pa, esiste ;
  srand48(time(0));
  printf("Riempi l'album di figurine!\n");
  x= getint("Inserisci il numero di figurine ", MIN_FIGU ,MAX_FIGU );
  printf("L'utente ha due scelte:\n");
  printf("Premere 0 se i due bambini si possono scambiare i doppioni\n");
  printf("Premere 1 se i due bambini non possono scambiarsi i doppioni\n");
  scanf("%d", &scelta);
  if(scelta==0) {
    for(i=0; i<=x; i++){
      pacchetto[i] = packet(x, 1);
      /* printf(" %d n.%d \n",pacchetto[i], z0++);*/
    } 
   for(j=0; j<= x; j++){
     y0Pa= packet(NEW_MAX_FIGU, NEW_MIN_FIGU);
     pacchetto[j]= packet(x,1);
     update (paolo, x, ARRAY, &esiste);
     paolo[j] = esiste;  
     printf("Pa=  %d \n",paolo[j]);
    }
    y0Pa= packet(NEW_MAX_FIGU, NEW_MIN_FIGU);
    for(j=0; j<=y0Pa; j++){
      paolo[j] = packet(NEW_MAX_FIGU, NEW_MIN_FIGU);
      printf("Pa=  %d \n",paolo[j]);
      }
   for(j=0; j<= x; j++){
     y0Pi= packet(NEW_MAX_FIGU, NEW_MIN_FIGU);
     pacchetto[j]= packet(x,1);
     update (pietro, x, ARRAY, &esiste);
     pietro[j] = esiste;  
     printf("Pi=  %d \n",pietro[j]);
    }
   y0Pi= packet(NEW_MAX_FIGU, NEW_MIN_FIGU);
   for(j=0; j<=y0Pi; j++){
      pietro[j] = packet(NEW_MAX_FIGU, NEW_MIN_FIGU);
      printf("Pi=  %d \n",pietro[j]);
      }



  
  } else if (scelta==1){
     y1Pa= packet(NEW_MAX_FIGU, NEW_MIN_FIGU); 
     for(j=0; j<= y1Pa; j++){
       paolo[j] = packet(x,1);
       printf("Pa= %d \n", paolo[j]);
    }
     y1Pi= packet(NEW_MAX_FIGU, NEW_MIN_FIGU);
     for(j=0; j<=y1Pi; j++){
       pietro[j] = packet(NEW_MAX_FIGU, NEW_MIN_FIGU);
       printf("Pi=  %d \n",pietro[j]);
    }

    for(i=0; i<=x; i++){
      pacchetto[i] = packet(x, 1);
      printf(" %d n.%d \n",pacchetto[i], z1++);
    }




  




  }
    
  

exit(0);
}


int getint( char* messaggio, int min, int max){

  int dato;
  do{
    printf("%s nell'intervallo [%d , %d]: ",messaggio, min, max);
    scanf("%d", &dato);
    if(dato<=min || dato>=max) {
      printf("ERRORE! Valore non compreso nell'intervallo [%d , %d]\n",min,max);
    }
  }while(dato<=min || dato>=max);
  return dato;
}


int packet( int max, int min) {
  
  return (int)(max-min)*lrand48()/RAND_MAX+min;



}

void update (int array[], int n, int figura, int* esiste){
  int middle, start = 0, end = n-1, found = 0;
  do{
    middle=(start+end)/2;
    if(array[middle]==figura){
      found=1;
    } else if(array[middle]<figura){
      start=middle+1;
    } else {
      end=middle-1;
    }
  } while (!found && start<=end);
  if(found){ 
    esiste++;
      }
}
  



