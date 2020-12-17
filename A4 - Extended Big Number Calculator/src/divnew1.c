#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern char* subnew();
extern char* addnew();
extern bool compare();
extern char* trim();
char* divnew(char a[],char b[]){
     // printf("DIV\n");
     // printf("DIV: a=%s b=%s\n",a,b);
     // printf("$$\n");
     int precision=20;
     int sizea=strlen(a);
     int sizeb=strlen(b);
     bool finalsign=true;
     //True-positive
     //False-negative
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
     precision++;
     sizea=strlen(a);
     sizeb=strlen(b);
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
     // printf("sizea=%d\n",sizea);
     // printf("sizeb=%d\n",sizeb);
     char newa[sizea+precision];
     i=0;
     j=0;
     k=0;
     int sum=0;
     int carry=0;
     char temp[sizeb+2];
     char temp1[sizeb+1];
     char* temp2;
     i=0;
     // char rem[sizeb];
     char quo[sizea+precision];
     // printf("a==|%s|\n",a);
     for(i=sizea; i<sizea+precision; i++){
          a[i]='0';
     }
     a[i]='\0';
     // printf("a==|%s|\n",a);
     for(i=0; i<sizea+precision; i++){
          quo[i]='0';
     }
     quo[i]='\0';
     // printf("quo==|%s|\n",quo);
     // printf("rem==|%s|\n",rem);
     sizea=sizea+precision;

     int p=0;
     int q=0;
     int quocounter=0;

     // printf("A=%s\n",a);
     // printf("B=%s\n",b);
     // printf("temp3=%s\n",temp3);
     q=0;
     int j1=0;
     char c[3000000];
     int initialdp=0;
     int sizetemp=strlen(b);
     char newb[sizetemp];
     char* b1=(char*)malloc(sizetemp*sizeof(b));
     strcpy(b1,trim(b));
     int p2=0;
     int tillwhere=strlen(b1);
     for(p2=0; p2<tillwhere; p2++){
          b[p2]=b1[p2];
     }
     b[p2]='\0';
     sizeb=strlen(b);
     // free(b1);
     for(j1=0; j1<sizeb; j1++){
          c[j1]=b[j1];
     }
     c[j1]='\0';
     // printf("c=%s\n", c);
     char temp3[sizeb+1];
     k=0;
     for(q=0; q<sizeb; q++){
          temp3[k++]=a[q];
     }
     temp3[k]='\0';
     for(p=sizeb; p<sizea; p++){
          k=0;
          // printf("%d\n",quocounter);
          char* temp4 = (char*)malloc(3000000*sizeof(char));
          // printf("$$$$$$$$\n");
          while(temp3[0]!='-'){

                    // printf("\t%d %d %d %d\n",sizea,p,sizeb,quocounter);
                    // initialdp = quocounter;

               // printf("X %s %s \n",c,temp3);
               strcpy(temp4,subnew(temp3,c));
               int m = quo[quocounter]-'0';
               // printf("m=%d\n", m);
               quo[quocounter]= (char)(m+49);
               int n=0;
               for(n=0; n<strlen(temp4); n++){
                    temp3[n]=temp4[n];
               }
               temp3[n]='\0';
               // printf("temp3=|%s|\n",temp3);
               // printf("Q=|%s|\n",quo);
          }
          // printf("$$$$$$$$ %d\n",p);
          j1=0;
          for(j1=0; j1<strlen(b); j1++){
               c[j1]=b[j1];
          }
          c[j1]='\0';
          // free(temp4);
          int m1 = quo[quocounter]-'0';
          quo[quocounter]= (char)(m1+47);
          quocounter++;
          // printf("Q = %s\n", quo);
          char* temp5 = (char*)malloc(3000000*sizeof(char));
          // printf("Y=%s %s \n",c,temp3);
          strcpy(temp5,addnew(temp3,c));
          // printf("temp5=%s\n",temp5);
          k=0;
          for(k=0; k<strlen(temp5); k++){
               temp3[k]=temp5[k];
          }
          temp3[k]=a[p];
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
          // free(temp5);
          // printf("^^=|%s|\n",temp3);
          // printf("##==|%s|\n",quo);
          // printf("|%d %d %d|\n",p,sizea,sizeb);
     }

     i=0;

     int partialdp=sizea-precision-strlen(b)+1;
     // printf("a=%s\n",a);
     // printf("sizea=%d\n",sizea);
     // printf("adA=%d adB=%d dp=%d fl=%d f=%s\n",adA,adB,partialdp,strlen(finalans),finalans);
     // printf("idp=%d pdp=%d\n",initialdp,partialdp);
     int start=partialdp-adA+adB;
     quo[start+precision]='\0';
     char* finalans=quo;
     int end=strlen(finalans);
     char c1='.';
     for(i=start; i<end; i++){
          char c2=finalans[i];
          finalans[i]=c1;
          c1=c2;
     }
     finalans[i]='\0';

     char * ultimateresult=(char*)malloc(3000000*sizeof(char));
     i=0;
     while(finalans[i]=='0'){
          i++;
     }
     j=0;
     k=0;
     for(j=i; j<strlen(finalans); j++){
          ultimateresult[k++]=finalans[j];
     }

     ultimateresult[k]='\0';
     char* ultimateans=(char*)malloc(3000*sizeof(char));;
     if(finalsign==false){
          // printf("^^\n");
          ultimateans[0]='-';
          // printf("^^\n");
          // int yy=strlen(ultimateresult);
          // printf("^^\n");
          // printf("ultimateresult=%s\n", ultimateresult);
          i=strlen(ultimateresult)-1;
          while(ultimateresult[i]=='0'){
               i--;
          }
          int pp=0;
          if(ultimateresult[i]=='.'){
               i++;
          }
          for(pp=0; pp<=i; pp++){
               ultimateans[pp+1]=ultimateresult[pp];
          }
          ultimateans[pp+1]='\0';
     }
     else{
          // printf("ultimateresult=%s\n", ultimateresult);
          i=strlen(ultimateresult)-1;
          while(ultimateresult[i]=='0'){
               i--;
          }
          // printf("i=%d\n", i);
          if(ultimateresult[i]=='.'){
               i++;
          }
          int pp=0;
          if(ultimateresult[0]=='.'){
               ultimateans[0]='0';
               for(pp=0; pp<=i; pp++){
                    ultimateans[pp+1]=ultimateresult[pp];
               }
               ultimateans[pp+2]='\0';
          }
          else{
               for(pp=0; pp<=i; pp++){
                    ultimateans[pp]=ultimateresult[pp];
               }
               ultimateans[pp+1]='\0';
          }
          // printf("ultimateans=%s\n", ultimateans);

     }
     // printf("DIV_ans=%s\n", ultimateans);
     // printf("$$\n");
     // free(ultimateresult);
     // free(temp5);
     return ultimateans;
}
