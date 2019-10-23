#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define FMIN 180
#define FMAX 220
#define PMIN 4
#define PMAX 7

int  packet(int,int*);
void  update(int*,int*,int*,int);
int check(int*,int);
void exchange(int*,int*,int*,int*,int);


int main() {

  int nf,dop,i,npac,pietroc=0,paoloc=0,costopa,costopi,ndoppa=0,ndoppi=0;
  int pietro[FMAX]={0};
  int paolo[FMAX]={0};
  int pacchetto[PMAX]={0};
  int doppionipa[FMAX]={0};
  int doppionipi[FMAX]={0};

  srand48(time(0));

  printf("Questo programma simula il completamento di due album di figurine di due bambini\n");

  do{

    printf("Inserire il numero di figurine da trovare negli album compreso tra %d e %d: \n",FMIN,FMAX);
    scanf("%d",&nf);
  
  if (nf<FMIN || nf>FMAX) printf("Valore non valido.\n");

  } while (nf<FMIN || nf>FMAX);

  do{ 

    printf("I due bambini possono scambiarsi i doppioni? (scrivere 1 per si, 0 per no): \n");
    scanf("%d",&dop);

    if (dop != 0 && dop != 1) printf("Valore non valido\n");

  } while (dop!=0 && dop!=1);

  do{
 
    while (pietroc==0) {

      npac=packet(nf,pacchetto);

      update(pacchetto,pietro,doppionipi,npac);

      costopi++;

    }

    while (paoloc==0) {

    npac=packet(nf,pacchetto);

    update(pacchetto,paolo,doppionipa,npac);
    
    costopa++;

    } 

    pietroc=check(pietro,nf);

    paoloc=check(paolo,nf);


    if(dop==1 && pietroc!=1 && paoloc!=1) {

      exchange(paolo,pietro,doppionipa,doppionipi,nf);
   
     }

    } while (pietroc!=1 && paoloc!=1);

  for(i=0;i<nf;i++) {

    if (doppionipa[i]==1) ndoppa++;
    if (doppionipi[i]==1) ndoppi++;

  }

    printf("PAOLO:\nPacchetti comprati:%d\t Numero doppioni:%d\nPIETRO:\n Pacchetti comprati:%d\tDoppioni rimasti:%d\n",costopa,ndoppa,costopi,ndoppi);

    exit(0);

}


int  packet(int a,int *b) {

  int c,i,j,d;

  for (i=0;i<PMAX;i++) {

    *(b+i)=0;

  }

  c=lrand48()%PMAX +PMIN;

  for(i=0;i<c;i++) {

    do {

      d=0;

      *(b+i)=lrand48()%a +1;

        for (j=0;j<c;j++) {

	  if (*(b+i)==*(b+j)) d++;

	}
    } while (d>=2);  

  }
  return c;
}
  
void update(int*a,int*b,int*c,int d) {

  int i;

  for (i=0;i<d;i++) {

    if (*(b+*(a+i-1))==1) *(c+*(a+i-1))+=1;

      else if (*(b+*(a+i-1))==0) *(b+*(a+i-1))=1;
  }

}

int check(int*a,int b) {

  int i,q=0,w=0;

  for (i=0;i<b;i++) {

    if (*(a+i)==1) q++;

     }
  if (q==b) w=1;

  return w;

}

void exchange(int*a,int*b,int*da,int*db,int q) {

  /*non finito*/

  int i,j;

  for(i=0;i<q;i++) {

    j=0;

    if (*(da+i)>=0 && *(b+i)==0) {


      do {

	if (*(db+j)>=0 && *(a+i)==0) {

	  *(db+j)-=1;

	  *(a+i)=1;
	} 

	  j++; 

      } while (*(a+i)==0);
    }
}
}




 
