#ifndef __PERSONNE__
#define __PERSONNE__


#include "../../TD2/Revision/Chaine.hpp" 

namespace enseirb {

  class Personne {

  private:
    Chaine _nom;
    
  public:
    Personne(const Chaine &);
    virtual Chaine nom() const;
    ~Personne();
  };
}


#endif
