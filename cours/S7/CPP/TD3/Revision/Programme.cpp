#include <iostream>

#include "../../TD2/Revision/Chaine.cpp" 
#include "Personne.cpp"


using enseirb::Personne;

void afficheNom(const Personne & p) {

std::cout <<"nom=" << p.nom() << std::endl;
}



int main() {
  
  Chaine nom("Royce");
  Personne p(nom);
  
  
  return 0;
}
