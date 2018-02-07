#include <stdio.h>

#include "Chaine.cpp"

void annexe(const Chaine & s) {

  std::printf("la taille est: %d \n", s.taille()); 
}


Chaine print(Chaine s) {

  s.debug();
  return s;
}


void main1() {

  std::printf("\nLes premiers essais !!!!\n\n");
  Chaine chaine("Une petite");
  annexe(chaine);

  Chaine s1("futur");
  Chaine s2(s1);
  Chaine s3 = s1;

  s1.debug();
  s2.debug();
  s3.debug();
  
  Chaine c("Power trip");
  print(c);
}



int main() {

  //main1();

  std::printf("\nLes seconds essais, operateur !!!!\n\n");

  Chaine s1("hahaha");
  Chaine s2("blitz");

  Chaine s3 = s1 + s2;
  
  for(unsigned int i = 0; i<s3.taille(); i++)
    std::printf(" %c", s3[i]);
  std::printf("\n");

  s2 = s1;
  s2.debug();
  
  for(unsigned int i = 0; i<s2.taille(); i++)
    std::printf(" %c\t", s2[i]);
  
  std::printf("\n");
  
  std::printf("_donnees converti: %s \n", (const char *) s2);


  return 0;
}
