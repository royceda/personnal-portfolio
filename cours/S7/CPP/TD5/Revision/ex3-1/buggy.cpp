#include "SmartPointer.hpp"
#include <cstdio>

int main(){
  using enseirb::SmartPointer;

  SmartPointer<int, enseirb::FonctorSimple<int> > buggy(new int(10));
  SmartPointer<int, enseirb::FonctorArray<int> > buggy2 = new int[64];
  
  buggy2[2] = 12;

  for(int i = 0; i < 64; ++i)
    printf("buggy: %d \n", buggy2[i]);


  return 0;
}
