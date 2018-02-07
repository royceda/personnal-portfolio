CC=g++
CPPFLAGS=-Wall -Wextra -std=c++0x

prog: Chaine.o Programme.o Personne.o
	$(CC) $^ -o $@
Personne.o: Personne.hpp Chaine.hpp

Programme.o: Chaine.hpp

Chaine.o: Chaine.hpp

clean:
	rm -f *.o prog
