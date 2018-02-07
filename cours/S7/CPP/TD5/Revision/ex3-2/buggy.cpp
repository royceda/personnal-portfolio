#include "SmartPointer.hpp"
#include <cstdio>

int main(){
  using enseirb::SmartPointer;

  SmartPointer<int, enseirb::freeSimple<int> > buggy(new int(10));
  SmartPointer<int, enseirb::freeArray<int> > buggy2 = new int[12];

  return 0;
}
