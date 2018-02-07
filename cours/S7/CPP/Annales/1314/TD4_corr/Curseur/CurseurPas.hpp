#ifndef CURSEUR_PAS_HPP
#define CURSEUR_PAS_HPP

#include"Curseur.hpp"

namespace enseirb {
  
  class CurseurPas : public Curseur {
  private:
    //premiere position visitee
    unsigned _debut;
    //derniere position visitee
    unsigned _fin;
    //pas <> 0
    int _pas;
  public:
    /* Contraintes :
       - pas<>0
       - fin-debut nul ou de meme signe que pas
       - debut et fin dans le bon intervalle
       si fin <=0, _fin est calcule a partir de la fin de la chaine
        (si fin=0 et pas<0, _fin sera le debut de la chaine)
       fin est arrondi pour que _fin-_debut soit un multiple de pas
     */
    CurseurPas(const Chaine&,unsigned debut, int fin, int pas);
    CurseurPas& operator++();
    CurseurPas& operator--();
    bool fini() ;
    void debut() ;
    void fin();
    
  };
  
}//enseirb

#endif // CURSEUR_PAS_HPP
