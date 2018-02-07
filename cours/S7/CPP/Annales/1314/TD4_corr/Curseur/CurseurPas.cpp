#include"CurseurPas.hpp"

namespace enseirb {
  
  CurseurPas::CurseurPas(const Chaine& chaine ,unsigned debut, int fin, int pas) :
    Curseur(chaine,debut), _debut(debut), _pas(pas) {
    if(debut>=chaine.taille())
	throw std::out_of_range("Debut au dela de la taille de la chaine");
    if(pas==0)
      throw std::logic_error("Pas nul");
    if(fin<0 || (fin==0 && pas>0))
      fin=chaine.taille()+fin-1;
    if(fin<0)
      throw std::out_of_range("Fin en deca de la taille de la chaine");
    if(fin>=chaine.taille())
      throw std::out_of_range("Fin au dela de la taille de la chaine");
    if((fin-(int)debut)*pas<0)
      throw std::logic_error("Debut et Fin mal ordonnes");
    _fin=(int)debut+(fin-(int)debut)/pas*pas;
  }
  
  CurseurPas& CurseurPas::operator++() {
    _position+=_pas;
    return *this;
  }
  CurseurPas& CurseurPas::operator--() {
    _position-=_pas;
    return *this;
  }
  
  bool CurseurPas::fini() {
    return _position<((_debut<_fin)?_debut:_fin) || _position>((_debut>_fin)?_debut:_fin);
  }
  
  void CurseurPas::debut() {
    _position=_debut;
  }
  
  void CurseurPas::fin() {
    _position = _fin;
  }
  
}//enseirb
