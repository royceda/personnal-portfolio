#include "Chaine.cpp"
using namespace std;


void annexe(Chaine s) {}




int main() {

  std::printf("appel static:\n");
  Chaine   C1; // alloc auto
  Chaine * C2; // appel du constructeur Chaine()
  Chaine * C3; // ____________________________

  std::printf("appel dynamique:\n");
  C2 = new Chaine(); //alloc dynamique
  C3 = new Chaine("BONJOUR");
  
  std::printf("\ntaille de C1 (static): %d \n", C1.taille());
  std::printf("taille de C2 (pointeur): %d \n", C2->taille());
  std::printf("taille de C3 (pointeur): %d \n", C3->taille());
  
  annexe("salue ca va");
  /*
    Alloc dynamique sur la pile
    appel constructeur Chaine (const Chaine&) et en statique
    execution de annexe()
    appel destructeur ~Chaine()
    liberation automatique
   */


  delete(C2); // Appel du destructeur (objet *p)
  delete(C3); // Liberation dynamique
  return 0;
  /*
    Appel du destructeur (objet c)
    liberation automatique
  */
}
