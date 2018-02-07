all: Chaine.o Curseur.o CurseurClassique.o CurseurInverse.o CurseurPas.o Programme.o test

Chaine.o: Chaine.cpp
	g++ -c -Wall Chaine.cpp -o Chaine.o

Curseur.o: Curseur.cpp
	g++ -c -Wall Curseur.cpp -o Curseur.o

CurseurClassique.o: CurseurClassique.cpp
	g++ -c -Wall CurseurClassique.cpp -o CurseurClassique.o

CurseurInverse.o: CurseurInverse.cpp
	g++ -c -Wall CurseurInverse.cpp -o CurseurInverse.o

CurseurPas.o: CurseurPas.cpp
	g++ -c -Wall CurseurPas.cpp -o CurseurPas.o

Programme.o: Programme.cpp
	g++ -c -Wall Programme.cpp -o Programme.o

test: Programme.o Curseur.o CurseurClassique.o Chaine.o
	g++ -Wall  Programme.o Curseur.o CurseurClassique.o CurseurInverse.o CurseurPas.o Chaine.o -o test

clean:
	rm *.o test
