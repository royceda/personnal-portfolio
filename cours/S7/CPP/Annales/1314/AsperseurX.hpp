#ifndef __ASPERSEURX__
#define __ASPERSEURX__


typedef enum{A,B,C} choix;

namespace Arrossage{

  class AsperseurX: public Asperseur{
  private:
  public:
    AsperseurX(int choix);
    ~AsperseurX() {};
  };
}
#endif 
