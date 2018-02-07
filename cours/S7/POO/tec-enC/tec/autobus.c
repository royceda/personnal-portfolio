#include <stdlib.h>
#include <string.h>

static const char const *version __attribute__((unused))="Vers: 2.1";

#include "ps_standard.h"
#include "autobus.h"

#include "__fonctions_internes.h"

#define MAX 100

struct autobus {
  long max_assis;
  long assis;
  long max_debout;
  long debout;

  int arret;

  struct ps_standard *passagers[MAX];
};

static void ajouter_passager(struct autobus *a, const struct ps_standard *p) {
  a->passagers[(a->assis + a->debout) - 1] = (struct ps_standard *) p;
}

struct autobus*  atb_creer(long nb_assis, long nb_debout) {
  struct autobus *a = malloc(sizeof(struct autobus));
  a->debout = a->assis = 0;
  a->max_assis = nb_assis;
  a->max_debout = nb_debout;
  a->arret = 0;
  return a;
}

void atb_liberer(struct autobus *a) {
  free(a);
}

void atb_aller_arret_suivant(struct autobus *a) {
  a->arret++;
  for (int i = 0; i < (a->assis + a->debout); i++)
    __ps_std_nouvel_arret(a->passagers[i], a, a->arret);
}

// fonctions internes
bool __atb_a_place_assise(const struct autobus *a) {
  return a->assis < a->max_assis;
}

bool __atb_a_place_debout(const struct autobus *a) {
  return a->debout < a->max_debout;
}

void __atb_demander_assise(struct autobus *a, struct ps_standard *p) {
    a->assis++;
    __ps_std_accepter_assise(p);
    ajouter_passager(a, p);
}

void __atb_demander_debout(struct autobus *a, struct ps_standard *p) {
    a->debout++;
    __ps_std_accepter_debout(p);
    ajouter_passager(a, p);
  }

void __atb_changer_debout(struct autobus *a, struct ps_standard *p) {
    a->assis--;
    a->debout++;
    __ps_std_accepter_debout(p);
  }

void __atb_changer_assis(struct autobus *a, struct ps_standard *p) {
  a->debout--;
  a->assis++;
  __ps_std_accepter_assise(p);
}

void __atb_demander_sortie(struct autobus *a, struct ps_standard *p) {
  if (ps_std_est_debout(p)) {
    a->debout--;
    __ps_std_accepter_sortie(p);
  }
  
  if (ps_std_est_assis(p)) {
    a->assis--;
    __ps_std_accepter_sortie(p);
  }
}


