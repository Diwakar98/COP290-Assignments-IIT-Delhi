#include <stdlib.h>
#include <stdbool.h>
double myCos(double a){
     int i=2;
     double result=1.0;
     double term=1.0;
     bool f=true;
     for(i=2; i<=100; i=i+2){
          term=term*a*a/((i)*(i-1));
          if(f==true){
               result=result-term;
               f=false;
          }
          else{
               result=result+term;
               f=true;
          }
     }
     return result;
}
