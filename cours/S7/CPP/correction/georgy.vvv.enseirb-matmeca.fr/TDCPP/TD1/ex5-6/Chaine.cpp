#include <cstdio>
#include <cstring>
#include "Chaine.hpp"

static const char FIN = '\0';

Chaine::Chaine(){
  _donnees = (char *)&FIN;
  _taille = 0;
  std::printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
}

Chaine::Chaine(const char* toto){
  _donnees = new char[strlen(toto) + 1];
  _taille = strlen(toto);
  strcpy(_donnees, toto);
  std::printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
}

Chaine::~Chaine(){
  if (_donnees != &FIN)
    delete[] _donnees;
  std::printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
}


unsigned int Chaine::taille(){
  return _taille;
}

char Chaine::get(unsigned int i){
  if(i>_taille)
    return '\0';

  return _donnees[i];
}
