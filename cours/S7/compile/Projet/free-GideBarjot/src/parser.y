%{
#include <stdio.h>
#include <string.h>
#include "table.h"
#include <stdlib.h>

  extern char yytext[];
  extern int column, yylineno;
  extern FILE *yyin;  
  char *file_name = NULL;
  struct table *T;
  struct type * type;
  enum _type retour;

  int yylex ();
  int yyerror ();
  void *malloc(size_t size);

  void printiint(int a){
    printf("%d",a);
  }

  void printfloat(float f){
    printf("%f",f);
  }
%}

%token <data.str> IDENTIFIER 
%token <data.val> ICONSTANT
%token <data.valf> FCONSTANT
%token INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token INT FLOAT VOID
%token IF ELSE WHILE RETURN FOR DO

%type<data> primary_expression
%type<data> argument_expression_list
%type<data> unary_expression
%type<data> multiplicative_expression
%type<data> additive_expression
%type<data> comparison_expression
%type<data> expression
%type<data> declaration
%type<data> declarator_list
%type<data> type_name
%type<data> declarator
%type<data> parameter_list
%type<data> parameter_declaration
%type<data> statement
%type<data> compound_statement
%type<data> declaration_list
%type<data> statement_list
%type<data> expression_statement
%type<data> selection_statement
%type<data> iteration_statement
%type<data> jump_statement
%type<data> program
%type<data> external_declaration
%type<data> function_definition

%union {
  struct data{
    int val;
    float valf;
    char *str;
    char *code;
    struct type{
      enum _type {_INT,_FLOAT,_VOID} t; //0:void,1:int,2:float
      int dimension;//0:primitif,>0: tableau
      struct type * retour;//null sauf pour les fonctions
      int nb_parametres;
      struct type * parametres;//null sauf pour les fonctions
    }*type;
    struct symbole{
      char * str;
      struct type *t;
      struct symbole *suivant;
    }*sym;
  }data;
}

%start program
%%

primary_expression
: IDENTIFIER {
  $$.code = malloc(sizeof(char));
  *($$.code) = '\0';

  $$.str = $1;
  struct type *t=cherche_symbole(T,$1);
  if(t == NULL){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  else{
    $$.type = malloc(sizeof(struct type));
    memcpy($$.type,t,sizeof(struct type));
  }
}
| ICONSTANT {
  $$.code=malloc(sizeof(char));
  *($$.code)='\0';
  //$$.val=$1; //deja fait par scanner.l
  $$.type=malloc(sizeof(struct type));
  $$.type->t=_INT;
  $$.type->dimension=0;
  $$.type->retour=NULL;
  $$.type->parametres=NULL;
  $$.type->nb_parametres=0;
}
| FCONSTANT {
  $$.code=malloc(sizeof(char));
  *($$.code)='\0';
  //$$.valf=$1; //deja fait par scanner.l
  $$.type=malloc(sizeof(struct type));
  $$.type->t=_FLOAT;
  $$.type->dimension=0;
  $$.type->retour=NULL;
  $$.type->parametres=NULL;
  $$.type->nb_parametres=0;
}
| '(' expression ')' {
  $$ = $2; //Pas .str ?
}
| IDENTIFIER '(' ')' {

  $$.code=malloc(sizeof(char));
  *($$.code)='\0';

  struct type* t= cherche_symbole(T,$1);
  if (NULL==t){    
    char s[] = "Fonction non déclarée.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->retour == NULL){
    char s[] = "Incompatibilité des déclarations.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->nb_parametres!=0){
    char s[] = "Nombre de paramètres incompatible. Attendu : 0.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }

  $$.type = t->retour;
  //$$.str = $1;
}
| IDENTIFIER '(' argument_expression_list ')' {
  $$.code=malloc(sizeof(char));
  *($$.code)='\0';

  struct type* t= cherche_symbole(T,$1);
  if (NULL==t){    
    char s[] = "Fonction non déclarée.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->retour == NULL){
    char s[] = "Incompatibilité des déclarations.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->nb_parametres!=0){
    char s[] = "Nombre de paramètres incompatible. Attendu : 0.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  int i;
  for (i=0;i<t->nb_parametres;i++){
    if(!compare_type_arguments(&t->parametres[i],&$3.type->parametres[i])){
      char s[] = "Nombre de paramètres incompatible.";
      yyerror(s);
      exit(EXIT_FAILURE);
    }
  }
  $$.type = t->retour;
  //$$.str = $1;
}
| IDENTIFIER INC_OP {
  $$.code=malloc(sizeof(char));
  *($$.code)='\0';
  struct type *t=cherche_symbole(T,$1);
  if (NULL==t){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  $$.type=malloc(sizeof(struct type));
  memcpy($$.type,t,sizeof(struct type));
  //$$.str = $1;
}
| IDENTIFIER DEC_OP {
  $$.code=malloc(sizeof(char));
  *($$.code)='\0';
  struct type *t=cherche_symbole(T,$1);
  if (NULL==t){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  $$.type=malloc(sizeof(struct type));
  memcpy($$.type,t,sizeof(struct type));
  //$$.str = $1;
}
| IDENTIFIER '[' expression ']' {
  $$.code=malloc(sizeof(char));
  *($$.code)='\0';
  struct type *t=cherche_symbole(T,$1);
  if (NULL==t){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->dimension > 0){
    char s[] = "Mauvaise déclaration : attendu tableau.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if( $3.type->t != _INT ){
    char s[] = "Pas un entier.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  //Extension : tester si expression appartient aux bornes : entre 0 et dimension(inclus pour 0)  
  if( ($3.val >= t->dimension) || ($3.val < 0) ){
    char s[] = "Débordement de tableau.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
}
;

argument_expression_list
: expression {
  $$.code = $1.code;
  $$.type = malloc(sizeof(struct type));
  $$.type->nb_parametres = 1;
  $$.type->parametres = $1.type;
}
| argument_expression_list ',' expression {
  int k=$1.type->nb_parametres+1;
  struct type *t=malloc(sizeof(struct type)*k);
  memcpy(t,$1.type->parametres,sizeof(struct type)*(k-1));
  t[k-1]=*($3.type);
  $$.type->parametres=t;
  $$.type->nb_parametres=k;
  //code
}
;

unary_expression
: primary_expression {
  $$ = $1;
}
| '-' unary_expression {
  if( $2.type->t != _INT || $2.type->t != _FLOAT ){
    char s[] = "Opposé d'un type interdit.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if( $2.type->t == _INT ){
    $2.val = -$2.val;
  }
  else{
    $2.valf = -$2.valf;
  }
  $$ = $2;
}
| '!' unary_expression{
  if( $2.type->t != _INT || $2.type->t != _FLOAT ){
    char s[] = "Opposé d'un type interdit.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if( $2.type->t == _INT ){
    $2.val = !$2.val;
  }
  else{
    $2.valf = !$2.valf;
  }
  $$ = $2;
}
;

multiplicative_expression
: unary_expression {
  $$ = $1;
}
| multiplicative_expression '*' unary_expression {
  if( ($1.type->t == _VOID) || ($3.type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }

  if( ($1.type->t == _INT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code ?
    $$.val = $1.val * $3.val;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code
    $$.valf = $1.valf * $3.val;
  }
  else if( ($1.type->t == _INT) && ($3.type->t == _FLOAT) ){
    $$ = $3;
    //code
    $$.valf = $1.val * $3.valf;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    //code
    $$.valf = $1.valf * $3.valf;
  }
}
;

additive_expression
: multiplicative_expression {
  $$ = $1;
}
| additive_expression '+' multiplicative_expression {
  if( ($1.type->t == _VOID) || ($3.type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }

  if( ($1.type->t == _INT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code ?
    $$.val = $1.val + $3.val;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code
    $$.valf = $1.valf + $3.val;
  }
  else if( ($1.type->t == _INT) && ($3.type->t == _FLOAT) ){
    $$ = $3;
    //code
    $$.valf = $1.val + $3.valf;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    //code
    $$.valf = $1.valf + $3.valf;
  }
}
| additive_expression '-' multiplicative_expression {
  if( ($1.type->t == _VOID) || ($3.type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }

  if( ($1.type->t == _INT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code ?
    $$.val = $1.val - $3.val;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code
    $$.valf = $1.valf - $3.val;
  }
  else if( ($1.type->t == _INT) && ($3.type->t == _FLOAT) ){
    $$ = $3;
    //code
    $$.valf = $1.val - $3.valf;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    //code
    $$.valf = $1.valf - $3.valf;
  }
}
;

comparison_expression
: additive_expression{
  $$ = $1;
}
| additive_expression '<' additive_expression {
  if( ($1.type->t == _VOID) || ($3.type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ($1.type->t == _INT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code ?
    $$.val = $1.val < $3.val;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _INT) ){
    $$ = $3;
    //code
    $$.val = $1.valf < $3.val;
  }
  else if( ($1.type->t == _INT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    //code
    $$.val = $1.val < $3.valf;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    $$.type = _INT;
    //code
    $$.val = $1.valf < $3.valf;
  }
}
| additive_expression '>' additive_expression {
  if( ($1.type->t == _VOID) || ($3.type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ($1.type->t == _INT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code ?
    $$.val = $1.val > $3.val;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _INT) ){
    $$ = $3;
    //code
    $$.val = $1.valf > $3.val;
  }
  else if( ($1.type->t == _INT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    //code
    $$.val = $1.val > $3.valf;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    $$.val = _INT;
    //code
    $$.val = $1.valf > $3.valf;
  }
}
| additive_expression LE_OP additive_expression {
  if( ($1.type->t == _VOID) || ($3.type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ($1.type->t == _INT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code ?
    $$.val = $1.val <= $3.val;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _INT) ){
    $$ = $3;
    //code
    $$.val = $1.valf <= $3.val;
  }
  else if( ($1.type->t == _INT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    //code
    $$.val = $1.val <= $3.valf;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    $$.type = _INT;
    //code
    $$.val = $1.valf <= $3.valf;
  }
}
| additive_expression GE_OP additive_expression {
  if( ($1.type->t == _VOID) || ($3.type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ($1.type->t == _INT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code ?
    $$.val = $1.val >= $3.val;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _INT) ){
    $$ = $3;
    //code
    $$.val = $1.valf >= $3.val;
  }
  else if( ($1.type->t == _INT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    //code
    $$.val = $1.val >= $3.valf;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    $$.type = _INT;
    //code
    $$.val = $1.valf >= $3.valf;
  }
}
| additive_expression EQ_OP additive_expression {
  if( ($1.type->t == _VOID) || ($3.type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ($1.type->t == _INT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code ?
    $$.val = $1.val == $3.val;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _INT) ){
    $$ = $3;
    //code
    $$.val = $1.valf == $3.val;
  }
  else if( ($1.type->t == _INT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    //code
    $$.val = $1.val == $3.valf;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    $$.type = _INT;
    //code
    $$.val = $1.valf == $3.valf;
  }
}
| additive_expression NE_OP additive_expression {
  if( ($1.type->t == _VOID) || ($3.type->t == _VOID)){
    char s[] = "Multiplication de VOID interdite.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  
  if( ($1.type->t == _INT) && ($3.type->t == _INT) ){
    $$ = $1;
    //code ?
    $$.val = $1.val != $3.val;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _INT) ){
    $$ = $3;
    //code
    $$.val = $1.valf != $3.val;
  }
  else if( ($1.type->t == _INT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    //code
    $$.val = $1.val != $3.valf;
  }
  else if( ($1.type->t == _FLOAT) && ($3.type->t == _FLOAT) ){
    $$ = $1;
    $$.type = _INT;
    //code
    $$.val = $1.valf != $3.valf;
  }
}
;

expression
: IDENTIFIER '=' comparison_expression {
  struct type *t=cherche_symbole(T,$1);
  if (NULL==t){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->t == _VOID){
    char s[] = "Type VOID non compatible avec comparaison.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }

  if( t->t == _INT ){
    $$.type = malloc(sizeof(struct type));
    memcpy($$.type,t,sizeof(struct type));
    //code
    $$.val = $3.val;
  }
  else if( t->t == _FLOAT ){
    $$.type = malloc(sizeof(struct type));
    memcpy($$.type,t,sizeof(struct type));
    //code
    $$.valf = $3.val;
  }
}
| IDENTIFIER '[' expression ']' '=' comparison_expression {
  struct type *t=cherche_symbole(T,$1);
  if (NULL==t){
    char s[] = "Non déclaré.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if(t->t == _VOID){
    char s[] = "Type VOID non compatible avec comparaison.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if( t->dimension == 0 ){
    char s[] = "Pas un tableau.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  //EXTENSION expression doit être compris entre 0 et dimension, 0 inclus
  if( ($3.val >= t->dimension) || ($3.val < 0) ){
    char s[] = "Débordement de tableau.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
  if( t->t == _INT ){
    $$.type = malloc(sizeof(struct type));
    memcpy($$.type,t,sizeof(struct type));
    //code
    $$.val = $3.val;
  }
  else if( t->t == _FLOAT ){
    $$.type = malloc(sizeof(struct type));
    memcpy($$.type,t,sizeof(struct type));
    //code
    $$.valf = $3.val;
  }
}
| comparison_expression {
  $$ = $1;
}
;

declaration
: type_name declarator_list ';' {
  //code
  struct symbole *s=$2.sym;
  enum _type type_name;
   
  type_name = $1.type->t;
  
  while(s!=NULL){
    s->t->t=type_name;
    ajout_symbole(T,s->str,s->t);
    s = s->suivant;
  }
}
;

declarator_list
: declarator {
  //code
  $$.sym=malloc(sizeof(struct symbole));
  $$.sym->str=$1.str;
  $$.sym->t=$1.type;
  $$.sym->suivant=NULL;

}
| declarator_list ',' declarator {
  $$.sym=malloc(sizeof(struct symbole));
  $$.sym->str=$3.str;
  $$.sym->t=$3.type; 
  $$.sym->suivant=$1.sym;
  //code
}
;

type_name
: VOID {
  $$.type = malloc(sizeof(struct type));
  $$.type->t = _VOID;
}
| INT {
  $$.type = malloc(sizeof(struct type));
  $$.type->t = _INT;
}
| FLOAT {
  $$.type = malloc(sizeof(struct type));
  $$.type->t = _FLOAT;
}
;

declarator
: IDENTIFIER {
  $$.type = malloc(sizeof(struct type));
  $$.type->dimension = 0;
  $$.type->retour = NULL;
  $$.type->parametres = NULL;
  $$.type->nb_parametres = 0; 
  $$.str = $1;
}
| '*' IDENTIFIER {
  $$.type = malloc(sizeof(struct type));
  $$.type->dimension = 42; //Ceci est un pointeur. Nous ne savons pas gérer les malloc
  $$.type->retour = NULL;
  $$.type->parametres = NULL;
  $$.type->nb_parametres = 0;
  $$.str = $2;
}
| IDENTIFIER '[' ICONSTANT ']' {
  $$.type = malloc(sizeof(struct type));
  $$.type->dimension = $3; //Là on peut !
  $$.type->retour = NULL;
  $$.type->parametres = NULL;
  $$.type->nb_parametres = 0;
  $$.str = $1;
}
| declarator '(' parameter_list ')' {
  $$.type = malloc(sizeof(struct type));
  $$.type->dimension = 0;
  $$.type->retour = NULL;
  $$.type->parametres = $3.type->parametres;
  $$.type->nb_parametres = $3.type->nb_parametres;
  $$.str = $1.str;
}
| declarator '(' ')' {
  $$.type = malloc(sizeof(struct type));
  $$.type->dimension = 0;
  $$.type->retour = NULL;
  $$.type->parametres = NULL;
  $$.type->nb_parametres = 0;
  $$.str = $1.str;
}
;

parameter_list
: parameter_declaration {
  struct type *param = malloc(sizeof(struct type));
  param->t = $1.type->t;
  param->dimension = 0;
  param->retour = NULL;
  param->parametres = NULL;
  param->nb_parametres = 0;
 
  $$.type->parametres = param;
}
| parameter_list ',' parameter_declaration {
  int k = $1.type->nb_parametres+1;
  struct type *t = malloc(sizeof(struct type)*k);
  memcpy(t,$1.type->parametres,sizeof(struct type)*(k-1));
  t[k-1] = *($3.type);
  $$.type->parametres = t;
  $$.type->nb_parametres = k;
  //code
}
;

parameter_declaration
: type_name declarator {
  $$ = $2;
  $$.type->t = $1.type->t;
}
;

statement
: compound_statement //A voir en fonction de la suite
| expression_statement{ 
  $$ = $1;
  }
| selection_statement{
  $$ = $1;
  }
| iteration_statement{
  $$ = $1;
  }
| jump_statement{
  $$ = $1;
  }
;

compound_statement
: '{' '}' {} 
| '{' { T = nouvelle_table(T);} statement_list '}' { 
  T = T->englobante;
 }
| '{'{T = nouvelle_table(T);} declaration_list statement_list '}'{
  T = T->englobante;  
  }
;

declaration_list
: declaration{
  //TODO
 }
| declaration_list declaration{
  //TODO
 }
;

statement_list
: statement {
  //TODO
}
| statement_list statement
;

expression_statement
: ';' {}
| expression ';' {
  $$ = $1;
}
;

selection_statement
: IF '(' expression ')' statement {
  if( $3.val != 0 )
    $$ = $5;
  //Extension : return
}
| IF '(' expression ')' statement ELSE statement {
  if( $3.val != 0 )
    $$ = $5;
  else
    $$ = $7;
}
;

iteration_statement
: WHILE '(' expression ')' statement {
  if( $3.val != 0 )
    $$ = $5;
}
| FOR '(' expression_statement expression_statement expression ')' statement {
  if( $4.val != 0 )
    $$ = $7;
}
|FOR '('expression_statement expression_statement expression ')' expression {
  if( $4.val != 0)
    $$ = $7; 
  
}
| DO statement WHILE '(' expression ')' {
  $$ = $2;
}
;

jump_statement
: RETURN ';' {
  if( retour != _VOID ){
    char s[] = "Type de retour faux : VOID attendu.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
}
| RETURN expression ';' {
  if( ($2.type->t != retour) && ($2.type->t == _VOID) ){
    char s[] = "Type de retour faux.";
    yyerror(s);
    exit(EXIT_FAILURE);
  }
}
;

program
: external_declaration {
  //code remonté à écrire
 }
| program external_declaration {
  //code remonté à écrire
}
;

external_declaration
: function_definition {
  //code
}
| declaration {
  //code
}
;

function_definition
: type_name declarator { 
  retour = $1.type->t; 
  if ($1.type->dimension > 0) {
    char s[] = "Retour de tableau invalide";
    yyerror(s);
    exit(EXIT_FAILURE);
  } 
 } compound_statement {
   $$.type = $2.type;
   $$.type->retour = malloc(sizeof(struct type));
   $$.type->retour->dimension = 0;
   $$.type->retour->retour = NULL;
   $$.type->retour->nb_parametres = 0;
   $$.type->retour->parametres = NULL;
   $$.type->retour->t = retour;
   ajout_symbole(T,$2.str,$$.type);
   }
;

%%
int yyerror (char *s) {
  fflush (stdout);
  fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
  return 0;
}


int main (int argc, char *argv[]) {
  FILE *input = NULL;
  T=nouvelle_table(NULL);
  if (argc==2) {
    input = fopen (argv[1], "r");
    file_name = strdup (argv[1]);
    if (input) {
      FILE *output = NULL;
      char *output_file_name = strdup (argv[1]);
      yyin = input;
      output_file_name[strlen(output_file_name)-1] = 's';
      output = fopen (output_file_name, "w");
      if (output){
	yyparse();
	fclose(output);
      }
      else{
	fprintf (stderr, "%s: Could not open %s.\n", *argv, output_file_name);
	return 1;
      }
      free(output_file_name);
      fclose(input);
    }
    else {
      fprintf (stderr, "%s: Could not open %s.\n", *argv, argv[1]);
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
