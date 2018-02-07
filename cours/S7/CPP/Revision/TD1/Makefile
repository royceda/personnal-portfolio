all:Chaine.o Programme.o test.o

Chaine.o: Chaine.hpp
	g++ -Wall -c Chaine.cpp -o Chaine.o;


Programme.o: 
	g++ -Wall -c Programme.cpp -o Programme.o

test.o: Programme.o Chaine.o
	g++ -Wall Programme.o Chaine.o -o test.o



clean:
	rm *.o
