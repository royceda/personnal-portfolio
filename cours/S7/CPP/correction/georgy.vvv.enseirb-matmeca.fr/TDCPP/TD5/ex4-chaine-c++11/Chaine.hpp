#ifndef CHAINE_HPP
#define CHAINE_HPP

#include "SmartPointer.hpp"

class Chaine {
private:
  unsigned int _taille;
  enseirb::SmartArray<char> _donnees;
  
 public:
  Chaine();
  Chaine(const char*);
  
 public:
  unsigned int taille() const;
  char operator[](int indice) const;
  operator char const *(void) const;
};

#endif

