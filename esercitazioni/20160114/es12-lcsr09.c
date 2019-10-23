#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 180
#define MAX 220

int packet(void);
void update(int *, int);

int check(int *, int); 

int main() {
  int nfig, scelta, i=0, h, q=0, p=0;
  printf("Questo programma stima il numero di pacchetti di figurine necessari a far completare un album a due bambini.\n");
  do {
    printf("Il numero di figurine in ciascun album compreso tra 180 e 220: \n");
    scanf("%d", &nfig);
  }while(nfig<MIN||nfig>MAX);
  int paolo[nfig], pietro[nfig];
  for(i=0;i<nfig;i++) {
    paolo[i]=0;
    pietro[i]=0;
  }
  srand48(time(0));
do{
  printf("Se i due bambini possono scambiarsi i doppioni, si prema 1.\n Altrimenti si prema 2.\n");
  scanf("%d", &scelta);
  }while(scelta!=1&&scelta!=2);
 if(scelta==1){
   /*do{
    update(paolo, nfig);
    update(pietro, nfig);
    }while*/
      }
 else if(scelta==2){
   do{
 update(paolo, nfig);
 q+=1;
 h=check(paolo, nfig);
   }while(h==1);
   do{
 update(pietro, nfig);
 p+=1;
 h=check(pietro, nfig);
   }while(h==1);
   printf("Il numero di pacchetti comprati da Paolo: %d\n Il costo per completare album: %d\n Il numero di pacchetti comprati da Pietro: %d euro.\n Il costo per completare album: %d euro.\n", q, q, p, p);
  }


    
     

}
  int packet(void) {
    return (4+(lrand48()%4));
  }
  
void update(int A[], int nfig) {
    int i=0, z, a;
    a=packet();
    for(i=0;i<a;i++){
      z=(lrand48()%nfig);
    A[z]+=1;
    }
}

int check(int A[], int nfig) {
  int h=0, i=0;
  for(i=0;i<nfig;i++){
    if(A[i]==0){
      h+=1;
    }
  }
  
  if(h==0)
    return 1;
  else
    return 0;
}
  







  


  
