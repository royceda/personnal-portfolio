#ifndef __CHAINE__
#define __CHAINE__


class Chaine {
  
private:
  unsigned int _taille;
  char * _donnees;


public:
  Chaine();
  Chaine(const char *str);
  int taille();
  char get(unsigned int i);
  ~Chaine(); 
};

#endif
