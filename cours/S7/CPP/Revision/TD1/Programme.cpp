#include "Chaine.hpp"
#include <cstdio>



void annexe(Chaine c){}



int main() {

  Chaine C1 ;
  Chaine *C2;
  Chaine *C3 = new Chaine();
  Chaine *C4 = new Chaine("bonjour");

  printf("taille de C1: %d \n", C1.taille());
  printf("taille de C3: %d \n", C3->taille());  
  printf("taille de C2: %d \n", C2->taille());
  printf("taille de C4: %d \n", C4->taille());

  printf("3eme caractere: %c \n", C4->get(3));
  

  delete C3;
  delete C4;


  annexe(C1);

  annexe("aloolooooo");



  return 0;
}
