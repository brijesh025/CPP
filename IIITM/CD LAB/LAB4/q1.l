%{
    #include <stdio.h>
    #include <string.h>
    FILE *infile, *outfile;
%}

%%

[ \n\t]+    { fprintf(outfile, " "); }
.           { fprintf(outfile, "%s", yytext); }

%%

int yywrap() { return 1; }

int main() {
    infile = fopen("input_file.txt", "r");
    if (!infile) {
        printf("Error: input_file.txt not found.\n");
        return 1;
    }
    outfile = fopen("output_file.txt", "w");
    if (!outfile) {
        printf("Error: cannot open output_file.txt for writing.\n");
        fclose(infile);
        return 1;
    }

    yyin = infile;  // Flex reads from this stream
    yylex();

    fclose(infile);
    fclose(outfile);
    return 0;
}
