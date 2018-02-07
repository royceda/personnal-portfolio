#ifndef _GRAPHE_H_
#define _GRAPHE_H_

#include <stdio.h>
#include <stdlib.h>
#include <gvc.h>
#include <string.h>

#define LIMITLINE 80

#define LIMIT 10

char* binder[LIMIT][LIMIT];

char **str_split (char *s, const char *ct); // sépare la chaine de caractère par le délimiteur ct
void DelSpace(char* str);
Agnode_t * getNodeByLabel(Agraph_t *g, char* s);
void controle_graph();
char* next_node(char* id_view, Agraph_t *g);
int graphSize(Agraph_t *g);
void initBindLabel(char* label, int i);
void delBindLabel(char* label, int size);
#endif

