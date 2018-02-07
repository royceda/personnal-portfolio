#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <cstring>
#include <iostream>
#include <SmartPointer.hpp>
#include<stdexcept>

namespace enseirb {
  
  class Chaine {
  private:
    unsigned int _taille;
    SmartPointer _donnees;
    
  public:
    Chaine();
    explicit Chaine(const char*);
    Chaine(const Chaine&);
    ~Chaine();
    const Chaine& operator=(const Chaine&);
    // conversion
    operator const char *() const;
    
    // Accesseurs
    char& operator[](unsigned i);
    char operator[](unsigned i) const;
    unsigned int taille() const;
    char get(unsigned int i) const;
    
    Chaine operator+ (const Chaine&) const ;
    
    
    
  };
  
  std::ostream& operator<< (std::ostream&, const Chaine&);
  
}//namespace enseirb

#endif
