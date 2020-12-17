#include <stdio.h>
extern void mySquare();
extern int myPythonInC();
extern int myCOP();
extern int mySqrt();
int main(int argc, char *argv[]){
     myCOP();
     mySquare();
     mySqrt();
     myPythonInC(1,argv);
}
