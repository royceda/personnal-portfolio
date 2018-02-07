%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
int lineno=0;
int cno=0;
%}
%%
[0-9]+		{cno+=strlen(yytext); yylval.n=atoi(yytext);return N;}
"+"             {cno++;return '+'; }
"-"             {cno++;return '-'; }
"*"             {cno++;return '*'; }
"("             {cno++;return '('; }
")"             {cno++;return ')'; }
.		{cno++;}
\n		{cno=0; lineno++;}
%%
int yywrap() {
	return 1;
}
