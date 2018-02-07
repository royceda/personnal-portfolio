all: Chaine.o Personne.o Etudiant.o Enseignant.o EleveVacataire.o test

Chaine.o: Chaine.cpp
	g++ -c -Wall ./chaine3/Chaine.cpp -o Chaine.o

Etudiant.o: Etudiant.cpp 
	g++ -c -Wall Etudiant.cpp -o Etudiant.o

Programme.o: Programme.cpp  
	g++ -c -Wall Programme.cpp -o Programme.o

Personne.o: Personne.cpp 
	g++ -c -Wall Personne.cpp -o Personne.o

Enseignant.o: Enseignant.cpp 
	g++ -c -Wall Enseignant.cpp -o Enseignant.o

EleveVacataire.o: EleveVacataire.cpp 
	g++ -c -Wall EleveVacataire.cpp -o EleveVacataire.o

test: Programme.o EleveVacataire.o Enseignant.o Etudiant.o Personne.o Chaine.o
	g++ Programme.o EleveVacataire.o Enseignant.o Etudiant.o Personne.o Chaine.o -o test

clean:
	rm *.o test
