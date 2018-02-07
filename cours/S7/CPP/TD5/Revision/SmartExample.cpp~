#include"SmartPointer.hpp"

#include<cstdio>

void f(int *p){
  printf("%d\n",*p);
}

int main(){
  using enseirb::SmartPointer;
  SmartPointer p(new int(10));
  SmartPointer q(p);
  
  

  f(p);

  *p=5;
  f(q);
}
