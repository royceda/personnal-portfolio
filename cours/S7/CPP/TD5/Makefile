
SmartExample: SmartExample.o SmartPointer.o
	g++ -Wall -o SmartExample SmartExample.o SmartPointer.o


SmartExample.o: SmartExample.cpp SmartPointer.hpp 
	g++ -c SmartExample.cpp


SmartPointer.o: SmartPointer.hpp 
	g++ -c SmartPointer.hpp


clean: 
	rm -f SmartPointer.o SmartExample.o SmartExample
