#include "SmartPointer.hpp"
#include "Chaine.cpp"

#include <cstring>
#include <cstdio>

void f(int *p){
  printf("%d\n",*p);
}

void g(char s){
  printf("%c\n",s);
}

void h(char *s){
  printf("%s\n", s);
}


int main(){
  using enseirb::SmartPointer;
  using enseirb::Chaine;

  //Int
  SmartPointer<int> p(new int(10));
  SmartPointer<int> q(p);
  
  f(p);
  *p=5;
  f(q);

  //Char
  SmartPointer<char> p1(new char('a'));
  SmartPointer<char> q1(p1);
  
  g(*p1);
  *p1='z';
  g(*q1);
  g(*p1);

  //String
  char* bb = new char[16];
  strcpy(bb, "bonjour");

  SmartPointer<char> p2(bb);
  SmartPointer<char> q2(p1);
  
  h(p2);

  //Chane
  SmartPointer<Chaine> p3(new Chaine("bonjour"));
  printf("taille: %d\n", p3->taille());
  
  /*f(p);
  *p="e";
  */
  return 0;
}
