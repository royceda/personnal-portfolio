
Prog: Chaine.o Programme.o
	g++ -Wall -o prog Chaine.o Programme.o

Programme.o: Chaine.o
	g++ -c Programme.cpp


Chaine.o: Chaine.cpp SmartPointer.hpp Chaine.hpp 
	g++ -c Chaine.cpp


clean: 
	rm -f Chaine.o Programme.o prog