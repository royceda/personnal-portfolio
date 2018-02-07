#include "Etudiant.hpp"
#include "./chaine3/Chaine.hpp"

namespace enseirb{
  static Chaine C1("Etudiant: ");

  Etudiant::Etudiant(Chaine &nom, Chaine &enseignement, Chaine &filiere):
    Personne(nom), _enseignement(enseignement), _filiere(filiere){}
  

  Chaine Etudiant::filiere()const{
    return _filiere;
  }

  Chaine Etudiant::enseignement()const{
    return _enseignement;
  }

  Chaine Etudiant::nom() const{
    return C1 + Personne::nom();
  }

  /*void Etudiant::setEnseignement(const Chaine &enseignment){
   _enseignement = enseignement;
   }*/
}
