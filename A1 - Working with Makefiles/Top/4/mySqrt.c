#include <stdio.h>
int mySqrt() {
    int i;
    float a,x,y,b;
    printf("\n\t\t<-------FINDING SQUARE ROOT USING NEWTON'S METHOD------->");
    printf("\n\nEnter a positive number: ");
    scanf("%f", &a);
    b=a;
    x=a/2+1;
    y=0;
    for (i = 1; i <=20; ++i) {
         y=(x+a/x)/2;
         if((x-y<=0.001 && x-y>=0) || (y-x<=0.001 && y-x>=0))
         {
              break;
         }
         x=y;
    }
    printf("The Square Root of %f",b);
    printf(" is = %f", y);
    printf("\n\n");
    return 0;
}
