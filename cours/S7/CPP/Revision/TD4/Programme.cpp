#include "CurseurClassique.hpp"
#include "CurseurInverse.hpp"
#include "CurseurPas.hpp"
#include "Curseur.hpp"
#include <cstdio>

using enseirb::Curseur;
using enseirb::CurseurClassique;
using enseirb::CurseurInverse;
using enseirb::CurseurPas;


void Classique(){

  printf("Parcour classique: \n\n");

  Chaine C("Bonjour");
  CurseurClassique Ite(C);
  
  
  Ite.debut();
  printf("Debut : %c \n", *Ite);
  ++Ite;
  printf("++Ite : %c \n", *Ite);
  --Ite;
  printf("--Ite : %c \n", *Ite);

  while(!Ite.fini())
    ++Ite;

  printf("Last : %c \n", *Ite);
  
  Ite.fin();
  printf("Fin : %c \n", *Ite);
}

void Inverse(){

  printf("Parcour inverse: \n\n");

  Chaine C("Bonjour");
  CurseurInverse Ite(C);
   
  Ite.debut();
  printf("Debut : %c \n", *Ite);
  ++Ite;
  printf("++Ite : %c \n", *Ite);
  --Ite;
  --Ite;
  printf("--Ite : %c \n", *Ite);

  while(!Ite.fini())
    ++Ite;

  printf("Last : %c \n", *Ite);
  
  Ite.fin();
  printf("Fin : %c \n", *Ite);
}


void Pas(){

  unsigned int start = 1, end = 5;
  int step = 1;

  printf("Parcour Pas: \n\n");

  Chaine C("Bonjour");
  CurseurPas Ite(C, start, end, step);
   
  Ite.debut();
  printf("Debut : %c \n", *Ite);
  ++Ite;
  printf("++Ite : %c \n", *Ite);
  --Ite;
  --Ite;
  printf("--Ite : %c \n", *Ite);

  while(!Ite.fini())
    ++Ite;

  printf("Last : %c \n", *Ite);
  
  Ite.fin();
  printf("Fin : %c \n", *Ite);
}


int main(){
  Classique();
  Inverse();
  Pas();
  return 0;
}
