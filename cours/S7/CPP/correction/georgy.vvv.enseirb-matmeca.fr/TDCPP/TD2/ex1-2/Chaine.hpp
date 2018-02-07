#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <cstring>

class Chaine {
 private:
  char* _donnees;
  unsigned int _taille;

 public:
  Chaine();
  Chaine(const char*);
  ~Chaine();

  unsigned int taille() const;
  char get(unsigned int i);

};

#endif
