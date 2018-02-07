#include<cstdio>

#include "Chaine.hpp"

static char * copie(const char * source, int taille) {
  char * dest ;
  dest = new char[taille + 1] ;
  std::strcpy(dest, source) ;
  return dest ;
}

Chaine::Chaine():_taille(0) {
  _donnees=NULL;
}

Chaine::Chaine(const char *s) {
  // Cas s==NULL a gerer plus tard.
  _taille = std::strlen(s);
  _donnees = copie(s, _taille) ;
  std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}

Chaine::Chaine(const Chaine & s) {
  _taille = s._taille ;
  _donnees = copie(s._donnees, _taille) ;
  printf("opérateur par recopie\n") ;
}

Chaine::~Chaine() {
  if (_donnees != NULL)
    delete[] _donnees;
  _donnees=NULL;
  std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}


const Chaine& Chaine::operator=(const Chaine& s){
  if(this == &s)
    return *this;

  if (_donnees != NULL)
    delete [] _donnees;

  _taille = s._taille ;
  _donnees = copie(s._donnees, _taille) ;
  return *this;
}

char Chaine::operator[](unsigned int indice) const {
  return _donnees[indice];
}

char& Chaine::operator[](unsigned int indice){
  return _donnees[indice];
}


unsigned int Chaine::taille() const {
  return _taille;
}

char Chaine::get(unsigned int i){
  if (_donnees==NULL) return '\0';
  if (i>_taille) return '\0';
  return _donnees[i];
}

void Chaine::debug() const {
  printf("%s\n", this->_donnees) ;
}

