#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NEXP 10000
#define SIGMA 1.5

int inserimento(int min, int max);
double gauss(double mu, double sigma);

int main() {

    // per la prima parte NS e NB sono fissati
    double Mh = 125.11;
    int NS = inserimento(5, 10);
    int NB = inserimento(50, 100);

    // inizializzazione SEME
    srand48(time(NULL));

    // apertura file
    FILE *file_signal = fopen("segnale.txt", "w");
    FILE *file_bg = fopen("fondo.txt", "w");

    int j;
    double significanza = 0.0; // significanza media su tutti esperiemnti

    // ciclo esperimenti
    for(j = 0; j < NEXP; j++) {

        // ciclo per segnale
        int i;
	int S;
        for(i = 0; i < NS; i++) {
	    S = 0; // azzero per ogni esperimento
            double mass = gauss(Mh, SIGMA);
	    
	    // stampo su file solo per il primo esperimento
            if(j == 0) {
                fprintf(file_signal, "%lf\n", mass);
            }

	    // conteggio evento di segnale nell'intervallo
            if(mass > (Mh - 2.5 * SIGMA) && mass < (Mh + 2.5 * SIGMA)) {
                S++;
            }
        } // ciclo segnale

	// ciclo per il fondo
        int B; 
        for(i = 0; i < NB; i++) {
    	    B  = 0; // azzero per ogni esperimento

            double mass = drand48() * 30 + 110;

	    // scrittura sul file solo per il primo esperimento
	    if(j == 0) {
                fprintf(file_bg, "%lf\n", mass);
            }

	    // calcolo numero eventi di fondo nell'intervallo
            if(mass > (Mh - 2.5 * SIGMA) && mass < (Mh + 2.5 * SIGMA)) {
                B++;
            }
        } // ciclo fondo
        
        double significanza_exp = S / sqrt(B);
        significanza += significanza_exp;
        if(j == 0) {
            printf("significanza primo esperimento: %.2lf\n", significanza_exp);
        }
    } // ciclo esperimenti
    // calcolo valore medio significanza su tutti esperimenti
    significanza /= NEXP;
    
    fclose(file_signal);
    fclose(file_bg);

    printf("significanza media: %.2lf\n", significanza);

    return 0;
}

int inserimento(int min, int max) {
    int res;
    do {
        printf("Inserire un valore compreso tra %d e %d:\n", min, max);
        scanf("%d", &res);
    } while(res < min || res > max);

    return res;
}

double gauss(double mu, double sigma) {
  double y1 = drand48(); // y1 in [0.,1.)
  double y2 = 1.-drand48(); // y2 in (0, 1.]
    
    return sqrt(-2 * log(y2)) * cos(2 * M_PI * y1) * sigma + mu;
}
