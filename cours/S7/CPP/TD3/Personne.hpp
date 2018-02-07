#ifndef __PERSONNE_HPP__
#define __PERSONNE_HPP__

#include "./chaine3/Chaine.hpp"

namespace enseirb {

class Personne {

private:
Chaine _nom;

public:
Personne(const Chaine & );
virtual Chaine& nom() const;
~Personne();	  
};

}// fin namespace enseirb
#endif
