#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NROW 3
#define NCOL 3

int main() {
  int vec[NROW] = {1 ,2 ,3 };
  int mat[NROW][NCOL] = {1,2,3, 4,5,6, 7,8,9 };
  int i,j;
  
  
  // ciclo i righe
  for(i = 0; i < NROW; i++) {
    
    // ciclo j colonne
    for(j = 0; j < NCOL; j++) {
      printf("mat[%1d][%1d] \t",i,j);
    }
    printf("\n");
    
    for(j = 0; j < NCOL; j++) {
      //printf("%10p \t", *(mat+i)+j );
      printf("%10p \t", &mat[i][j] );
    }
    printf("\n");
    
    for(j = 0; j < NCOL; j++) {
      //printf("%10d \t", *(*(mat+i)+j) );
      printf("%10d \t", mat[i][j] );
    }
    printf("\n\n");
  }

  printf("---------------------------------\n");

  // mat e` puntatore -> mat[0][0]
  printf("mat             : \t %p\n", mat);

  // *mat puntatore -> mat[0][0] 
  printf("*mat (puntatore): \t %p\n", *mat);

  // *mat non e` un intero 
  printf("*mat (intero)   : \t %d\n", *mat);

  // **mat  equivale a mat[0][0]
  printf("**mat           : \t %d\n", **mat);    

  
  printf("------------ mat[i] ------------------\n");

  // mot[i] puntatore al primo elemento della riga i
  printf("mat[0] =  %p\n", mat[0] );
  printf("*mat[0] =  %d\n", *mat[0] );

  printf("mat[1] =  %p\n", mat[1] );
  printf("*mat[1] =  %d\n", *mat[1] );

  printf("mat[2]+2 =  %p\n", mat[2]+2 );
  printf("*(mat[2]+2) =  %d\n", *(mat[2]+2) );

  printf("------------ *mat+i ---------------------\n");
  
  // *mat+1 equivale a &mat[0][1]
  printf("*mat+1 =  %p\n", *mat+1);
  printf("&mat[0][1] =  %p\n", &mat[0][1]);
  
  printf("*(*mat+1) =  %d\n", *(*mat+1));
  printf("mat[0][1] =  %d\n", mat[0][1]);

  printf("------------ *(mat+i) ---------------------\n");

  // *(mat+1) equivale a &mat[1][0]
  printf("*(mat+1) =  %p\n", *(mat+1) );
  printf("&mat[1][0] =  %p\n", &mat[1][0]);
  
  printf("**(mat+1) =  %d\n", **(mat+1));
  printf("mat[1][0] =  %d\n", mat[1][0]);

  printf("------------ *(mat+k)+l ---------------------\n");

  // *(mat+2)+1 equivale a &mat[2][1]
  printf("*(mat+2)+1 =  %p\n", *(mat+2)+1 );
  printf("&mat[2][1] =  %p\n", &mat[2][1]);
  
  printf("*(*(mat+2)+1) =  %d\n", *(*(mat+2)+1));
  printf("mat[2][1] =  %d\n", mat[2][1]);

  
  printf("------------ mat[k] ---------------------\n");
  // 
  for(i = 0; i < NROW; i++) {
    printf("mat[%d]:%p \t *mat[%d]:%i \n", i, mat[i], i,  *mat[i]);
  }

  printf("\n\n");


  // ciclo i righe
  for(i = 0; i < NROW; i++) {
    printf("=============== mat[%d] = %p ===============\n", i, mat[i]);

    // ciclo j colonne
    for(j = 0; j < NCOL; j++) {
      printf("mat[%1d][%1d] \t",i,j);
    }
    printf("\n");
    
    for(j = 0; j < NCOL; j++) {
      //printf("%10p \t", *(mat+i)+j );
      printf("%10p \t", &mat[i][j] );
    }
    printf("\n");
    
    for(j = 0; j < NCOL; j++) {
      //printf("%10d \t", *(*(mat+i)+j) );
      printf("%10d \t", mat[i][j] );
    }
    
    printf("\n");
  } // ciclo righe
  
}
