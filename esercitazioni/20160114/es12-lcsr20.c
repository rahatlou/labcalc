# include<time.h>
# include<stdio.h>
# include<stdlib.h>
# include<math.h>

#define dim 220
#define dim2 7

int check(int bambino[], int n);

int packet(int pack[], int n);

void update(int bambino[], int pack[], int r);

void exchange(int pietro[], int paolo[]);

int main(){

  int n, paolo[dim], pietro[dim], pacchetto[dim2], numpac, numpac1, numpac2,  x, c=0, x2, k, k2, i, risp, dopp1, dopp2;

  srand48(time(0));

  printf("questo programma calcola il numero di pacchetti che Paolo e Pietro devono comprare per riempire i propri album\n");

  do{
    printf("inserire la capacita' degli album, compresa tra 180 e 220\n");
    scanf("%d",& n);
    if(n<180 || n>220){
      printf("inserimento errato\n");
    }
  }while(n<180 || n>220);

  printf("i due bambini possono scambiarsi i doppioni? 1=si, 0=no\n");

  do{
    scanf("%d", & risp);
    if(risp!=0 || risp!=1){
      printf("inserimento errato\n");
    }
  }while(risp!=0 && risp!=1);

  if(risp==0){

    do{
      k=packet(pacchetto, n);
      update(pietro, pacchetto, k);
      numpac1++;
      x=check(paolo, n);
    }while(x==0);

    do{
      k2=packet(pacchetto, n);
      update(paolo, pacchetto, k2);
      numpac2++;
      x=check(pietro, n);
    }while(x==0);

  } else{

    do{
      k=packet(pacchetto, n);
      update(pietro, pacchetto, k);
      numpac1++;
      x=check(pietro, n);

      k2=packet(pacchetto, n);
      update(paolo, pacchetto, k2);
      numpac2++;
      x2=check(paolo, n);
      //exchange entra in funzione se i due album non sono pieni e se ci sono doppioni da entrambe le parti.
      //avremmo dovuto aggiungere un altro if che verifica l'esistenza dei doppioni in entrambi gli album, poi chiamare exchange
      if(x==0 && x2==0){
	exchange();
      }else{
	if(x==1 && x2==1){
	  c=1;
	}
      }
    }while(c!=1);


  }
    
  numpac=numpac1+numpac2;

  for(i=0; i<n; i++){
    dopp2+=pietro[i]-1;
    dopp1+=pietro[i]-1;
  }

  printf("numero di pacchetti comprati da paolo: %d;\n", numpac2);
  printf("numero di pacchetti comprati da pietro: %d;\n", numpac1);
  printf("numero di pacchetti comprati in totale (costo totale): %d;\n", numpac);
  printf("numero di doppioni rimasti a pietro: %d;\n", dopp1);
  printf("numero di doppioni rimasti a paolo: %d;\n", dopp2);

  return 0;
}

int packet(int pack[], int n){
 
  int r, i;

  r=lrand48()%4;
  r+=3;

  for(i=0; i<r; i++){
    pack[i]=lrand48()%(n+1);
  }


  return r;

}

void update(int bambino[], int pack[], int r){

  int i, q;

  for(i=0; i<r; i++){
    q=pack[r];
    bambino[q]++;
  }

}

int check(int bambino[], int n){

  int x, i, min=3000000;

  for(i=0; i<n; i++){
    if(bambino[i]<min){
      min=bambino[i];
    }
  }

  if (min==0){
    x=1;
  }else{
    x=0;
  }

  return x;
}

void exchange(int pietro[], int paolo[]){

  //questa funzione tramimte un utilizzo di cicli for e di if doveva scambiare i doppioni


}
