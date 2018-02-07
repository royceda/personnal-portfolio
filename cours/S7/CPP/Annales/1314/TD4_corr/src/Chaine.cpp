#include<Chaine.hpp>

namespace enseirb {

  Chaine::Chaine():_taille(0),_donnees(new char[1]) {}
  
  Chaine::Chaine(const char *s) : _taille(std::strlen(s)), _donnees(new char[_taille + 1]) {
    std::strcpy(_donnees.get(), s);
  }
  
  Chaine::Chaine(const Chaine& c) : _taille(c._taille), _donnees(c._donnees) {}
  
  const Chaine& Chaine::operator=(const Chaine& c) {
    if( &c == this)
      return *this;
    _taille = c._taille;
    _donnees = c._donnees;
    return *this;
  }
  
  Chaine::~Chaine() {}
  
  unsigned int Chaine::taille() const {
    return _taille;
  }
  
  char Chaine::get(unsigned int i) const {
    if (i>=_taille)
      throw std::out_of_range("Out of Chaine");
    return _donnees.get()[i];
  }
  
  char Chaine::operator[] (unsigned i) const {
    if (i>=_taille)
      throw std::out_of_range("Out of Chaine");
    return get(i);
  }
  
  char& Chaine::operator[] (unsigned i) {
    if (i>=_taille)
      throw std::out_of_range("Out of Chaine");
    return _donnees.get()[i];
  }
  
  Chaine::operator const char *() const {
    return _donnees.get();
  }
  
  Chaine Chaine::operator+ (const Chaine& c) const {
    if (_taille==0)
      return c;
    if (c._taille==0)
      return *this;
    Chaine r;	
    r._taille = _taille+c._taille;
    char *donnees = new char[r._taille+1];
    std::strcpy(donnees, _donnees);
    std::strcpy(donnees+_taille, c._donnees);
    r._donnees=SmartPointer(donnees);
    return r;
  }
  
  std::ostream& operator<< (std::ostream& o, const Chaine& c) {
    o << (const char *) c;
    return o;
  }
  
}// namespace enseirb

