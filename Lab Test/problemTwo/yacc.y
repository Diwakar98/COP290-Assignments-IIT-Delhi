%{
     #include "lex.yy.c"
     #include <stdio.h>
     #include <ctype.h>
     #include <math.h>
     #include <string.h>
     #include <unistd.h>
     #include <stdlib.h>
     #include <stdbool.h>
     void yyerror(char *);
%}
%token TOKEN
%start S
%%
     S: TOKEN  {

                    int count=0;
                    char *x=(char*)malloc(1000*sizeof(char));
                    strcpy(x,yytext);
                    int i=0;
                    int size=strlen(x);
                    for(i=0; i<size; i++){
                         if(x[i]=='a'){
                              count++;
                         }
                         else if(x[i]=='b'){
                              count--;
                         }
                    }
                    if(count==0)
                         printf("EQUAL\n");
                    else
                         printf("NOT EQUAL\n");
                    count=0;
                    free(x);
               }
%%
void yyerror(char *s) {
     printf("%s\n", s);
}
int main(){
     yyparse();
}
