%{
     #include <stdlib.h>
     #include "y.tab.h"
%}
%%
[a]*("\n")          {printf("TRUE\n"); return TOKEN;}
[b]*("\n")          {printf("TRUE\n"); return TOKEN;}
[a]*[b]+("\n")      {printf("TRUE\n"); return TOKEN;}
.                   {printf("FALSE\n");char c; while((c=input())!='\n'){}}
%%
int yywrap(){
     return 1;
}
