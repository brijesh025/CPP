%option c++
%option noyywrap
%{
  #include <stdio.h>
  #include <string.h>
%}

digit   [0-9]+
floatn  {digit}\.{digit}+

%%
{floatn}   { printf("%s is a floating-point number\n", yytext); }
{digit}    { printf("%s is not a floating-point number\n", yytext); }
%%

int main() {
    printf("Enter number: ");
    yyFlexLexer lexer;
    while(lexer.yylex());
    printf("2023-IMT025 BRIJESH SINGH");
    return 0;
}