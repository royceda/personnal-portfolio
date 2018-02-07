#include "SmartPointer.hpp"
#include "Chaine.hpp"

#include <cstdio>

void f(int *p){
  printf("%d\n",*p);
}

int main(){
  using enseirb::SmartPointer;



  SmartPointer<Chaine> c(new Chaine("aaaa"));
  SmartPointer<Chaine> d(c);

  SmartPointer<int> p(new int(10));
  SmartPointer<int> q(p);
  
  // /!\ penser a delete[]

  f(p);

  *p=5;
  f(q);
return 1;
}
