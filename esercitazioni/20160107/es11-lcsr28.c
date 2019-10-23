#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100



int main(){

  int N=0, i, graniA=0, graniB=0, graniC=0, b, c;
  float x , y,Amed=0, Bmed=0, Cmed=0, K, Q;
  int A[MAX]; int  B[MAX]; int C[MAX];
    srand48(time(0));


    for(b=0;b<N;b++){
      A[b]=0;
      B[b]=0;
      C[b]=0;
    }
 
  

    printf("Il programma simula la posizione casuale di punti materiali in 3 quadrati di lato 0.5m\n");
    printf("Inserire numero di grani caduti compreso tra 330 e 550:\t");
           do{
              scanf("%d", &N);
	      if(N<330 || N>550){
		printf("\nErrore . Inserire numero tra 330 e 550\n");
	      }
	   } while(N<330 || N>550);
	   
	   for(c=0;c<MAX;c++){
	     Amed+=graniA;
	     Bmed+=graniB;
	     Cmed+=graniC;

	       graniA=0;
	       graniB=0;
	       graniC=0;
                         

	       for(i=0;i<N;i++){
	       
	       do{
		 K=(float)lrand48()/RAND_MAX;
	       }while(K>0.77);
		 do{
	       Q=(float)lrand48()/RAND_MAX;
		 }while(Q>0.77);

		   x=Q;
		   y=K;
	                 

			      /* printf("%f %f", x,y);*/
			      
			      if(x>0.5 && y>0.5){
				graniC++;
				/*  printf("Il grano di pepe e caduto nella mattonella C\n");*/
			      }
			    
			      if(x<0.5 && y<0.5){
				 graniA++;
				 /*( printf("Il grano di pepe e caduto nella mattonella A\n"); */
			      }

			      if(x<0.5 && y>0.5){
				graniB++;
				/*printf("Il grano di pepe e caduto nella mattonella B\n");*/
			      }
		  A[c]=graniA;
		  B[c]=graniB;
		  C[c]=graniC;

	   
	     }
	    
	     printf("%d:\t%d, %d, %d\n",c, A[c], B[c], C[c]);

	   }			
	     Amed=Amed/100;
	     Bmed=Bmed/100;
	     Cmed=Cmed/100;		      
	   printf("media a:%f,media b: %f,media c: %f", Amed,Bmed, Cmed);
	   
	   exit(-1);

	   
}

