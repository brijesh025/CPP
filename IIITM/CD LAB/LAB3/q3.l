%{
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>

    static bool invalid = false;
    static int expectOperand = 1; 
    static int seenOperand = 0;
%}

WS          [ \t\r]+
IDENT       [a-zA-Z][a-zA-Z0-9]*
NUMBER      [0-9]+
OPER        [+\-*/]

%%

{WS}                ; 
{IDENT}|{NUMBER}    {
                        if (!expectOperand) { invalid = true; }
                        else {
                            expectOperand = 0;
                            seenOperand = 1;
                        }
                    }
{OPER}              {
                        if (expectOperand) { invalid = true; }
                        else {
                            expectOperand = 1;
                        }
                    }
\n                  {
                        if (!invalid && seenOperand && !expectOperand)
                            printf("Valid expression identified\n");
                        else
                            printf("Expression is invalid\n");
                        return 0;
                    }
.                   { invalid = true; } 

%%

int yywrap(void) {
    if (!invalid && seenOperand && !expectOperand)
        printf("Valid expression identified\n");
    else
        printf("Expression is invalid\n");
    printf("2023-IMT025 BRIJESH SINGH");
    return 1;
}

int main() {
    printf("Input an expression: ");
    yylex();
    return 0;
}