#ifndef __FONCTIONS_INTERNES_H 
#define __FONCTIONS_INTERNES_H 

#include <stdbool.h>

// fonctions internes utilisees par ps_standard.
bool __atb_a_place_assise(const struct autobus*);
bool __atb_a_place_debout(const struct autobus*);

void __atb_demander_assise(struct autobus*, struct ps_standard*);
void __atb_demander_debout(struct autobus*, struct ps_standard*);
void __atb_demander_sortie(struct autobus*, struct ps_standard*);

void __atb_changer_debout(struct autobus *, struct ps_standard *);
void __atb_changer_assis(struct autobus *, struct ps_standard *);


// fonctions internes utilisees par autobus.
void __ps_std_accepter_sortie(struct ps_standard *);
void __ps_std_accepter_assise(struct ps_standard *);
void __ps_std_accepter_debout(struct ps_standard *);

void __ps_std_nouvel_arret(struct ps_standard *, struct autobus *, int);

#endif //__FONCTIONS_INTERNES_H 
