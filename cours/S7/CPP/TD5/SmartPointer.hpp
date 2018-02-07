#ifndef SMART_POINTER_HPP
#define SMART_POINTER_HPP

#include <cstdlib>

namespace enseirb{  
  template<class DataType>

  class SmartPointer{
    DataType *data;
    int      *counter;
    
    void releasePointer(){
      *counter = *counter-1;
      if (*counter==0)
	{
	  delete counter;
	  delete data;
	}
      counter=NULL;
    }
    

  public:
    SmartPointer(DataType *data):data(data),counter(new DataType(1)){} 
    SmartPointer(const SmartPointer &p):data(p.data),counter(p.counter){
    *counter=*counter+1;
  }

    ~SmartPointer(){releasePointer();}

    DataType *operator->() {return data;}
    const DataType *operator->()const {return data;}
    DataType  &operator*() {return *data;}
    const DataType &operator*()const {return *data;}
    
    const SmartPointer &operator=(const SmartPointer &p){
      
      if ((this==&p)||(this->data==p.data)) return *this;
      releasePointer();
      counter=p.counter;
      *counter=*counter+1;
      data=p.data;
      return *this;
    }

    const SmartPointer &operator=(DataType *data){

      releasePointer();
      counter=new DataType(1);
      this->data=data;
      return *this;
    }

    operator DataType *(){return data;}
    operator const DataType *() const {return data;}
  };
}

#endif
