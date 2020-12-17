#include <stdio.h>
void mySquare(void){
     printf("\n\t\t\t<-------FINDING SQUARE OF A NUMBER----->");
     printf("\nEnter a number: ");
     int a;
     scanf("%d", &a);
     int sqr = a*a;
     printf("The Square of %d",a);
     printf(" is: %d",sqr);
     printf("\n\n");
}
