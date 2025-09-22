#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// costanti da usare
#define NZERI 10000
#define BINS 20

void ordina_zeri(double zeri[2]);
double calc_err(double zeri_th[2], double zeri_num[2]);
void solve_quadratic(double c[2], double zeri[2]);
void solve_quadratic_best(double c[2], double zeri[2]);
void updisto(int isto[BINS], double epsilon);

int main() {
    srand48(time(NULL));
    int i;

    // dichiarazione di array. NB: NON SERVE DA NESSUNA PARTE AVERE ARRAY LUNGHI NZERI
    int istoA[BINS] = {0}, istoB[BINS] = {0};
    double zeri_th[2], zeri_num[2], zeri_num_best[2];
    double coef[2];
    double epsilon, epsilon_best;
    
    for(i = 0; i < NZERI; i++) {
      // generare zeri veri secondo la formula fornita
      zeri_th[0] = 1e30 + (drand48() - 0.5) * 1e20;
      zeri_th[1] = 1e-30 + drand48() * 1e20;

      // calcolo coeff equazione secondo grado: b==coef[1], c==coef[0] 
      coef[1] = -(zeri_th[0] + zeri_th[1]);
      coef[0] = zeri_th[0] * zeri_th[1];
      
      // risolvo con i due metodi
      solve_quadratic(coef, zeri_num);
      solve_quadratic_best(coef, zeri_num_best);
        
      // ordinare zeri veri, A e B
      ordina_zeri(zeri_th);       
      ordina_zeri(zeri_num);  
      ordina_zeri(zeri_num_best);
      
      // calcolo errore di A
      epsilon = calc_err(zeri_th, zeri_num);
      updisto(istoA, epsilon);

      // calcolo errore di B
      epsilon_best = calc_err(zeri_th, zeri_num_best);
      updisto(istoB, epsilon_best);
      
      // stamper per i primi 10
      if(i < 10) {
	printf("x1_th: %.15G\t x2_th: %.15G\t eps_A: %.15G\t eps_B: %.15G\n",
	       zeri_th[0], zeri_th[1], epsilon, epsilon_best);
      }
    }
    
    // apertura di file
    FILE *out = fopen("isto.dat", "w");
    
    // scrittura su file
    for(i = 0; i < BINS; i++) {
      fprintf(out, "%d %lf %lf\n", i, istoA[i] / (double) NZERI, istoB[i] / (double) NZERI);
    }
    
    fclose(out);
    
    return 0;
}

// ordinamento elementi di array di lunghezza 2
void ordina_zeri(double zeri[2]) {
  if(zeri[0] > zeri[1]) {
    double tmp = zeri[0];
    zeri[0] = zeri[1];
    zeri[1] = tmp;
  }
}

// calcolo errore relativo
double calc_err(double zeri_th[2], double zeri_num[2]) {
  return fabs((zeri_th[0] - zeri_num[0]) / zeri_th[0]) + fabs((zeri_th[1] - zeri_num[1]) / zeri_th[1]);
}

// metodo A usato comunemente
void solve_quadratic(double c[2], double zeri[2]) {
  double delta = c[1] * c[1] - 4 * c[0];
  zeri[0] = (-c[1] + sqrt(delta)) / 2.0;
  zeri[1] = (-c[1] - sqrt(delta)) / 2.0;
}

// metodo B piu` preciso
void solve_quadratic_best(double c[2], double zeri[2]) {
  double delta = c[1] * c[1] - 4 * c[0];
  if(c[1] >= 0) {
    zeri[0] = -(c[1] + sqrt(delta)) / 2.0;
  } else {
    zeri[0] = (-c[1] + sqrt(delta)) / 2.0;
  }
  
  if(zeri[0] == 0.0) {
    zeri[1] = 0.0;
  } else {
    zeri[1] = c[0] / zeri[0];
  }
}

// aggiorna array di conteggi che costituisce l'istogramma
void updisto(int isto[BINS], double epsilon) {

  int k_bin = (int)(log10(epsilon) + BINS);

  // per eps==0 si ha k<0. escludiamo questi casi
  if(k_bin >= 0 && k_bin < BINS) {
    isto[k_bin]++;
  }
}
