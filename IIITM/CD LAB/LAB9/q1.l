%{
#include "q1.tab.h"
#include <cstring>
#include <cstdlib>
%}

digit  [0-9]
number {digit}+

%%

[ \t\r]+          ; /* skip whitespace */
{number}          {
                    yylval.sval = strdup(yytext);
                    return NUMBER;
                  }
"("               { return '('; }
")"               { return ')'; }
"+"               { return '+'; }
"-"               { return '-'; }
"*"               { return '*'; }
"/"               { return '/'; }
\n                { return '\n'; }
.                 { /* skip unknown characters */ }

%%

int yywrap(void){ printf("2023IMT-025 BRIJESH SINGH"); return 1; }
