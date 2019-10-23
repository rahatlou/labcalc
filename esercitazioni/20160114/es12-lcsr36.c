#include <stdlib.h>
#include <stdio.h> 
#include <time.h>
#include <math.h>

#define MIN 180
#define MAX 220
#define NMAX 7
#define NMIN 4


void packet(int, int, int*, int[], int*);
void update(int[][2], int[], int*);


int main(){
	int fig, c, f;
	srand48(time(0));
	printf("questo programma stima il numero di pacchetti che Paolo e Pietro devono comprare per completare i propri album di figurine\n");

do{
	printf("inserire il numero di figurine contenute in ciascun album tra 180 e 220: ");
	scanf("%d",&fig);
	
	if(fig<MIN || fig>MAX){
		printf("valore errato reinserire: ");
	}
}while(fig<MIN || fig>MAX);

	int paolo[fig][2], pietro[fig][2], g[NMAX];

/*printf("\nPaolo e Pietro possono scambiarsi figurine:\nse SI scrivere 0,\nse NO scrivere un altro numero\n");
	scanf("%d",&t);
	if(t==0){



}else{







}*/
packet(NMIN, NMAX, &fig, g, &f);
update1(paolo, g, &f);



}
void packet(int a, int b, int*fig, int g[], int*f){
*f=lrand48()%(b-a+1)+a;
g[*f];
int i, p, j=-1;
g[0]=lrand48()%(*fig);
for(i=1; i<*f; i++){		
	do{
		g[i]=lrand48()%(*fig);
		p=0;
			for(j=0; j<i; j++){
				p++;}	
	}while(g[i]==g[i-p]);
 }
}
void update(int paolo[][2], int g[], int*f){
int j, i;
for(j=0; j<*f; j++){
i=g[j];
paolo[i-1][0]=i;
}
}
void update(int pietro[][2], int g[], int*f){
int j, i;
for(j=0; j<*f; j++){
i=g[j];
pietro[i-1][0]=i;
}
}
