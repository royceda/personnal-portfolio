
#include "Enseignant.hpp"

namespace enseirb {

  static const Chaine enseignant("Enseignant ");
  
  Enseignant::Enseignant(const Chaine& nom, int nbHeures) : 
    Personne(nom), _nbHeures(nbHeures) {
  }
  
  int Enseignant::nbHeures() const {
    return _nbHeures;
  }
  
  Chaine Enseignant::nom() const {
    return enseignant + Personne::nom();
  }
}
