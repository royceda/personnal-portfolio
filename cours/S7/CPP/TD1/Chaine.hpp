#ifndef _CHAINE_HPP_
#define _CHAINE_HPP_



class Chaine {
private:  //inutile car visibilité par defaut dans class
  unsigned int _taille;
  char* _donnees;

public:
  unsigned int taille();
  Chaine();
  Chaine(const char *); 
  ~Chaine();
};
#endif 
