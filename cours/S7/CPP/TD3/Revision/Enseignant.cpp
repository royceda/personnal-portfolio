#include "Enseignant.hpp"

namespace enseirb {

  Enseignant::Enseignant(const Chaine &nom, const int &service) :
    Personne(nom), _service(service) {}


  int Enseignant::nbHeure() {
    return _service;
  }

  Chaine Enseignant::nom() {
    Chaine s1("Enseignant");
    s1 = s1 + Personne::nom();
    return s1;
  }

}
