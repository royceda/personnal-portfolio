#include "CurseurInverse.hpp"


namespace enseirb{

  CurseurInverse::CurseurInverse(const Chaine &C):
    Curseur(C) {}

  void CurseurInverse::operator++(){
    if(!fini())
      _position--;
  }

  void CurseurInverse::operator--(){
    if( _position != _chaine.taille()-1)
      _position++;
  }
  
  bool CurseurInverse::fini(){
    if(_position == 0)
      return true;
    else 
      return false;
  }

  void CurseurInverse::debut(){
    _position = _chaine.taille()-1;
  }

  void CurseurInverse::fin(){
    _position = 0;
  }
}
