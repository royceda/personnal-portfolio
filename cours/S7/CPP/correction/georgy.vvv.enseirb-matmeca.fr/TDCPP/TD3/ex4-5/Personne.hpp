#ifndef PERSONNE_HPP
#define PERSONNE_HPP
#include "Chaine.hpp"
namespace enseirb {

  class Personne {
	private:
	Chaine _nom;
	public:
	Personne(const Chaine &);
	virtual Chaine nom() const;
	virtual const Chaine & getName();
        virtual ~Personne() {}
};
}
#endif
