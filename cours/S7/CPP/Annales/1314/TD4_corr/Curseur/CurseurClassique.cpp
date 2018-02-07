#include"CurseurClassique.hpp"

namespace enseirb {
  
  CurseurClassique::CurseurClassique(const Chaine & chaine) :
    Curseur(chaine,0) {}
  
  CurseurClassique& CurseurClassique::operator++() {
    ++_position;
    return *this;
  }
  CurseurClassique& CurseurClassique::operator--() {
    --_position;
    return *this;
  }
  
  bool CurseurClassique::fini() {
    return _position >= this->getChaine().taille();
  }
  
  void CurseurClassique::debut() {
    _position=0;
  }
  
  void CurseurClassique::fin() {
    _position = this->getChaine().taille()-1;
  }
  
}// enseirb
