#include"CurseurInverse.hpp"

namespace enseirb {
  
  CurseurInverse::CurseurInverse(const Chaine & chaine) :
    Curseur(chaine,chaine.taille()-1) {
  }
  
  CurseurInverse& CurseurInverse::operator++() {
    --_position;
    return *this;
  }
  CurseurInverse& CurseurInverse::operator--() {
    ++_position;
    return *this;
  }
  
  bool CurseurInverse::fini() {
    return _position >= this->getChaine().taille(); // !_position unsigned
  }
  
  void CurseurInverse::debut() {
    _position=this->getChaine().taille()-1;
  }
  
  void CurseurInverse::fin() {
    _position = 0;
  }
  
}// enseirb
