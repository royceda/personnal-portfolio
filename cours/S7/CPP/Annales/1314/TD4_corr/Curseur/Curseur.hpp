#ifndef CURSEUR_HPP
#define CURSEUR_HPP 
#include<Chaine.hpp>

namespace enseirb {
  
  class Curseur {
    Chaine _chaine;
  protected:
    unsigned _position;
    Curseur(const Chaine& chaine, unsigned depart);
    Chaine& getChaine();
  public:
    virtual Curseur& operator++() =0;
    virtual Curseur& operator--() =0;
    char operator*();
    virtual bool fini() =0;
    //Place le curseur sur la premiere position valide
    virtual void debut() =0;
    //Place le curseur sur la derniere position valide
    virtual void fin() =0;
    virtual ~Curseur();
  };
  
}// enseirb

#endif //CURSEUR_HPP
