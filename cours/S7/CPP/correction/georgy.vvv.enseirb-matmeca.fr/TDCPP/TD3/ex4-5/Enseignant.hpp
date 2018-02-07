#ifndef ENSEIGNANT_HPP
#define ENSEIGNANT_HPP

#include "Personne.hpp"

namespace enseirb {

  class Enseignant : public Personne {
  private:
    int _nbHeures;

  public:
    Enseignant(const Chaine& nom, int nbHeures);
    int nbHeures() const;
    
    virtual Chaine nom() const;
  };
}
#endif
