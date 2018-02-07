#include <cstdio>

#include "Chaine.hpp"

Chaine::Chaine():_taille(0) {
  _donnees = NULL;
}

Chaine::Chaine(const char *s) {
  // Cas s==NULL a gerer plus tard.
  _taille = std::strlen(s);

  _donnees = new char[_taille + 1];
  std::strcpy(_donnees, s);
  
  std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}

Chaine::Chaine(const Chaine &s) {
  // Cas s==NULL a gerer plus tard.
  _taille = s._taille;
  _donnees = new char[_taille +1];
  std::strcpy(_donnees, s._donnees);
  std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}

Chaine::~Chaine() {
  if (_donnees != NULL)
    delete[] _donnees;
  _donnees=NULL;
  std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}

unsigned int Chaine::taille() const{
    return _taille;
}

char Chaine::get(unsigned int i){
  if (_donnees==NULL) return '\0';
  if (i>_taille) return '\0';
  return _donnees[i];
}

void Chaine::debug() {
  printf("_donnees = %s \n", _donnees);
}


Chaine print(Chaine s) {
  s.debug();
  return s;  
}


// 
const Chaine& Chaine::operator=(const Chaine &c) {

  if(this == &c)
    return c;
  this->_taille = c._taille;
  
  if(_donnees != NULL)
    delete[] _donnees;
  
  _donnees = new char[_taille+1];
  
  if(_donnees)
    delete[]_donnees;
  if(c._donnees)
    std::strcy(_donnees, c._donnees);
  else
    _donnees = NULL;
  
  return *this;
}



char Chaine::operator[](unsigned int i) const {

  return _donnees[(i)];
}

