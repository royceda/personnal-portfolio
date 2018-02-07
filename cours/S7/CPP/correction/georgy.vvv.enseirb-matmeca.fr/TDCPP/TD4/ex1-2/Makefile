CXX=g++
CXXFLAGS=-Wall -g 
#-DDEBUG

Programme: Programme.o Chaine.o SmartPointer.o Curseur.o CurseurClassique.o
	$(CXX) $(CXXFLAGS) $^ -o $@

Programme.o: Programme.cpp Chaine.hpp

Chaine.o: Chaine.cpp Chaine.hpp 

SmartPointer.o: SmartPointer.cpp SmartPointer.hpp

Curseur.o: Curseur.cpp Curseur.hpp

CurseurClassique.o: CurseurClassique.cpp Curseur.hpp CurseurClassique.hpp

clean:
	rm Programme Programme.o Chaine.o SmartPointer.o Curseur.o CurseurClassique.o