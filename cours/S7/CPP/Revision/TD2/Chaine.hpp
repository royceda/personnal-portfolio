#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <cstring>

class Chaine {
private:
  char* _donnees;
  unsigned int _taille;
  
public:
  Chaine();
  Chaine(const Chaine &);
  Chaine(const char*);
  ~Chaine();

  unsigned int taille() const;
  char get(unsigned int i);
  void debug();
  
  const Chaine& operator=(const Chaine &);
  char& operator[](unsigned int );
  operator char* () const;
  Chaine* operator+ (const Chaine &) const; 
};

#endif
