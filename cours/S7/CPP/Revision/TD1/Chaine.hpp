#ifndef __CHAINE__
#define __CHAINE__


class Chaine{
  
private:
  char* _donnees;
  unsigned int _taille;
  
public:
  Chaine();
  Chaine(const char *);
  int taille();
  char get(unsigned int i);
  ~Chaine();
};









#endif
