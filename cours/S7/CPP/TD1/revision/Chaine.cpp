#include "Chaine.hpp"
#include <cstring>
#include <cstdio>
#include <cstdlib>


int Chaine::taille() {
  
  return _taille;
}


Chaine::Chaine() {
  
  _taille = 0;
  _donnees = NULL;
  printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}


Chaine::Chaine(const char *str) {

  _taille = strlen(str);
  _donnees = new char(_taille+1);
  strcpy(_donnees,str);
}


char Chaine::get(unsigned int i) {

  if( i > _taille)
    return '\0';

  return _donnees[i];
}

Chaine::~Chaine() {

  if(_donnees != NULL)
    delete _donnees;
  printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}

