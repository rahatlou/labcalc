#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NMC 100000

double FN (double nutot,  int N);
double FP (double nub,  int N);
double poisson(int N, double mu);
double fattoriale(int N);
void findBestTime(double nub,double nutot,double *tbest, int* Nbest);

int main(){
	double nub0,nut0;
	double tbest;
	int Nbest;

        srand48( time(0) );

        do{
          printf("frequenza del solo fondo (valore positivo) :");
          scanf("%lf", &nub0);
        } while(nub0 <= 0.);

        do{
          printf("frequenza in presenza del segnale (>%.2lf) :", nub0);
          scanf("%lf", &nut0);
        } while(nut0 <= nub0 );

	findBestTime(nub0,nut0,&tbest, &Nbest);
	printf("best time: %.2lf (secondi)\t with count: %2d\n",tbest,Nbest);


        return 0;
}

void findBestTime(double nub,double nutot,double *tbest, int* Nbest){
	double t,chi2, chi2best=1E12;
	int N,i;
 
        for(i=0; i< NMC; i++) {
          t = 20.*lrand48()/RAND_MAX;
          N = 1 + lrand48()%20;
          chi2 = pow( FP(nub*t, N)-0.01, 2 ) + pow( FN(nutot*t, N)-0.05, 2);
          if(chi2<chi2best) {
            chi2best=chi2;
            *tbest=t;
            *Nbest=N;
          }

        }
}


double FP (double mub, int N){
	double res=0;
	int i;
	for (i=0; i<N; i++) res+=poisson(i,mub);
	return 1-res;
}

double FN (double mutot,  int N){
	double res=0;
	int i;
	for (i=0; i<N; i++) res+=poisson(i,mutot);
	return res;
}

double poisson(int N, double mu){
	return exp(-mu)*pow(mu,N)/fattoriale(N);
}

double fattoriale (int N){
	if(N<=1)return 1;
	double f=1;
	int i;
	for (i=2; i<=N; i++) f*=i;
        return f;
}

