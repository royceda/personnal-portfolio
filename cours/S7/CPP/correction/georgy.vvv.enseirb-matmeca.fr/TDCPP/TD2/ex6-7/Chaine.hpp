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
  Chaine(const Chaine &) ;
  ~Chaine();

  const Chaine& operator=(const Chaine&);
  char operator[](unsigned int) const ;
  char& operator[](unsigned int);

  unsigned int taille() const;
  char get(unsigned int);
  void debug() const ;

};

#endif
