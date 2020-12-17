#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int compare(char a[], char b[]){
     // printf("---COMPARE---\n");
     // printf("a=%s\n", a);
     // printf("b=%s\n", b);
     // printf("---COMPARE---\n");
     int sizea = strlen(a);
     int sizeb = strlen(b);

     if(a[0]=='-' && b[0]=='-'){
          char newa[sizea-1];
          char newb[sizeb-1];
          int px=0;
          for(px=1; px<sizea; px++){
               newa[px-1]=a[px];
          }
          newa[px-1]='\0';
          px=0;
          for(px=1; px<sizeb; px++){
               newb[px-1]=b[px];
          }
          newb[px-1]='\0';
          return compare(newb,newa);
     }
     else if(a[0]!='-' && b[0]=='-'){
          return 1;
     }
     else if(a[0]=='-' && b[0]!='-'){
          return -1;
     }

     int decimala=sizea,decimalb=sizeb;
     bool isafloat=false;
     bool isbfloat=false;
     int i=0,j=0;
     for(i=0; i<sizea; i++){
          if(a[i]=='.'){
               isafloat=true;
               decimala=i;
               break;
          }
     }
     for(i=0; i<sizeb; i++){
          if(b[i]=='.'){
               isbfloat=true;
               decimalb=i;
               break;
          }
     }
     int bdA,adA,bdB,adB;
     bdA=decimala;
     bdB=decimalb;
     if(bdA > bdB){
          return 1;
     }
     else if(bdB > bdA){
          return -1;
     }
     adA=sizea-decimala-1;
     adB=sizeb-decimalb-1;
     int maxbd=0,maxad=0;
     if(bdA>=bdB){
          maxbd=bdA;
     }
     else{
          maxbd=bdB;
     }
     if(adA>=adB){
          maxad=adA;
     }
     else{
          maxad=adB;
     }
     int newsize=maxbd+maxad+2;
     //printf("SIZE=%d\n",newsize);
     char newa[newsize];
     char newb[newsize];

     newa[maxbd]='.';
     newb[maxbd]='.';
     newa[newsize]='\0';
     newb[newsize]='\0';
     // printf("1=%s\n",newb);
     // printf("1=%d\n",strlen(newb));
     int p1=maxbd+1;
     int temp1=decimala+1;
     for(p1=maxbd+1; p1<maxbd+1+adA; p1++){        // .A
          newa[p1]=a[temp1++];
     }
     while(p1<newsize){
          newa[p1++]='0';
     }
     p1=maxbd+1;
     temp1=decimalb+1;
     for(p1=maxbd+1; p1<maxbd+1+adB; p1++){        //.B
          newb[p1]=b[temp1++];
     }
     while(p1<newsize){
          newb[p1++]='0';
     }
     p1=maxbd-1;
     temp1=decimala-1;
     while(temp1>=0){                        //A.
          newa[p1]=a[temp1];
          temp1--;
          p1--;
     }
     while(p1>=0){
          newa[p1--]='0';
     }
     p1=maxbd-1;
     temp1=decimalb-1;
     while(temp1>=0){
          newb[p1]=b[temp1];
          temp1--;
          p1--;
     }
     while(p1>=0){                           //B.
          newb[p1--]='0';
     }
     for(i=0; i<newsize; i++){
          if(newa[i]!='.' || newb[i]!='.'){
               if(newa[i]>newb[i]){
                    return 1;
               }
               else if(newb[i] > newa[i]){
                    return -1;
               }
          }
     }

     return 0;;
}
