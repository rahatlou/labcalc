#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NMAX 220
#define NMIN 180
#define FMAX 7
#define FMIN 4

int getint(int, int);
int uniforme(int, int);
void packet(int, int*);
int doppioni(int*, int);
void update(int*, int*);
void exchange(int*, int*, int);
int check(int*, int);
void azzera(int*,int);
int contadoppioni(int*, int);



int main(){
	int N, scelta, paolo[NMAX]={0}, pietro[NMAX]={0}, pacchetto[FMAX]={0}, npa=0, npi=0, dpi=0,dpa=0 ;
	srand48(time(0));
	printf("Questo programma simula il riempimento di un album di figurine\n");
	printf("Inserire il numero di figurine necessarie a completare l'album: ");
	N=getint(NMIN, NMAX);
	printf("Inserire 0 per permettere lo scambio dei doppioni oppure 1 per non permetterlo: ");
	scelta=getint(0,1);
	
	do{	
		
		if(check(pietro, N)==0){
			packet(N, pacchetto);
			npi++;
			/*for(i=0; i<FMAX; i++){
				printf("pacchetto[%d]=%d\n", i, pacchetto[i]);
			}*/
			update(pacchetto, pietro);
		
		}
		if(check(paolo, N)==0){
			packet(N, pacchetto);
			npa++;
			/*for(i=0; i<FMAX; i++){
				printf("pacchetto[%d]=%d\n", i, pacchetto[i]);
			}*/
			update(pacchetto, paolo);
		
		}
		/*for(i=0; i<N+1; i++){
			printf("pietro[%d]=%d\n", i, pietro[i]);
			}
		for(i=0; i<N+1; i++){
			printf("paolo[%d]=%d\n", i, paolo[i]);
			}*/	

		if(check(pietro, N)==0 && check(paolo, N)==0 && scelta==0) 
			exchange(pietro, paolo, N);

	}while(check(pietro, N)==0 || check(paolo, N)==0);
	
	printf("Numero pacchetti comprati da pietro:%d\tNumero pacchetti compati da paolo:%d\nNumero totale pacchetti:%d\n",npi, npa, npa+npi );
	dpi=contadoppioni(pietro, N);
	dpa=contadoppioni(paolo, N);
	printf("Numero doppioni rimasti a pietro:%d\tNumero doppioni rimasti a paolo:%d\nNumero totale doppioni:%d\n",dpi, dpa, dpa+dpi );

return 0;
}

int getint(int a,int b){
	int n;
	do{
		scanf("%d", &n);
		if(n<a || n>b)
			printf("Valore non valido! Inserire un valore tra %d e %d: ",a,b);

	}while(n<a || n>b);
	return n;
}

int uniforme(int a, int b){
	return (lrand48()%(b-a+1))+a;
}

void packet(int N, int pacchetto[FMAX]){
	int n,i;
	azzera(pacchetto, FMAX);
	n=uniforme(FMIN, FMAX);
	//printf("n=%d\n", n);
	for(i=0; i<n; i++){
		do{
			*(pacchetto+i)=uniforme(1, N);
			//printf("numero figurina: %d\n",*(pacchetto+i));
		}while(doppioni(pacchetto, i)==1);
	}
}



int doppioni(int*elenco, int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=i+1; j<=n; j++){
			if(*(elenco+i)==*(elenco+j)) return 1;
		}
	}
	return 0;
}

void update(int pacchetto[FMAX], int bambino[NMAX]){
	int i;
	for(i=0; i<FMAX; i++){
		if(*(pacchetto+i)!=0)
			(*(bambino+ *(pacchetto+i)))++;
	}
}

void exchange(int pietro[NMAX], int paolo[NMAX], int N){
	int i;
	for(i=1; i<=N; i++){
		if(*(pietro+i)==0 && *(paolo+i)>1){
			(*(pietro+i))++;
			(*(paolo+i))--;
		}else if(*(paolo+i)==0 && *(pietro+i)>1){
			(*(pietro+i))--;
			(*(paolo+i))++;
		}
	}
}

int check(int bambino[NMAX], int N){
	int i;
	for(i=1; i<=N; i++){
		if(*(bambino+i)==0) return 0;
	}
	return 1;
}		

void azzera(int*array, int N){
	int i;
	for(i=0; i<N; i++){
		*(array+i)=0;
	}
}

int contadoppioni(int bambino[NMAX], int N){
	int i, somma=0;
	for(i=1; i<=N; i++){
		somma += *(bambino+i);
	}
	somma=somma-N;
	return somma;
}








