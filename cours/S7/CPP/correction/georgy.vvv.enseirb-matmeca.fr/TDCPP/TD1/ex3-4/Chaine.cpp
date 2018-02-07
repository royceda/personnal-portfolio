#include <cstdio>
#include <cstring>
#include "Chaine.hpp"

Chaine::Chaine(){
  _donnees = NULL;
  _taille = 0;
  printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
}

Chaine::Chaine(const char* toto){
  _donnees = new char[strlen(toto) + 1];
  _taille = strlen(toto);
  strcpy(_donnees, toto);
  printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
}

Chaine::~Chaine(){
  if (_donnees != NULL)
    delete[] _donnees;
  printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
}


unsigned int Chaine::taille(){
  return _taille;
}
