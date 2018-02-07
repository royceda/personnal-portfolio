#include "Enseignant.hpp"



namespace enseirb{
  static const Chaine C("Enseignant: ");


  Enseignant::Enseignant(Chaine &nom, int time):
    Personne(nom), _service(time){}

  int Enseignant::nbHeure() const{
    return _service;
  }

  Chaine Enseignant::nom()const{
    return C + Personne::nom(); 
  }

}
