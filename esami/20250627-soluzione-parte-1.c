#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
int input() {
  int fine=0, na, ret;
  do {
    printf("Immetti il numero di asteroidi:");
    ret=scanf("%d", &na);
    if (ret < 1 || na < 10 || na > 20 ) 
      fine=0;
    else
      fine=1;
  } while(fine==0);
  return na;
}

void print_grid(char grid[SIZE][SIZE]) {
  int ix, iy;
  for (ix=0; ix < SIZE; ix++) {
    printf("| ");
    for (iy=0; iy < SIZE; iy++) {
      printf("%c ", grid[ix][iy]);
    }
    printf("|\n");
  }
}
void fillmatrix(char grid[SIZE][SIZE], int nstar) {
  int ok, ix, iy;
  do {
    ok = 0;
    do {
      ix = drand48()*SIZE;
      iy = drand48()*SIZE;
      if (grid[ix][iy]=='-' && !(ix==0 && iy==0))
        {
          grid[ix][iy]='*';
          ok = 1;
          nstar--;
        }
    }
    while (!ok);
  }
  while (nstar>0);
}
int move(int pos[2]) {
  int dir, ok=1;
  dir = drand48()*4;
  if (dir == 0 && pos[0] < SIZE-1)
    pos[0]++;
  else if (dir == 1 && pos[0] > 0)
    pos[0]--;
  else if (dir == 2 && pos[1] < SIZE-1)
    pos[1]++;
  else if (dir == 3 && pos[1] > 0)
    pos[1]--;
  else
    ok=0;
  return ok;
}
int main(void) {
  char grid[SIZE][SIZE]={0};
  int ix, iy, nstar, shields, st=0, pos[2];

  // numero asteriodi e scudi
  nstar = input();
  srand48(time(0));
  shields=5;

  // griglia inziale vuota
  for (ix=0; ix < SIZE; ix++)
    for (iy=0; iy < SIZE; iy++)
      grid[ix][iy]='-';

  // posizione iniziale
  pos[0]=pos[1]=0;

  // mettere asteriodi sulla griglia
  fillmatrix(grid, nstar);
  
  grid[0][0]='A';
  print_grid(grid);

  while (1) {
    while (!move(pos));
    st++;
    if (grid[pos[0]][pos[1]] == '*') {
      shields--;
      printf("Dopo %d passi l'astronave ha colpito un asteroide in (%d,%d) scudi=%d\n", st, pos[0], pos[1], shields);       
    }
    grid[pos[0]][pos[1]] = 'A';
    if (shields < 0)
      break;  
  }
  print_grid(grid);
  printf("Dopo %d passi l'astronave è esplosa\n", st);
  return 0;
}
