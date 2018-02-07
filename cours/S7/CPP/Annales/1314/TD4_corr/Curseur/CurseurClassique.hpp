#ifndef CURSEUR_CLASSIQUE_HPP
#define CURSEUR_CLASSIQUE_HPP

#include"Curseur.hpp"

namespace enseirb {
  
  class CurseurClassique : public Curseur {
  public:
    CurseurClassique(const Chaine&);
    CurseurClassique& operator++();
    CurseurClassique& operator--();
    bool fini() ;
    void debut() ;
    void fin();
    
  };
  
}// enseirb

#endif // CURSEUR_CLASSIQUE_HPP
