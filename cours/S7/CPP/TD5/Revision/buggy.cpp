#include "SmartPointer.hpp"
#include <cstdio>

int main(){
  using enseirb::SmartPointer;

  SmartPointer<int> buggy(new int(10));

  return 0;
}
