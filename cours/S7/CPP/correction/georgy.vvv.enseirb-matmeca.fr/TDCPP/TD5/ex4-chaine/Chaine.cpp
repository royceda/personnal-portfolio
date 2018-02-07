#include<cstdio>
#include<cstring>

#include "Chaine.hpp"


static char *dupliquer(const char* src, int taille) {
  if (NULL == src) 
    return NULL;

  char *tmp = new char[taille + 1];

  std::strcpy(tmp, src);
  return tmp;
}

Chaine::Chaine() : _taille(0), _donnees(NULL) {
}

Chaine::Chaine(const char *s) : _taille(::strlen(s)), _donnees(dupliquer(s, _taille)){
}

unsigned int Chaine::taille() const {
    return _taille;
}

char Chaine::operator[](int indice) const {
  if (NULL == _donnees)
    return '\0';
  return _donnees[indice];  
}

Chaine::operator char const *(void) const {
  return _donnees;
}


