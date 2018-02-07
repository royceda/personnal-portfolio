CXX=g++
CXXFLAGS=-Wall -g 

Programme: Programme.o Chaine.o
	$(CXX) $(CXXFLAGS) $^ -o $@

Programme.o: Programme.cpp Chaine.hpp

Chaine.o: Chaine.cpp Chaine.hpp 

clean:
	rm Programme Programme.o Chaine.o