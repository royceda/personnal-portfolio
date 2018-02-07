#include "Personne.hpp"
#include "Enseignant.hpp"
#include "Etudiant.hpp"
#include "EleveVacataire.hpp"
#include "./chaine3/Chaine.hpp"
#include <iostream>

using enseirb::Personne;
using enseirb::Enseignant;
using enseirb::Chaine;
using enseirb::Etudiant;
using enseirb::EleveVacataire;


void afficheNom(Personne &P){
  std::cout << "getname: " ;
  for(unsigned int i=0; i < P.nom().taille(); ++i)
      std::cout << P.nom()[i];

  std::cout<< "\n";
}


int main(){

  Chaine S("Prince");
  Personne *P = new Personne(S);
  afficheNom(*P);

  Chaine S1("Charlie Brown");
  Enseignant E(S1, 32);
  afficheNom(E);


  Chaine S2("Charlie Brown");
  Chaine B("Algo Proba");
  Chaine A("Info");
  Etudiant E1(S2, B, A);
  afficheNom(E1);
  
  
  Chaine S3("Tupac");
  Chaine B1("RO");
  Chaine A1("Info");
  EleveVacataire E2(S3, B1, A1, 24);
  afficheNom(E2);
  
  

  return 0;
}
