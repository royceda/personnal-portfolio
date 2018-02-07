#ifndef __PERSONNE__
#define __PERSONNE__

#include "./chaine3/Chaine.hpp"

namespace enseirb{
  class Personne{
  private:
    Chaine _nom;

  public:
    Personne(const Chaine );
    virtual Chaine nom() const;
  };
}

#endif
