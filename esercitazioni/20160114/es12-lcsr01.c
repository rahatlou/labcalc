#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define figmin 180
#define figmax 220
#define nmin 4
#define nmax 7
void packet(int *,int,int*);
int getint(int, int);
void assegnaval(int*,int,int);
int check (int*,int);
void update(int*,int,int*,int);
void exchange(int*, int*, int, int);
int contadopp(int*,int);

int main(){
  srand48(time(0));
  int fig, scelta,stop,c1,c2,packpietro=0,packpaolo=0,doppietro=0,doppaolo=0,i;
  int pietro[figmax]={0}, paolo[figmax]={0}, figpack[nmax]= {0};
  printf("Simulatore album figurine.\n");
  do{
    printf("Inserire numero di figurine dell album tra 180 e 220:\t");
    scanf("%d", &fig);
  }while(fig<figmin||fig>figmax);
  printf("I bambini possono scambiarsi i doppioni? (si=1,no=0):\t");
  scanf("%d",&scelta);

  do{
    c1= check(pietro,fig);
    if (c1==0) packpietro++;
    c2= check(paolo,fig);
    if (c2==0) packpaolo++;
    packet(figpack,fig,&stop);
    //printf("SHR: dopo packet pietro\n");
    update(pietro,fig,figpack,stop);

    packet(figpack,fig,&stop);
    //printf("SHR: dopo packet paolo\n");
    update(paolo,fig,figpack,stop);
    //exchange(pietro,paolo,fig,scelta);
    
    /* for(i=0;i<fig;i++) */
    /*   { */
    /* 	printf("%d\t", *(pietro+i)); */
    /*   } */
    /* 	printf("\n\n\n"); */
}while(c1==0||c2==0);

  doppietro=contadopp(pietro,fig);
  doppaolo=contadopp(paolo,fig);
  printf("Pack Pietro:\t%d\nDoppioni Pietro:\t%d\nPack Paolo:\t%d\nDoppioni Paolo:\t%d\n",packpietro,doppietro,packpaolo,doppaolo);
    
    
}

int getint(int a, int b)
{
  int c;
  c = lrand48()%(b-a+1) +a;
  if(c==0) printf("SHR: c = 0 in getint!!\n");
  return c;
}
void packet(int *figpack,int fig,int*stop)
{
  /* SHR add j*/
  int j, flag=0;
  int i,a;
  int nfig;
  nfig =getint(nmin, nmax);
  *(stop)=nfig;
  assegnaval(figpack,nmax,figmax);
  for(i=0;i<nfig;i++)
    {
      do{
      a=getint(0, fig-1);
      if(a==0) {
	flag = 1;
	printf("SHR: a = 0 in packet!! \t nfig: %d\n", nfig);
	for(j=0; j<7; j++) {printf("figpack[%d]: %d\t", j, figpack[j]);	}
	printf("\n");
      }

      }while(a==*(figpack)||a==*(figpack+1)||a==*(figpack+2)||a==*(figpack+3)||a==*(figpack+4)||a==*(figpack+5)||a==*(figpack+6)||a==*(figpack+7));
      *(figpack+i)=a;

      
      if(flag==1) printf("SHR: figpack[%d]: %d\t", i, figpack[i]);
    }
  //printf("\n");
}

void assegnaval(int*arr,int len,int val)
{
  int i;
  for(i=0;i<len;i++)
    {
      *(arr+i)=val;
    }
}
      
int check (int*arr,int fig)
{
  int i,c=0;
  for(i=0;i<fig;i++)
    {
      if(*(arr+i)==0) c++;
      //printf("SHR: arr[%d]: %d\n", i, arr[i]);
    }
  if (c==0) return 1;//quando e completo da 1
  else return 0;
}

void update(int* arr,int fig,int*figpack,int stop)
{
  int c,i;
  c=check(arr,fig);
  if (c==0) {
    for(i=0;i<stop;i++)
      {
	*(arr+*(figpack+i))+=1;
	//printf("SHR: figpack[%d]: %d \t arr[%d]: %d\n", i, figpack[i], figpack[i], arr[figpack[i]]);
      }
  }
  else{}
}


void exchange(int *arr1, int *arr2, int fig, int scelta)
{
  int c1, c2, i, j,c=0,p;
  c1=check(arr1,fig);
  c2=check(arr2,fig);
  if(scelta==1&&c1==0&&c2==0){
    for(i=0;i<fig; i++)
      {
	if(*(arr1+i)>1&&*(arr2+i)==0)
	  {
	    p=0;
	    for(j=0;(j<fig&&p==0);j++)
	      {
		if(*(arr2+j)>1&&*(arr1+j)==0)
		  {
		    *(arr1+i)-=1;
		    *(arr2+i)+=1;
		   	      
		    *(arr2+j)-=1;
		    *(arr1+j)+=1;
		    p++;
		  }
	      }
	  }
      }
  }
}

int contadopp(int*arr,int fig)
{
  int i, c=0;
  for(i=0;i<fig;i++)
    {
      if(*(arr+i)>1) 
	{
	  c+=*(arr+i)-1;
	}
    }
  return c;
}
