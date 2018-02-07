#include "Chaine.hpp"
#include <cstdio>

Chaine::Chaine(){
  printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
}

Chaine::~Chaine(){
  printf("%s(%d): %s\n",__FILE__,__LINE__,__func__);
}


unsigned int Chaine::taille(){
  return _taille;
}
