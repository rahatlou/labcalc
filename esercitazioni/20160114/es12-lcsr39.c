#include <stdio.h>
#include <stdlib.h>                                                        
#include <time.h>
#define LEN 220 

void packet(int, int *);
int check(int *, int);
int main() {
  
  int N, *a, *b , i, ka,  Paolo[LEN] = {0};
  int Pietro[LEN] = {0};
  srand48(time(0));

  a = &Pietro[0];
  b = &Paolo[0];  
  printf("Benvenuto alla simulazione della raccolta di figurine\n");

  do{
  printf("inserire numero massimo di figurine\n");
  scanf("%i", &N);
  } while(N < 180 || N > 220);
  
  
  packet(N, *a);
  for(i = 0; i < N; i++){
    printf("valore[%i] = %i\n", i, Paolo[i]);
  }


 ka = check(*a, N);
 printf("%i", ka);

}





void packet(int N,int *p){
  int m, n, i, c, k, a, q, array[7] = {0};

 
  i = 0;
  m = lrand48();
  n = (m % 4) + 4;

  for(i = 0; i < n; i++){
    do{
      q = array[i];
      k = lrand48();
      array[i] = k % N; 
    } while (array[i] == q);
    
  }
}


int check(int *a, int N ){
  int j;
  for(j = 0; j < N ; j++){

    if(*(a + j) == 0){

      return 0;
    }
  }
  
  return 1;
}





