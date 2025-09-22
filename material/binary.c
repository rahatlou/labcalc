#include <stdio.h>
#include <math.h>


#define NBIT 20


int main() {

   int in, cifra=0, resto;
   int binary[NBIT] = {0};

  do{ 
    printf("Inserisci numero positivo < %d in base 10: ", (int)pow(2,NBIT));
    scanf("%d", &in);
  } while( in <= 0 || in >= pow(2, NBIT) );

  do {

   resto = in % 2;
   printf("%3d-esima cifra: %d \t moltiplica 2 ^%3d (%8.0f)\n",cifra+1, resto, cifra,pow(2,cifra));

   binary[cifra] = resto;
   in /= 2;
   cifra++;

  } while (in != 0);

  printf("base 10: %d \t base 2: ", in);
  for(int i = NBIT-1; i>= 0; i--) {
    printf("%1d", binary[i]);

  }
  printf("\n");
  
} 



