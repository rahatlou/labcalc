#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define fmax 220
#define fmin 180
#define fmaxb 7
#define fminb 4


void packet(int*, int*, int);
void update(int, int *, int*, int*);
void exchange(int, int*, int*);
int check(int *, int);

int main() {

  int b[fmaxb], Nfig, i, d, Bpa, Bpi, Epa=0, Epi=0, Dpa=0, Dpi=0;
  float v;
  int paolo[fmax], pietro[fmax];


  srand48(time(0));

  printf("il programma simula due bambini che riempiono due album di figurine\n");

  printf("inserire il numero di figurine nell album [180,220]: ");

  do{
    scanf("%d",&Nfig);
    if(Nfig<fmin || Nfig >fmax) printf("valore errato, reinserire: ");
      
  } while(Nfig<fmin || Nfig >fmax);


  
    printf("possibilita di fare scambi tra doppioni: inserire 1\nimpossibilita di fare scambi: inserire 2\n");

    do{
      scanf("%f",&v);
      if(v!=1 && v!=2) printf("scelta inesistente, reinserire: ");
    }while(v!=1. && v!=2.);
   

    do{

      if(Epa==0){
       packet(b,&d,Nfig);
       update(d,b,paolo,&Bpa);
      }

      if(Epi==0){
        packet(b,&d,Nfig);
        update(d,b,pietro,&Bpi);
      }

      if(v==1.)  exchange(Nfig,pietro,paolo);


      Epa=check(paolo, Nfig);
      Epi=check(pietro,Nfig);

    } while(Epa==0 || Epi==0);

    for(i=0;i<Nfig;i++){

      Dpa+=(paolo[i]);
      Dpi+=(pietro[i]);

    }

    Dpa-=Nfig;
    Dpi-=Nfig;


    printf("pacchetti comprati da paolo: %d\tdoppioni: %d\tspesa: %d euro\n", Bpa, Dpa, Bpa);
    printf("pacchetti comprati da pietro: %d\tdoppioni: %d\tspesa: %d euro\n", Bpi, Dpi, Bpi);


    exit(0);
}













void packet(int* b, int* d, int Nfig){

  int i, j, x;

  *d=(lrand48()%(fmaxb-fminb+1))+fminb;


  do{
    x=0;
    for(i=0;i<*d;i++){
      *(b+i)=lrand48()%Nfig;
      for(j=0;j<i;j++){
	if(*(b+j)==*(b+i)) x=1;
      }
    }}while(x==1);

  
     
    }


void update(int d, int* b, int* C, int* Bpa){

  int i;

  for(i=0;i<d;i++){

    (*(C+(b[i])))++;
  }

  (*Bpa)++;

}


void exchange(int Nfig, int* pietro, int* paolo){

  int i, j;

  for(i=0;i<Nfig;i++){

    if((*(paolo+i))>1){

      if((*(pietro+i))==0){

	for(j=0;j<Nfig;j++){

	  if((*(pietro+j))>1){

	    if((*(paolo+j))==0){

	      (*(paolo+j))++;
	      (*(pietro+j))--;
	      (*(paolo+i))--;
	      (*(pietro+i))++;

	     

	    }
	  }
	}
      }
    }
  }
}


int check(int* E, int Nfig){

  int i;

  for(i=0;i<Nfig;i++){

    if(E[i]==0) return 0;

  }

  return 1;
}
