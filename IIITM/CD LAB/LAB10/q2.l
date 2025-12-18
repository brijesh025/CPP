%{
#include "q1.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%%

[ \t\r\n]+               /* skip whitespace */

[0-9]+                   {
                            yylval.sval = strdup(yytext);
                            return NUMBER;
                         }

[a-zA-Z_][a-zA-Z0-9_]*   {
                            yylval.sval = strdup(yytext);
                            return ID;
                         }


"="                      { return '='; }
"["                      { return '['; }
"]"                      { return ']'; }
"+"                      { return '+'; }
"-"                      { return '-'; }
"*"                      { return '*'; }
"/"                      { return '/'; }
";"                      { return ';'; }

.                        { return yytext[0]; }

%%

int yywrap(void) { return 1; }
