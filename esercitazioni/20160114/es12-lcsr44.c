#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define len 220

void packet(int []);

void update(int [],int []);

int check(int []);

//void exchange(int [], int[]);

int main() {

  srand48(time(0));
  int n,m,x,i,ch;
  int pietro[len]={0};
  int paolo[len]={0};
  int pack[7]={0};

  printf("Questo programma stima il numero di pacchetti che due bambini devono comprare\n per completare i loro album\n\n");
  printf("Inserire il numero di figurine contenute negli album di paolo e di pietro \n che sia compreso tra 180 e 220\n");  
do{
  scanf("%d %d",&m,&n);
  if(n>220||n<180||m>220||m<180){
    printf("valori errati, ripeti\n");
  }
 }while(n>220||n<180||m>220||m<180);

 printf("I due bambini possono scambiarsi i doppioni? 1 si 0 no\n");
 do{ 
   scanf("%d",&x);
   if(x!=0&&x!=1){
     printf("valore errato, ripeti\n");
   }
 }while(x!=0&&x!=1);

 if(x==0){
   for(i=0;i<m;i++){
     paolo[i]=1;
   }
   for(i=0;i<n;i++){
     pietro[i]=1;
  }
   do{
     packet(pack);
     update(pietro,pack);
     ch=check(pietro);
     }while(ch==0);

    do{
     packet(pack);
     update(paolo,pack);
     ch=check(paolo);
     }while(ch==0);
   
 

 }


 if(x==1){
  for(i=0;i<m;i++){
     paolo[i]=1;
   }
   for(i=0;i<n;i++){
     pietro[i]=1;
 }
 }

 return 0;
}

void packet(int x[7]){
  int y,i,z;
  y=((int)lrand48()/RAND_MAX)*(4)+4;

  for(i=0;i<y;i++){
    z=((int)lrand48()/RAND_MAX)*(220)+1;
    x[z]=1;
  }
}


void update(int album[len],int pack[len]){
  int i;
  
  for(i=0;i<len;i++){
   album[i]=album[i]+pack[i];
    
  }
  
}

 int check(int p[len]){
   int i,x;
   for(i=0;i<len;i++){
     if(p[i]==0){
       x=0;
     }
     else{
       x=1;
     }
   }
   return x;
 }

// void exchange(int pietro[len], int paolo[len]){
