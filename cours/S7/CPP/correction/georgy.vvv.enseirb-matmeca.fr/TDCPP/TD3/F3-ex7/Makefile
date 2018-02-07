CXX=g++
CXXFLAGS=-Wall -g 
#-DDEBUG

Programme: Programme.o Chaine.o SmartPointer.o
	$(CXX) $(CXXFLAGS) $^ -o $@

Programme.o: Programme.cpp Chaine.hpp

Chaine.o: Chaine.cpp Chaine.hpp 

SmartPointer.o: SmartPointer.cpp SmartPointer.hpp

clean:
	rm Programme Programme.o Chaine.o SmartPointer.o