%{
#include <stdio.h>
#include <string.h>

char longest[1000];
int longest_len = 0;
%}

%%
([+]+[0]{0,3}[-]+) {
    int len = yyleng;
    if(len > longest_len) {
        longest_len = len;
        strncpy(longest, yytext, len);
        longest[len] = '\0';
    }
    printf("(%s)", yytext);   // surround feature with ()
}
\n {
    if(longest_len > 0) {
        printf("\nLongest feature in this row: %s\n", longest);
    } else {
        printf("\nNo feature in this row.\n");
    }
    printf("BRIJESH SINGH 2023IMT-025. \n");
    longest_len = 0; // reset for next row
}
.   { ECHO; }   // print any other character unchanged
%%

int yywrap() { return 1; }

int main() {
    yylex();
    return 0;
}
