#include "Personne.hpp"
namespace enseirb {

Personne::Personne(const Chaine &name) {
 _nom=name;
}

Chaine Personne::nom() const {
	return _nom;
}

const Chaine & Personne::getName() {
	return _nom;
}
}
