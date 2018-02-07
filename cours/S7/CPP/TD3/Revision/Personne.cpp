#include "Personne.hpp"
#include <cstdio>

namespace enseirb {
  
  Personne::Personne(const Chaine &C) {
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
    _nom = C;
  }

  Chaine Personne::nom() const {
    return _nom;
  }

  Personne::~Personne() {
    std::printf("%s(%d): %s\n", __FILE__, __LINE__, __func__);
  }
 
}
