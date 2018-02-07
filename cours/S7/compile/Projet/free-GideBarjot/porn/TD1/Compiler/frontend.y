%{
    #include <stdio.h>
    extern int yylineno;
    int yylex ();
    int yyerror ();

%}

%token <str> IDENTIFIER CONSTANT
%union {
	char *str;
}
%start S
%%

F
: IDENTIFIER  { printf("F -> id(%s)\n",$1); }
| CONSTANT    { printf("F -> cst(%s)\n",$1); }
| '(' E ')'   { printf("F -> ( E )\n"); }
;

T
: F           { printf("T -> F\n"); }
| T '*' F     { printf("T -> T * F\n"); }
;

E
: T           { printf("E -> T\n"); }
| E '+' T     { printf("E -> E + T\n"); }
| E '-' T     { printf("E -> E - T\n"); }
;

I
: IDENTIFIER '=' E ';' { printf("I -> id(%s) = E;\n",$1); }
;

S
: I              { printf("S -> I\n"); }
| S I            { printf("S -> S I \n"); }
;

%%
#include <stdio.h>
#include <string.h>

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (char *s) {
    fflush (stdout);
    fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
    return 0;
}


int main (int argc, char *argv[]) {
    FILE *input = NULL;
    if (argc==2) {
	input = fopen (argv[1], "r");
	file_name = strdup (argv[1]);
	if (input) {
	    yyin = input;
	}
	else {
	  fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
	    return 1;
	}
    }
    else {
	fprintf (stderr, "%s: error: no input file\n", *argv);
	return 1;
    }
    yyparse ();
    free (file_name);
    return 0;
}
