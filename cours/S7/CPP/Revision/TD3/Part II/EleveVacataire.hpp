#ifndef __ELEVEVACATAIRE__
#define __ELEVEVACATAIRE__

#include "Personne.hpp"
#include "Etudiant.hpp"
#include "Enseignant.hpp"


namespace enseirb{
  class EleveVacataire: public Etudiant,
			public Enseignant{
  private:
  public:
    EleveVacataire(Chaine &, Chaine &, Chaine &, int );
    virtual Chaine nom() const;
    
  };
}

#endif
