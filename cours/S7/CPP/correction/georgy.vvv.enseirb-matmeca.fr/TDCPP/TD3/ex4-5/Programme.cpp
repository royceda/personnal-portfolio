#include <iostream>

#include "Personne.hpp"
#include "Etudiant.hpp"
#include "Enseignant.hpp"

//using enseirb::Chaine;
//using enseirb::Personne;

using namespace enseirb;

void afficheNom(const Personne & p) {
  std::cout << "nom = " << p.nom() << std::endl;
}

int main(){
  Personne p("Amel");
  afficheNom(p);

  enseirb::Etudiant cyprien("Cyprien","Info");
  afficheNom(cyprien);

  Enseignant ens("Georgy",192);
  afficheNom(ens);
}
