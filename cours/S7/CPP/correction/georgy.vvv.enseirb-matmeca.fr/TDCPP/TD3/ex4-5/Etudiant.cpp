#include"Etudiant.hpp"
namespace enseirb{
  static const Chaine el("Eleve ");

  Etudiant::Etudiant (const Chaine &nom, const Chaine &filiere) :
    Personne(nom), _filiere(filiere), _gName(el + Personne::getName()) {
  }
  
  Chaine Etudiant::filiere(){
    return _filiere;
  }
  
  Chaine Etudiant::enseignement(){
    return _enseignement;
  }
  
  void Etudiant::setEnseignement(const Chaine &ens){
    _enseignement = ens;
  }
  
  Chaine Etudiant::nom() const{
    return  el + Personne::nom();
  }
  
  const Chaine & Etudiant::getName(){
    return _gName;
  }
}
