#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define L 0.5
#define RISPY 100 
#define RAGG 0.77
#define PEPMIN 330 
#define PEPMAX 550


void genCirc(float*, float*, float, float);
void contaPepe(float*, float*, int, int*, int*, int*);
void media(int[], int[], int[], float*, float*, float*);

int main(){
int N, A, B, C, j; 
float x, y, NA, NB, NC;
int MA[RISPY], MB[RISPY], MC[RISPY];

srand48(time(0));

printf("questo programma simula la caduta di grani di pepe a terra e la loro disposizione casuale su un sistema di riferimento cartesiano x;y\nInserire numero di granelli di pepe caduto tra 330 e 550: ");


do{
	scanf("%d",&N);
		if(N < PEPMIN || N > PEPMAX){
			printf("valore errato, reinserire un valore tra 330 e 550!! : ");
		}
}while(N < PEPMIN || N > PEPMAX);

for(j=0; j<RISPY; j++){
	contaPepe(&x, &y, N, &A, &B, &C);
		MA[j]=A;
		MB[j]=B;
		MC[j]=C;
printf("MA[%d]=%d   MB[%d]=%d   MC[%d]=%d\n", j, A, j, B, j, C);
}		

	media(&MA[RISPY], &MB[RISPY], &MC[RISPY], &NA, &NB, &NC);
		printf("Valore medio di grani di pepe nella mattonella A: %f\nValore medio di grani di pepe nella mattonella B: %f\nValore medio di grani di pepe nella mattonella C: %f\n", NA, NB, NC);
}




void genCirc(float* x, float* y, float a, float b){

	*x = ((float)lrand48()/RAND_MAX)*(b-a)+a;
	*y = ((float)lrand48()/RAND_MAX)*(b-a)+a;

}

void contaPepe(float*x, float*y, int N, int*A, int*B, int*C){
	int i;
	*A=0;
	*B=0;
	*C=0;
	for(i=0; i<N; i++){
		genCirc(x, y, -RAGG, RAGG);
		if(*x>0 && *x<L && *y>0 && *y<L){
			*A=*A+1;
		}else if(*x>0 && *x<L && *y>L && *y<2*L){
			*B=*B+1;
		}else if(*x>L && *x<2*L && *y>L && *y<2*L){
			*C=*C+1;
		}

	}
}
void media(int MA[RISPY], int MB[RISPY], int MC[RISPY], float*NA, float*NB, float*NC){
	float totA=0, totB=0, totC=0;
	int i;

for(i=0; i<RISPY; i++){
	totA += MA[i];
	totB += MB[i];
	totC += MC[i];
}
 
*NA=(float)totA/RISPY;
*NB=(float)totB/RISPY;
*NC=(float)totC/RISPY;
}


































