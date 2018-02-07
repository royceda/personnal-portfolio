#ifndef __ETUDIANT_HPP__
#define __ETUDIANT_HPP__

#include "./chaine3/Chaine.hpp"
#include "Personne.hpp"

namespace enseirb {

  class Etudiant: public Personne {

  private:
    Chaine _filiere;
    Chaine _enseignement;

  public:
    Etudiant(const Chaine& nom, 
	     const Chaine& filiere,
	     const Chaine& enseignement);
    const Chaine& filiere() const;
    const Chaine& enseignement() const;
    void setEnseignement(const Chaine& e);
    const Chaine& nom() const;
    ~Etudiant();


  };
} // fin du  namespace

#endif
