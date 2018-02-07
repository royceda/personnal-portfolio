#include <iostream>
#include <cstdio>

class A{
public:
  void m(){printf("A\n");};
};


class B:public A{
public:
  virtual void m(){printf("B\n");};
  virtual void m(int a){printf("Bi\n");};
};

class C:public B{
private:
  int *i;
public:
  C():i(new int(0)){};
  ~C(){delete i;};
  using B::m;
  void m(){printf("C\n");};
};
  
  
void f(A &a){a.m();}
void g(B b){b.m();}
void h(B &c){c.m();}


int main(){
  C *c = new C();
  c->m(1);
  f(*c);
  g(*c);
  h(*c);
  delete c;
}
