%{
#include <stdio.h>
#include <string.h>
%}

%%
[0-9]*00           { printf("%s match rule a\n", yytext); }
[0-9]*222          { printf("%s match rule b\n", yytext); }
([0-9]*5[0-9]*5[0-9]*)   { if(strlen(yytext)>=5) printf("%s match rule c\n", yytext); }
1[01]*             { 
                      int val=0; 
                      for(int i=0;i<yyleng;i++) val=(val*2+(yytext[i]-'0'))%5; 
                      if(val==0) printf("%s match rule d\n", yytext);
                   }
[0-9]*1[0-9]{9}$   { printf("%s match rule e\n", yytext); }
[0-9]{4}           { 
                      int sum=0; 
                      for(int i=0;i<4;i++) sum+=yytext[i]-'0'; 
                      if(sum==9) printf("%s match rule f\n", yytext);
                      int asc=1; 
                      for(int i=1;i<4;i++) if(yytext[i]<yytext[i-1]) asc=0;
                      if(asc) printf("%s match rule g\n", yytext);
                   }
.|\n               { /* ignore others */ }
%%

int yywrap() { return 1; }

int main() {
    yylex();
    return 0;
}
