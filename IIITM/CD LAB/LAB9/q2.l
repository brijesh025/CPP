%{
#include "q2.tab.h"
#include <cstdio>
%}

/* rules */
%%

[ \t\r]+    ; /* skip whitespace and Windows CR */
"a"         { printf("Shift a\n"); return A; }
"b"         { printf("Shift b\n"); return B; }
\n          { return '\n'; }
.           { /* skip unknown chars */ }

%%

int yywrap(void) { return 1; }
