#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
     int a=fork();
     if(a==0){
          char *c[]={"./SHELL",NULL};
          execvp(c[0],c);
          return 0;
     }
     else{
          wait(NULL);
     }
     return 0;
}
