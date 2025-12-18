%{
#include <bits/stdc++.h>
using namespace std;

/* global stack of symbols collected during parsing (left-to-right order) */
vector<string> stk;

/* reduction helpers (same logic as the simulator version) */

bool apply_multi_reduction(vector<string>& s) {
    int n = (int)s.size();
    for (int i = 0; i + 2 < n; ++i) {
        if (s[i] == "a" && s[i+1] == "S" && s[i+2] == "a") {
            s.erase(s.begin()+i, s.begin()+i+3);
            s.insert(s.begin()+i, "S");
            printf("Reduce S -> aSa\n");
            return true;
        }
        if (s[i] == "b" && s[i+1] == "S" && s[i+2] == "b") {
            s.erase(s.begin()+i, s.begin()+i+3);
            s.insert(s.begin()+i, "S");
            printf("Reduce S -> bSb\n");
            return true;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == "a" && s[i+1] == "a") {
            s.erase(s.begin()+i, s.begin()+i+2);
            s.insert(s.begin()+i, "S");
            printf("Reduce S -> aa\n");
            return true;
        }
        if (s[i] == "b" && s[i+1] == "b") {
            s.erase(s.begin()+i, s.begin()+i+2);
            s.insert(s.begin()+i, "S");
            printf("Reduce S -> bb\n");
            return true;
        }
    }
    return false;
}

bool apply_single_center_reduction(vector<string>& s) {
    int n = (int)s.size();
    if (n == 0) {
        printf("Reduce S -> ε\n");
        s.push_back("S");
        return true;
    }
    int center = n / 2;
    if (s[center] == "a") {
        s.erase(s.begin()+center);
        s.insert(s.begin()+center, "S");
        printf("Reduce S -> a\n");
        return true;
    }
    if (s[center] == "b") {
        s.erase(s.begin()+center);
        s.insert(s.begin()+center, "S");
        printf("Reduce S -> b\n");
        return true;
    }
    return false;
}

void reduce_all(vector<string>& s) {
    while (true) {
        if (apply_multi_reduction(s)) continue;
        if (apply_single_center_reduction(s)) continue;
        break;
    }
}

/* called when a full input line is parsed */
void process_line() {
    // perform reductions on stk
    reduce_all(stk);
    // if after reductions we have single S, accept
    if (stk.size() == 1 && stk[0] == "S") printf("ACCEPTED\n");
    else printf("REJECTED\n");
    stk.clear();
}

extern int yylex();
extern FILE *yyin;
void yyerror(const char *s) {
    /* On parse error, print REJECTED to match expected behaviour */
    printf("REJECTED\n");
}
%}

/* tokens */
%token A B

%%

input:
      lines
    ;

lines:
      /* empty */
    | lines line
    ;

line:
      seq '\n'    { process_line(); }
    | seq         { process_line(); } /* allow EOF without newline */
    | '\n'        { /* blank line -> treat as epsilon case */ process_line(); }
    ;

seq:
      /* empty */ { /* no action, empty input stays as empty vector */ }
    | seq A       { stk.push_back("a"); }
    | seq B       { stk.push_back("b"); }
    ;

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) { perror("fopen"); return 1; }
    } else yyin = stdin;
    yyparse();
    return 0;
}
