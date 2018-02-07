#ifndef CHAINE_HPP
#define CHAINE_HPP

class Chaine{

  unsigned int _taille;
  char * _donnees;

public:

  Chaine();
  Chaine(const char*);
  ~Chaine();
  unsigned int taille();
  //Les indices commencent à 0  
  char get(unsigned int);
  
};

#endif
