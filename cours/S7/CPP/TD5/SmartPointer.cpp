#include "SmartPointer.hpp"

namespace enseirb{
  void SmartPointer::releasePointer(){
    *counter = *counter-1;
    if (*counter==0)
      {
	delete counter;
	delete data;
      }
    counter=NULL;
  }
  
  SmartPointer::SmartPointer(DataType *data):data(data),counter(new DataType(1)){}
  
  SmartPointer::SmartPointer(const SmartPointer &p):data(p.data),counter(p.counter){
    *counter=*counter+1;
  }
  
  SmartPointer::~SmartPointer(){releasePointer();}
  
  DataType *SmartPointer::operator->(){return data;}
  
  const DataType *SmartPointer::operator->()const {return data;}
  
  DataType &SmartPointer::operator*(){return *data;}
  const DataType &SmartPointer::operator*()const{return *data;}
  
  const SmartPointer &SmartPointer::operator=(const SmartPointer &p){
    if ((this==&p)||(this->data==p.data)) return *this;
    releasePointer();
    counter=p.counter;
    *counter=*counter+1;
    data=p.data;
    return *this;
  }
  
  const SmartPointer &SmartPointer::operator=(DataType *data){
    releasePointer();
    counter=new DataType(1);
    this->data=data;
    return *this;
  }
  
  SmartPointer::operator DataType *(){return data;}
  SmartPointer::operator const DataType *() const {return data;}    
  
}
