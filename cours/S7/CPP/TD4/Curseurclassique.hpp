#ifndef __CLASSICCURSOR__
#define __CLASSICCURSOR__

class CurseurClassique : public Cursor {

private:




public:
  CurseurClassique(const Chaine &c);
  virtual operator++();
  virtual operator--();
  virtual operator*();
  virtual bool fini();
  virtual void debut();
  virtual void fin();

  


}
#endif
