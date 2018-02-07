#include "Chaine.hpp"
#include <cstdio>
#include <cstring>



using namespace std;

int Chaine::taille() {

  return _taille;
}



Chaine::Chaine() {
  printf("%s(%d): %s \n", __FILE__, __LINE__, __func__);
  _taille = 0;
}


Chaine::Chaine(const char *s){
  printf("%s(%d): %s \n", __FILE__, __LINE__, __func__);
  _taille = strlen(s);
  _donnees = new char[taille()+1];
  strcpy(_donnees, s);
}



char Chaine::get(unsigned int i){

  return _donnees[i];
}



Chaine::~Chaine(){
  if(taille())
    delete _donnees;
}
