#include<iostream>
#include"CurseurClassique.hpp"
#include"CurseurInverse.hpp"
#include"CurseurPas.hpp"


int main() {
enseirb::Chaine c("Une chaine a parcourir");
std::cout << "A l'endroit" << std::endl;
enseirb::CurseurClassique curs(c);
while(!curs.fini()) {
std::cout << *curs << std::endl;
++curs;
}
std::cout << "A l'envers" << std::endl;
enseirb::CurseurInverse cursi(c);
while(!cursi.fini()) {
std::cout << *cursi << std::endl;
++cursi;
}
std::cout << "De 2 en 2" << std::endl;
enseirb::CurseurPas cursa(c,0,-3,2);
while(!cursa.fini()) {
std::cout << *cursa << std::endl;
++cursa;
}
std::cout << "De -3 en -3" << std::endl;
enseirb::CurseurPas cursb(c,c.taille()-1,0,-3);
while(!cursb.fini()) {
std::cout << *cursb << std::endl;
++cursb;
}
return 0;
}
