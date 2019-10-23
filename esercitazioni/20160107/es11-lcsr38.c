#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#define NM 550
#define Nm 330
#define t 100
void gencirc (double, double,double);
void contapepe(double*,double*,int*,int*,int*); 
     int main(){
       int A,B ,C      ;
       double x,y,r;
 float  N,i  ;
  srand48(time(0));  
  printf(" Questo programma simula la posizione dei grani di pepe e calcola il numero di grani caduti nelle mattonelle a,b,c\n");
  do{ 
    printf(" Inserire il numero di grani di pepe caduti compresi tra 330 e 550\n");
    scanf("%f",&N);
    if(N>NM || N<Nm  ){
      printf("ERRORE , il numero di grani inseriti non e' compreso tra 330 e 550\n");
    }}while (N>NM && N<Nm);
 
   for(i=0;i<100;i++){

 


 
  return 0;
   }
   


    void  gencirc(double*x ,double *y,double r     ){
      do{
	r=0.77;
       *y=-r+2*r*lrand48()/RAND_MAX;
       *x=-r+2*r*lrand48()/RAND_MAX;
	return 0;
      }while([(*x)*(*x)]+[(*y)*(*y)]>=r*r)             ;
    
void contapepe(double x , double y,int h , int k ,int l ){
      if(x<0.5 && y<0.5){
	h++;}
      else if(y>0.5 && y<1 && x<0.5){
	k++;}
      else if (y>0.5 && y<1  && x>0.5 && x<1){
	l++;}}
   


      exit(0);
     }
