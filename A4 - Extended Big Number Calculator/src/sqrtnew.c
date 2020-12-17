#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern int compare();
extern char* addnew();
extern char* divnew();
extern char* subnew();
extern char* trim();
char* sqrtnew(char n[]){
     // printf("SQRT: a=%s\n",n);
     if(n[0]=='-'){
          char* ans="SQUARE ROOT OF NEGATIVE IS NOT COMPLEX";
          return ans;
     }
     else{
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
          int lenN=strlen(n);

          char* x=(char*)malloc(lenN*sizeof(char));
          i=0;
          for(i=0; i<strlen(n); i++){
               x[i]=n[i];
          }
          x[i]='\0';
          // printf("x==%s\n", x);

          char* y=(char*)malloc(lenN*sizeof(char));
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
          while(px++<400){
               // printf("%d\n",px);
               // printf("------------------\n");
               i=0;
               char xtemp1[lenN];
               char ytemp1[lenN];
               char xtemp2[lenN];
               char ytemp2[lenN];
               // printf("x=%s\n",x);
               // printf("y=%s\n",y);
               for(i=0; i<strlen(x); i++){
                    xtemp1[i]=x[i];
                    xtemp2[i]=x[i];
               }
               xtemp1[i]='\0';
               xtemp2[i]='\0';
                // printf("xtemp=|%s|\n",xtemp);
               i=0;
               for(i=0; i<strlen(y); i++){
                    ytemp1[i]=y[i];
                    ytemp2[i]=y[i];
               }
               ytemp1[i]='\0';
               ytemp2[i]='\0';
               // printf("ytemp=|%s|\n",ytemp);

               //x-y>e
               // char* xminusy=subnew(xtemp,ytemp);
               char* xminusy = (char*)malloc(lenN*sizeof(char));
               strcpy(xminusy,subnew(xtemp1,ytemp1));
               char xminusyarr[lenN];
               i=0;
               for(i=0; i<strlen(xminusy); i++){
                    xminusyarr[i]=xminusy[i];
               }
               xminusyarr[i]='\0';
     //-->
               // free(xminusy);
               // printf("xminusyarr=%s\n", xminusyarr);
               // printf("e=%s\n", e);
               int f=compare(xminusyarr,e);
               // printf("f=%d\n", f);

               if(f<0){

                    break;
               }


               //x=(x+y)/2
               // char* xplusy=addnew(xtemp,ytemp);
               char* xplusy=(char*)malloc(lenN*sizeof(char));
               strcpy(xplusy,addnew(xtemp2,ytemp2));
               char xplusyarr[lenN];
               i=0;
               for(i=0; i<strlen(xplusy); i++){
                    xplusyarr[i]=xplusy[i];
               }
               xplusyarr[i]='\0';
     //-->
               // free(xplusy);
               // printf("xplusyarr=%s\n", xplusyarr);
               // printf("two=%s\n", two);
               // printf("xy=%s\n", xplusyarr);


               // char* xplusydiv2=divnew(xplusyarr,two);
               char* xplusydiv2 = (char*)malloc((lenN+20)*sizeof(char));
               strcpy(xplusydiv2,divnew(xplusyarr,two));
               // printf("xplusydiv2=%s\n", xplusydiv2);
               i=0;
               for(i=0; i<strlen(xplusyarr); i++){
                    x[i]=xplusydiv2[i];
               }
               x[i]='\0';

     //-->
               // free(xplusydiv2);
               // printf("x=%s\n", x);

               char xarr[lenN];
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


               // char* ndivxarr=divnew(c,xarr);
               char* ndivxarr = (char*)malloc((lenN+20)*sizeof(char));
               strcpy(ndivxarr,divnew(c,xarr));
               // printf("n1=%s\n", n);
               // printf("ndivxarr=%s\n", ndivxarr);
               i=0;
               int ndivxarrlen=strlen(ndivxarr);
               // printf("ndivxarrlen=%d\n", ndivxarrlen);
               for(i=0; i<ndivxarrlen; i++){
                    y[i]=ndivxarr[i];
               }
               y[i]='\0';
     //-->
               // free(ndivxarr);
               // printf("y=%s\n", y);
          }

          // printf("SQRT_ans=%s\n",x);
          i=0;
          int sizexx=strlen(x);
          char ans[sizexx];
          for(i=0; i<sizexx; i++){
               ans[i]=x[i];
          }
          ans[i]='\0';
          // free(x);
          char* finalans=(char*)malloc(sizexx*sizeof(char));
          strcpy(finalans,trim(ans));
          return finalans;
     }
}
