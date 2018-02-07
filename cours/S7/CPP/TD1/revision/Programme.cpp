#include "Chaine.cpp"


void annexe(Chaine s) {}



int main() {

Chaine C1;
Chaine *C2;
Chaine *C3 = new Chaine();
Chaine *C4 = new Chaine("Seen it all");

std::printf("taille C1: %d \n", C1.taille());
std::printf("taille C2: %d \n", C2->taille());
std::printf("taille C3: %d \n", C3->taille());


std::printf(" la 5eme est : %c \n", C4->get(5));

delete C3;
delete C4;

annexe("aaaaaaa");

return 0;
}
