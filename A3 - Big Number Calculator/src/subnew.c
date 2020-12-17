#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern int compare();
char* subnew(char a[],char b[]){
     // printf("SUB\n");
     int sizea=strlen(a);
	int sizeb=strlen(b);
     int compareTo = compare(a,b);
     int decimala=sizea,decimalb=sizeb;
     int i=0,j=0;
     for(i=0; i<sizea; i++){
          if(a[i]=='.'){
               decimala=i;
               break;
          }
     }
     for(i=0; i<sizeb; i++){
          if(b[i]=='.'){
               decimalb=i;
               break;
          }
     }
     int bdA,adA,bdB,adB;
     bdA=decimala;
     bdB=decimalb;
     bool swaped=false;
     if(compareTo<0){
          swaped=true;
          // printf("\nSWAP\n");
          char swap[1000];
          for(i=0; i<sizea; i++){
               swap[i]=a[i];
          }
          swap[i]='\0';
          for(i=0; i<sizeb; i++){
               a[i]=b[i];
          }
          a[i]='\0';
          for(i=0; i<strlen(swap); i++){
               b[i]=swap[i];
          }
          b[i]='\0';
          int k=bdA;
          bdA=bdB;
          bdB=k;
          k=decimala;
          decimala=decimalb;
          decimalb=k;
          k=sizea;
          sizea=sizeb;
          sizeb=k;
          k=bdA;
          bdA=bdB;
          bdB=k;
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
     char newa[newsize];
     char newb[newsize];
     newa[maxbd]='.';
     newb[maxbd]='.';

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
     // printf(" ");
     // for(i=0; i<newsize; i++){
     //      printf("%c",newa[i]);
     // }
     // printf("\n ");
     // for(i=0; i<newsize; i++){
     //      printf("%c",newb[i]);
     // }
     // printf("\n");
     i=newsize-1;
     int sum=0;
     int carry=0;
     char result[newsize+2];
     result[newsize+1]='\0';
     while(i>=0){
          if(newa[i]=='.'){
               result[i+1]='.';
          }
          else{
               int m=newa[i]-'0';
     		int n=newb[i]-'0';
     		//printf("-%d-%d-\n",m,n);
     		sum=(carry+m-n);
               if(sum>=0){
                    carry=0;
               }
               else{
                    sum=sum+10;
                    carry=-1;
               }
               result[i+1]=(char)(sum+48);
          }
          i--;
     }
     if(carry==0)
     result[i+1]='0';
     else
     result[i+1]='1';
     if(result[newsize]=='.'){
          result[newsize]='\0';
     }
     // printf("%s\n",result);
     char * finalans = (char*)malloc(3000000*sizeof(char));
     if(swaped==true){
          finalans[0]='-';
          if(result[0]=='0'){
               for(i=0; i<newsize; i++){
                    finalans[i+1]=result[i+1];
               }
               finalans[i+1]='\0';
          }
          else{
               for(i=0; i<newsize; i++){
                    finalans[i+1]=result[i];
               }
          }
          finalans[i+1]='\0';
     }
     else{
          if(result[0]=='0'){
               for(i=0; i<newsize; i++){
                    finalans[i]=result[i+1];
               }
               finalans[i]='\0';
          }
          else{
               for(i=0; i<newsize; i++){
                    finalans[i]=result[i];
               }
               finalans[i]='\0';
          }
          // finalans=result;
     }

     return finalans;
}
