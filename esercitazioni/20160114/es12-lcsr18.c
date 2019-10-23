#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define FMIN 180 /*numero minimo di figurine*/
#define FMAX 220 /*numero massimo di figurine*/

#define FPMIN 4 /*numero minimo di figurine per pacchetto*/
#define FPMAX 7 /*numero massimo di figurine per pacchetto*/

#define SCAMBISI 1
#define SCAMBINO 2

int getInt(char*,int,int);
int uniforme(int,int);
int packet(int*,int,int,int);
void update(int*,int*,int);
int check(int*,int);
int doppioni(int*,int);
void exchange(int*,int*,int);
int controlla(int*,int);
void scambio(int*,int*,int,int);

int main() {
  int paolo[FMAX]={0};
  int pietro[FMAX]={0};
  int pacchetto[FPMAX]={0};
  int nfig,nfpacchetto,scelta;

  /*npietro e npaolo sono i pacchetti comprati dai due collezionisti*/
  int npaolo=0, npietro=0;

  srand48(time(0));

  printf("\n\nSimulazione due bambini che completano album di figurine\n");

  nfig=getInt("numero figurine per album ",FMIN,FMAX);
  scelta=getInt("\n1 se i bambini possono scambiarsi le figurine\n2 se non possono\n",SCAMBISI,SCAMBINO);

  do {

    /*se l'album di paolo non e finito, paolo compra pacchetto e aggiorna l'album*/
    if ( check(paolo,nfig)==0 ) {
      nfpacchetto=packet(pacchetto,FPMIN,FPMAX,nfig);
      npaolo++;
      update(paolo,pacchetto,nfpacchetto);
    }

    /*se l'album di pietro non e finito, pietro compra pacchetto e aggiorna l'album*/
    if ( check(pietro,nfig)==0 ) {
      nfpacchetto=packet(pacchetto,FPMIN,FPMAX,nfig);
      npietro++;
      update(pietro,pacchetto,nfpacchetto);
    }

    /*se scambi si e album non finiti, scambio figurine*/
    if(scelta==SCAMBISI && check(pietro,nfig)==0 && check(paolo,nfig)==0) {
      exchange(pietro,paolo,nfig);
    }

    /*continua il ciclo fino a che pietro e paolo non hanno entrambi finito*/
  } while ( check(paolo,nfig)!=1 || check(pietro,nfig)!=1);

  printf("\nAlbum di paolo: \nNumero di doppioni rimasti: %d \nNumero di pacchetti acquistati [ovvero costo pacchetti]: %d\n",doppioni(paolo,nfig),npaolo);
  printf("\nAlbum di pietro: \nNumero di doppioni rimasti: %d \nNumero di pacchetti acquistati [ovvero costo pacchetti]: %d\n",doppioni(pietro,nfig),npietro);

  exit(0);
}

int getInt(char *mess,int min,int max) {
  int n;
  do {
    printf("\nInserire %stra %d e %d: ",mess,min,max);
    scanf("%d",&n);
    if(n>max||n<min) printf("Valore non valido");
  } while(n>max||n<min);
  return n;
}

int uniforme(int min,int max) {
  return (lrand48()%(max-min+1)+min);
}

int packet(int *pacchetto,int min, int max,int nfig) {
  int nf,i=0;
  nf=uniforme(min,max);
  do {
    for(i=0;i<nf;i++) {
      *(pacchetto+i)=uniforme(0,nfig-1);
    }
  }while(controlla(pacchetto,nf)==1);
  return nf;
}

/*"controlla" controlla che non ci siano doppioni nel pacchetto*/
int controlla(int *packet,int nf) {
  int j=0,control=0,i;
  do {
    i=nf-1;
    do {
      if(*(packet+i)==*(packet+j)) control=1;
      i--;
    }while(i>j && control!=1);
    j++;
  }while(j<nf-1 && control!=1);
  return control;
}


void update ( int *album,int *pacchetto, int nf) {
  int k;

  for (k=0; k< nf; k++ ) {
    *(album+ (*(pacchetto+k)))+=1;
  }

}

int check(int *album,int nfig) {
  int i=0,controlla=1;
  do {
    if(*(album+i)==0) controlla=0;
    i++;
  }while(i<nfig && controlla==1);
  return controlla;
}

int doppioni(int *album, int nfig) {
  int doppi=0,i;

  for (i=0; i < nfig; i++) {
    if ( *(album+i)>= 2) doppi+= *(album+i)-1;
  }
  return doppi;
}

 
/* exchange controlla se un album ha doppioni della i-esima figurina e l'altro non ha quella figurina    * 
 * della i-esima figurina. In questo caso, controlla tra le figurine successive se vi sono doppioni che  *
 * mancano all'altro (figurina j-esima nella funzione scambio). Se anche cio e verificato, allora scambia*
 * la figurina i-esima con la j-esima*/

void exchange(int *paolo,int *pietro,int nfig) {
  int i;
  for(i=0;i<nfig;i++) {

    if(*(paolo+i)>=2 && *(pietro+i)==0) {
      scambio(paolo,pietro,nfig,i);
    } 

    else if(*(paolo+i)==0 && *(pietro+i)>=2) {
      scambio(pietro,paolo,nfig,i);
    }
  }
}

void scambio(int *album1,int *album2,int nfig,int i) {
  int j,cond=0;
  j=i+1;
  do {
    if(*(album1+j)==0 && *(album2+j)>=2) {
      *(album1+j)+=1;
      *(album2+j)-=1;
      *(album1+i)-=1;
      *(album2+i)+=1;
      cond=1;
    }
    j++;
  }while(cond!=1 && j<nfig);
}
