#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern char* subnew();
extern char* addnew();
extern bool compare();
char* divnew(char a[],char b[]){
     // printf("DIV\n");
     // printf("a=%s\n",a);
     // printf("b=%s\n",b);
     char* finalans="";
     return finalans;
     int sizea=strlen(a);
     int sizeb=strlen(b);
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
     int bdA,adA,bdB,adB;
     bdA=decimala;
     bdB=decimalb;
     adA=sizea-decimala-1;
     adB=sizeb-decimalb-1;
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
     // printf("sizea=%d\n",sizea);
     // printf("sizeb=%d\n",sizeb);
     char newa[sizea+20];
     i=0;
     j=0;
     k=0;
     int sum=0;
     int carry=0;
     char temp[sizeb+2];
     char temp1[sizeb+1];
     char* temp2;
     i=0;
     char rem[sizeb];
     char quo[sizea+20];
     // printf("a==|%s|\n",a);
     for(i=sizea; i<sizea+20; i++){
          a[i]='0';
     }
     a[i]='\0';
     // printf("a==|%s|\n",a);
     for(i=0; i<sizea+20; i++){
          quo[i]='0';
     }
     quo[i]='\0';
     for(i=0; i<sizeb; i++){
          rem[i]='0';
     }
     rem[i]='\0';
     // printf("quo==|%s|\n",quo);
     // printf("rem==|%s|\n",rem);
     sizea=sizea+20;

     int p=0;
     int q=0;
     int quocounter=0;

     // printf("A=%s\n",a);
     // printf("B=%s\n",b);
     char temp3[sizeb+1];
     k=0;
     for(q=0; q<sizeb; q++){
          temp3[k++]=a[q];
     }
     temp3[k]='\0';
     // printf("temp3=%s\n",temp3);
     q=0;
     int j1=0;
     char c[3000000];
     for(j1=0; j1<strlen(b); j1++){
          c[j1]=b[j1];
     }
     c[j1]='\0';
     for(p=sizeb; p<sizea; p++){
          k=0;

          char* temp4 = (char*)malloc(3000000*sizeof(char));
          while(temp3[0]!='-'){
               // printf("X %s %s \n",c,temp3);
               strcpy(temp4,subnew(temp3,c));
               int m = quo[quocounter]-'0';
               quo[quocounter]= (char)(m+49);
               int n=0;
               for(n=0; n<strlen(temp4); n++){
                    temp3[n]=temp4[n];
               }
               temp3[n]='\0';
               // printf("=%s\n",temp3);
               // printf("Q=%c\n",quo[quocounter]);
          }
          j1=0;
          for(j1=0; j1<strlen(b); j1++){
               c[j1]=b[j1];
          }
          c[j1]='\0';
          free(temp4);
          int m1 = quo[quocounter]-'0';
          quo[quocounter]= (char)(m1+47);
          quocounter++;
          char* temp5 = (char*)malloc(3000000*sizeof(char));
          // printf("Y=%s %s \n",c,temp3);
          strcpy(temp5,addnew(temp3,c));
          // printf("temp5=%s\n",addnew(temp3,c));
          k=0;
          for(k=0; k<strlen(temp5); k++){
               temp3[k]=temp5[k];
          }
          temp3[k]=a[p+sizeb-1];
          temp3[k+1]='\0';

          k=0;
          while(temp3[k]=='0'){
               k++;
          }
          int k1=0;
          int k2=0;
          for(k2=k; k2<strlen(temp3); k2++){
               temp3[k1++]=temp3[k2];
          }
          temp3[k1]='\0';
          // printf("=%s\n",temp3);
          // printf("##==%s\n",quo);
          // printf("|%d %d %d|\n",p,sizea,sizeb);
     }


     finalans=quo;
     // return finalans;

}
