CC=g++
CPPFLAGS=-Wall -Wextra -std=c++0x

prog: Chaine.o Programme.o Personne.o Etudiant.o Enseignant.o
	$(CC) $^ -o $@

Enseignant.o : Enseignant.hpp Personne.hpp Chaine.hpp

Etudiant.o : Etudiant.hpp Personne.hpp Chaine.hpp

Personne.o: Personne.hpp Chaine.hpp

Programme.o: Chaine.hpp

Chaine.o: Chaine.hpp

clean:
	rm -f *.o prog
