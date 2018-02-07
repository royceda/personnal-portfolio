#include "point.hpp"
#include <iostream>

using namespace std;

namespace geo{

  Point::Point():
    x(0),y(0){}

  Point::Point(int a, int b): 
    x(a), y(b){}

  Point Point::operator+ (const Point p2) const{
    Point p(0,0);
    p.x = this->x + p2.x;
    p.y = this->y + p2.y;
    return p;    
  }

  int Point::operator[] (int a) const{
    try{
      switch(a) {
      case 0:
	return x;
	break;
	
      case 1:
	return y;
	break;
	
      default:
	throw a;
      }
    }catch(int b){
      
      cout << "Probleme de valeur: " << b << endl;
      throw;
      
    }

  }
}
