#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
char* absolute(char a[]){
     int size=strlen(a);
     if(a[0]=='-'){
          size--;
          char result[size+1];
          result[size]='\0';
          int i=0;
          for(i=0; i<size; i++){
               result[i]=a[i+1];
          }
          char* finalans=result;
          return finalans;
     }
     else{
          char* finalans=a;
          return finalans;
     }
}
