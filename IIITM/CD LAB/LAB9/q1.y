%{
#include <bits/stdc++.h>
using namespace std;

struct Node { int id; string val; int left, right; };
vector<Node> nodes;

int newNode(const char *v, int l=-1, int r=-1){
    Node n;
    n.id = (int)nodes.size();
    n.val = string(v);
    n.left = l;
    n.right = r;
    nodes.push_back(n);
    return n.id;
}

void printNodes(){
    for(auto &n : nodes){
        cout << "Node : " << n.id << " value : " << n.val;
        if(n.left==-1 && n.right==-1) {
            cout << "\n";
        } else {
            cout << " left child at : " << (n.left==-1? -1 : n.left) << " right child at : " << (n.right==-1? -1 : n.right) << "\n";
        }
    }
}

extern int yylex();
extern FILE *yyin;
void yyerror(const char *s){ cerr<<"Parse error: "<<s<<"\n"; }
%}

/* semantic value types */
%union {
    char *sval; /* for NUMBER (string) */
    int   ival; /* for node indices */
}

/* tokens and typed nonterminals */
%token <sval> NUMBER
%type  <ival> expr term factor

%left '+' '-'
%left '*' '/'
%right UMINUS
%start input

%%

input:
      expr '\n'       { printNodes(); }
    | '\n'            { /* blank line */ }
    ;

expr:
      expr '+' term   { $$ = newNode("+", $1, $3); }
    | expr '-' term   { $$ = newNode("-", $1, $3); }
    | term            { $$ = $1; }
    ;

term:
      term '*' factor { $$ = newNode("*", $1, $3); }
    | term '/' factor { $$ = newNode("/", $1, $3); }
    | factor          { $$ = $1; }
    ;

factor:
      '(' expr ')'    { $$ = $2; }
    | NUMBER          { $$ = newNode($1, -1, -1); free($1); }
    | '-' factor %prec UMINUS { $$ = newNode("-u", $2, -1); }
    ;

%%
int main(int argc, char **argv){
    if(argc>1) { yyin = fopen(argv[1],"r"); if(!yyin){ perror("fopen"); return 1; } }
    else yyin = stdin;
    yyparse();
    return 0;
}
