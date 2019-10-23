#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define GRAV 9.81

#define THMAX 90

int main() {

  float v0, dist, gitt, theta, thmin=0.01, dtheta=0.05, eps=0.5;

  printf("Simulazione del tiro a bersaglio\n");

  do{

    printf("velocita v0 in m/s: ");
    scanf("%f", &v0);

  } while( v0 <= 0 ); /* assicurare che sia vel positiva */ 

  /* inserimento della distanza inferiore alla gitatta massima */
  do{
    printf("distanza x < %.2f metri: ", v0*v0/GRAV);
    scanf("%f", &dist);
  } while( dist > v0*v0/GRAV || dist <= 0 );


  /* valore iniziale theta prima del ciclo */
  theta = thmin;

  do{

    /* calcolo gittata */
    gitt = 2.*sin(theta)*cos(theta)*(v0*v0)/GRAV;

    /* incrementa theta */
    theta += dtheta;

  } while( fabs(gitt-dist) > eps && theta<THMAX ); /* condizione per colpire bersaglio oppure superare i 90 gradi*/

  theta -= dtheta; /* togliere l'ultimo incremento */

  theta *= 180./M_PI; /* conversione in gradi */

  printf("Tollerenza: %f   Angolo per colpire bersaglio: %.2f gradi\n", eps, theta );

  return 0;
}
