#include <cstdio>
#include "Chaine.hpp"


int main(int argc, char** argv){
  Chaine maChaine; //allocation automatique et instanciation de la classe Chaine
  Chaine * monPointeur=NULL; //allocation automatique de la variable sans instanciation
  monPointeur = new Chaine(); // allocation dynamique et instanciation
  std::printf( "taille maChaine : %u \ntaille chaine pointee : %u \n", 
	       maChaine.taille(),monPointeur->taille());

  Chaine laChaineDantoine("georgy est vraiment très très beau");
  Chaine* laChaineDolivier = new Chaine("Antoine est beau\0");

  std::printf( "taille laChaineDolivier : %u \n", laChaineDolivier->taille()); 
   std::printf( "taille laChaineDantoine : %u \n", laChaineDantoine.taille()); 

  delete laChaineDolivier;
  delete monPointeur;
  return 0;
}
