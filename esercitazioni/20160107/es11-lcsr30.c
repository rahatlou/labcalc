#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define L 0.5
#define R 0.77
#define RIP 100



void genCirc (float*, float*);

void contaPepe (float, float, int*, int*, int*);

float media (int[]);



int main () {

  srand48(time(0));

  int n, i, j, A = 0, B = 0, C = 0, a[RIP] = {0}, b[RIP] = {0}, c[RIP] = {0};

  float x, y, na, nb, nc;


  printf("MASTERCHEF\nCalcolatore granelli pepe caduti su una superficie predefinita\n");          /*punto 1 e 2*/

  do{     
   
    printf("Inserire numero granelli pepe 330<=n<=550\n  N=");
     
    scanf("%d",&n);

      if(n<330 || n > 550){

	printf("Errore, numero non accettabile\n");
      }
  
  } while (n<330 || n>550);


  for(i=0;i<RIP;i++) {                                                                             /*punto 5 esperimenti*/

    for(j=0;j<n;j++) {

      genCirc (&x, &y);
      
      contaPepe (x, y, &A, &B, &C);
    
    }

    a[i] = A;

    b[i] = B;

    c[i] = C;

    A = 0;

    B = 0;
 
    C = 0;

  }


  na = media(a);                                                                                  /*punto 7 trascrizione e stampa media*/
  
  nb = media(b);

  nc = media(c);


  printf("RISULTATI:\n==========\nMedia in A:%.3f\nMedia in B:%.3f\nMedia in C:%.3f\n==========\n", na, nb, nc);


}






void genCirc (float *x, float *y) {                                                                /*punto 3 funzione genera posizione*/

  do{

    *x = (float)lrand48()/RAND_MAX*(R*2)-R;

    *y = (float)lrand48()/RAND_MAX*(R*2)-R;

  } while (*x*(*x)+(*y)*(*y) > R*R);

}





void contaPepe (float x, float y, int *A, int *B,int *C) {                                         /*punto 4 funzione controllo posizione*/

  if(x >= 0 && y >= 0) {

    if(x <= L) {

      if(y <= L) {

	(*A)++;

      } else {

	(*B)++;
      }
    
    } else {

      if(y >= L) {

	(*C)++;

      }

    }
  
  }

}



float media (int x[RIP]) {                                                                                       /*punto 6 funzione media*/

  int i;

  float nx = 0;


  for(i=0;i<RIP;i++) {

    nx += x[i];

  }

  nx = nx/RIP;

  return nx;

}





