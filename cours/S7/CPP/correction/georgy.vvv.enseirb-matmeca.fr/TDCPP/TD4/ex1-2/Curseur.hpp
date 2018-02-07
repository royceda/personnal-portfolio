#ifndef CURSEUR_HPP
#define CURSEUR_HPP

#include "Chaine.hpp"

class Curseur{
protected:
  Chaine _chaine;
  int _position;
  
public:
  Curseur(const Chaine&,int);

  virtual void avance()=0;  //méthode abstraite
  virtual void recule()=0;
  char donne();

  virtual bool fini()=0;
  virtual void debut()=0;
  virtual void fin()=0;

  char operator*();
  //Curseur operator++(int); //POSTFIX
  const Curseur& operator++(); //PREFIX
  //void operator--();

};

#endif
