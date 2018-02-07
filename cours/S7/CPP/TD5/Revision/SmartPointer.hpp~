#ifndef SMART_POINTER_HPP
#define SMART_POINTER_HPP

#include<cstdlib>

namespace enseirb{  

  class SmartPointer{
    int *data;
    int *counter;
    
    void releasePointer();
    
  public:
    SmartPointer(int *data);
    
    SmartPointer(const SmartPointer &p);

    ~SmartPointer();

    int *operator->();
    const int *operator->()const ;
    int &operator*();
    const int &operator*()const;
    
    const SmartPointer &operator=(const SmartPointer &p);

    const SmartPointer &operator=(int *data);
    operator int *();
    operator const int *() const ;
  };
}

#endif
