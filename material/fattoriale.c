#include <stdio.h>

int main() {
    int n, i;
    // 64 bit senza segno => max = 2^64 -1 = 18.5 x 10^18
    unsigned long long int fattoriale = 1; 

    do{ 
      printf("Inserisci numero intero positivo: ");
      scanf("%d", &n);
    } while( n<=0 );

    for (i = 1; i <= n; i++) {
       // moltiplicazione iterativa
       fattoriale *= i;  
    }

    printf("fattoriale di %d = %llu\n", n, fattoriale);
}


