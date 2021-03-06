#ifndef __ETUDIANT__
#define __ETUDIANT__

#include "chaine3/Chaine.hpp"
#include "Personne.hpp"

namespace enseirb{
  class Etudiant:public virtual Personne{
  private:
    Chaine _enseignement;
    Chaine _filiere;
  public:
    Etudiant(Chaine&, Chaine &, Chaine &);
    Chaine filiere() const;
    Chaine enseignement()const;
    void setEnseignement(const Chaine &);
    virtual Chaine nom() const;
  };
}


#endif
