#ifndef CURSEUR_CLASSIQUE_HPP
#define CURSEUR_CLASSIQUE_HPP

#include "Curseur.hpp"


class CurseurClassique:public Curseur{
public:
  CurseurClassique(const Chaine&);
  
  virtual void avance();
  virtual void recule();

  virtual bool fini();
  virtual void debut();
  virtual void fin();
  

};


#endif
