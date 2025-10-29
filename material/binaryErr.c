#include <stdio.h>
#include <math.h>


#define NBIT 20


int main() {

   int in, cifra=0, resto;

  do{ 
    printf("Inserisci numero positivo < %d in base 10: ", (int)pow(2,NBIT));
    scanf("%d", &in);
  } while( in <= 0 || in >= pow(2, NBIT) );

  int in10 = in;
  
  printf("base 10: %d \t base 2: ", in10);
  do {

   resto = in % 2;
   // stampa del resto come la cifra in binario
   printf("%1d", resto);

   in /= 2;
   cifra++;

  } while (in != 0);

  printf("\n");

  printf("questa conversione errata scrive le cifre al contrario!\n");
} 




