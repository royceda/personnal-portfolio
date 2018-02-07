#include "Curseur.hpp"

namespace enseirb{

  Curseur::Curseur(const Chaine &c):
    _position(0),
    _chaine(c){}

  char Curseur::operator*() const{
    return _chaine[_position];
  }

}
