#include <cstdio>
#include "Chaine.hpp"

void annexe(Chaine s){}

int main(int argc, char** argv){
  /*  Chaine maChaine; //allocation automatique et instanciation de la classe Chaine
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

  Chaine strClem("Bonjour Monde");
  Chaine * strVinc = new Chaine("Hello World");

  int i;
  for(i=0; i<6; i++)
    std::printf("Caractère %u de la Chaine \"strClem\" est : %c\n", i, strClem.get(i));
  
  for( i=0; i<7; i++)
    std::printf("Caractère %u de la Chaine \"strVinc\" est : %c\n", i, strVinc->get(i));

  delete strVinc;
  */

  Chaine c("toto titi");

  annexe(c);

  return 0;
}
