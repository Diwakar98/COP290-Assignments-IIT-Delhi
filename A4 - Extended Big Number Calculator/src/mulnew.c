#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern char* addnew();
extern char* trim();
char* mulnew(char a[],char b[]){
      // printf("MUL\n");
     // printf("MUL: a=%s b=%s\n",a,b);
     int px=strlen(a)+strlen(b);
     char* ans = (char*)malloc(px*sizeof(char));
     int sizea=strlen(a);
     int sizeb=strlen(b);
     bool finalsign=true;
     if(a[0]=='-' && b[0]=='-'){
          // printf("- -\n");
          finalsign=true;
          int xx=0;
          for(xx=0; xx<sizea; xx++){
               a[xx]=a[xx+1];
          }
          a[xx]='\0';
          sizea=sizea-1;
          xx=0;
          for(xx=0; xx<sizeb; xx++){
               b[xx]=b[xx+1];
          }
          b[xx]='\0';
          sizeb=sizeb-1;
     }
     else if(a[0]!='-' && b[0]=='-'){
          // printf("+ -\n");
          finalsign=false;
          int xx=0;
          // printf("XX\n");
          for(xx=0; xx<sizeb; xx++){
               // printf("ZZ\n");
               b[xx]=b[xx+1];
          }
          // printf("YY\n");
          b[xx]='\0';
          // printf("YY\n");
          sizeb=sizeb-1;
          // printf("b=%s\n",b);
     }
     else if(a[0]=='-' && b[0]!='-'){
          // printf("- +\n");
          finalsign=false;
          int xx=0;
          for(xx=0; xx<sizea; xx++){
               a[xx]=a[xx+1];
          }
          a[xx]='\0';
          sizea=sizea-1;
     }
     int decimala=sizea,decimalb=sizeb;
     int i=0,j=0,k=0;
     bool isAfloat,isBfloat;
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
     if(decimala==sizea){
          isAfloat=false;
     }
     else{
          isAfloat=true;
     }
     if(decimalb==sizeb){
          isBfloat=false;
     }
     else{
          isBfloat=true;
     }
     // printf("B=%d\n",sizeb);
     // printf("A=%d\n",sizea);
     int bdA,adA,bdB,adB;
     bdA=decimala;
     bdB=decimalb;
     adA=sizea-decimala-1;
     adB=sizeb-decimalb-1;
     if(adA<0)
     {adA = 0;}
     if(adB<0)
     {adB = 0;}
     if(isAfloat==true){
          for(i=decimala; i<sizea; i++){
               a[i]=a[i+1];
          }
          sizea--;
          a[sizea]='\0';
     }
     if(isBfloat==true){
          for(i=decimalb; i<sizeb; i++){
               b[i]=b[i+1];
          }
          sizeb--;
          b[sizeb]='\0';
     }
     char result[sizea+sizeb+4];
     i=0;
     j=0;
     k=0;
     int sum=0;
     int carry=0;
     char temp[sizeb+2];
     char temp1[sizeb+1];
     char* temp2;
     for(j=1; j<=sizea+sizeb+3; j++){
          result[j-1]='0';
     }
     result[sizea+sizeb+3]='\0';
     result[sizea+sizeb+2]='\0';
     for(i=0; i<=sizea-1; i++){
          temp2=(char*)malloc(px*sizeof(char));
          temp[sizeb+1]='\0';
          temp1[sizeb]='\0';
          k=sizea+sizeb+1;
          // printf("|||--%c--|||\n",a[i]);
          sum=0;
          carry=0;
          for(j=sizeb-1; j>=0; j--){
               // printf("|%c|-|%c|\n",a[i],b[j]);
               // printf("|||##%c##|||\n",b[j]);
               int m=a[i]-'0';
               int n=b[j]-'0';
               if((m>=0 && m<=9) && (n>=0 && n<=9)){
                    // printf("**\n");
                    sum=(carry+m*n) % 10;
                    carry = (carry+m*n) /10;
                    temp[j+1]=(char)(sum+48);
                    // printf("j=%d \tSum=%d\t Carry=%d \t temp[j+1]=%c\n",j,sum,carry,temp[j+1]);
               }
          }
          for(j=1; j<=sizea+sizeb+1; j++){
               result[j-1]=result[j];
          }
          result[sizea+sizeb+1]='0';
          temp[0]=(char)(carry+48);
          // printf("result1=%s\n",result);
          // printf("temp=%s\n",temp);
          // temp2=addnew(result,temp);
          strcpy(temp2, addnew(result,temp));


          // printf("temp2=%s\n",temp2);
          for(j=strlen(temp2)-1; j>=0; j--){
               // printf("^^\n");
               result[k--]=temp2[j];
          }
          // printf("result2=%s\n",result);
          free(temp2);
          // printf("temp=%s\n",temp);
     }
     if(isAfloat || isBfloat){
          // printf("Rem\n");
          int adR=adA+adB;
          // printf("%d %d %d\n",adA,adB,adR);
          j=sizea+sizeb+2;
          for(i=0; i<adR; i++){
               result[j]=result[j-1];
               j--;
          }
          result[j]='.';
     }

      // printf("RESULT=%s\n",result);
     ans =result;
     char finalans[strlen(ans)+1];
     i=0;
     while(ans[i]=='0'){
          i++;
     }
     // printf("i=%d\n",i);
     j=0;
     k=0;
     if(finalsign==false){
          finalans[k++]='-';
     }
     for(j=i; j<=strlen(ans); j++){
          finalans[k++]=ans[j];
     }
     finalans[k]='\0';
     // printf("|%d|\n",b)
     char* finalans1=(char*) malloc(px*sizeof(char));
     strcpy(finalans1,trim(finalans));
     // printf("MUL_ans=%s\n", finalans1);
     return finalans1;
}
