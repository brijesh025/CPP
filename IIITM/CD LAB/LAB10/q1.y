%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(const char *s) { fprintf(stderr, "Error: %s\n", s); }

int temp_count = 0;
char *newtemp(void) {
    char buf[32];
    sprintf(buf, "t%d", temp_count++);
    return strdup(buf);
}
%}

%union {
    char *sval;
}

%token <sval> ID NUMBER
%type  <sval> expr term power factor

%right '^'
%left '*' '/'
%left '+' '-'

%%

input:
      /* empty */
    | input line
    ;

line:
      ID '=' expr {
            printf("%s = %s;\n", $1, $3);
            free($1);
            free($3);
      }
    | expr {
            free($1);
      }
    ;

expr:
      expr '+' term {
            char *t = newtemp();
            printf("%s = %s + %s;\n", t, $1, $3);
            free($1); free($3);
            $$ = t;
      }
    | expr '-' term {
            char *t = newtemp();
            printf("%s = %s - %s;\n", t, $1, $3);
            free($1); free($3);
            $$ = t;
      }
    | term {
            $$ = $1;
      }
    ;

term:
      term '*' power {
            char *t = newtemp();
            printf("%s = %s * %s;\n", t, $1, $3);
            free($1); free($3);
            $$ = t;
      }
    | term '/' power {
            char *t = newtemp();
            printf("%s = %s / %s;\n", t, $1, $3);
            free($1); free($3);
            $$ = t;
      }
    | power {
            $$ = $1;
      }
    ;

power:
      factor '^' power {
            char *t = newtemp();
            printf("%s = %s ^ %s;\n", t, $1, $3);
            free($1); free($3);
            $$ = t;
      }
    | factor {
            $$ = $1;
      }
    ;

factor:
      NUMBER {
            char *t = newtemp();
            printf("%s = %s;\n", t, $1);
            free($1);
            $$ = t;
      }
    | ID {
            char *t = newtemp();
            printf("%s = %s;\n", t, $1);
            free($1);
            $$ = t;
      }
    | '(' expr ')' {
            $$ = $2;
      }
    ;

%%

int main(void) {
    printf("Enter expressions (Ctrl+Z or Ctrl+D to end):\n");
    yyparse();
    return 0;
}
