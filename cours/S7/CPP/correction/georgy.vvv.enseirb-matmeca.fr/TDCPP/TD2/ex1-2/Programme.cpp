#include <stdio.h>

#include "Chaine.hpp"

void annexe(const Chaine &s) {
  printf("%d\n", s.taille());
}

int main() {
  Chaine chaine("Une petite");

  annexe(chaine);
}
