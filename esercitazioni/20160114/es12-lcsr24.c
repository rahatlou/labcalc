#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define costopacchetto 1;


void packet(int, int[], int*);
void update(int[], int[], int);
int check(int[], int);
void exchange(int[], int[], int);

int main(){
  
  printf("Questo programma stima dopo quanti pacchetti di figurine Paolo e Pietro riescono a completare il loro album\n");

  srand48(time(0));
  int Nfigurine, scelta, i=0, j=0, k,  temp1, temp2, numfigpack=0, doppioni1=0, doppioni2=0, costototale;
  int paolo[221]={0};
  int pietro[221]={0};
  int figurina[7]={0};


  printf("Inserire il numero di figurine contenute nell'album compreso fra 180 e 220\n");
  do{
    scanf("%d", &Nfigurine);
    if(Nfigurine<180 || Nfigurine>220) printf("Errore valore non valido reinserire\n");
  }while(Nfigurine<180 || Nfigurine>220);

  printf("Se i bambini posso scambiarsi le figurine digita 1 altrimenti digita 0\n");
  do{
    scanf("%d", &scelta);
    if(scelta!=0 && scelta!=1) printf("Valore non valido reinserire\n");
  }while(scelta!=0 && scelta!=1);

    do{
      temp1=check(paolo,Nfigurine);
      if(temp1==0){
	i++;
	packet(Nfigurine, figurina, &numfigpack);
	update(figurina, paolo, numfigpack);
      }
      temp2=check(pietro,Nfigurine);
      if(temp2==0){
      	j++;
	packet(Nfigurine, figurina, &numfigpack);
	update(figurina, pietro, numfigpack);
      }
      if(scelta==1) exchange(paolo, pietro, Nfigurine);
    }while(temp1==0 || temp2==0);
    

     costototale=(i+j)*costopacchetto;
    
     for(k=0;k<Nfigurine;k++){
       if(paolo[k]>1) doppioni1+=(paolo[k]-1);
       if(pietro[k]>1) doppioni2+=(pietro[k]-1);
     }

     printf("Numero di pacchetti comprati da Paolo:%d\n Numero di pacchetti comprati da Pietro:%d\n Costo totale:%d\n Doppioni Paolo:%d\n Doppioni Pietro:%d\n", i, j, costototale, doppioni1, doppioni2);  

  return 0;
}

  void packet(int Nfig, int figurina[], int* numfigpack){
  int rand, i, j, tempfig, m;

  *numfigpack=4+lrand48()%4;
  rand= *numfigpack;
 
  for(i=0;i<rand;i++){
    do{
      tempfig=lrand48()%(Nfig+1);
      m=0;
    for(j=0;j<rand;j++){
      if(tempfig!=figurina[j]) m++;
    }
   
    if(m==rand)figurina[i]=tempfig;
    }while(m!=rand);
  }
}
  
  void update(int figurina[], int bambino[], int numfigpack){
  int j, temp;

    for(j=0;j<numfigpack;j++){
      temp=figurina[j];
      
      *(bambino+temp)+=1;
    }
}
  
int check(int bambino[], int Nfig){
  int i;

  for(i=0;i<Nfig;i++){
    if(bambino[i]<1) return 0;
  }
  return 1;
}
  
void exchange(int paolo[], int pietro[], int Nfig){
  int i, j;

  for(i=0;i<Nfig;i++){
    
    if(paolo[i]>1 && pietro[i]==0){
      for(j=0;j<Nfig;j++){
	if(pietro[j]>1 &&  paolo[j]==0){
	  paolo[i]--;
	  pietro[i]++;
	  paolo[j]++;
	  pietro[j]--;
	}
      }
    }
  }

  for(i=0;i<Nfig;i++){

     if(pietro[i]>1 && paolo[i]==0){
      for(j=0;j<Nfig;j++){
	if(paolo[j]>1 &&  pietro[j]==0){
	  pietro[i]--;
	  paolo[i]++;
	  pietro[j]++;
	  paolo[j]--;
	}
      }
     }
  }
}

  
