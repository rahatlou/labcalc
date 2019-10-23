#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NROW 3
#define NCOL 3

int main()
{
    int array1D[NROW];
    int array2D[NROW][NCOL];
    double array2Ddouble[NROW][NCOL];
    int i,j;

    for(i = 0; i < NROW; i++) {
        array1D[i] = i + 1;

        for(j = 0; j < NCOL; j++) {
            array2D[i][j] =  i*3 + j + 1;
            array2Ddouble[i][j] =  i*3 + j + 1;
        }
    }

    for(i = 0; i < NROW; i++) {
      for(j = 0; j < NCOL; j++) {
	printf("array2D[%1d][%1d] \t",i,j);
      }
      printf("\n");
      
      for(j = 0; j < NCOL; j++) {
	printf("%-14p \t", *(array2D+i)+j );
      }
      printf("\n");
      
      for(j = 0; j < NCOL; j++) {
	printf("%-14d \t", *(*(array2D+i)+j) );
      }
      printf("\n");
    }

    for(i = 0; i < NROW; i++) {
      printf("array2D[%d]:%p \t *array2D[%d]:%i \n", i, array2D[i], i,  *array2D[i]);
    }

    printf("array2D             : \t %p\n", array2D);
    printf("*array2D (puntatore): \t %p\n", *array2D);
    printf("*array2D (intero)   : \t %d\n", *array2D);
    printf("**array2D           : \t %d\n", **array2D);    
    
    return 0;
}
