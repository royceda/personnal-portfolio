#include <stdio.h>

#include "Chaine.hpp"

void annexe(const Chaine &s) {
  printf("%d\n", s.taille());
}

Chaine print(Chaine s) {
  s.debug();
  return s;
}

//avec le constructeur recopie "explicit"
/* 
void print(Chaine &s, Chaine * sortie) {
  // à suivre
  Chaine tmp(s);
  tmp.debug();
  *sortie = tmp;

}
*/

int main() {
  // Chaine chaine("Une petite");
  // Chaine s2(chaine) ;
  // Chaine s3 = chaine ;

  // chaine.debug() ;
  // s2.debug() ;
  // s3.debug() ;

  Chaine c("message") ;
  print(c);

  //avec le constructeur recopie "explicit"
  /*
  Chaine c("message") ;
  Chaine s;
  print(c, &s);
  */
  //  annexe(chaine);
}
