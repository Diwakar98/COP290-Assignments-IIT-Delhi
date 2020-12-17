#include <stdio.h>
double myFactorial(int n){
     double l=1;
     int i=1;
     for(i=1; i<=n; i++){
          l=l*i;
     }
     return l;
}
