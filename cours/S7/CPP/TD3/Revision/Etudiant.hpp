
#ifndef __ETUDIANT__
#define __ETUDIANT__

#include "Personne.hpp"

namespace enseirb {

  class Etudiant : public virtual Personne{
  private :
    Chaine _filiere;
    Chaine _enseignement;
    
  public :
    Etudiant(const Chaine &, const Chaine &);
    Chaine filiere();
    Chaine enseignement();
    void setEnseignement(const Chaine &);
    virtual Chaine nom() const;
    ~Etudiant() {}
  };
  
}
#endif
