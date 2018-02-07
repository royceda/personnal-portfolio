#ifndef __CURSEUR__
#define __CURSEUR__

#include "Chaine.hpp"

namespace enseirb{

  class Curseur{

  protected:
    unsigned int    _position;
    Chaine _chaine;
    
  public:
    Curseur(const Chaine&);
    virtual void operator++() = 0;
    virtual void operator--() = 0;
    char operator*() const;
    virtual bool fini() = 0;
    virtual void debut() = 0;
    virtual void fin() = 0;
    ~Curseur() {};
  };
}
#endif
