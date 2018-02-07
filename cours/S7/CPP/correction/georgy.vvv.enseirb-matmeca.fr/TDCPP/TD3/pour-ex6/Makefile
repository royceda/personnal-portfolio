CC=g++
CPPFLAGS=-Wall -Wextra

BIN=prog
OBJ= prog.o Personne.o Chaine.o Etudiant.o Enseignant.o EleveVacataire.o

${BIN}: ${OBJ}
	$(CC) $^ -o $@

all: ${BIN}

clean:
	rm -f ${BIN} ${OBJ} 


Chaine.o: Chaine.hpp 

prog.o: Chaine.hpp Personne.hpp Etudiant.hpp Enseignant.hpp 

Personne.o: Personne.hpp Chaine.hpp

Etudiant.o: Etudiant.hpp Personne.hpp

Enseignant.o: Enseignant.cpp Enseignant.hpp Personne.hpp

EleveVacataire.o: EleveVacataire.hpp Enseignant.hpp Etudiant.hpp Personne.hpp


