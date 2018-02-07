
SmartExample: SmartExample.o SmartPointer.o
	g++ -Wall -o SmartExample SmartExample.o SmartPointer.o


SmartExample.o: SmartExample.cpp SmartPointer.hpp 
	g++ -c SmartExample.cpp


SmartPointer.o: SmartPointer.cpp SmartPointer.hpp 
	g++ -c SmartPointer.cpp


clean: 
	rm -f SmartPointer.o SmartExample.o SmartExample