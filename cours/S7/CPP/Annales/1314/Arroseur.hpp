#ifndef __ARROSEUR__
#define __ARROSEUR__

namespace Arrossage{

  class Arroseur{
  private:
  public:
    Arroseur();
    virtual bool estEnMarche()=0;
    virtual void demarrer()=0;
    virtual void arreter()=0;
    virtual double quantiteEau()=0;
    virtual double debit()=0;
    ~Arroseur(){};
  };
}
#endif
