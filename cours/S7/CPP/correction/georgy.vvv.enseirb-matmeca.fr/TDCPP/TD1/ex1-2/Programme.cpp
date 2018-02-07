#include <cstdio>
#include "Chaine.hpp"


int main(int argc, char** argv){
  Chaine maChaine; //allocation automatique et instanciation de la classe Chaine
  Chaine * monPointeur=NULL; //allocation automatique de la variable sans instanciation
  monPointeur = new Chaine(); // allocation dynamique et instanciation
  std::printf( "taille maChaine : %u \ntaille chaine pointee : %u \n", 
	       maChaine.taille(),monPointeur->taille());
  delete monPointeur;
  return 0;
}
