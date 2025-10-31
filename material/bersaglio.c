#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define GRAV 9.81

#define THMAX 90

int main() {

  double v0, dist, gitt, theta, thmin=0.01, dtheta=0.005, eps=0.5;

  printf("Simulazione del tiro a bersaglio\n");

  do{

    printf("velocita v0 in m/s: ");
    scanf("%lf", &v0);

  } while( v0 <= 0 ); /* assicurare che sia vel positiva */ 

  /* inserimento della distanza inferiore alla gitatta massima */
  do{
    printf("distanza x < %.2f metri: ", v0*v0/GRAV);
    scanf("%lf", &dist);
  } while( dist > v0*v0/GRAV || dist <= 0 );

  // distanza minima dal bersaglkio
  double distmin = dist;
  

  /* valore iniziale theta prima del ciclo */
  theta = thmin;
  
  printf("theta\t gittata\n"
	 "=================\n");
  do{

    /* calcolo gittata */
    gitt = 2.*sin(theta)*cos(theta)*(v0*v0)/GRAV;

    // aggiorna distanza minima dal bersaglio
    if( fabs(gitt-dist) < distmin ) distmin =  fabs(gitt-dist);

    /* incrementa theta */
    theta += dtheta;

    printf("%.2f\t %.3f\n", theta, gitt);

  } while( fabs(gitt-dist) > eps && theta<M_PI/2. ); /* condizione per colpire bersaglio oppure superare i 90 gradi*/

  theta -= dtheta; /* togliere l'ultimo incremento */

  theta *= 180./M_PI; /* conversione in gradi */

  printf("=================\n");

  printf("minima |gittata-distanza| = %.3f metri, tolleranza: %.3f metri\n", distmin, eps );
  
  if( fabs(gitt-dist) > eps ) {
    printf("Raggiunto limite di 90 gradi senza soluzione. Aumentare epsilon e/o ridurre passo dtheta\n");
  } else {  
    printf("Tollerenza: %.3f metri   Angolo per colpire bersaglio: %.2f gradi\n", eps, theta );
  }
  
  return 0;
}
