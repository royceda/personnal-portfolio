#include "Curseur.hpp"


Curseur::Curseur(const Chaine& chaine, int pos)
  : _chaine(chaine), _position(pos)
{
}


char Curseur::donne(){
  return _chaine[_position];
}


char Curseur::operator*(){
  return donne();
}

const Curseur& Curseur::operator++(){
  avance();
  return *this;
}


// Curseur Curseur::operator++(int){
//   Curseur tmp = *this;
//   avance();
//   return tmp;
// }





