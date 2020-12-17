#include <stdlib.h>
#include <stdbool.h>
double mySin(double a){
     int i=3;
     double result=a;
     double term=a;
     bool f=true;
     for(i=3; i<=100; i=i+2){
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
