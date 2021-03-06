#include<cstdio>
#include <cstring>
#include "Chaine.hpp"

Chaine::Chaine():_taille(0) {
  _donnees=NULL;
}

Chaine::Chaine(const char *s) {
  // Cas s==NULL a gerer plus tard.
  _taille = std::strlen(s);

  _donnees = new char[_taille + 1];
  std::strcpy(_donnees, s);
  
  std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
}

Chaine::Chaine(const Chaine &c){
  
  _taille = c.taille();
  _donnees = new char[_taille+1];
  strcpy(_donnees, c._donnees);
  
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



const Chaine& Chaine::operator=(const Chaine &c){
  
  _taille = c.taille();
  _donnees = new char[_taille+1];
  strcpy(_donnees, c._donnees);
  return *this;
}

char Chaine::get(unsigned int i){
  if (_donnees==NULL) return '\0';
  if (i>_taille) return '\0';
  return _donnees[i];
}


void Chaine::debug(){
  printf("donnees: %s\n", _donnees);
}

char& Chaine::operator[](unsigned int index){

  return _donnees[index];
}

Chaine::operator char* () const{
  
  return _donnees;
}

Chaine* Chaine::operator+ (const Chaine &C1) const{

  Chaine *C = new Chaine;

  C->_taille = taille() + C1.taille();
  C->_donnees = new char[C->_taille+1];

  strcpy(C->_donnees, _donnees);
  strcat(C->_donnees, C1._donnees);
  return C;
}

