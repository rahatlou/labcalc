#include<stdio.h>
#include<stdlib.h>

#define LEN 4
#define FMAX 100
#define SMAX 10
#define VMAX 10

int main() {

  char nome[SMAX][FMAX];
  int  voto[SMAX][SMAX];
  int i,j;
  char fname[FMAX], c;

  FILE* fin = 0;

  printf("inserire il nome del file: ");
  while( (c = getchar()) != '\n' && i<FMAX ) {
    fname[i++] = c;
  }
  fname[i++] = '\0';
  fin = fopen(fname,"r+");
  if( !fin ) {
    printf("bad filename %s. terminating... \n", fname);
    exit(-1);
  }

  for(i=0; i< LEN; i++) {
    fscanf(fin,"%s %d %d %d %d %d", nome[i], *(voto+i), *(voto+i)+1,*(voto+i)+2,*(voto+i)+3,*(voto+i)+4 );
  }
  fclose(fin);

  for(i=0;i<LEN;i++) {
    printf("nome[%d]: %-10s", i, nome[i]);
    for(j=0;j<5;j++) {
      printf("\t %d", voto[i][j]);
    }
    printf("\n");
  
  }

}
