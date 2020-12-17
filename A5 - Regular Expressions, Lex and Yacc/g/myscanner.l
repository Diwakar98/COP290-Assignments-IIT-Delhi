%{
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int countlines=1;
int nestedcomment=0;
void managelines();
void processcomment();
void processstring();
void processchar();
void yyerror(char *);
bool comment=false;
bool stringlinestart=false;
bool charlinestart=false;
%}
%%
("\n")             {countlines++;printf("\n");}
("/*")             {
                         processcomment();
                   }
("\"")             {
                         processstring();
                    }
("\'")              {
                         processchar();
                    }
.                   ECHO;
%%
void processstring(){
     /* printf("STARTSTRING"); */
     char c;
     char c1;
     bool eof=false;
     if(!comment){
          printf("\"");
     }
     while(true && !comment){
          c=input();
          if(c=='\\'){
               c=input();
               printf("%c%c",'\\',c);
          }
          else if(c=='"'){
               break;
          }
          else{
               printf("%c",c);
          }
          if(c=='\n'){
               countlines++;
          }
          int n=c-'0';
          if(n==-48){
               eof=true;
               break;
          }
     }
     if(eof==false)
     printf("\"");
     /* printf("ENDSTRING"); */
}
void processchar(){
     /* printf("STARTCHAR"); */
     charlinestart=!charlinestart;
     char c;
     char c1;
     bool eof=false;
     if(!comment){
          printf("\'");
     }
     while(true && !comment){
          c=input();
          if(c=='\\'){
               c=input();
               printf("%c%c",'\\',c);
          }
          else if(c=='\''){
               break;
          }
          else{
               printf("%c",c);
          }
          if(c=='\n'){
               countlines++;
          }
          int n=c-'0';
          if(n==-48){
               eof=true;
               break;
          }
     }
     if(eof==false)
     printf("\'");
     /* printf("ENDCHAR"); */
}
void processcomment(){
     /* printf("STARTCOMMENT"); */
     int lineno=countlines;
     char c;
     char c1;
     bool f=false;
     bool eof=false;
     bool error=true;
     int i=0;
     int line1=0;
     while(true){
          comment=true;
          c=input();
          if(c=='*'){
               c1=input();
               if(c1=='/'){
                    error=false;
                    break;
               }
          }
          else if(c=='\n'){
               countlines++;
               line1++;
               /* printf(" $\n"); */
          }
          int n=c-'0';
          if(n==-48){
               eof=true;
               break;
          }
     }
     printf(" ");
     int j=0;
     //printf("|%d|",line1);
     for(j=0; j<line1; j++){
          printf("\n");
     }
     if(error==true){
          fprintf(stderr,"Error: line %d: unterminated comment\n",lineno);
     }
     comment=false;
     /* printf("ENDCOMMENT"); */
}
void yyerror(char *s) {
     fprintf(stderr,"%s\n", s);
}
int main(){
     yylex();
     return 0;
}
