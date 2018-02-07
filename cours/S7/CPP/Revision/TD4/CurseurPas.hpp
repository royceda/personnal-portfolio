#ifndef __CURSEURP__
#define __CURSEURP__

#include "Curseur.hpp"

namespace enseirb{
  
  class CurseurPas: public Curseur{
  private:
    unsigned int _start;
    unsigned int _end;
    int _step;
    
  public:    
    CurseurPas(const Chaine&, unsigned int, unsigned int, int );
    virtual void operator++();
    virtual void operator--();
    virtual bool fini();
    virtual void debut();
    virtual void fin();
    ~CurseurPas() {};

  };
}

#endif
