%option c++
%option noyywrap

%{
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int count  = 0;
string identifier[100];
int token_id[100];
int identifier_count = 0;

int find_identifier(const string &id){
    for(int i=0;i<identifier_count;i++){
        if(identifier[i] == id){
            return token_id[i];
        }
    }
    return -1;
}

void add_identifier(const string &id){
    identifier[identifier_count] = id;
    token_id[identifier_count] = count+1;
    identifier_count++;
}
%}

digits      [0-9]+
keyword     Prog|Integer|Begin|read|if|then|else|endif|while|do|endwhile|write|end
assignment  :=
relations   <|<=|>|>=|==
delimiter   ;|,
identifier  [a-zA-Z][a-zA-Z0-9_]*

%%

{keyword}       { cout << "Token: " << ++count << " Keyword: " << yytext << endl; }
{digits}        { cout << "Token: " << ++count << " Digits: " << yytext << endl; }
{assignment}    { cout << "Token: " << ++count << " Assignment: " << yytext << endl; }
{relations}     { cout << "Token: " << ++count << " Relation: " << yytext << endl; }
{delimiter}     { cout << "Token: " << ++count << " Delimiter: " << yytext << endl; }
{identifier}    {
                    int token_number = find_identifier(yytext);
                    if(token_number == -1){
                        add_identifier(yytext);
                        cout << "Token: " << ++count << " Identifier: " << yytext << endl;
                    } else {
                        cout << "Token: " << token_number << " Identifier: " << yytext << endl;
                    }
                }
.               {}

%%

int main(){
    yyFlexLexer lexer;
    while(lexer.yylex());
    return 0;
}
