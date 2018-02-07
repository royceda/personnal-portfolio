#include "poisson.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "graphe.h"


///mettre un graph et l'aquarium principal en global

void RandomWayPoint( struct poisson* poisson , struct aquarium* aqua ){ // graphe dans l'aquarium
  srand(time (NULL));
  int x = rand()%PIXEL_BOX;
  int y = rand()%PIXEL_BOX;
  int neg1 = rand()%2;
  int neg2 = rand()%2;
  if (neg1 == 0)
    neg1 = -1;
  if( neg2 == 0)
    neg2 = -1;
  printf("nouvelle pos = %dx%d\n", poisson->courant_coord->x + x*neg1, poisson->courant_coord->y + y*neg2);
  if ( (poisson->courant_coord->x + x*neg1 < 100 &&  poisson->courant_coord->y + y*neg2 < 100) &&  (poisson->courant_coord->x + x*neg1 > 0 && poisson->courant_coord->y + y*neg2 > 0 )){
    poisson->isStart = 1;
    poisson->courant_coord->x += x*neg1;
    poisson->courant_coord->y += y*neg2;
    poisson->time = 1;
  }
  else {
    poisson->id_view = next_node(poisson->id_view, aqua->g);
    printf("nouveau view = %s\n",poisson->id_view);
    poisson->courant_coord->x = DEST_X;
    poisson->courant_coord->y = DEST_Y;
  }
}

void RandomWPAll( struct aquarium* aqua){
  int i = 0;
  for (i = 0; i < aqua->nb_poisson; i++){
    if( aqua->tab_poisson[i]->isStart == 1){
      RandomWayPoint(aqua->tab_poisson[i], aqua); 
    }
  }
}

struct aquarium* new_aquarium(Agraph_t *g){
  struct aquarium* new_aqua = malloc(sizeof(struct aquarium));
  int i = 0;
  for (i = 0; i< MAX_FISH; i++){
   new_aqua->tab_poisson[i] = malloc(sizeof(struct poisson));
  }
  new_aqua->g = g;
  new_aqua->nb_poisson = 0;
  return new_aqua;
}

struct coordonnees* init_coordonne(int x, int y){
  struct coordonnees *coord = malloc(sizeof(struct coordonnees));
  coord->x = x;
  coord->y = y;
  return coord;
}

void add_aqua(struct poisson *poisson, struct aquarium *aqua){

  if ( aqua->nb_poisson == MAX_FISH)
    printf("Aquarium plein");
  // aqua->tab_poisson = realloc(aqua->tab_poisson, aqua->nb_poisson*sizeof(struct poisson));
  aqua->tab_poisson[aqua->nb_poisson] = poisson;
  aqua->nb_poisson =   aqua->nb_poisson +1;
}


int addFish(char* line, struct aquarium* aqua) {
  struct poisson *poisson = malloc(sizeof(struct poisson));
  char** tab_line = str_split(line, " ");
  int x = atoi(tab_line[3]);
  int y = atoi(tab_line[4]);
  poisson->name = malloc(sizeof(char)*MAX_BUFF);
  poisson->image = malloc(sizeof(char)*MAX_BUFF);
  poisson->routine = malloc(sizeof(char)*MAX_BUFF);
  poisson->id_view = malloc(sizeof(char)*MAX_BUFF);

  strcat(poisson->name, tab_line[1]);
  poisson->time = 0;
  poisson->courant_coord = init_coordonne(x, y);

  x = atoi(tab_line[5]);
  y = atoi(tab_line[6]);

  poisson->rectangle_coord = init_coordonne(x, y);
  strcat(poisson->image, tab_line[2]);


  strcat(poisson->id_view, tab_line[8]);

  strcat(poisson->routine, tab_line[7]);
  poisson->destination_coord = init_coordonne(0,0);
 
  add_aqua(poisson, aqua);
  
  // printf("id_view est %s\n ",aqua->tab_poisson[aqua->nb_poisson - 1 ]->id_view);
  return 0;
}

int delFish(char* line_name, struct aquarium *aqua){
  int i;
  char** tab_line = str_split(line_name, " ");
  char* name = tab_line[1];
  for (i = 0; i< aqua->nb_poisson; i++){
    if (strncmp(aqua->tab_poisson[i]->name, name, strlen(aqua->tab_poisson[i]->name -1)) == 0){
      free(aqua->tab_poisson[i]);
      aqua->tab_poisson[i] = aqua->tab_poisson[aqua->nb_poisson];
      aqua->nb_poisson = aqua->nb_poisson -1;
      //   aqua->tab_poisson = realloc(aqua->tab_poisson, aqua->nb_poisson*sizeof(struct poisson));
      return 0;
    }
  }
  return 1;
}

struct poisson* getPoissonByName(char* name, struct aquarium *aqua){
  int i;
  // name[strlen(name)-1]='\0';
 for (i = 0; i< aqua->nb_poisson; i++){
   fprintf(stderr, "la nom est %s le nom du poisson est :%s\n",name, aqua->tab_poisson[i]->name);
   if (strncmp(aqua->tab_poisson[i]->name, name, strlen(aqua->tab_poisson[i]->name)-1) == 0)
      return aqua->tab_poisson[i];
 }
 return NULL;
}

void change_noeud(struct poisson *poisson, char* new_view){
  poisson->id_view = new_view;
}

char* status(char* view, struct aquarium *aqua){
  char* list_poisson = malloc(MAX_BUFF*sizeof(char));
  int i;
  printf(" il y a %d poisson\n", aqua->nb_poisson);
  if (aqua->nb_poisson == 0){
    //  list_poisson = strcat(list_poisson, "pas de poisson");
     return "Pas de poisson";
  }
  for (i = 0; i< aqua->nb_poisson; i++){
  
    if ( strcmp(aqua->tab_poisson[i]->id_view, view) == 0) {
      list_poisson = strcat(list_poisson, aqua->tab_poisson[i]->name);
      list_poisson = strcat(list_poisson, " ");
    }
  }
  list_poisson = strcat(list_poisson, "\n");
  return list_poisson;
}

char* getFishes(char* id_view, struct aquarium* aqua){
  char* line = malloc(MAX_BUFF*sizeof(char));
  char* fishes = malloc(MAX_BUFF*sizeof(char));
  
  int i = 0;
  if (aqua->nb_poisson == 0){
    strcat(fishes, "[];");
  }
  for (i= 0; i< aqua->nb_poisson; i++) {
    if ( strcmp(aqua->tab_poisson[i]->id_view, id_view) == 0) {
      // printf("id_view est %s view est %s\n ",aqua->tab_poisson[i]->id_view, id_view);
      // printf("name est %s\n ",aqua->tab_poisson[i]->name);
      //printf("routine est %s\n ",aqua->tab_poisson[i]->routine);
      //printf("image est %s\n ",aqua->tab_poisson[i]->image);
      //printf("dest coord est %d, %d\n ",aqua->tab_poisson[i]->destination_coord->x, aqua->tab_poisson[i]->destination_coord->y);
      //printf("rec coord est %d, %d\n ",aqua->tab_poisson[i]->rectangle_coord->x, aqua->tab_poisson[i]->rectangle_coord->y);
     
      sprintf(line, "[%s at %dx%d, %dx%d, %s];",aqua->tab_poisson[i]->name,aqua->tab_poisson[i]->courant_coord->x, aqua->tab_poisson[i]->courant_coord->y, aqua->tab_poisson[i]->rectangle_coord->x, aqua->tab_poisson[i]->rectangle_coord->y, aqua->tab_poisson[i]->id_view);
      strcat(fishes, line);
    
      
    }

  }
  // free(line);
  strcat(fishes, "\n");
  return fishes;

}

int startFish(char* line, struct aquarium* aqua){
  fprintf(stderr, "toto2\n");
  char** tab_line = str_split(line, " ");
  char* name = tab_line[1];
  struct poisson *tmp_fish = getPoissonByName(name, aqua);
 
  if (tmp_fish == NULL) {
     fprintf(stderr, "le poisson est manquant\n");
    return 1;
  }
  if(strcmp(tmp_fish->routine, "RandowWayPoint")){
    tmp_fish->isStart = 1;
    return 0;
  } 
  return 1;
}
