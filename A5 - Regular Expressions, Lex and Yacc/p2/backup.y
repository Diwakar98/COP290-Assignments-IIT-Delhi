%{
#define YYSTYPE double
#include "lex.yy.c"
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
void yyerror(char *);
void leaf();
void nonleaf();
void result();
char* stack[100];
double value[100];
int top=0;
%}

%token NUM OP NEWLINE
%left '+'  '-'
%left '*'  '/'
%right UMINUS
%right '^'
%%

S : E NEWLINE  {
                    result();
                    yyterminate();
               }
     |
     ;
E : E E OP     {
                    nonleaf();
               }
     | NUM     {
                    leaf();
               }
     ;
%%

void yyerror(char *s) {
 fprintf(stderr, "%s\n", s);
}
int main(void){
     //printf("Enter: ");
     yyparse();
     return 0;
}
void leaf(){
     //printf("(%s)\n",yytext);
     stack[top]=(char*)malloc(100*sizeof(char));
     strcpy(stack[top],yytext);
     value[top++]=atoi(yytext);
     //printf("|%s|\n",stack);
     /*int i=0;
     for(i=0; i<top; i++){
          printf("-%s-",stack[i]);
     }
     printf("\n");*/
}
void nonleaf(){
     char* infix=(char*)malloc(100*sizeof(char));
     //printf("OP=%s",yytext);
     top--;
     double x=value[top];
     char* p=stack[top];
     //printf("p=%s",p);
     top--;
     double y=value[top];
     char* q=stack[top];
     //printf("q=%s",q);
     //printf("%f %f\n",x,y);
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
     /*for(i=0; i<top; i++){
          printf("-%f-",value[i]);
     }
     printf("\n");*/
}
void result(){
     printf("%f\n%s\n",value[0],stack[0]);
}
