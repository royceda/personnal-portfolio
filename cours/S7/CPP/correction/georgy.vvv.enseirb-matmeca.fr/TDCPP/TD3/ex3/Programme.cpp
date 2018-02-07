#include <iostream>

#include "Chaine.hpp"
#include "Personne.hpp"

using enseirb::Chaine;
using enseirb::Personne;

Chaine annexe(Chaine u, Chaine t) {
  return u + t;
}


void affiche(const Chaine &s){
  std::cout << "AFFICHE <";
  for(unsigned int i = 0; i < s.taille(); i++)
    std::cout << s[i];
  std::cout << ">" << std::endl;
}

void afficheNom(const Personne & p) {
	std::cout << "nom = " << p.nom() << std::endl;
	//affiche(p.nom());
}
int main(){
  Personne p("Amel");

  afficheNom(p);
}
