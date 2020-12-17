#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern char* mulnew();
extern char* subnew();
bool iszeropointer(char* x){
     int i=0;
     for(i=0; i<strlen(x); i++){
          if(x[i]!='0'){
               return false;
          }
     }
     return true;
}
char* pownew(char a[], char b[]){
     // printf("POW: a=%s b=%s\n",a,b);
     char* bnew=b;
     int sizea=strlen(a);
     int sizeb=strlen(b);
     int px1=sizea*sizeb;
     char result[px1];
     result[0]='1';
     result[1]='\0';
     char unit[2];
     unit[0]='1';
     unit[1]='\0';
     char c[px1];
     while(!iszeropointer(bnew)){
          int j=0;
          for(j=0; j<strlen(a); j++){
               c[j]=a[j];
          }
          c[j]='\0';
          char* ans=(char*)malloc(px1*sizeof(char));
          strcpy(ans,mulnew(result,c));
          int i=0;
          for(i=0; i<strlen(ans); i++){
               result[i]=ans[i];
          }
          result[i]='\0';
          strcpy(bnew,subnew(bnew,unit));
          free(ans);
     }
     char* finalans = result;
     // printf("POW_ans=%s\n", finalans);
     return finalans;
}
