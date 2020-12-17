#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern char* subnew();
extern char* trim();
char* addnew(char a[],char b[]){
     // printf("ADD\n");
     // printf("ADD: a=%s b=%s\n",a,b );
     int px=strlen(a)+strlen(b);
     char* ans = (char*)malloc(px*sizeof(char));
     if((a[0]=='-') && (b[0]!='-')){
          // printf("- +\n");
          // printf("a=%s b=%s d1=%d\n",a,b,strlen(a));
          char newa[strlen(a)-1];
          int j=0;
          // printf("-%d\n",strlen(newa));
          for(j=0; j<strlen(a)-1; j++){
               newa[j]=a[j+1];
          }
          newa[j]='\0';
          // printf("XX %s %s %s\n",newa,a,b);
          strcpy(ans, subnew(b,newa));
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
          strcpy(ans, subnew(a,newb));
          // printf("ans=%s\n",ans);
          return ans;
     }
     else if((a[0]=='-') && (b[0]=='-')){
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
          strcpy(ans,addnew(newa,newb));
          char* finalans= (char*)malloc(px*sizeof(char));
          finalans[0]='-';
          int sizeans=strlen(ans);
          for(j=0; j<sizeans; j++){
               finalans[j+1]=ans[j];
          }
          finalans[j+1]='\0';
          return finalans;
     }


     int sizea=strlen(a);
	int sizeb=strlen(b);
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

     // printf("5=%s\n",newb);
     // printf("5=%d\n",strlen(newb));
     //printf("%s\n",newb);
     /*printf(" ");
     for(i=0; i<newsize; i++){
          printf("%c",newa[i]);
     }
     printf("\n ");
     for(i=0; i<newsize; i++){
          printf("%c",newb[i]);
     }
     printf("\n");*/

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
               // printf("#%c#%c#\n",newa[i],newb[i]);
               int m=newa[i]-'0';
     		int n=newb[i]-'0';
     		// printf("-%d-%d-\n",m,n);
     		sum=(m+n+carry) % 10;
     		carry = (m+n+carry) / 10;
               result[i+1]=(char)(sum+48);
               // printf("|%c|\n",result[i+1]);
          }
          i--;
     }
     if(carry==0)
     {
          // printf("^");
          result[i+1]='0';
          if(result[newsize]=='.'){
               result[newsize]='\0';
          }
          char newresult[newsize+1];
          newresult[newsize]='\0';
          // printf("\n|%s|\n",result);
          for(i=0; i<=newsize; i++){
               newresult[i]=result[i+1];
          }
          // printf("\n|%s|\n",newresult);
          for(i=newsize-1; i>=0; i--){
               // printf("X");
               // printf("%c-",newresult[i]);
               if(newresult[i]!='0'){
                    if(newresult[i]=='.'){
                         // printf("Z");
                         newresult[i]='\0';
                    }
                    else{
                         // printf("Y");
                         newresult[i+1]='\0';
                    }
                    break;
               }
          }
          strcpy(ans, trim(result));
          // printf("==%s\n",ans);
          // printf("ADD_ans=%s\n",ans);
          return ans;
     }
     else{
          result[i+1]='1';
          if(result[newsize]=='.'){
               result[newsize]='\0';
          }
          for(i=newsize; i>=0; i--){
               // printf("X");
               if(result[i]!='0'){
                    if(result[i]=='.'){
                         // printf("Z");
                         result[i]='\0';
                    }
                    else{
                         // printf("Y");
                         result[i+1]='\0';
                    }
                    break;
               }
          }
          strcpy(ans, trim(result));
          // printf("result=%s\n", result);
          // printf("ADD_ans=%s\n",ans);
          return ans;
     }
     // printf("%s\n",result);
}
