#include <stdio.h>
#include <math.h>


int main() {

  int in, cifra=0, resto;


  do{ 
    printf("Inserisci numero positivo in base 10: ");
    scanf("%d", &in);
  } while( in <= 0 );

  do {
   cifra++;

   resto = in % 2;
   printf("%3d-esima cifra: %d \t moltiplica 2 ^%3d (%8.0f)\n",cifra, resto, cifra-1,pow(2,cifra-1));

   in /= 2;

  } while (in != 0);

} 



