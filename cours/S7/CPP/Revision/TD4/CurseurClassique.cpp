#include "CurseurClassique.hpp"

namespace enseirb{

  CurseurClassique::CurseurClassique(const Chaine &c):
    Curseur(c){}


  void CurseurClassique::operator++(){
    if(!this->fini())
      _position++;
  }

  void CurseurClassique::operator--(){
    if(_position > 0)
      _position--;
  }

  bool CurseurClassique::fini(){
    if( _position == _chaine.taille() - 1)
      return true;
    else 
      return false;
  }
    
  void CurseurClassique::debut(){
    _position = 0;
  }

  void CurseurClassique::fin(){
    _position = _chaine.taille()-1;
  }
  
}
