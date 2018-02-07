#include <stdio.h>

#include "Chaine.hpp"

void annexe(const Chaine &s) {
  printf("%d\n", s.taille());
}


int main() {
  // Chaine chaine("Une petite");
  // Chaine s2(chaine) ;
  // Chaine s3 = chaine ;

  // chaine.debug() ;
  // s2.debug() ;
  // s3.debug() ;
  // Chaine s1 ("une chaine");
  // Chaine s2 ("Coucou");
  // Chaine s;
  // s2 = s1;
  // s1 = s1;
  // s = s2;

  // s2.debug();
  //  annexe(chaine);

  const Chaine s("une chaine");
  Chaine s1("autre");

  for (unsigned int i = 0; i < s.taille(); i++){
    printf("%c\n", s[i]);
  }

  s1[3] = 'Z';
  printf("%c\n", s1[3]);

}
