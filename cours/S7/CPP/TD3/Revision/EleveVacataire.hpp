#ifndef __ELEVEVACATAIRE__
#define __ELEVEVACATAIRE__


#include "Etudiant.hpp"
#include "Enseignant.hpp"

namespace enseirb {

  class EleveVacataire : public Enseignant, public Etudiant {
  public:
    EleveVacataire(const Chaine &nom, const Chaine &filiere, const int service);
    virtual Chaine nom();
  }; 
}

#endif
