#include "CurseurClassique.hpp"


CurseurClassique::CurseurClassique(const Chaine& chaine): Curseur(chaine,0) {
}


void CurseurClassique::avance(){
  if(!fini()){
    _position++;
  }
}

void CurseurClassique::recule(){
  if(_position > 0){
    _position--;
  }
}


bool CurseurClassique::fini(){
  return _position == (int)_chaine.taille()-1;
}


void CurseurClassique::debut(){
  _position = 0;
}

void CurseurClassique::fin(){
  _position = _chaine.taille()-1;
}



