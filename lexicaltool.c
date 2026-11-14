Save the following file as lexer.l.



%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"if"|"else"|"while"|"return" {
    printf("%s : Keyword\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("%s : Identifier\n", yytext);
}

[0-9]+ {
    printf("%s : Number\n", yytext);
}

[+\-*/=<>] {
    printf("%s : Operator\n", yytext);
}

[;,(){}] {
    printf("%s : Special Symbol\n", yytext);
}

[ \t\n]+    ;

"//".*      ;

. {
    printf("%s : Invalid Character\n", yytext);
}
%%

int main()
{
    printf("Enter the input:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}




%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"if"|"else"|"while"|"return" {
    printf("%s : Keyword\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("%s : Identifier\n", yytext);
}

[0-9]+ {
    printf("%s : Number\n", yytext);
}

[+\-*/=<>] {
    printf("%s : Operator\n", yytext);
}

[;,(){}] {
    printf("%s : Special Symbol\n", yytext);
}

[ \t\n]+    ;

"//".*      ;

. {
    printf("%s : Invalid Character\n", yytext);
}
%%

int main()
{
    printf("Enter the input:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}


Step 1: Generate the C file.
flex lexer.l

Step 2: Compile the generated C file.
gcc lex.yy.c -o lexer -lfl

Step 3: Execute the program.
./lexer

Enter the input:
int a = 10;

int : Keyword
a : Identifier
= : Operator
10 : Number
; : Special Symbol