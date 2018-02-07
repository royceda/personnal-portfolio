%{
    #include <stdio.h>
    extern int lineno;
    extern int cno;
    int yylex ();
    int yyerror ();
%}

%token <n> N
%union {
  int n;
}
%start S
%%

S
: E 
;

E
: T '+' E 
| T '-' E 
| T
;

T
: F '*' T
| F
;

F
: N   
| '(' E ')'
;

%%
#include <stdio.h>
#include <string.h>

extern char yytext[];

int yyerror (char *s) {
    fflush (stdout);
    fprintf (stderr, "line %d column %d: %s\n", lineno, cno,s);
    return 0;
}

int main (int argc, char *argv[]) {
    yyparse ();
    return 0;
}
