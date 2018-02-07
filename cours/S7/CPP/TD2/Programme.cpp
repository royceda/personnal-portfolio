#include <stdio.h>

#include "Chaine.hpp"

void annexe(const Chaine &s) {
  
  printf("taile : %d \n", s.taille());
}


int main() {
  Chaine chaine("Une petite");
  annexe("salut");
  annexe(chaine);
  chaine.debug();

  Chaine s1("YaaaAAAAaaaa!");
  Chaine s2(s1);
  Chaine s3 = s1;

  s1.debug();
  s2.debug();
  s3.debug();
}
