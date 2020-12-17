%{
#define YYSTYPE int
#include "lex.yy.c"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
void yyerror(char *);
void leaf();
void nonleaf();
void result();
void initializestack();
char* stack[100];
int value[100];
int top=0;
bool printornot=true;
%}

%token NUM OP NEWLINE
%start Z
%left '+'  '-'
%left '*'  '/'
%right UMINUS
%right '^'
%%

Z : S NEWLINE Z
     | S NEWLINE {yyterminate();}

S : E {
          if(printornot)
          result();
          top=0;
          printornot=true;
      }
     ;
E : E E OP     {
                    nonleaf();
               }
     | E E     {fprintf(yyout,"INVALID INPUT\n"); initializestack; printornot=false;}
     | NUM     {
                    leaf();
               }
     ;
%%

void yyerror(char *s) {
     printf("%s\n", s);
}
int main(int argc, char* argv[]){
     extern FILE *yyin, *yyout;
     //printf("%s %s",argv[0],argv[1]);
     yyin = fopen(argv[1],"r");
     yyout = fopen(argv[2],"w");
     //printf("%s",yyin);
     if(yyin==NULL){
          printf("ERROR: File Not Found\n");
          yyterminate();
     }
     yyparse();
     return 0;
}
void leaf(){
     stack[top]=(char*)malloc(100*sizeof(char));
     strcpy(stack[top],yytext);
     value[top++]=atoi(yytext);
}
void nonleaf(){
     char* infix=(char*)malloc(100*sizeof(char));
     top--;
     int x=value[top];
     char* p=stack[top];
     top--;
     int y=value[top];
     char* q=stack[top];
     stack[top]=(char*)malloc(100*sizeof(char));
     sprintf(stack[top],"%s %s %s",yytext,q,p);
     if(yytext[0]=='+'){
          value[top]=x+y;
     }
     else if(yytext[0]=='-'){
          value[top]=y-x;
     }
     else if(yytext[0]=='*'){
          value[top]=y*x;
     }
     else if(yytext[0]=='/'){
          value[top]=y/x;
     }
     else if(yytext[0]=='^'){
          value[top]=pow(y,x);
     }
     top++;
     int i=0;
}
void result(){
     fprintf(yyout,"%s %d\n",stack[0],value[0]);
}
void initializestack(){
     int i=0;
     for(i=0; i<100; i++){
          strcpy(stack[i],"");
          value[i]=0;
     }
}
