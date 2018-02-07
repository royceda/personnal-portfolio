#ifndef __POISSON_H__
#define __POISSON_H__
#include <stdio.h>
#include <stdlib.h>
#include"../controller/test_graphe.h"
struct position{
  int x;
  int y;
};

struct poisson{
  char* nom;
  struct position * posDepart;
  struct position * posArrivee;
  char* deplacement;
  char* nodeLabel;
};

struct listPoisson{
  struct poisson** tabPoisson;
  int number;
  int maxFish;
};

struct listPoisson* newFishList();
void addFishList(struct poisson* poisson, struct listPoisson* listFish);
void delFishList(char* namePoisson, struct listPoisson* listFish);
struct poisson* selectFish(char* line, struct listPoisson* listFish);

void setPosition(int x, int y, struct position *position);


struct poisson* initFish(char* name, int xe, int ye, int xd, int yd, char* deplacement); 
void addFish(char* line, listPoisson* poissonTab);

void delFish(char* line, struct listPoisson* poissonList );
void startFish(char* line);
	     
#endif
