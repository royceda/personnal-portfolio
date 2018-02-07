


typedef struct node_s {
  char kind; // kind of operation, or leaf
  struct node_s *left, *right; // NULL if leaf
  union {
    int i;
    float f;
    char *id;
  } leaf;
} node_t;



//creation d'un node
node_t *create(char kind, node_t *left, node_t *right) {
  node_t *n=malloc(sizeof(node_t));
  n->kind=kind;
  n->left=left;
  n->right=right;
  return n;
}



node_t *create_int(int i) {
  node_t *n=malloc(sizeof(node_t));
  n->kind='I'; // for leaf of type integer
  n->leaf.i=i;
  n->left=n->right=NULL;
  return n;
}



//representation des opérations
void print_node(node_t *n) {
  switch (n->kind) {
    // example for one leaf
  case 'I': printf("%d",n->leaf.i); break;
    // example for a binary operation
  case '+': print_node(n->left); printf("+"); print_node(n->right); break;
    /// for the assignment
  case '=': print_node(n->left); printf("="); print_node(n->right); break;
    ...
								      }
}


//action semantique

primary_expression
: ICONSTANT { $$ = create_int('I',$1); }
...
additive_expression
: multiplicative_expression { $$ = $1 ; }
| additive_expression '+' multiplicative_expression { $$ = create_node('+', $1, $3); }
...
expression
: IDENTIFIER '=' comparison_expression { $$ = create_node('=', create_id('V',$1), $3);
  print_node($$);
}

