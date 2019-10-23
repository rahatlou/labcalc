#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAX 220
#define MIN 180

void packet(int, int, int, int*, int*);
void update(int*, int*, int);
void exchange(int*, int*, int);
int check(int*, int);

int main(){

  int Nfig,scambio,*pointer,Packfig, paolocompleto=0, pietrocompleto=0;
  int doppionipaolo=0, doppionipietro=0, i, pacchettipaolo=0, pacchettipietro=0; 
  int Paolo[MAX],Pietro[MAX], cards[7];
  srand(time(0));


  printf("Questo programma stima il numero di pacchetti che due bambini devono acquistare \n per completare i loro album\n");

  do{
    printf("Inserire il numero di figurine degli album compreso tra 180 e 220\n");
    scanf("%d",&Nfig);
  }while(Nfig<MIN || Nfig>MAX);

  for(i=0; i<Nfig; i++){
    Paolo[i]=0;
    Pietro[i]=0;
  }

  do{
    printf("Inserire 1 se i due bambini possono scambiarsi i doppioni\nInserire  0 se non possono scambiarsi i doppioni\n");
    scanf("%d",&scambio);
  }while(scambio!=1 && scambio!=0);

  while(paolocompleto!=1 && pietrocompleto!=1){

  pointer = &Packfig;
  packet(4, 7, Nfig, cards, pointer);

  if(paolocompleto!=1){
    update(cards, Paolo, Packfig);
    pacchettipaolo++;
  }
  packet(4, 7, Nfig, cards, pointer);
  if(pietrocompleto!=1){
    update(cards, Pietro, Packfig);
    pacchettipietro++; 
 }
  paolocompleto = check(Paolo, Nfig);
  pietrocompleto = check(Pietro, Nfig);
  if(scambio==1){
    exchange(Paolo, Pietro, Nfig);
  }
  }

  for(i=0; i<Nfig; i++){
    doppionipaolo += Paolo[i];
    doppionipietro += Pietro[i];
  }
  doppionipaolo -= Nfig;
  doppionipietro -= Nfig;
  printf("Paolo ha %d doppioni\n Pietro ha %d doppioni\n", doppionipaolo, doppionipietro);


  printf("Paolo ha comprato %d pacchetti\n Pietro ha comprato %d pacchetti\n", pacchettipaolo, pacchettipietro);




  exit(0);
}

void packet(int a, int b, int nalbum, int* cards,int *pointer){
  int numfig;
  int i, j;

  numfig = a + lrand48()%(b-a+1);
  *pointer = numfig;
  for(i=0;i<numfig;i++){
    cards[i]=0;
  }
  for(i=0;i<numfig; i++){
    cards[i] = lrand48()%(nalbum + 1);

  }

}
void update(int*cards, int*bambino, int pack){
  int i;
  for(i=0; i<pack; i++){
    bambino[*(cards+i)]++;
  }
}

void exchange(int*bamb1, int*bamb2, int nfig){
  int i, j;

  for(i=0; i<nfig; i++){
    if(bamb1[i]==0 && bamb2[i]>1){
      for(j=0; j<nfig; j++){
	if(bamb1[j]>1 && bamb2[j]==0){
	  bamb1[i]++;
	  bamb2[i]--;
	  bamb1[j]--;
	  bamb2[j]++;
	}
      }
    }else if(bamb1[i]>1 && bamb2[i]==0){
      for(j=0; j<nfig; j++){
	if(bamb1[j]==0 && bamb2[j]>1){
	  bamb1[i]--;
	  bamb2[i]++;
	  bamb1[j]++;
	  bamb2[j]--;
	}
      }
    }
  }
}
int check(int*bamb, int nfig){
  int i, completo=0;
  for(i=0; i<nfig; i++){
    if(*(bamb+i)!=0){
      completo++;
    }
  }
  if(completo==nfig){
    return 1;
  }else{
    return 0;
  }
}
