#ifndef __CURSEURI__
#define __CURSEURI__

#include "Curseur.hpp"

namespace enseirb{

  class CurseurInverse: public Curseur{
  private:
  public:
    CurseurInverse(const Chaine&);
    virtual void operator++();
    virtual void operator--();
    virtual bool fini();
    virtual void debut();
    virtual void fin();
    ~CurseurInverse() {};
  };

}
#endif
