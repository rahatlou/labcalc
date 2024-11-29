#include <stdlib.h>
#include <stdio.h>
#include<math.h>

// stampa elementi array 2D
// bisogna specificare dimensione e lunghezza max di array
void printMat(double [7][4], int, int);

// assegna un valore a tutti gli elementi di un array
void assegna(double, double [7][4], int, int);


int main() {

    double mat[7][4] = {0};
    printMat(mat, 7, 4);
    assegna( 3.14, mat, 7, 4);
    printMat(mat, 7, 4);
    
}

void printMat(double m[7][4], int righe, int col){
    printf("printMat:\n");
    for(int i=0; i<righe; i++){
        for(int j=0; j<col; j++) {
            printf("%.4f\t", m[i][j] );
        }
    printf("\n");
    }   

}

void assegna(double val, double m[7][4], int nr, int nc) {
    printf("modificando valori matrice in assegna()\n");
    for(int i=0; i< nr; i++){
        for(int j=0; j<nc; j++){
            *(*(m+i)+j) = val;
        }
    }
}
