#ifndef __CURSOR__
#define __CURSOR__

#include "Chaine.hpp"

class Cursor {

private:
  Chaine _chaine;
  int _position;

  
public :
  operator++();
  operator--();
  operator*();
  bool fini();
  void debut();
  void fin();



}
#endif
