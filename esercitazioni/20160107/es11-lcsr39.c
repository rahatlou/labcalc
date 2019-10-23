#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CEN 100

float genCirc1(float);
float genCirc2(float);
int contaPepe(float, float, float);
float media(int, int);


int main(){
  int A[CEN] = {0};
  int B[CEN] = {0};
  int C[CEN] = {0};
  int N, i,  j, a = 0;
  int a1 = 0; 
  int b1 = 0;
  int c1 = 0;
  int b = 0;
  int c = 0;
  int k ;
  float l = 0.5;
  float  x, y, NA, NB, NC,  R = 0.77;
  srand48(time(0));

  
 
  

  printf("Questo programma conta i granelli caduti \nall interno delle mattonelle A, B e C\n");

  do {
  printf("inserire numero granelli N >= 330 e N <=550\n");
  scanf("%d", &N);
  

  if(N < 330 || N > 550) {
    printf("ERRORE NUMERO NON VALIDO\n");
  }
  
  } while(N < 330 || N > 550);




  for(k = 0; k < CEN; k++){
    a = b = c = 0;
    for(i = 0; i < N; i++){

      x = genCirc1(R);
      y = genCirc2(R);
      j = contaPepe(x, y, l);
      if(j == 1){
	a++;
      } else if(j == 2){
	b++;
      } else if(j == 3){
	c++;
      }

    }
    
    A[k] = a;
    a1 += a;
    B[k] = b;
    b1 += b;
    C[k] = c;
    c1 += c;


    
  }

  NA = media(a1, N);
  NB = media(b1, N);
  NC = media(c1, N);
  
  printf("numero media in A = %f\n", NA);
  printf("numero media in B = %f\n", NB);
  printf("numero media in C = %f\n", NC);

  return 0;
}







float genCirc1(float r){
  float x;

  
 x = r * (float)lrand48() / RAND_MAX ;
 
 return x;
  
  
}








float genCirc2(float r){
  float y;

  
 y = r * (float)lrand48() / RAND_MAX ;
 
 return y;
  
  
}


int contaPepe(float a, float b, float k){
  
  if(a < k && b < k){
    return 1;
  } else if(a >= k && b <= k){

    return 2;
  }else if(a >= k && b > k){
    return 3;
  } else { 
    return 0;
  }
}

    



float media(int a, int tot){
  float c;
  c = (float)a / tot ; 
  
  return c;
}
