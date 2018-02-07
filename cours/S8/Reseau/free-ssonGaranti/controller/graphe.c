#include "graphe.h"
#include "poisson.h"




char **str_split (char *s, const char *ct) // sépare la chaine de caractère par le délimiteur ct
{
   char **tab = NULL;

   if (s != NULL && ct != NULL)
   {
      int i;
      char *cs = NULL;
      size_t size = 1;

/* (1) */
      for (i = 0; (cs = strtok (s, ct)); i++)
      {
         if ((int) size <= i + 1)
         {
            void *tmp = NULL;

/* (2) */
            size <<= 1;
            tmp = realloc (tab, sizeof (*tab) * size);
            if (tmp != NULL)
            {
               tab = tmp;
            }
            else
            {
               fprintf (stderr, "Memoire insuffisante\n");
               free (tab);
               tab = NULL;
               exit (EXIT_FAILURE);
            }
         }
/* (3) */
	 tab[i] = cs;
         s = NULL;
      }
      tab[i] = NULL;
   }
   return tab;
}

Agnode_t * getNodeByLabel(Agraph_t *g, char* s){
  int i;
  Agnode_t * a = agfstnode(g);
  Agnode_t * tmp = NULL;
  // printf("agnnode = %d\n", agnnodes(g));
  for(i=0; i<graphSize(g); i++){
    // printf("toto %s %s \n", agget(a, "label"), s);
    if(strcmp(s, agget(a, "label")) == 0){

      tmp = a;
    }
    a = agnxtnode(g, a);
  }
  return tmp;
}

int graphSize(Agraph_t *g){
  return agnnodes(g);
}


void initBindLabel(char* label, int i){
  binder[0][i] = malloc(16*sizeof(char));
  binder[0][i] = label;
  binder[1][i] = malloc(8*sizeof(char));
  binder[1][i] = NULL;
}

void delBindLabel(char* label, int size){
  int i;
  for(i=0; i<size+1; i++){
    if(strcmp(binder[0][i], label) == 0)
      binder[1][i] = NULL;
  }
}


void controle_graph(Agraph_t *g){
  FILE* graph_file;
  char *line =  malloc(sizeof(char)*LIMITLINE);
  char *commande =  malloc(sizeof(char)*LIMITLINE);
  int i;
  char** args;
  FILE* graph_tmp;

  printf("Bienvenu dans le gestionnaire de graphe\n");
  while(1) {
    printf("A vous la main\n");
    fgets(line, LIMITLINE, stdin );
   if ((commande = strstr( line, "load")) != NULL && commande[4] ==  ' ' ){
     line = strchr(line, ' ');
     DelSpace(line);
     graph_file = fopen(line, "r+");
   
     aqua_tmp = new_aquarium(g);
   
     if (graph_file == NULL ){
        perror("fopen\n");
     }
     else {
      printf("Chargement du graphe sur le fichier %s\n", line);
      g = agread(graph_file, NULL);
      agwrite(g,stdout);
      graph_tmp = fopen("graphe.tmp", "r+");
      if (graph_tmp == NULL ){
	perror("fopen\n");
      }
      else {
	agwrite(g,graph_tmp);
      }
      Agnode_t * a = agfstnode(g);
      for(i=0; i< graphSize(g); i++){
	initBindLabel(agget(a, "label"), i);
	a = agnxtnode(g, a);
      }
     }
   }
   else if ((commande = strstr(line, "saved")) != NULL  && commande[5] ==  ' ' ){
     if (g == NULL) {
       printf(" Vous n'avez chargé aucun graphe, commande interdite.\n");
     }
     else {
       line = strchr(line, ' ');
	DelSpace(line);
	graph_file = fopen(line, "r+");
	if (graph_file == NULL ){
	  perror("fopen\n");
	}
	else {
	  printf("Chargement du graphe sur le fichier %s\n", line);
	  agwrite(g,graph_file);
	  agwrite(g,stdout);
	}
	printf("Sauvegarde du graphe\n");
     }
   }
   else if ((commande = strstr(line, "add link")) != NULL  && commande[8] ==  ' ' ){
     if (g == NULL) {
       printf(" Vous n'avez chargé aucun graphe, commande interdite.\n");
     }
     else {

       char del= ' ';
       Agnode_t *tmp1, *tmp2;
       args = str_split (line, &del);
       DelSpace(args[2]);
       DelSpace(args[3]);
       tmp1 = getNodeByLabel(g, args[2]);
       tmp2 = getNodeByLabel(g, args[3]);
       if (NULL != tmp1 && NULL != tmp2) {
	 agedge(g, tmp1,tmp2, NULL, TRUE);
	 printf("Ajout d'une arrete du graphe\n");
       }
       else
	 printf("Erreur sur les noms des noeuds\n");
     }
   }
   else if ((commande = strstr(line, "del link")) != NULL  && commande[8] ==  ' '){
     if (g == NULL) {
       printf(" Vous n'avez chargé aucun graphe, commande interdite.\n");
     }
     else {
       char del= ' ';
       Agnode_t *tmp1, *tmp2;
       Agedge_t *e;
       args = str_split (line, &del);
       DelSpace(args[2]);
       DelSpace(args[3]);
       tmp1 = getNodeByLabel(g, args[2]);
       tmp2 = getNodeByLabel(g, args[3]);
       if (NULL != tmp1 && NULL != tmp2) {
	 e = agedge(g, tmp1,tmp2, NULL, FALSE);
	 agdeledge(g,e);
	 printf("Suppression d'une arrete du graphe\n");
       }
       else
	 printf("Erreur\n");
     }
   }
   else if ((commande = strstr(line, "remove")) != NULL  && commande[6] ==  ' ' ){
     if (g == NULL) {
       printf(" Vous n'avez chargé aucun graphe, commande interdite\n.");
     }
     else {
       line = strchr(line, ' ');
       DelSpace(line);
       Agnode_t *ntmp;
       ntmp = getNodeByLabel(g, line);
       if(ntmp==NULL){
	 perror("Erreur noeud");
       }
       else{
	 agdelete(g, ntmp);
	 delBindLabel(line, graphSize(g));
	 printf("Suppression du noeud du graphe \n");
       }
     }
   }
   else if (strcmp(line,"show\n") == 0){
     if (g == NULL) {
       printf(" Vous n'avez chargé aucun graphe, commande interdite.\n");
     }
     else {
       printf("Affichage du graphe\n");
       agwrite(g,stdout);
     }
   }

   else if (strcmp(line,"quit\n") == 0){
     printf("Le programme quitte, Freesson Garantie !\n");
     return;
   }
   else {
     printf("Commande non reconnue, quit pour quitter\n.");
   }
  }
}

char* next_node(char* id_view, Agraph_t *g){
  FILE* graph_tmp;
  graph_tmp = fopen("graphe.tmp", "r+");
  if (graph_tmp == NULL ){
    perror("fopen\n");
  }  
  g = agread(graph_tmp, NULL);
    Agnode_t * tmp = NULL;
    Agnode_t *  a = NULL;
    tmp =  getNodeByLabel(g, id_view);
    a = agfstnode(g);
    while( a != NULL){
      printf("noeud= %s\n", agget(a, "label"));
	if (agfindedge(g, tmp, a) != NULL && strcmp(agget(tmp, "label"), agget(a, "label")) )
	  return agget(a, "label");
      a = agnxtnode(g, a);
    }
    return agget(tmp, "label");
}
