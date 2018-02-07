#include <cstdio>
#include "Chaine.hpp"

Chaine::Chaine(): _taille(0) {
  _donnees = NULL;
}

Chaine::Chaine(const char *s) {
  // Cas s==NULL a gerer plus tard.
  _taille = std::strlen(s);

  _donnees = new char[_taille + 1];
  std::strcpy(_donnees, s);
  
  std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}

Chaine::~Chaine() {
  if (_donnees != NULL)
    delete[] _donnees;
  _donnees=NULL;
  std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}


Chaine::Chaine(const Chaine &s){

  _taille = s.taille();

  _donnees = new char[_taille+1];
  strcpy(_donnees, s._donnees);
}


void Chaine::debug() {

  printf("donnees: %s \n", _donnees);
}

unsigned int Chaine::taille() const{
    return _taille;
}

char Chaine::get(unsigned int i){
  if (_donnees==NULL) return '\0';
  if (i>_taille) return '\0';
  return _donnees[i];
}


const Chaine& Chaine::operator= (const Chaine &s) {
  
  if(_donnees != NULL)
    delete[] _donnees;

  _donnees = new char[s.taille()+1];
  strcpy(_donnees, s._donnees);

  return *this;
}

char& Chaine::operator[] (unsigned int i) {

  return _donnees[i];
}


char *Chaine::operator char* () const{
  
  return _donnees;
} 



Chaine Chaine::operator+ (const Chaine &C1) {

  Chaine C;
  C._taille = C1.taille() + taille();
  C._donnees = new char[C.taille()+1];
  strcpy(C._donnees, _donnees);
  strcat(C._donnees, C1._donnees);

  return C;
}
