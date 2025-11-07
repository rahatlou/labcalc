    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>

    #define EPSMIN  1e-6
    #define EPSMAX  0.1

    /* calcolo della radice quadrata con il metodo babilonese */

    int main() {

      double eps; /* precisione. chiedere all'utente o fissare */
      double delta; /* differenza con risultato di sqrt */

      double rold, rnew;
      double yold, ynew;

      double diff; // differenza tra old e new
        
      double a; /* di cui calcolare la radice. chiedere con scanf */

      int i, niter=0;


      printf("Calcolo radice quadrata di a con precisione eps.\n");

      /* acquisire eps */
      do{
        printf("Precisione eps in [%lf,%lf]: ", EPSMIN, EPSMAX);
        scanf("%lf", &eps);
      }while( eps<EPSMIN || eps>EPSMAX);


      do{
        printf("Numero di cui calcolare la radice a>0 : ");
        scanf("%lf", &a);
      } while(a<0);

      /* caso banale non richiede calcolo */
      if(a==0.) {
        printf("sqrt(0) = 0. non sevono conti!\n");
        exit(0);
      }

      /* il primo termine della successione */
      do{
        printf("Primo termine della successione r0!=0: ");
        scanf("%lf", &rnew);
      } while(rnew==0);

 
      /* Metodo babilonese */
      printf("Metodo babilonese\n");
      printf("#iter\t rn\n");
      do {
        niter++;
        rold = rnew;
        rnew = 0.5*(rnew + a/rnew);
        diff = rold - rnew;
        printf("%3d\t  %.10lf\n", niter, rnew);
      } while( fabs(diff) > eps );
        
      delta = fabs(rnew - sqrt(a));
      
      printf("Stima radice quadrata di %lf: %.10lf \n", a, rnew);
      printf("Numero totale di iterazioni: %3d \n", niter);
      printf("|rn - sqrt(a)|: %.5g \n", delta);
        
      //printf("stima r2: %lf\n", rnew);
        

      // =================  terza parte =======================
      
      /* Metodo alternativo */
      printf("Metodo alternativo\n");
        
      /* prima successione con 2 iterazioni */
      rnew = 2517; //scegliere il valore di r0
      
      /* Metodo babilonese con 2 iterazioni */
      for(i=0; i<2; i++) {
        rnew = 0.5*(rnew + a/rnew);
      }
        
      /* inizializza primo termine di yn */
      yold  = 1/rnew;
     
      /* azzera contatore */
      niter = 0;

      printf("#iter\t 1/yn\n");

      do {
        niter++;
        ynew = 1.5*yold - a*yold*yold*yold/2.;
        diff =  1/ynew - 1/yold;
        printf("%3d\t %.10lf\n", niter, 1/ynew);

        yold = ynew;
     
      } while( fabs(diff) > eps );
        
      rnew = 1/ynew; //calcolo della nuova radice
        
      /* differenza tra ynew e sqrt(a) */
      delta = rnew - sqrt(a);
    
      printf("Stima radice quadrata di %lf: %.10lf \n", a, rnew);
      printf("Numero totale di iterazioni: %3d \n", niter);
      printf("|1/yn - sqrt(a)| = %.5g \n", delta);

    }
