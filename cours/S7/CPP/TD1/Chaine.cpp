#include "Chaine.hpp"

#include <cstdio>
#include <cstring>
#include <cstdlib>


unsigned int Chaine::taille() { 
  return this->_taille;
}



/* Les constructeurs */


//Un vrai init
/*
  Chaine::Chaine():
  _taille(0), _donnees(NULL){} 
*/


 
Chaine::Chaine() {
_taille = 0;
_donnees = NULL;
printf("%s (%d): %s\n", __FILE__,__LINE__,__func__);
}


Chaine::Chaine(const char *s) {
_taille = std::strlen(s);
_donnees = (char *)std::malloc(_taille+1);
std::strcpy(_donnees,s);
printf("%s (%d): %s\n", __FILE__,__LINE__,__func__);
}


Chaine::~Chaine() {
if(_donnees)
  std::free(_donnees);
}
