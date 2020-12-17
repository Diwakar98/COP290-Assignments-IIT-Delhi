#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void absolute(char a[]){
     printf("ABSOLUTE\n");
     int size=strlen(a);
     // printf("%s\n",a);
     if(a[0]=='-'){
          size--;
          char result[size+1];
          result[size]='\0';
          int i=0;
          for(i=0; i<size; i++){
               result[i]=a[i+1];
          }
          printf("%s\n",result);
     }
     else{
          printf("%s\n",a);
     }
}
