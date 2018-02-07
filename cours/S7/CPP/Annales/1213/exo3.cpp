#include <cstdio>
using namespace std;
class A{
  void m( int i){ printf ("A: :m( int )nn\n");}
};

struct B: public A{
  void m( char c){ printf ("B: :m( char )nn\n");}
  virtual ~B(){ printf ("B: : ~B()nn\n");}
  virtual void f(int i){ printf ("B: : f ( int )nn\n");}
  virtual B&g(){ printf ("B: : g()nn\n"); return * this ;}
};

class C: public virtual B{
public :
  //virtual A&g(){return *this ;} // 1.
  virtual void f(int i){ printf ("C: : f ( int )nn\n");}
  virtual void m(int ){ printf ("C: :m( int )nn\n");}
};

class D: public C, public virtual B{
public :
  ~D (){}
  using C::f; // 2.
  virtual D&g(){ printf ("D: : g()nn\n"); return * this ;} // 3.
  virtual void f( char c){ printf ("D: : f ( char )nn\n");}
  virtual void m(int ){ printf ("D: :m( int )nn\n");}
};

int main (){
  D d;
  A &a(d);
  A a2(d);
  B *b=&d;
  C *c=new D();
  A &x=*( new D ());
  
  d.f (10); // 4.
  d.f('a '); // 5.
  d.g(); // 6.
  //a .m(10) ; // 7.
  b->m (20); // 8.
  c->m (1); // 9.
  
  delete c;
  delete &x; // 10.
}
