#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NMIN 330
#define NMAX 550
#define RAGGIO 0.77
#define XA 0.5
#define YA 0.5
#define XC 1.0
#define YC 1.0
#define REP 100


int getint(int , int);
void genCirc(float*, float*);
float uniforme(float, float);
void contaPepe(float, float, int*, int*, int*);
float media(int*);
float perc(float, int);

int main(){
	int N, A[REP]={0}, B[REP]={0}, C[REP]={0}, i, j;
	float x, y, NA, NB, NC;
	srand48(time(0));

	printf("Questo programma simula la caduta di N grani di pepe in un cerchio di raggio %.2f\n", RAGGIO);
	printf("Inserire il numero di grani di pepe tra %d e %d ", NMIN, NMAX);
	N=getint(NMIN, NMAX);

	for(j=0; j<REP; j++){
		for(i=0; i<N; i++){			
			genCirc(&x, &y);
			//printf("x=%f\ty=%f\n",x,y);
			contaPepe(x, y, &A[j], &B[j], &C[j]);
			
		}
		//printf("A[%d]=%d\tB[%d]=%d\tC[%d]=%d\n",j,A[j],j,B[j],j,C[j]);
	}
	
	NA=media(A);
	NB=media(B);
	NC=media(C);
	printf("\t ___ ___\n%.1f\t|   |   |\n \t| B | C |\n \t|___|___|\n%.1f\t|   |\n \t| A |\n\t|___|\n0\t   %.1f  %.1f\n\n",YC, YA,XA,XC);
	
	printf("Media di grani caduti su:\n\tA:%.2f (=%.2f%%)\n\tB:%.2f (=%.2f%%)\n\tC:%.2f (=%.2f%%)\n",NA,perc(NA, N), NB,perc(NB,N), NC,perc(NC, N));

	return 0;
}


//chiede un intero all'utente tra a e b
int getint(int a , int b){
	int n;	
	do{
		scanf("%d", &n);
		if(n<a||n>b){
			printf("Valore non valido!\n");
			printf("Inserire un valore tra %d e %d ", a, b);
		}
	}while(n<a||n>b);
	return n;
}
//genera numeri casuali tra a e b
float uniforme(float a, float b){
	return a+(b-a)*(float)(lrand48())/RAND_MAX;
}

//genera casualmente punti in un cerchio
void genCirc(float*x, float*y){
	do{
		*x=uniforme( -RAGGIO,RAGGIO);
		*y=uniforme( -RAGGIO,RAGGIO);
	}while( (*x)*(*x)+ (*y)*(*y) > RAGGIO*RAGGIO);
}

//conta i numeri di grani caduti in ciascuna mattonella
void contaPepe(float x, float y, int* A, int* B, int* C){
	if(x<XA && x>0 && y<YA && y>0)
		(*A)++;
	if(x<XA && x>0 && y>YA && y<YC)
		(*B)++;
	if(x<XC && x>XA && y>YA && y<YC)
		(*C)++;
}

//calcola la media di grani caduti in ogni mattonella
float media(int Grani[REP]){
	int i, s=0;
	for(i=0; i<REP; i++){
		s+=*(Grani+i);
	}
	return (float)s/REP;
}

//calcola la percentuale media di grani in ogni mattonella
 float perc(float media, int N){
	return (media/N)*100;
}












