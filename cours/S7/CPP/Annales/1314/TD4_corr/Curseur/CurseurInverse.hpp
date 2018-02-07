#ifndef CURSEUR_INVERSE_HPP
#define CURSEUR_INVERSE_HPP

#include"Curseur.hpp"

namespace enseirb {
  
  class CurseurInverse : public Curseur {
  public:
    CurseurInverse(const Chaine&);
    CurseurInverse& operator++();
    CurseurInverse& operator--();
    bool fini() ;
    void debut() ;
    void fin();
    
  };

}//enseirb

#endif // CURSEUR_INVERSE_HPP
