%option c++
%option noyywrap

%{
    #include<bits/stdc++.h>
    using namespace std;
    set<string> keywords,identifiers, numbers,operators, punctuations;
    int token=0;
%}

WHITESPACE      [ \t\r\n]+
KEYWORD         int|float
NUMBER          [0-9]+
IDENTIFIER      [a-zA-Z][a-zA-Z0-9]*
INVALID_ID      [0-9]+[a-zA-Z][a-zA-Z0-9]*

OPERATOR        ("=="|"\+"|"\-"|"\*"|"/"|"=")   
PUNCT           (;|:)

%%
{WHITESPACE}    ;
{INVALID_ID}    ;
{KEYWORD}       { keywords.insert(yytext); token++; }
{NUMBER}        { numbers.insert(yytext); token++; }
{IDENTIFIER}    { identifiers.insert(yytext); token++; }
{OPERATOR}      { operators.insert(yytext); token++; }
{PUNCT}         { punctuations.insert(yytext); token++; }
.               ;
%%


int main() {
    printf("Enter your program: ");
    yyFlexLexer lexer;
    while(lexer.yylex());
    printf("\nNumber of Keywords: %d", keywords.size());
    printf("\nNumber of numbers: %d", numbers.size());
    printf("\nNumber of Identifier: %d", identifiers.size());
    printf("\nNumber of Operators: %d", operators.size());
    printf("\nNumber of Punctuations: %d", punctuations.size());
    printf("\nTotal number of Token: %d\n", token);
    return 0;
}