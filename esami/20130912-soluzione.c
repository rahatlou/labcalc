#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define NBAT 8
#define NATLETI 8

float genera(float a, float b);
void Finale(int Lun, float* tBat);

int main() {

  int iBat, iAtl;
  int Lun;
  float vel, tau, tAtleta; 
  float TempiBatteria[NBAT];
  float tMedio, tMin;
  int iMin;


  /* 1pt: uso corretto di srand48 */
  srand48( time(0) );

  printf("Simulazione di una gara di nuoto con 8 batterie e 8 atleti per batteria\n");

  /* 2pt: acquisizione valore Lun */
  do{
    printf("Inserire la lunghezza della gara compresa tra 50 e 400 inclusi: ");
    scanf("%d", &Lun);
  } while(Lun<50 || Lun>400);


  /* 2pt: ciclo batterie */
  for(iBat=0; iBat<NBAT; iBat++) {

    tMedio = 0;
    tMin = 9999.;
    iMin = 0;

    /* 2pt: ciclo atleti */
    for(iAtl=0; iAtl<NATLETI; iAtl++) {

       /* 2pt: calcolo tempo atleta */
       vel = genera(0., 5.5);
       tau = genera(0., 0.5);
       tAtleta = tau + Lun/vel;

       /* 2pt: calclo tempo minimo e vincitore */
       if(tAtleta < tMin ) { 
         iMin = iAtl;
         tMin = tAtleta;     
       }

       /* 2pt: calcolo tempo medio */
       tMedio += tAtleta;

    }
    tMedio /= NATLETI;
    
    /* 1pt: stampa risultato batteria */
    printf("Batteria: %d tempo medio: %.2f   Vincitore in corsia %d  con il tempo %.2f\n",
           iBat, tMedio, iMin, tMin);
    TempiBatteria[iBat] = tMin;

  } 

  Finale( Lun, TempiBatteria );


  return 0;
}



/* 2pt: funzione con interfaccia giusta */
float genera(float a, float b) {

  /* 1pt: estrazione corretta */
  return a + (b-a)*(float)lrand48()/RAND_MAX;
}

/* 3pt: interfaccia funzione Finale() */
void Finale(int Lun, float* tBat) {

  int i,iMin;
  float TempiFinale[NBAT]={0.};
  float vel, tau;


  /* 2pt: apertura file */
  FILE* fout;
  fout = fopen("Podio.dat","w");


  iMin = 0;

  /* 2pt: utilizzo ciclo corretto */
  for(i=0; i<NBAT; i++) {

     /* 2pt: calcolo tempo totale */
     vel = genera(0., 5.5);
     tau = genera(0., 0.5);
     TempiFinale[i] = tBat[i] +  tau + Lun/vel;

     if(TempiFinale[i] < TempiFinale[iMin]) iMin = i;

     /* 2pt: scrittura su file */
     fprintf(fout, "%d \t %.2f\n", i, TempiFinale[i] );

  }

  /* 1pt: sommario */
  printf("Vincitore in corsia %d con il tempo totale %.2f\n", iMin, TempiFinale[iMin]);

  /* 1pt: chiusura file */
  fclose(fout);
  printf("risultati della final sono stati salvati in Podio.dat\n");


}

