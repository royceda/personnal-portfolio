#include "CurseurPas.hpp"

namespace enseirb{

  CurseurPas::CurseurPas(const Chaine &C, unsigned int start, unsigned int end, int step):
    Curseur(C), 
    _start(start),
    _end(end),
    _step(step)
  {}

  void CurseurPas::operator++(){
    if( _position + _step <= _end)
      _position += _step;
  }

  void CurseurPas::operator--(){
    if( _position - _step >= _start)
      _position -= _step;
  }

  bool CurseurPas::fini(){
    if( _position == _end)
      return true;
    else
      return false;
  }

  void CurseurPas::debut(){
    _position = _start;
  }
  
  void CurseurPas::fin(){
    _position = _end;
  }
}
