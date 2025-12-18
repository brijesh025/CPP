%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyparse(void);
void yyerror(const char *s) { fprintf(stderr, "Error: %s\n", s); }

int temp_count = 0, reduction = 1;
int dtype_size = 1, num_arrays = 0, num_dim = 0, dims[10];

char *newtemp(void) {
    char buf[32];
    sprintf(buf, "t%d", temp_count++);
    return strdup(buf);
}

/* compute cumulative dimension multiplicative factor after dim_index */
int compute_offset(int dim_index) {
    int size = 1;
    for (int i = dim_index + 1; i < num_dim; i++)
        size *= dims[i];
    return size * dtype_size;
}

/* helper to build a textual LHS like "A[i]" or "A[i][j]" */
char *build_lhs_text(const char *id, const char *i1, const char *i2) {
    if (i2 == NULL) {
        size_t n = strlen(id) + strlen(i1) + 4;
        char *s = malloc(n);
        snprintf(s, n, "%s[%s]", id, i1);
        return s;
    } else {
        size_t n = strlen(id) + strlen(i1) + strlen(i2) + 8;
        char *s = malloc(n);
        snprintf(s, n, "%s[%s][%s]", id, i1, i2);
        return s;
    }
}
%}

%union {
    char *sval;
}

%token <sval> ID NUMBER
%type  <sval> expr term factor array_rvalue array_lhs stmt stmt_list

%right '^'
%left '*' '/'
%left '+' '-'

%%

/* program: read declarations (interactive), then statements */
program:
      decls stmt_list
    ;

/* decls: an action executed before parsing statements to read dtype/array dims */
decls:
    /* empty */ {
        printf("Enter size of data type :\n");
        fflush(stdout);
        if (scanf("%d", &dtype_size) != 1) { fprintf(stderr, "Invalid input\n"); exit(1); }

        printf("Enter no of arrays :\n");
        fflush(stdout);
        if (scanf("%d", &num_arrays) != 1) { fprintf(stderr, "Invalid input\n"); exit(1); }

        /* For this simple program we read dims for each array (we keep last array's dims in global vars) */
        for (int i = 1; i <= num_arrays; i++) {
            printf("Enter no of dimension of %d array :\n", i);
            fflush(stdout);
            if (scanf("%d", &num_dim) != 1) { fprintf(stderr,"Invalid input\n"); exit(1); }

            printf("Enter dimensions of %d array :\n", i);
            fflush(stdout);
            for (int j = 0; j < num_dim; j++) {
                if (scanf("%d", &dims[j]) != 1) { fprintf(stderr,"Invalid input\n"); exit(1); }
            }
        }

        /* consume trailing newline left by scanf before we read expressions */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) ;
        printf("\nEnter expressions ending with Semicolon\n");
    }
    ;

/* list of statements (allow multiple statements) */
stmt_list:
      /* empty */
    | stmt_list stmt
    ;

/* a statement: assignment to array-lhs or a standalone expression followed by semicolon */
stmt:
      array_lhs '=' expr ';' {
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s\n", $1, $3);
          free($1);
          free($3);
      }
    | expr ';' {
          /* standalone expression (we free the generated temp) */
          free($1);
      }
    ;

/* expressions produce temporaries (three-address style) */
expr:
      expr '+' term {
          char *t = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s + %s\n", t, $1, $3);
          free($1); free($3);
          $$ = t;
      }
    | expr '-' term {
          char *t = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s - %s\n", t, $1, $3);
          free($1); free($3);
          $$ = t;
      }
    | term { $$ = $1; }
    ;

/* term forwards to factor (you can add * and / reductions here if desired) */
term:
      term '*' factor {
          char *t = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s * %s\n", t, $1, $3);
          free($1); free($3);
          $$ = t;
      }
    | term '/' factor {
          char *t = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s / %s\n", t, $1, $3);
          free($1); free($3);
          $$ = t;
      }
    | factor { $$ = $1; }
    ;

/* factor: number or array rvalue or parenthesized expr */
factor:
      NUMBER {
          char *t = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s\n", t, $1);
          free($1);
          $$ = t;
      }
    | array_rvalue { $$ = $1; }
    | '(' expr ')' { $$ = $2; }
    ;

/* array rvalues: produce temporaries that load from array based on computed offset */
/* single-dimension rvalue: B[k]  -> compute k * dtype_size, then load B[t] */
array_rvalue:
      ID '[' ID ']' {
          int offset = dtype_size;
          char *t1 = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s * %d\n", t1, $3, offset);

          char *t2 = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s[%s]\n", t2, $1, t1);

          free($1); free($3); free(t1);
          $$ = t2;
      }
    /* two-dimensional rvalue: A[i][j] -> compute combined offset and load A[t] */
    | ID '[' ID ']' '[' ID ']' {
          /* multiplier for first index i */
          int size1 = compute_offset(0);

          char *t1 = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s * %d\n", t1, $3, size1);

          char *t2 = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s * %d\n", t2, $6, dtype_size);

          char *t3 = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s + %s\n", t3, t1, t2);

          char *t4 = newtemp();
          printf("After reduction number %d\n", reduction++);
          printf("%s = %s[%s]\n", t4, $1, t3);

          free($1); free($3); free($6);
          free(t1); free(t2); free(t3);
          $$ = t4;
      }
    ;

/* array form used on LHS: build textual LHS like "A[i]" or "A[i][j]" (no address computation here) */
array_lhs:
      ID '[' ID ']' {
          char *s = build_lhs_text($1, $3, NULL);
          free($1); free($3);
          $$ = s;
      }
    | ID '[' ID ']' '[' ID ']' {
          char *s = build_lhs_text($1, $3, $6);
          free($1); free($3); free($6);
          $$ = s;
      }
    ;

%%

int main(void) {
    yyparse();
    return 0;
}
