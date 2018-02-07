#include "Personne.hpp"
#include <cstring>
#include <memory>


namespace enseirb{
    
  Personne::Personne(const Chaine & nom): _nom(nom) {} //constructeur
  
  virtual  Chaine Personne::nom() const {
    return _nom;
  }
  
   
}
