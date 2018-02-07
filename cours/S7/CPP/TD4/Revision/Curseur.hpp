#ifndef __CURSEUR__
#define __CURSEUR__

#include "Chaine.hpp"

nammespace enseirb{
  
  class Curseur {
  protected:
    Chaine _chaine;
    int    _position;

  public:
    Curseur(int , const Chaine &);
    const Cusreur& operator++ ();
    const Curseur& operator-- ();
    bool    fini();
    Curseur debut();
    Curseur fin();
    ~Curseur() {};
  };
}

#endif
