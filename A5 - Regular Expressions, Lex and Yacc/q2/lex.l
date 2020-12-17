%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[-+]?([1-9][0-9]*)|[0]             {
                                        yylval=atoi(yytext);
                                        return NUM;
                                   }
("+"|"-"|"*"|"/"|"^")         {return OP;}
[\n]                          {return NEWLINE;}
[ \t]                              ;
%%

int yywrap(){
     return 1;
}
