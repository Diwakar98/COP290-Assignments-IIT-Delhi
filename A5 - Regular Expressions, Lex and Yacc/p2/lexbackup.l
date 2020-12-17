%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
([1-9][0-9]*)|[0]                  {
                                        yylval=atoi(yytext);
                                        return NUM;
                                   }
"+"|"-"|"*"|"/"|"^"                             {return OP;}
[ \t]                              ;
.|\n                               {return NEWLINE};
%%

int yywrap(){
     return 1;
}
