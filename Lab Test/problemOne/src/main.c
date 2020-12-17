#include <stdio.h>
#include <stdlib.h>
#include "myMath.h"
#include <string.h>
#include <stdbool.h>
#include <math.h>
int main(int argc, char* argv[]){
     printf("Enter: \t1 -> Factorial\n\t2 -> nCr\n\t3 -> sin(x) & cos(x) _ -> Exit\n");
     while(true){
          printf("\n\nEnter choice: ");
          int t=0;
          scanf("%d", &t);
          if(t==1){
               // printf("Enter number: ");
               int n;
               scanf("%d",&n);
               double fact=myFactorial(n);
               printf("%0.0f\n",fact);
          }
          else if(t==2){
               int n,r;
               printf("Enter n: ");
               scanf("%d",&n);
               printf("Enter r: ");
               scanf("%d",&r);
               double ncr=nCr(n,r);
               printf("%0.0f\n",ncr);
          }
          else if(t==3){
               double pi=M_PI;
               double d=2 * pi / 360.0;
               double a=-pi;
               char* commandsForGnuplot[]={
                      "set boxwidth 1",
                      "set xlabel \"(x) ---->\"",
                      "set ylabel \"(function(x)) ---->\"",
                      "set title \"Comparing sin/cos with mySin/myCos over [-pi,pi]\"",
                      "set style fill solid border -1","set style data lines",
                      " plot \"data.txt\" using 2:xtic(1) with lines t \'Time\'",
                      "\" using 3 title \"GCC\" lt rgb \"#403090\"",
                      "set term pngcairo","set output \"./output/graph.png\"",
                      "set terminal png","replot","set output",
              };
              FILE * temp = fopen("data.txt", "w");
              FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
              int i=0;
              for(i=0; i<500; i++){
                   fprintf(temp, "%f %f\n",a,sin(a),mySin(a),cos(a),myCos(a));
                   a=a+d;
              }
              for(i=0; i<10; i++){
                  fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
             }
          }
          else{
               break;
          }
     }
     printf("problemOne successfully compiles and runs\n");
     return 0;
}
