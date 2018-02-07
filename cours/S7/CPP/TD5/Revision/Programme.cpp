#include<cstdio>

#include "Chaine.hpp"


void affiche(const Chaine &s){
  std::puts("affiche:");
  for(unsigned int i = 0; i < s.taille(); i++)
    std::putchar(s[i]);
  std::puts("");
}

int main(int argc, char **argv){
  Chaine s("un texte long");
  Chaine p("test");
  Chaine copie=p;


  affiche(s);
  affiche(p);
  affiche(copie);

  p=s;
  
  affiche(s);
  affiche(p);
  affiche(copie);
}
