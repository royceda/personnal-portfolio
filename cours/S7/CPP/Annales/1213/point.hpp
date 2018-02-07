#ifndef __POINT__
#define __POINT__


namespace geo{
  class Point{
  private:
    int x;
    int y;
  public:
    Point();
    Point(int, int);
    void annexe(){};
     void  annex2(){};
    Point operator+ (const Point) const;
    int operator[] (int) const;
    ~Point(){};
  };
}



#endif

