/*
 * Scenario avec trois passager standard
 *  passager K monte à l'arret numero 1 destination arret numero 6
 *  passager J monte à l'arret numero 1 destination arret numero 4 
 *  passager I monte à l'arret numero 2 destination arret numero 3
 * L'autobus a 1 place assise et 2 places debout sur trois arret.
 */

#include <stdio.h>

#include "autobus.h"
#include "ps_standard.h"

static int arret = 0;

static void debogue_etat(struct ps_standard *p) {
  printf("%d:%s -> assis: %d, debout: %d, dehors: %d\n", arret,
	 ps_std_nom(p), 
	 ps_std_est_assis(p), 
	 ps_std_est_debout(p), 
	 ps_std_est_dehors(p)); 
}

int main() {
  struct autobus *serenity = atb_creer(1, 2);

  atb_aller_arret_suivant(serenity); arret++;

  struct ps_standard *kaylee = ps_std_creer("Kaylee", 6);
  struct ps_standard *jayne = ps_std_creer("Jayne", 4);
  struct ps_standard *inara = ps_std_creer("Inara", 3);

  ps_std_monter_dans(kaylee, serenity);
  ps_std_monter_dans(jayne, serenity);

  debogue_etat(kaylee);
  debogue_etat(jayne);
  debogue_etat(inara);

  atb_aller_arret_suivant(serenity); arret++;

  ps_std_monter_dans(inara, serenity);

  debogue_etat(kaylee);
  debogue_etat(jayne);
  debogue_etat(inara);

  atb_aller_arret_suivant(serenity); arret++;

  debogue_etat(kaylee);
  debogue_etat(jayne);
  debogue_etat(inara);
 
  atb_aller_arret_suivant(serenity); arret++;

  debogue_etat(kaylee);
  debogue_etat(jayne);
  debogue_etat(inara);
 
  atb_liberer(serenity);
  ps_std_liberer(kaylee);
  ps_std_liberer(jayne);
  ps_std_liberer(inara);
}
