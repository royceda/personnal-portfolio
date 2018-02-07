#include "EleveVacataire.hpp"


namespace enseirb{
  static Chaine C3("Eleve Vacataire: ");

  EleveVacataire::EleveVacataire(Chaine &nom, Chaine &enseignement, Chaine &filiere, int time):
    Personne(nom), Etudiant(nom, enseignement, filiere), Enseignant(nom,time){}

  Chaine EleveVacataire::nom() const{
    return C3 + Personne::nom();
  }

}
