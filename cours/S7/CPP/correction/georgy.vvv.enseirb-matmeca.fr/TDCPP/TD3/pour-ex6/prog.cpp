#include <iostream>

#include "Personne.hpp"
#include "EleveVacataire.hpp"

void afficheNom(const Personne &p) {
  std::cout << "getNom: " << p.getNom() << ", nom: " << p.nom() << "\n";
}

int main() {
  Personne un("Moi");

  afficheNom(un);

  EleveVacataire v("Finch", "info3", 2);
  //std::cout << v.nom() << "\n";
  //afficheNom(v); 
}
