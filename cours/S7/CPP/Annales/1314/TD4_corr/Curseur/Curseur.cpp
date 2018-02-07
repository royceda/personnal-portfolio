#include"Curseur.hpp"

namespace enseirb {
  
  Curseur::Curseur(const Chaine& chaine, unsigned depart)
    : _chaine(chaine), _position(depart) {
  }
  
  Chaine& Curseur::getChaine() {
    return _chaine;
  }
  
  char Curseur::operator*() {
    return _chaine[_position];
  }
  
  Curseur::~Curseur() {}
  
}// enseirb

