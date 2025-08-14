%option noyywrap
%x COMMENT

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int line_no = 1;

/* Unique token storage (case-insensitive key, original first-seen lexeme) */
static char **uniqueKeys = NULL;
static char **uniqueOrig = NULL;
static int uniqueCount = 0;
static int uniqueCap = 0;

/* Occurrence storage: stores tokens in the order they appear */
typedef struct {
    int id;
    char *lexeme; /* strdup of yytext for that occurrence */
} Occurrence;

static Occurrence *occurs = NULL;
static int occursCount = 0;
static int occursCap = 0;

char *str_tolower_dup(const char *s) {
    size_t n = strlen(s);
    char *p = (char*)malloc(n + 1);
    if (!p) return NULL;
    for (size_t i = 0; i < n; ++i) p[i] = (char)tolower((unsigned char)s[i]);
    p[n] = '\0';
    return p;
}

int find_or_add_token(const char *lexeme) {
    char *key = str_tolower_dup(lexeme);
    if (!key) return -1;
    for (int i = 0; i < uniqueCount; ++i) {
        if (strcmp(uniqueKeys[i], key) == 0) {
            free(key);
            return i + 1; /* tokens numbered from 1 */
        }
    }
    /* add new token */
    if (uniqueCount == uniqueCap) {
        int newCap = (uniqueCap == 0) ? 32 : uniqueCap * 2;
        uniqueKeys = (char**)realloc(uniqueKeys, newCap * sizeof(char*));
        uniqueOrig = (char**)realloc(uniqueOrig, newCap * sizeof(char*));
        uniqueCap = newCap;
    }
    uniqueKeys[uniqueCount] = key;               /* store lowercased key */
    uniqueOrig[uniqueCount] = strdup(lexeme);    /* store original first-seen */
    uniqueCount++;
    return uniqueCount;
}

void add_occurrence(int id, const char *lexeme) {
    if (occursCount == occursCap) {
        int newCap = (occursCap == 0) ? 128 : occursCap * 2;
        occurs = (Occurrence*)realloc(occurs, newCap * sizeof(Occurrence));
        occursCap = newCap;
    }
    occurs[occursCount].id = id;
    occurs[occursCount].lexeme = strdup(lexeme);
    occursCount++;
}

/* helper to free allocated memory (optional but tidy) */
void free_all() {
    for (int i = 0; i < uniqueCount; ++i) free(uniqueOrig[i]);
    for (int i = 0; i < uniqueCount; ++i) free(uniqueKeys[i]);
    free(uniqueOrig); free(uniqueKeys);
    for (int i = 0; i < occursCount; ++i) free(occurs[i].lexeme);
    free(occurs);
}
%}

/* token patterns */
DIGIT   [0-9]
ID      [A-Za-z_][A-Za-z0-9_]*
NUMBER  {DIGIT}+(\.{DIGIT}+)?    /* integers or decimals */

%%

"//".*                        { /* single-line comment - skip */ }
"/*"                          { BEGIN(COMMENT); }
<COMMENT>[^*]+                { /* inside comment */ }
<COMMENT>"*"+[^*/]*           { /* inside comment */ }
<COMMENT>"*"+"/"              { BEGIN(INITIAL); }
[ \t\r]+                      { /* skip whitespace */ }
\n                            { line_no++; }


":="                          { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
"=="|"!="|"<="|">="           { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }


"<"|">"|"="                   { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
"+"|"-"|"*"|"/"               { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
";"                           { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
","                           { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
"("                           { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
")"                           { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
"{"                           { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
"}"                           { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
"["                           { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
"]"                           { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
":"                           { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }

{ID}                          { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }
{NUMBER}                      { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }

.                             { int id = find_or_add_token(yytext); add_occurrence(id, yytext); }

%%

int main(int argc, char **argv)
{
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) { perror("fopen"); return 1; }
        yyin = f;
    }

    /* Scan entire input and store tokens/occurrences */
    yylex();

    /* Now print the full token stream at once (in original order) */
    for (int i = 0; i < occursCount; ++i) {
        printf("token%d: %s\n", occurs[i].id, occurs[i].lexeme);
    }

    /* Summary of unique tokens */
    printf("\n---- Unique tokens (%d) ----\n", uniqueCount);
    for (int i = 0; i < uniqueCount; ++i) {
        printf("token%d: %s\n", i + 1, uniqueOrig[i]);
    }

    free_all();
    return 0;
}
