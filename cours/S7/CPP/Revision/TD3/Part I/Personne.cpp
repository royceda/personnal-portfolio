#include "Personne.hpp"

namespace enseirb{

  Personne::Personne(const Chaine C): 
    _nom(C) {}
  
  
  Chaine Personne::nom() const{
    return _nom;
  }

}
