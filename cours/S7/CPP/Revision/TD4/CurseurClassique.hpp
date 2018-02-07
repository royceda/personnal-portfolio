#ifndef __CURSEURC__
#define __CURSEURC__

#include "Curseur.hpp"

namespace enseirb{

  class CurseurClassique: public Curseur{
  private:
  public:
    CurseurClassique(const Chaine&);
    virtual void operator++();
    virtual void operator--();
    virtual bool fini();
    virtual void debut();
    virtual void fin();
    ~CurseurClassique() {};
  };

}
#endif
