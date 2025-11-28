#include <stdlib.h>
#include <stdio.h>

// stampa elementi array
void printVec(double*, int);

// assegna un valore a tutti gli elementi di un array
//void modVec(double, double*, int);
void modVec(double, double [], int);

int main() {

    double dati[7] = {0};
    printVec(dati, 7);
    modVec( -3., dati, 7);
    printVec(dati, 7);
    
}

void printVec(double* vec, int lun){
    printf("printVec:\n");
    for(int i=0; i<lun; i++){
        printf("%.4f\t", *(vec+i) );
    }
    printf("\n");
}

//void modVec(double val, double* vec, int lun) {
void modVec(double val, double vec[], int lun) {
    printf("modificando il vettore in modVec()\n");
    for(int i=0; i< lun; i++){
        *(vec+i) = val;
    }
}

