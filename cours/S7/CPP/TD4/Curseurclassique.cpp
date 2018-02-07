#include "CurseurClassique.hpp"


CurseurClassique::CurseurClassique(const Chaine &chaine) :
  Cursor(chaine, 0) {}

CurseurClassique::operator++() {} //++curs
CurseurClassique::operator++(int) {} //curs++
 

CurseurClassique::operator--() {}
CurseurClassique::operator*() {}
CurseurClassique::fini(){}
CurseurClassique::debut(){}
CurseurClassique::fin(){}
