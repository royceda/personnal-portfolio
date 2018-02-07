%{
#include <stdio.h>
#include "parser.h"
  extern int yylineno;
  int yylex ();
  int yyerror ();
%}

%token <str> IDENTIFIER
%token <val> ICONSTANT
%token <valf> FCONSTANT
%type <type_s> declarator
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token INT FLOAT VOID
%token IF ELSE WHILE RETURN FOR
%token DO
%union {
  char *str;
  int val;
  float valf;
  struct type_s t_s;
}
%start program
%%

primary_expression
: IDENTIFIER { printf("Valeur de l'attribut str : %s\n", $1); }
| ICONSTANT { printf("Valeur de l'attribut val : %d\n", $1); }
| FCONSTANT { printf("Valeur de l'attribut valf : %f\n", $1); }
| '(' expression ')'
| IDENTIFIER '(' ')' { printf("Valeur de l'attribut str : %s\n", $1); }
| IDENTIFIER '(' argument_expression_list ')' { printf("Valeur de l'attribut str : %s\n", $1); }
| IDENTIFIER INC_OP { printf("Valeur de l'attribut str : %s\n", $1); }
| IDENTIFIER DEC_OP { printf("Valeur de l'attribut str : %s\n", $1); }
| IDENTIFIER '[' expression ']' { printf("Valeur de l'attribut str : %s\n", $1); }
;

argument_expression_list
: expression
| argument_expression_list ',' expression
;

unary_expression
: primary_expression
| '-' unary_expression
| '!' unary_expression
;

multiplicative_expression
: unary_expression
| multiplicative_expression '*' unary_expression
;

additive_expression
: multiplicative_expression
| additive_expression '+' multiplicative_expression
| additive_expression '-' multiplicative_expression
;

comparison_expression
: additive_expression
| additive_expression '<' additive_expression
| additive_expression '>' additive_expression
| additive_expression LE_OP additive_expression
| additive_expression GE_OP additive_expression
| additive_expression EQ_OP additive_expression
| additive_expression NE_OP additive_expression
;

expression
: IDENTIFIER '=' comparison_expression
| IDENTIFIER '[' expression ']' '=' comparison_expression
| comparison_expression
;

declaration
: type_name declarator_list ';'
;

declarator_list
: declarator
| declarator_list ',' declarator
;

type_name
: VOID {yylval.t_s.is_int_float_void = 2;}
| INT  {yylval.t_s.is_int_float_void = 0;}
| FLOAT {yylval.t_s.is_int_float_void = 1;}
;

declarator
: IDENTIFIER { printf("Valeur de l'attribut str : %s\n", $1); }
| '*' IDENTIFIER { printf("Valeur de l'attribut str : %s\n", $2); }
| IDENTIFIER '[' ICONSTANT ']' { printf("Valeur de l'attribut str : %s\n", $1); printf("Valeur de l'attribut val : %d\n", $3); }
| declarator '(' parameter_list ')'
| declarator '(' ')'
;

parameter_list
: parameter_declaration {yylval.t_s.size++;}
| parameter_list ',' parameter_declaration
;

parameter_declaration
: type_name declarator {struct type_s new; yylval.t_s.params = &new;}
;

statement
: compound_statement
| expression_statement 
| selection_statement
| iteration_statement
| jump_statement
;

compound_statement
: '{' '}'
| '{' statement_list '}'
| '{' declaration_list statement_list '}'
;

declaration_list
: declaration
| declaration_list declaration
;

statement_list
: statement
| statement_list statement
;

expression_statement
: ';'
| expression ';'
;

selection_statement
: IF '(' expression ')' statement
| IF '(' expression ')' statement ELSE statement
;

iteration_statement
: WHILE '(' expression ')' statement
| FOR '(' expression_statement expression_statement expression ')' statement
| DO statement WHILE '(' expression ')'
;

jump_statement
: RETURN ';'
| RETURN expression ';'
;

program
: external_declaration
| program external_declaration
;

external_declaration
: function_definition {yylval.t_s.is_fun = 1; yylval.t_s.size = 0;}
| declaration {yylval.t_s.is_fun = 0; yylval.t_s.size = 0;}
;

function_definition
: type_name declarator compound_statement
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
	    yyparse();
	}
	else {
	  fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
	    return 1;
	}
	free(file_name);
    }
    else {
	fprintf (stderr, "%s: error: no input file\n", *argv);
	return 1;
    }
    return 0;
}
