#ifndef AUTOBUS_H 
#define AUTOBUS_H 

struct autobus;
struct ps_standard;

struct autobus*  atb_creer(long nb_assis, long nb_debout);
void atb_liberer(struct autobus *);

void atb_aller_arret_suivant(struct autobus *);

#endif //AUTOBUS_H 
