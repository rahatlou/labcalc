#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define GRAV 9.81

#define THMAX 90

int main() {

  float v0, theta, dist, gitt, alt;

  printf("Simulazione del moto del proiettile con vel v0 ed angolo theta\n");


  do{

    printf("velocita v0 in m/s: ");
    scanf("%f", &v0);

  } while( v0 <= 0 ); /* assicurare che sia vel positiva */ 


  do{

    printf("angolo theta (0,%d) gradi: ", THMAX);
    scanf("%f", &theta);

  } while( theta <=0 || theta >= THMAX ); /* solo 0 < theta < 90 gradi */


  /* convertire da gradi in radianti */
  theta *= M_PI/180.;

  /* calcolo gittata */
  gitt = 2.*sin(theta)*cos(theta)*(v0*v0)/GRAV;
  printf("gittata masima: %.2f metri\n", gitt);


  printf("distanza x (metri) per calcolo altezza del proiettile: ");
  scanf("%f", &dist);

  /* controlla distanza vs. gittata */
  if( dist > gitt ) {

    printf("distanza  superiore alla gittata massima. cade per terra dopo %.2f metri\n", gitt);
    exit(-1);

  }

  /* calcolo altezza */
  alt = dist*tan(theta) - 0.5*GRAV*(dist*dist)/( v0*v0*cos(theta)*cos(theta) );

  printf("distanza: %.2f metri   altezza: %.2f metri\n", dist, alt );


}
