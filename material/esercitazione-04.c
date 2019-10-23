#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPSMIN  0.000001
#define EPSMAX  0.1


/* calcolo della radice quadrata con il metodo babilonese */

int main() {

  double eps; /* precisione. chiedere all'utente o fissare */
  double delta; /* differenza con risultato di sqrt */

  double rnew;
  double yold, ynew, diff;

  double a; /* di cui calcolare la radice. chiedere con scanf */

  int i, niter=0;


  printf("calcolo radice quadrata di a con precisione eps\n");

  /* acquisire eps */
  do{
    printf("Precisione eps in [%lf,%lf]: ", EPSMIN, EPSMAX);
    scanf("%lf", &eps);
  }while( eps<EPSMIN || eps>EPSMAX);


  do{
    printf("a>0 : ");
    scanf("%lf", &a);
  } while(a<0);

  /* caso banale non richiede calcolo */
  if(a==0.) {
    printf("sqrt(0) = 0. non sevono conti!\n");
    exit(0);
  }

  /* il primo termine della successione */
  printf("inserisci il primo termine della successione r0: ");
  scanf("%lf", &rnew);


  /* prima successione con 2 iterazioni */
  for(i=0; i<2; i++) {
    rnew = 0.5*(rnew + a/rnew);
  }

  printf("stima r2: %lf\n", rnew);

  /* inizializza primo termine di yn */
  yold  = 1/rnew;
 
  /* azzera contatore */
  niter = 0;
  do {
    niter++;
    ynew = 1.5*yold - a*yold*yold*yold/2.;
    diff = 1/yold - 1/ynew; 
    printf("niter: %3d   stima:%4.20lf\n", niter, 1/ynew); 

    yold = ynew;
 
  } while( fabs(diff) > eps );

  /* differenza tra ynew e sqrt(a) */
  delta = 1/ynew - sqrt(a);

  printf("ynew-sqrt(a) = %2.2E\n", delta);

}
