#include <stdio.h>
#include "Chaine.cpp"

void annexe(const Chaine &s) {
  printf("taille: %d\n", s.taille());
}


Chaine print (Chaine s){
    s.debug();
    return s;
}
 
 
int main() {
  Chaine s1("Une petite");
  Chaine s2(s1);
  Chaine s3=s1;
  
  s1.debug();
  s2.debug();
  s2.debug();
  
  Chaine c("message");
  print(c);

  c[3] = 'Z';

  for(unsigned int i = 0; i< c.taille(); ++i)
    printf("%c \t", c[i]);

  printf("\n");


  printf("cast: %s \n", (const char*) c);


  Chaine C1("bonjour ");
  Chaine C2("Royce");

  Chaine *C3 = C1 + C2;
  print(*C3);

  return 0;
}
