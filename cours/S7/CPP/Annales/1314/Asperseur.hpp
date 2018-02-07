#ifndef __ASPERSEUR__
#define __ASPERSEUR__

#include "Arroseur.hpp"

namespace Arrossage{
  class Asperseur:public Arroseur{
  private:
  public:
    Asperseur();
    virtual void demarrer();
    virtual void arreter();
    virtual bool estEnMarche();
    virtual double quantiteEau();
    virtual double debit();
    ~Asperseur(){};
  };
}


#endif
