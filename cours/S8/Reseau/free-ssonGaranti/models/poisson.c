#include"poisson.h"x

void addFishList(struct poisson* poisson, struct listPoisson* listFish){
  listFish->tabpoisson[listFish->number] = poisson;
  listFish->number ++;
}



struct poisson* selectFish(char* name, struct listPoisson* listFish){
  for ( int i =0; i< listFish->number; i ++){
    if (strcomp(name, listFish->tabPoisson[i]->nom) == 0) {
      return listFish[i];
    }
  }
  printf("Poisson Inéxistant");
  return NULL;
}

void delFishList(char* name, struct listPoisson* listFish){
  if (selectFish(name, listFish) == NULL){ //On test si le poisson est présent dans l'aquarium, je sais pas encore s'il faut tester l'appartenance du poisson à la liste complete ou bien a l'appartenance à la liste des poisson qui appartiennent au noeud
     printf("Poisson inéxistant");
     return;
  }
  // struct poisson* delPoisson = selectFish(tabLine[1], listFish);
    for (int i =0; i< listFish->number; i ++){
      if (strcomp(name, listFish->tabPoisson[i]->nom) == 0) {
	free(listFish->tabPoisson[i]);
	listFish->tabPoisson[i] = listFish->tabPoisson[i+1]
	  }
    }
    number--;
}

struct listPoisson* newFishList(){
  struct listPoisson* fishList = malloc(sizeof(struct listPoisson));
  fishList-> maxFish = 100;
  fishList-> number = 0;
  fishList->tabPoisson = malloc(fishList->maxFish*sizeof(struct poisson*));
  return fishList;
}


void setPosition(int x, int y, struct position* position){
  position->x=x;
  position->y=y;
}

struct poisson* initFish(char* name, int xe, int ye, int xd, int yd, char* deplacement){
  struct poisson* poisson = malloc(sizeof(struct poisson));
  poisson->nom = name;
  setPosition(xe, ye, poisson->posDepart);
  setPosition(xd, yd, poisson->posArrivee);
  poisson->deplacement = deplacement;
  return poisson;
}

void addFish(char* line, struct listPoisson listFish){  //gestion d'erreur non fait
  char **tabLine = str_split(line, ' ');
  char **positions  = str_split(tabLine[3], ',');
  char **positionEx = str_split(positions[0], 'x');
  char **positionDes = str_split(positions[1], 'x');
  struct poisson* newFish = initFish(tabLine[0], atoi(positionEx[0]),atoi(positionEx[1]),  atoi(positionDes[0]),atoi(positionDes[1]), tabLine[4]);
  addFishList(newFish, listFish);
}

void delFish(char* line, struct listPoisson* listFish ){
  char** tabLine =  str_split(line, ' ');
  char* name = tabLine[1];
  delFishList(name, listFish);
}
