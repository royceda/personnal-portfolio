#include "EleveVacataire.hpp"


namespace enseirb {

  EleveVacataire::EleveVacataire(const Chaine &nom, const Chaine &filiere, const int service):
    Personne(nom), Etudiant(nom, filiere), Enseignant(nom, service) {}
  
  
   Chaine EleveVacataire::nom() {     
     Chaine s1("Eleve Vacataire \n");
     s1 = s1 + Etudiant::nom();
     s1 = s1 + Enseignant::nom();
     return s1;
   }
  



}
