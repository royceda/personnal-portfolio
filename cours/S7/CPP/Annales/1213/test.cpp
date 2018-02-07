#include "point.cpp"


using namespace geo;

int main(){
  
  Point p1(1,2);
  Point p2(3,7);

  ///  int *a = new int[10];
  Point *p = new Point[12];

  Point p3 = p1 + p2;

  cout << "p2[1]: " << p2[1] << endl;
  cout << "sum " << p3[0] << ", " << p3[1] << endl;

  cout << "taille " << sizeof(Point) << endl;


  return 0;
}
