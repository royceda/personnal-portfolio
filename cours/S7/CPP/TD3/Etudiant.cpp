#include "Etudiant.hpp"



namespace enseirb {

  Etudiant(const Chaine& nom,
	   const Chaine& filiere,
	   const Chaine& enseignement): Personne(nom), 
					_filiere(filiere), 
					_enseignement(enseignement) {}
  
  const Chaine& Etudiant::filiere() const {
    return _filiere;
  }
  
  const Chaine& Etudiant::enseignement() const{
    return _enseignement;
  }

  void setEnseignement(const Chaine & e) {
    _enseignement = e;
  }

  const Chaine& Etudiant::nom() const {
    static Chaine r;
    Chaine c("Etudiant:");
    r = c+Personne::nom();
    return r;            ;
  }

} //fin du namespace
