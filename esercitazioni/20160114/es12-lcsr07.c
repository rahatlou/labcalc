#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIG_MAX 220
#define FIG_MIN 180

void packet(int,int*);
void update(int,int*,int*,int*,int);
int check(int,int*,int*,int);
void exchange(int,int*,int*);
int contadoppioni(int,int*,int*,int);

int main()
{
  
  int nfig, scelta,contapackpaolo=0, contapackpietro=0, costototale,doppionipietro, doppionipaolo, paolo[FIG_MAX]={0};
  int pietro[FIG_MAX]={0};
  int figpacket[FIG_MAX];
  double seed;
  seed=time(0);
  srand48(seed);
  printf("\nIl programma stima il numero di pacchetti necessari a due bambini per completare i loro album di figurine.\n");
  do
  {
    printf("\nInserire numero di figurine contenute nell'album (compreso tra %d e %d): ", FIG_MIN, FIG_MAX);
    scanf("%d",&nfig);
    if (nfig < FIG_MIN || nfig > FIG_MAX)
      printf("\nValore inserito non valido");
  } while(nfig<FIG_MIN || nfig>FIG_MAX);

  do
  {
    printf("\n Scegliere tra 0 e 1:\n0) I bambini si scambiano i doppioni\n1) I bambini NON si scambiano i doppioni\n");
    scanf("%d",&scelta);
    if(scelta!=0 && scelta!=1)
      printf("\nValore non valido.");
  } while(scelta!=1 && scelta!=0);

  do
  {
    if(check(nfig,pietro,paolo,0)!=1)
    {
      packet(nfig,figpacket);
      update(nfig,figpacket,pietro,paolo,0);
      contapackpietro+=1;
      
    }
    if(check(nfig,pietro,paolo,1)!=1)
    {
      packet(nfig,figpacket);
      update(nfig,figpacket,pietro,paolo,1);
      contapackpaolo+=1;
    }
    if(scelta==0)
    {
      if(check(nfig,pietro,paolo,0)==0 && check(nfig,pietro,paolo,1)==0)
      {
	exchange(nfig,pietro,paolo);
      }
    }
  }while(check(nfig,pietro,paolo,0)!=1 || check(nfig,pietro,paolo,1)!=1);
  
  costototale=contapackpaolo+contapackpietro;

  doppionipietro=contadoppioni(nfig,pietro,paolo,0);
  doppionipaolo=contadoppioni(nfig,pietro,paolo,1);

  printf("\nPacchetti comprati da Pietro: %d\nPacchetti comprati da Paolo: %d\nCosto totale: %d  euro\nDoppioni rimasti a Pietro: %d \nDoppioni rimasti a Paolo: %d\n",contapackpietro, contapackpaolo, costototale,doppionipietro,doppionipaolo);

  return 0;

}

void packet (int nfig, int figpacket[])
{
  int dpacket,i,typefig;
  for(i=0;i<nfig;i++)
    figpacket[i]=0;
  dpacket=(lrand48()%4)+4;
  for(i=0;i<dpacket;i++)
  {  
    do
    {
      typefig=lrand48()%nfig;    
    }while(figpacket[typefig]!=0);
    figpacket[typefig]=1;
  }
  return;
}

void update(int nfig, int figpacket[], int pietro[], int paolo[], int salbum)  //salbum=0 per pietro, salbum=1 per paolo
{
  int i;
  if(salbum==0)
  {
    for(i=0;i<nfig;i++)
    {
      if(figpacket[i]==1)
	pietro[i]+=1;
    }
  }
  else
  {
    for(i=0;i<nfig;i++)
    {
      if(figpacket[i]==1)
	paolo[i]+=1;
    }
  }
  return;
}

int check(int nfig,int pietro[], int paolo[],int salbum)  //salbum=0 per pietro, salbum=1 per paolo
{
  int cpaolo=1,cpietro=1,i;
  for(i=0;i<nfig;i++)
  {
    if(pietro[i]==0)
      cpietro=0;
    if(paolo[i]==0)
      cpaolo=0;
  }
  if(salbum==0)
    return cpietro;
  if(salbum==1)
    return cpaolo;
  return 2;
}

void exchange(int nfig, int pietro[], int paolo[])
{
  int i,j;
  for(i=0;i<nfig;i++)
  {
    if(pietro[i]==2 && paolo[i]==0)
      for(j=0;j<nfig;j++)
      {
	if(paolo[j]==2 && pietro[j]==0)
	{
	  pietro[i]--;
	  paolo[i]++;
	  paolo[j]--;
	  pietro[j]++;
	  j=nfig;
	}
      }
      
  }
  return;
}

int contadoppioni(int nfig, int pietro[], int paolo[], int salbum)       //salbum=0 per pietro, salbum=1 per paolo
{
  int i, contatore=0;
  if(salbum==0)
  {
    for(i=0;i<nfig;i++)
      if (pietro[i]>=2)
	contatore++;
  }
  else if(salbum==1)
  {
    for(i=0;i<nfig;i++)
      if(paolo[i]>=2)
	contatore++;
  }
  return contatore;
}
