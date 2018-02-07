%{
#include <stdio.h>
int num_lines = 0, num_chars = 0, num_float = 0, num_int = 0;
%}
DIGIT [0-9]
FLOAT {DIGIT}+"."{DIGIT}*
%%
\n       { ++num_lines;}
.        { ++num_chars;}
{FLOAT}  { ++num_float; printf("float: %s\n",yytext);}
{DIGIT}+ { ++num_int; printf("integer: %s\n",yytext);}
%%

int main() {
yylex();
printf(" # of lines = %d,\n # of float = %d\n # of chars = %d \n # of int = %d \n", num_lines, num_float, num_chars, num_int);
}

