#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char* trim(char a[]){
     int size=strlen(a);
     char temp[size];
     bool neg=false;
     if(a[0]=='-'){
          neg=true;
     }
     int i=0;

     int m=0;
     bool isfloat=false;
     for(m=0; m<size; m++){
          if(a[m]=='.'){
               isfloat=true;
               break;
          }
     }
     if(neg==true){
          i=1;
     }
     if(isfloat==true){
          while(a[i]=='0' && i<size){
               i++;
          }
          // printf("i=%d\n", i);
          if(a[i]=='.'){
               a--;
          }
          int j=size-1;
          // printf("j=%d\n", j);
          while(a[j]=='0'){
               j--;
          }
          // printf("j=%d\n", j);
          if(a[j]=='.'){
               j--;
          }
          int c=0;
          // printf("ZZ\n" );
          if(neg==true){
               // printf("XY\n" );
               temp[c++]='-';
          }
          int k=i;
          for(k=i; k<=j; k++){
               // printf("k=%d %c\n", j,a[k]);
               // printf("c=%d\n", c);
               temp[c++]=a[k];

          }
          if(i>j){
               // printf("XX\n" );
               temp[c++]='0';
          }
          temp[c]='\0';
          // printf("temp==%s\n", temp);
          char* finalans=(char*)malloc(size*sizeof(char));
          strcpy(finalans,temp);
          // printf("fial=%s\n", finalans);
          return finalans;
     }
     else{
          while(a[i]=='0' && i<size){
               i++;
          }
          int c=0;
          // printf("ZZ\n" );
          if(neg==true){
               // printf("XY\n" );
               temp[c++]='-';
          }
          int k=i;
          int j=size-1;
          for(k=i; k<=j; k++){
               // printf("k=%d %c\n", j,a[k]);
               // printf("c=%d\n", c);
               temp[c++]=a[k];

          }
          if(i>j){
               // printf("XX\n" );
               temp[c++]='0';
          }
          temp[c]='\0';
          // printf("temp==%s\n", temp);
          char* finalans=(char*)malloc(size*sizeof(char));
          strcpy(finalans,temp);
          // printf("fial=%s\n", finalans);
          return finalans;
     }
}
