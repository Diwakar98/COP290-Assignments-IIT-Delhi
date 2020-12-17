#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern int compare();
extern char* addnew();
extern char* divnew();
extern char* subnew();
char* sqrtnew(char n[]){
     // printf("SQRT: a=%s\n",n);
     int sizex=strlen(n);
     int i=0;
     bool isfloat=false;
     int dp=0;
     for(i=0; i<sizex; i++){
          if(n[i]=='.'){
               dp=i;
               isfloat=true;
               break;
          }
     }
     if(isfloat==true){
          i=0;
          for(i=sizex; i<=dp+20; i++){
               n[i]='0';
          }
          n[i]='\0';
     }
     else{
          n[sizex]='.';
          i=0;
          for(i=sizex+1; i<=sizex+21; i++){
               n[i]='0';
          }
          n[i]='\0';
     }
     // printf("N=%s\n", n);


     char* x=(char*)malloc(3000000*sizeof(char));
     i=0;
     for(i=0; i<strlen(n); i++){
          x[i]=n[i];
     }
     x[i]='\0';
     // printf("x==%s\n", x);

     char* y=(char*)malloc(3000000*sizeof(char));
     y[0]='1';
     y[2]='\0';
     char e[10];
     e[0]='0';
     e[1]='.';
     for(i=2; i<20; i++){
          e[i]='0';
     }
     e[i]='1';
     e[i+1]='\0';
     char two[2];
     two[0]='2';
     two[1]='\0';
     int px=0;
     // printf("e=|%s|\n",e);
     // printf("two=|%s|\n",two);
     // printf("n=|%s|\n",n30
     char c[strlen(n)];
     while(px++<500){
          // printf("------------------\n");
          i=0;
          char xtemp[3000000];
          char ytemp[3000000];
          // printf("x=%s\n",x);
          // printf("y=%s\n",y);
          for(i=0; i<strlen(x); i++){
               xtemp[i]=x[i];
          }
          xtemp[i]='\0';
           // printf("xtemp=|%s|\n",xtemp);
          i=0;
          for(i=0; i<strlen(y); i++){
               ytemp[i]=y[i];
          }
          ytemp[i]='\0';
          // printf("ytemp=|%s|\n",ytemp);

          //x-y>e
          char* xminusy=subnew(xtemp,ytemp);
          char xminusyarr[3000000];
          i=0;
          for(i=0; i<strlen(xminusy); i++){
               xminusyarr[i]=xminusy[i];
          }
          xminusyarr[i]='\0';
          // printf("xminusyarr=%s\n", xminusyarr);
          // printf("e=%s\n", e);
          int f=compare(xminusyarr,e);
          // printf("f=%d\n", f);
          // printf("%d\n",px);
          if(f<0){

               break;
          }


          //x=(x+y)/2
          char* xplusy=addnew(xtemp,ytemp);
          char xplusyarr[3000000];
          i=0;
          for(i=0; i<strlen(xplusy); i++){
               xplusyarr[i]=xplusy[i];
          }
          xplusyarr[i]='\0';


          // printf("xplusyarr=%s\n", xplusyarr);
          // printf("two=%s\n", two);
          // printf("xy=%s\n", xplusyarr);
          char* xplusydiv2=divnew(xplusyarr,two);
          // printf("xplusydiv2=%s\n", xplusydiv2);
          i=0;
          for(i=0; i<strlen(xplusyarr); i++){
               x[i]=xplusydiv2[i];
          }
          x[i]='\0';
          // printf("x=%s\n", x);

          char xarr[3000000];
          i=0;
          for(i=0; i<strlen(x); i++){
               xarr[i]=x[i];
          }
          xarr[i]='\0';

          //y=n/x;

          // printf("xarr=%s\n", xarr);
          // printf("n2=%s\n", n);
          i=0;
          for(i=0; i<strlen(n); i++){
               c[i]=n[i];
          }

          c[i]='\0';
          // printf("c=%s\n", c);
          char* ndivxarr=divnew(c,xarr);
          // printf("n1=%s\n", n);
          // printf("ndivxarr=%s\n", ndivxarr);
          i=0;
          int ndivxarrlen=strlen(ndivxarr);
          // printf("ndivxarrlen=%d\n", ndivxarrlen);
          for(i=0; i<ndivxarrlen; i++){
               y[i]=ndivxarr[i];
          }
          y[i]='\0';
          // printf("y=%s\n", y);
     }

     // printf("SQRT_ans=%s\n",x);
     return x;
}
