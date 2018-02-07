#ifndef ETUDIANT_HPP
#define ETUDIANT_HPP
#include"Personne.hpp"

namespace enseirb{
  class Etudiant : public Personne{
  private :
    Chaine _filiere;
    Chaine _enseignement;
    Chaine _gName;
  public :
    Etudiant(const Chaine &nom, const Chaine &filiere);
    Chaine filiere();
    Chaine enseignement();
    void setEnseignement(const Chaine& ens);
    virtual Chaine nom() const;
    virtual const Chaine & getName();
  };
}
#endif
