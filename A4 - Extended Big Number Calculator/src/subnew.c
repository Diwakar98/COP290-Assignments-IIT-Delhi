#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern int compare();
extern char* addnew();
char* subnew(char a[],char b[]){
     // printf("SUB\n");
     // printf("SUB: a=%s b=%s\n",a,b);
     int px=strlen(a)+strlen(b);
     char* ans = (char*)malloc(px*sizeof(char));
     if((a[0]=='-') && (b[0]!='-')){
          // printf("- +\n");
          // printf("a=%s b=%s d1=%d\n",a,b,strlen(a));
          int sizeb=strlen(b);
          char newb[sizeb+1];
          int j=0;
          newb[0]='-';
          for(j=0; j<sizeb; j++){
               newb[j+1]=b[j];
          }
          newb[j+1]='\0';
          // printf("XX %s %s %s %s\n",newa,a,newb,b);
          strcpy(ans, addnew(newb,a));

          // printf("ans=%s\n",ans);
          return ans;
     }
     else if(((a[0]!='-') && (b[0]=='-'))){
          // printf("+ -\n");
          char newb[strlen(b)-1];
          int j=0;
          for(j=0; j<strlen(b)-1; j++){
               newb[j]=b[j+1];
          }
          newb[j]='\0';
          // printf("YY %s %s\n",a,newb);
          strcpy(ans, addnew(a,newb));
          // printf("ans=%s\n",ans);
          return ans;
     }
     else if((a[0]=='-') && (b[0]=='-')){
          // printf("- -\n" );
          int sizea=strlen(a);
          int sizeb=strlen(b);
          char newa[sizea-1];
          char newb[sizeb-1];
          int j=0;
          for(j=0; j<sizea-1; j++){
               newa[j]=a[j+1];
          }
          newa[j]='\0';
          j=0;
          for(j=0; j<sizeb-1; j++){
               newb[j]=b[j+1];
          }
          newb[j]='\0';
          strcpy(ans,subnew(newb,newa));
          return ans;
     }

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
     char * finalans = (char*)malloc(px*sizeof(char));
     if(swaped==true){
          finalans[0]='-';
          if(result[0]=='0'){
               // printf("APLH\n");
               int px=1;
               while(result[px]=='0'){
                    px++;
               }
               if(result[px]=='.'){
                    px=px-1;
               }
               // int qx=strlen(result)-1;
               // while(result[qx]=='0'){
               //      qx--;
               // }
               // if(result[qx]=='.'){
               //      qx--;
               // }
               int fx=1;
               for(i=px; i<strlen(result); i++){
                    finalans[fx++]=result[i];
               }
               finalans[fx]='\0';
          }
          else{
               // printf("XX\n");
               int px=0;
               while(result[px]=='0'){
                    px++;
               }
               // int qx=strlen(result)-1;
               // while(result[qx]=='0'){
               //      qx--;
               // }
               // if(result[qx]=='.'){
               //      qx--;
               // }
               int fx=1;
               for(i=px; i<strlen(result); i++){
                    finalans[fx++]=result[i];
               }
               finalans[fx]='\0';
          }
     }
     else{
          if(result[0]=='0'){
               // printf("&&=%s\n",result);
               i=0;
               while(result[i]=='0'){
                    i++;
               }
               // printf("qx==%d\n", i);
               if(result[i]=='.'){
                    i=i-1;
               }
               // int qx=strlen(result)-1;
               // // printf("%s\n", result);
               // while(result[qx]=='0'){
               //      // printf("*\n");
               //      qx--;
               // }
               // if(result[qx]=='.'){
               //      qx--;
               // }
               // printf("i=%d\n",strlen(result));

               int k1=0;
               int k2=0;
               for(k1=i; k1<strlen(result); k1++){
                    finalans[k2++]=result[k1];
               }
               finalans[k2]='\0';
               if(strlen(finalans)==0){
                    finalans[0]='0';
                    finalans[1]='\0';
               }
               // printf("final=|%s|\n",finalans);
          }
          else{
               // printf("^^\n");
               // int qx=strlen(result)-1;
               // while(result[qx]=='0'){
               //      qx--;
               // }
               // if(result[qx]=='.'){
               //      qx--;
               // }
               for(i=0; i<strlen(result); i++){
                    finalans[i]=result[i];
               }
               finalans[i]='\0';
          }
          // finalans=result;
     }
     // printf("SUB_ans=%s\n", finalans);
     return finalans;
}
