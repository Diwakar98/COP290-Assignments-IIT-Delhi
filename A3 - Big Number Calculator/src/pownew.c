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
     char* bnew=b;
     int sizea=strlen(a);
     int sizeb=strlen(b);
     char result[3000000];
     result[0]='1';
     result[1]='\0';
     char unit[2];
     unit[0]='1';
     unit[1]='\0';
     char c[3000000];
     while(!iszeropointer(bnew)){
          int j=0;
          for(j=0; j<strlen(a); j++){
               c[j]=a[j];
          }
          c[j]='\0';
          char* ans=(char*)malloc(3000000*sizeof(char));
          // bnew = (char*)malloc(3000000*sizeof(char));
          // printf("XX\n");
          // printf("a=%s  b=%s\n",result,c);
          strcpy(ans,mulnew(result,c));
          // printf("\tAns=%s\n",ans);
          int i=0;
          for(i=0; i<strlen(ans); i++){
               result[i]=ans[i];
          }
          // printf("XX1\n");
          result[i]='\0';
          // printf("XX2\n");
          strcpy(bnew,subnew(bnew,unit));
          // printf("XX3\n");
          free(ans);
          // printf("XX4\n");
     }
     // printf("%s\n",result);
     char* finalans = result;
     return finalans;
     //
}
