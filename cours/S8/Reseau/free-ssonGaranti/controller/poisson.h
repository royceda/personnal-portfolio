#ifndef __POISSON_H__
#define __POISSON_H__

#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include <gvc.h>
#include <string.h>


#define MAX_BUFF 2048
#define MAX_FISH 25
#define PIXEL_BOX 5

#define DEST_X 15
#define DEST_Y 15
struct aquarium *aqua_tmp ;

struct coordonnees {
  int x;
  int y;
};

struct poisson {
  int id;
  char* name;
  char* image;
  char* id_view;
  //int id_destination;
  struct coordonnees* courant_coord;
  struct coordonnees* rectangle_coord;
  struct coordonnees* destination_coord;
  char* routine;
  int time;
  int isStart; // je sais pas encore si cela va servir.
 // on est pas sur
};


struct aquarium {
  struct poisson* tab_poisson[MAX_FISH];
  //int noeuds;
  int nb_poisson;
  Agraph_t *g; // graphe dans l'aquarium
};


void add_aqua(struct poisson *poisson, struct aquarium *aqua);
struct aquarium* new_aquarium(Agraph_t *g);
char* getFishes(char* id_view, struct aquarium* aqua);
struct coordonnees* init_coordonne(int x, int y);
int addFish(char* line, struct aquarium *aqua); // return 0
int delFish(char* name, struct aquarium *aqua); // return 0 si le poisson a été supprimé, 1 s'il n'existe pas dans la liste
void change_noeud(struct poisson *poisson, char* new_view);
char* status(char* view, struct aquarium *aqua); // renvoie le nom des poissons qui sont dans la view
int startFish(char* line, struct aquarium *aqua);// return 0 si le start marche, 0 sinon
struct poisson* getPoissonByName(char* name, struct aquarium *aqua); // renvoi un pointeur vers la struct poisson du poisson Name
void RandomWayPoint(struct poisson*, struct aquarium*);
void RandomWPAll(struct aquarium*);
#endif
