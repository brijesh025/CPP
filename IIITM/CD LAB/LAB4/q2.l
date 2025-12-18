%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

FILE *infile, *outfile;

int is_vowel(char c){
    c=tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
%}

%%

[[:alpha:]]+ {
    char word[1024];
    strcpy(word, yytext);

    if(is_vowel(word[0])){
        fprintf(outfile,"%say",word);
    } else {
        fprintf(outfile,"%s%cay",word+1,word[0]);
    }
}

[^[:alpha:]]+ {
    fprintf(outfile,"%s",yytext);
}

%%

int yywrap(){return 1;}

int main(){
    infile=fopen("input_file.txt","r");
    if(!infile){
        printf("Error: input_file.txt not found.\n");
        return 1;
    }
    outfile=fopen("output_file.txt","w");
    if(!outfile){
        printf("Error: cannot open output_file.txt for writing.\n");
        fclose(infile);
        return 1;
    }

    yyin=infile;
    yylex();

    fclose(infile);
    fclose(outfile);
    return 0;
}
