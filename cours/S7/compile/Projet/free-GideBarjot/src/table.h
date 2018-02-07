#ifndef TABLE_H
#define TABLE_H

struct table{
  struct symbole *premier;
  struct table * englobante;
};

struct type *cherche_symbole(struct table *t,char* id);
int verif_type_operation(struct type* a,struct type* b,char c);
int verif_type_moins(struct type *t);
int verif_type_prod_scalaire(struct type *a,struct type *b);
int verif_type_comp(struct type *a,struct type *b);
int verif_type_access(struct type *a);
int verif_type_affect(struct type *a,struct type *b,char * affect_type);
void ajout_symbole(struct table * courante,char * id,struct type *t);
struct table * nouvelle_table(struct table * englo);
void delete_type(struct type * t);
void delete_symboles(struct symbole * s);
struct table *delete_table(struct table * courante);
int compare_type_arguments(struct type*a,struct type *b);

#endif
