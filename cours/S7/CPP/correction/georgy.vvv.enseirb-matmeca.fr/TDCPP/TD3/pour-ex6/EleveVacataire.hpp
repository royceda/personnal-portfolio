#ifndef ELEVEVACATAIRE_HPP
#define ELEVEVACATAIRE_HPP

#include "Etudiant.hpp"
#include "Enseignant.hpp"

class EleveVacataire //heritage multipe 
 {

 public:
  EleveVacataire(const Chaine& nom, const Chaine& filiere, int nbHeures);

  //const Chaine nom() const;
};
#endif
